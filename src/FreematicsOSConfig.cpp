#import "src/FreematicsOSConfig.h"
#import "src/hardware/OBD2/OBD2.h"



FreematicsOSConfig_t config = {
	true,						// enable_gps
	true,						// enable_celldata

	"freematics",				// hostname

	false,						// buzzer_enabled

	"",							// celldata_apn
	"1234",						// celldata_pin

	"Freematics",				// wifi_station_ssid
	"password",					// wifi_station_password

	"Freematics",				// wifi_client_ssid
	"password",					// wifi_client_password

	OBD2_PROTO_AUTO,			// obd2_mode
	true,						// obd2_sniffer

	true,						// enabe_export_csv
	"/Freematics.csv",			// csv_filename
	',',						// csv_delimiter

	false,						// enable_export_freematics

	true,						// enable_export_traccar
	"traccar.myserver.nowhere",	// traccar_host
	5055,						// traccar_port
	"12345"						// traccar_device_id
};
