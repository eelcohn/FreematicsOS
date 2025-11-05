#pragma once



class GNSS {

	public:

		char isotime[24];

		uint64_t	timestamp;		// Timestamp
		float		lattitude;		// Lattitude
		float		longitude;		// Longitude
		float		altitude;		// Altitude
		float		speed;			// Speed
		float		heading;		// Heading [degrees]

		void		begin(void);
		void		update(void);

	private:

		/* Logging tag */
//		const inline static char *LOG_TAG = "GNSS"; 
	    static constexpr const char* LOG_TAG = "GNSS";

};
