#pragma once

#include <Arduino.h>						// uint8_t, uint16_t



typedef struct {							// Structure declaration

	bool		enable_gps;					// Enable/disable GPS
	bool		enable_celldata;			// Enable/disable cellular data

	char		hostname[33];				// Hostname

	bool		buzzer_enabled;				// Enable/disable buzzer sounds

	char		celldata_apn[33];			// Access point name
	char		celldata_pin[5];			// SIM card PIN code

	char		wifi_station_ssid[33];		// WiFi SSID (Station mode)
	char		wifi_station_password[65];	// WiFi password (Station mode)

	char		wifi_client_ssid[33];		// WiFi SSID (Client mode)
	char		wifi_client_password[65];	// WiFi password (Client mode)

	uint8_t		obd2_mode;					// OBD2 serial mode (Automatic, 250k/500k)
	bool		obd2_sniffer;				// OBD2 sniffer mode (true=on, false=off)

	bool		enable_export_csv;			// Enable/disable export to CSV file
	char		csv_filename[256];			// CSV filename
	char		csv_delimiter;				// CSV column delimiter

	bool		enable_export_freematics;	// Enable/disable export data to Freematics Hub

	bool		enable_export_traccar;		// Enable/disable export data to Traccar server
	char		traccar_host[256];			// Traccar server hostname
	uint16_t	traccar_port;				// Traccar server port
	char		traccar_device_id[16];		// Traccar device ID

} FreematicsOSConfig_t; 
