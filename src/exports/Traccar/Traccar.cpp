#include <WiFi.h>

#include "src/FreematicsOSConfig.h"
#include "src/hardware/GNSS/GNSS.h"
#include "src/exports/Traccar/Traccar.h"



extern FreematicsOSConfig_t config;
extern GNSS gnss;
extern WiFiClient wifi_client;



void Traccar::begin(void) {
	
}

void Traccar::update(void) {
	
}

void Traccar::exportdata(void) {

	if (wifi_client.connect(config.traccar_host, 80)) {

		/* Prepare and send data in OsmAnd protocol (refer to https://www.traccar.org/osmand) */
		wifi_client.print(String(
			"GET /?id=") + config.traccar_device_id + "&timestamp=" + gnss.isotime + "&lat=" + gnss.lattitude + "&lon=" + gnss.longitude + "&altitude=" + int(gnss.altitude) + "&speed=" + gnss.speed + "&heading=" + gnss.heading + " HTTP/1.1\r\n" +
			"Host: " + config.traccar_host + "\r\n" +
			"Connection: keep-alive\r\n\r\n"
		);

		/* Handle server response */
	}
	

}
