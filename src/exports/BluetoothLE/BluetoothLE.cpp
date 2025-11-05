#include <Arduino.h>									// sprintf()

#include "src/exports/BluetoothLE/BluetoothLE.h"
#include "src/hardware/BluetoothLE/ble_spp_server.h"


void BluetoothLE::begin(void) {
	ble_init();
}

void BluetoothLE::update(void) {
	
}

void BluetoothLE::exportdata(void) {
	uint32_t t = millis();	// TODO
	uint32_t txCount = 0;	// TODO
	uint32_t txBytes = 0;	// TODO
	char buffer[32];
	int length = sprintf(buffer, "T:%u P:%u B:%u", t, txCount, txBytes);
	ble_send(SPP_IDX_SPP_STATUS_VAL, buffer, length);
}
