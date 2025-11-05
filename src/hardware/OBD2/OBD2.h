#pragma once

#include <OBD2_CanBus.h>

#include "src/hardware/Freematics/Freematics.h"					// PIN_CAN_RX, PIN_CAN_TX
#include "src/hardware/OBD2/OBD2 Protocol/OBD2_Services.h"
#include "src/hardware/OBD2/OBD2 Protocol/OBD2_PIDs.h"



typedef enum {
    OBD2_PROTO_AUTO			= 0x00,
    OBD2_PROTO_ISO_9141_2	= 0x03,
    OBD2_PROTO_KWP2000_5K	= 0x04,
    OBD2_PROTO_KWP2000_FAST	= 0x05,
    OBD2_PROTO_CAN_11B_500K	= 0x06,
    OBD2_PROTO_CAN_29B_500K	= 0x07,
    OBD2_PROTO_CAN_29B_250K	= 0x08,
    OBD2_PROTO_CAN_11B_250K	= 0x09,
    OBD2_PROTO_J1939		= 0x0B,
} OBD_PROTOCOLS;



class OBD2 {

	public:

		/* Class constructor/deconstructor */
		OBD2(void);
		~OBD2(void);

		/* Static (non-changing) OBD2 values */
		String		vin;
		String		cid;
		String		cvn;
		uint8_t		obd2_standards = 0;
		uint8_t		fuel_type = 0;

		/* Live OBD2 values */
		int			rpm = -1;
		int			speed = -1;
		int			coolant_temperature = -1;
		float		battery_voltage = -1;
		uint8_t		fuel_level = 0;
		uint64_t	odometer = 0;

		/* Function declarations */
		void		begin(void);
		void		update(void);
		String		printSupportedPIDs(uint8_t mode);

	private:

		OBD2_CanBus canbus = OBD2_CanBus(PIN_CAN_RX, PIN_CAN_TX);

		/* Static (non-changing) OBD2 values */
		uint32_t	pidsupported0120;
		uint32_t	pidsupported2140;
		uint32_t	pidsupported4160;
		uint32_t	pidsupported6180;
		uint32_t	pidsupported81A0;
		uint32_t	pidsupportedA1C0;
		uint32_t	pidsupportedC1E0;

		/* Logging tag */
	    static constexpr const char* LOG_TAG = "OBD2";
//		const inline static char *LOG_TAG = "OBD2"; 

};
