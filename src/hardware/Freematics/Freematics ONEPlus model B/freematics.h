#pragma once

#include <SoftwareSerial.h>		// Software emulated serial UART



/* Freematics Model */
static const char *FREEMATICS_MODEL	= "Freematics ONE+ model B";

/* SPI bus */
#define SPI_FREQ 1000000

/* SDCard */
#define PIN_SDCARD_CS 5

/* Accelerometer */


/* OBD2 CAN bus */
#define PIN_CAN_RX 13
#define PIN_CAN_TX 14

/* Cellular network module (XBee) */
#define PIN_CELLDATA_POWER 27
#define PIN_CELLDATA_RXD 35
#define PIN_CELLDATA_TXD 2
#define CELLDATA_BAUDRATE 115200

/* GPS */
#define PIN_GPS_POWER 15
#define PIN_GPS_RXD 32
#define PIN_GPS_TXD 33

/* Buzzer */
#define PIN_BUZZER 25

/* LED's */
#define PIN_LED_BLUE 4

/* Serial ports */
//HardwareSerial & uart_debug = Serial;
//HardwareSerial & uart_gnss = Serial1;
//HardwareSerial & uart_cell = Serial2;
//SoftwareSerial sim900(7, 8);



/* Class definition of the ESP32 MCU */
class MCU {

	public:

		float temperature = 0;
		float battery_voltage = 0;

		void begin(void);
		void update(void);
		void readChipTemperature(void);
		const uint32_t getFlashChipSize(void);
		const uint32_t getSketchSize(void);
		const uint32_t getCPUFreqMhz(void);
		const uint32_t get_cpu_id(void);
		const uint32_t get_flash_chip_id(void);
		const char * getFlashMode(void);
		const uint32_t getFlashChipSpeed(void);
		const bool checkFlashCRC(void);
		const uint32_t getFreeSketchSpace(void);
		const String getSketchMD5(void);
		const uint32_t getFreeHeap(void);
		const uint32_t getHeapFragmentation(void);
		const uint32_t getHeapMaxFreeBlockSize(void);
		const size_t getFreeSpace(void);
		void buzzer(uint16_t freq, uint16_t duration);
		void enableLED(void);
		void disableLED(void);
		void enableCelldata(void);
		void disableCelldata(void);
		void enableGPS(void);
		void disableGPS(void);
		void readBatteryVoltage(void);

	private:

		/* Logging tag */
	    static constexpr const char* LOG_TAG = "System";

};
