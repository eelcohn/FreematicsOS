#include <Arduino.h>

#include "src/hardware/Freematics/Freematics.h"				// MCU
#include "src/exports/USBSerialConsole/USBSerialConsole.h"
#include "src/hardware/OBD2/OBD2.h"



extern MCU mcu;
extern OBD2 obd;



void USBSerialConsole::begin(void) {
	
}

void USBSerialConsole::update(void) {
	
}

void USBSerialConsole::exportdata(void) {
	Serial.printf("ESP Battery voltage: %f\n", mcu.battery_voltage);
	Serial.printf("OBD Battery voltage: %f\n", obd.battery_voltage);
}
