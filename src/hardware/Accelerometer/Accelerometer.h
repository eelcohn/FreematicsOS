#pragma once

#include <ICM20948_WE.h>		   			// https://github.com/wollewald/ICM20948_WE



class Accelerometer {

	public:

		xyzFloat	flux;					// magnetic flux density [µT]
		xyzFloat	acceleration_raw;		// Raw acceleration [g]
		xyzFloat	acceleration;			// Acceleration [g]
		xyzFloat	g;						// ... [g]
		float		acceleration_resultant;	// Resultant acceleration [g]
		xyzFloat	gyroscope_raw;			// Raw gyroscope data [degrees/second]
		xyzFloat	gyroscope;				// Gyroscope data [degrees/second]
		xyzFloat	angle;					// Angle [degrees]
		float		pitch;					// Pitch
		float		roll;					// Roll
		float		temperature;			// Temperature [°C]

		void		begin(void);
		void		update(void);
		void		calibrate(void);
		void		sleep(void);
		void		wakeup(void);

	private:

		ICM20948_WE	myIMU = ICM20948_WE(&Wire);

		/* Logging tag */
	    static constexpr const char* LOG_TAG = "Accelerometer";
//		const inline static char *LOG_TAG = "Accelerometer";

};
