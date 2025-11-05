#include <OBD2_CanBus.h>

#include "src/hardware/Freematics/Freematics.h"
#include "src/hardware/OBD2/OBD2.h"



//OBD2_CanBus CanBus(PIN_CAN_RX, PIN_CAN_TX); // TODO move this inside the OBD2 class/instance



OBD2::OBD2(void) {
//OBD2::OBD2(void) : canbus(PIN_CAN_RX, PIN_CAN_TX) {
	/* Initialize the CAN bus class instance */
//	OBD2_CanBus CanBus(PIN_CAN_RX, PIN_CAN_TX);
}

OBD2::~OBD2(void) {
	
}

void OBD2::begin(void) {

	/* Initialize the CAN bus class instance */
	canbus.setDebug(Serial);          // Optional: outputs debug messages to the selected serial port
	canbus.setProtocol("Automatic");  // Optional: communication protocol (default: Automatic; supported: 11b250. 11b500, 29b250, 29b500)
	canbus.setReadTimeout(200);       // Optional: maximum time (ms) to wait for a response after sending a request

	if (canbus.initOBD2()) {

		/*  */
		ESP_LOGI(LOG_TAG, "Vehicle Identification Number: %s", vin);
		ESP_LOGI(LOG_TAG, "Calibration ID: %s", cin);
		ESP_LOGI(LOG_TAG, "Calibration verification numbers: %s", cvn);
		ESP_LOGI(LOG_TAG, "OBD2 Standards: 0x%08X", obd2_standards);
		ESP_LOGI(LOG_TAG, "Fuel type: 0x%08X", fuel_type);

		/* Print supported mode 1 PIDs */
		printSupportedPIDs(SERVICE_LIVE_DATA);

		/* Print supported mode 2 PIDs */
		printSupportedPIDs(SERVICE_FREEZE_FRAME_DATA);

		/* Print supported mode 9 PIDs */
		printSupportedPIDs(SERVICE_REQUEST_VEHICLE_INFORMATION);

		/* Get static (non-changing) values */
		vin = canbus.getVehicleInfo(PID_9_VIN);
		cid = canbus.getVehicleInfo(PID_9_CALIBRATION_ID);
		cvn = canbus.getVehicleInfo(PID_9_CVN);
		obd2_standards = canbus.getLiveData(PID_1_OBD_STANDARDS);
		fuel_type = canbus.getLiveData(PID_1_FUEL_TYPE);

	} else {
		ESP_LOGE(LOG_TAG, F("Could not initialize OBD2"));
	}

}

void OBD2::update(void) {

	// Attempt to initialize OBD2 communication
	if (canbus.initOBD2()) {
		rpm = canbus.getLiveData(PID_1_RPM);
		speed = canbus.getLiveData(PID_1_SPEED);
		coolant_temperature = canbus.getLiveData(PID_1_COOLANT_TEMP);
		battery_voltage = canbus.getLiveData(PID_1_CONTROL_MODULE_VOLTAGE);
		fuel_level = canbus.getLiveData(PID_1_FUEL_LEVEL);
		odometer = canbus.getLiveData(PID_1_ODOMETER);
	}

}

String OBD2::printSupportedPIDs(uint8_t mode) {
	int liveDataLength;

	switch (mode) {

		case SERVICE_LIVE_DATA:
			liveDataLength = canbus.readSupportedLiveData();
			ESP_LOGV(LOG_TAG, F("Supported mode 1 (live data) PID's: "));
			break;

		case SERVICE_FREEZE_FRAME_DATA:
			liveDataLength = canbus.readSupportedLiveData();
			ESP_LOGV(LOG_TAG, F("Supported mode 2 (freeze frame) PID's: "));
			break;

		case SERVICE_REQUEST_VEHICLE_INFORMATION:
			ESP_LOGV(LOG_TAG, F("Supported mode 9 (vehicle information) PID's: "));
			liveDataLength = canbus.readSupportedVehicleInfo();
			break;

		default:
			liveDataLength = 0;
			ESP_LOGE(LOG_TAG, F("Unsupported print PID list"));
			break;
			
	}

	/* Print supported mode 1 PIDs */
	if (liveDataLength > 0) {
		for (int i = 0; i < liveDataLength; i++) {
			byte supported = canbus.getSupportedData(mode, i);
			Serial.printf("%02X ", supported);
		}
		Serial.println();
	}
}
