#include <Arduino.h>
#include <driver/temp_sensor.h>

#include "src/FreematicsOSConfig.h"
#include "src/hardware/Freematics/Freematics ONEPlus model B/freematics.h"



extern FreematicsOSConfig_t config;



void MCU::begin() {

	/* */
	ESP_LOGI(LOG_TAG, "%s %s", OS_NAME, OS_VERSION);
	ESP_LOGI(LOG_TAG, "Flash size: %u (%u Used / %u free) %i%\n", getFlashChipSize(), getSketchSize(), getFreeSpace(), (int)(getFreeSpace()/getFlashChipSize() * 100));

	/* Set up cellular network pins */
	pinMode(PIN_CELLDATA_POWER, OUTPUT);

	/* Set up GPS pins */
	pinMode(PIN_GPS_POWER, OUTPUT);

	/* Set up blue LED pin */
	pinMode(PIN_LED_BLUE, OUTPUT);

    /* Set up buzzer */
	pinMode(PIN_BUZZER, OUTPUT);

	/* Set up ESP32 internal temperature sensor */
    temp_sensor_config_t temp_sensor = TSENS_CONFIG_DEFAULT();
    temp_sensor.dac_offset = TSENS_DAC_L2;  // TSENS_DAC_L2 is default; L2(-10°C ~ 80°C)
    temp_sensor_set_config(temp_sensor);
    temp_sensor_start();
}

void MCU::update() {
	readChipTemperature();
	readBatteryVoltage();
}

void MCU::readChipTemperature(void) {
	temp_sensor_read_celsius(&temperature);
}

const uint32_t MCU::getFlashChipSize(void) {
	return ESP.getFlashChipSize();
}

const uint32_t MCU::getSketchSize(void) {
	return ESP.getSketchSize();
}

const uint32_t MCU::getCPUFreqMhz(void) {
	return (ESP.getCpuFreqMHz() * 1000000);
}

const uint32_t MCU::get_cpu_id(void) {
	return (ESP.getEfuseMac());
}

const uint32_t MCU::get_flash_chip_id(void) {
//	return ESP.getFlashChipId();
	return 0;
}

const char * MCU::getFlashMode(void) {
	FlashMode_t mode [[gnu::unused]] = ESP.getFlashChipMode();

	return (mode == FM_QIO ? "QIO" : mode == FM_QOUT ? "QOUT" : mode == FM_DIO ? "DIO" : mode == FM_DOUT ? "DOUT" : "UNKNOWN");
}

const uint32_t MCU::getFlashChipSpeed(void) {
	return ESP.getFlashChipSpeed();
}

const bool MCU::checkFlashCRC(void) {
//	return ESP.checkFlashCRC();
	return true;
}

const uint32_t MCU::getFreeSketchSpace(void) {
	return ESP.getFreeSketchSpace();
}

const String MCU::getSketchMD5(void) {
	return ESP.getSketchMD5();
}

const uint32_t MCU::getFreeHeap(void) {
	return ESP.getFreeHeap();
}

const uint32_t MCU::getHeapFragmentation(void) {
//	return ESP.getHeapFragmentation();
	return 0;
}

const uint32_t MCU::getHeapMaxFreeBlockSize(void) {
//	return ESP.getMaxFreeBlockSize();
	return 0;
}

const size_t MCU::getFreeSpace(void) {
	return (ESP.getFlashChipSize() - ESP.getSketchSize());
}

void MCU::buzzer(uint16_t freq, uint16_t duration) {
	if (config.buzzer_enabled) {
		tone(PIN_BUZZER, freq, duration);
	}
}

void MCU::enableLED() {
	digitalWrite(PIN_LED_BLUE, HIGH);
}

void MCU::disableLED() {
	digitalWrite(PIN_LED_BLUE, LOW);
}

void MCU::enableCelldata() {
	digitalWrite(PIN_CELLDATA_POWER, HIGH);	
}

void MCU::disableCelldata() {
	digitalWrite(PIN_CELLDATA_POWER, LOW);	
}

void MCU::enableGPS() {
	digitalWrite(PIN_GPS_POWER, HIGH);	
}

void MCU::disableGPS() {
	digitalWrite(PIN_GPS_POWER, LOW);	
}

void MCU::readBatteryVoltage(void) {
	battery_voltage = ((analogRead(A0) * 12 * 370) / 4095);
}
