#include <Arduino.h>
#include <esp_log.h>	// Arduino ESP logging
#include <SPI.h>		// SPI bus
#include <Wire.h>		// I2C bus
#include <WiFi.h>

#include "FreematicsOS.h"
#include "src/FreematicsOSConfig.h"
#include "src/Exports/Exports.h"
#include "src/hardware/Accelerometer/Accelerometer.h"
#include "src/hardware/Celldata/Celldata.h"
#include "src/hardware/Freematics/Freematics.h"
#include "src/hardware/GNSS/GNSS.h"
#include "src/hardware/OBD2/OBD2.h"
#include "src/hardware/SDCard/SDCard.h"



/* Create class instances */
Accelerometer accelerometer;	// Accelerometer
Exports exports;							// All export modules (CSV, Freematics Hub, Traccar, ...)
MCU mcu;											// ESP32 MCU
SdExFat sdcard;								// SD card
Celldata celldata;						// Cellular mobile data
GNSS gnss;										// Location services (GPS)
OBD2 obd;											// OBD2
WiFiClient client;						// WiFi client

/* Reference to default config */
extern FreematicsOSConfig_t config;



void setup(void) {

	/* Small delay before startup so we can monitor the USB serial console */
	delay(1000);

	/* Buzzer on setup */
	mcu.buzzer(1200, 500);

	/* Logging */
	static const char *LOG_TAG = "Setup";
	esp_log_level_set("*", ESP_LOG_VERBOSE); /* Set project-wide log level */

	/* Start the USB serial interface */
	Serial.begin(115200);
	while(!Serial);

	/* Start I2C bus */
	Wire.begin();

	/* Start SPI bus */
	SPI.begin();

	/* Start the SD card */
	sdcard.begin();

	/* Start the accelerometer */
	accelerometer.begin();

	/* Start the GNSS location service */
	gnss.begin();

	/* Start the OBD2 bus */
	obd.begin();

	/* Set WiFi hostname */
	WiFi.mode(WIFI_STA);
	WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
	WiFi.setHostname(config.hostname);
	WiFi.begin(config.wifi_client_ssid, config.wifi_client_password);

	/* Start all export modules */
	exports.begin();

	/* */
	ESP_LOGI(LOG_TAG, "Done");

	/* Buzzer on setup end */
	mcu.buzzer(2400, 500);
}

void loop(void) {

	/* Logging tag */
	static const char *LOG_TAG = "Main loop";

	ESP_LOGI(LOG_TAG, "ESP battery voltage: %f", mcu.battery_voltage);
	ESP_LOGI(LOG_TAG, "OBD battery voltage: %f", obd.getVoltage());

	/* Check if the ignition is on, motor is off */
	if ((obd.battery_voltage < BATTERY_VOLTAGE_JUMPSTART)) {

		/* Ignition is off */
//		obd.enterLowPowerMode();
		accelerometer.calibrate();
//		accelerometer.waitMotion(-1);
//		accelerometer.end();

		/* Start WiFi client */
		WiFi.mode(WIFI_STA);
		WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
		WiFi.setHostname(config.hostname);
		WiFi.begin(config.wifi_client_ssid, config.wifi_client_password);

		delay(5000);
	} else {

		/* Ignition is on */

		/* Update the accelerometer data */
		accelerometer.update();

		/* Update the Cellular Data data */
		celldata.update();

		/* Update the GNSS data */
		gnss.update();

		/* Update the OBD2 data */
		obd.update();

		/* Export data */
		exports.update();

		delay(1000);
	}
}
