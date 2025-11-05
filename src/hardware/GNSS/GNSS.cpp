#include <cstdio>		// sprintf()
#include <TimeLib.h>	// year(), month(), day(), hour(), minute(), second()
#include <esp_log.h>	// Arduino ESP logging

#include "src/hardware/GNSS/GNSS.h"



void GNSS::begin() {

}

void GNSS::update() {

	timestamp = 0; // tmp

	/* Generate ISO time string */
	sprintf(isotime, "%04u-%02u-%02uT%02u:%02u:%02u.%01uZ",
			year(timestamp),
			month(timestamp),
			day(timestamp),
			hour(timestamp),
			minute(timestamp),
			second(timestamp),
			0
	);

//	lattitude = gnss.lattitude / 1000000;
//	longitude = gnss.longitude / 1000000;
//	altitude = (gnss.altitude / 100);
//	speed = gnss.speed / 100;
//	heading = gnss.heading / 100;

}
