#pragma once

#define OBD2_MODE_READ_LIVE_DATA						0x01 // Show current live data
#define OBD2_MODE_READ_FREEZE_DATA						0x02 // Show freeze frame data
#define OBD2_MODE_READ_STORED_DTCS						0x03 // Show stored Diagnostic Trouble Codes (DTCs)
#define OBD2_MODE_CLEAR_DTCS							0x04 // Clear Diagnostic Trouble Codes and stored values
#define OBD2_MODE_TEST_OXYGEN_SENSORS					0x05 // Test results, oxygen sensor monitoring (non-CAN only)
#define OBD2_MODE_TEST_OTHER_COMPONENTS					0x06 // Test results, other component/system monitoring (for CAN)
#define OBD2_MODE_READ_PENDING_DTCS						0x07 // Show pending Diagnostic Trouble Codes
#define OBD2_MODE_CONTROL_ONBOARD_COMPONENTS			0x08 // Control operation of on-board component/system
#define OBD2_MODE_READ_VEHICLE_INFO						0x09 // Request vehicle information
#define OBD2_MODE_READ_PERMANENT_DTCS					0x0A // Show permanent Diagnostic Trouble Codes
