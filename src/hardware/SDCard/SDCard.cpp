#include <Arduino.h>
#include <SdFat.h>			// SDCard support (FAT16/FAT32/ExFAT)

#include "src/FreematicsOSConfig.h"
#include "src/hardware/Freematics/Freematics.h"
#include "src/hardware/SDCard/SDCard.h"



extern FreematicsOSConfig_t config;



void SDCard::begin() {

	if (!sd.begin(PIN_SDCARD_CS, SPI_FULL_SPEED)) {
		sd.initErrorHalt("initialization failed");
		ESP_LOGE(LOG_TAG, "initialization failed");
	}
}

// Check if the volume is damaged
bool SDCard::checkVolume() {

	return true;
//	return sd.checkVolume();

}

bool SDCard::writeln(const char *data) {

	// if the file opened okay, write to it:
	if (sd.open(config.csv_filename, O_RDWR | O_CREAT | O_AT_END)) {
		file.println("testing 1, 2, 3.");
		file.close();	// close the file

		return true;
	}

	ESP_LOGE(LOG_TAG, "open file for writing failed");
	sd.errorHalt("opening file for read failed");

	return false;
}

bool SDCard::readln(char &buffer, const size_t buf_len) {

	// if the file opened okay, write to it:
	if (sd.open(config.csv_filename, O_READ | O_AT_END)) {
		while (file.available()) {
			if (file.fgets(&buffer, buf_len) <= 0) {
				ESP_LOGE(LOG_TAG, "fgets failed");
			}
		}
		file.close();	// close the file

		return true;
	}

	ESP_LOGE(LOG_TAG, "open file for reading failed");
	sd.errorHalt("opening file for read failed");

	return false;
}
