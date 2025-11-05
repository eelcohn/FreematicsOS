#include <Arduino.h>
#include <esp_log.h>	// Arduino ESP logging

#include "src/hardware/Freematics/Freematics.h"
#include "src/hardware/Celldata/Celldata.h"

extern MCU mcu;


void Celldata::begin() {

//	xbBegin(CELLDATA_BAUDRATE, PIN_CELLDATA_RXD, PIN_CELLDATA_TXD);
}

void Celldata::update() {

}

void Celldata::togglePower() {
	enable();
	delay(100);
	disable();
	delay(200);
	enable();
	delay(100);
	disable();
}

void Celldata::enable() {
	mcu.enableCelldata();
}

void Celldata::disable() {
	mcu.disableCelldata();
}
