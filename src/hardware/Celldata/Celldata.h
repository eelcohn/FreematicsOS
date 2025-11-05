#pragma once



class Celldata {

	public:
		char rssi;			// 
		char mcc[4];		// Mobile country code [3 digits 0...9]
		char mnc[3];		// Mobile network code [3 digits 0...9]
		char lac;			// Local area code 
		char cid;			// Cell identification 

		void begin(void);
		void update(void);
		void togglePower(void);
		void enable(void);
		void disable(void);

	private:
		/* Logging tag */
//		const inline static char *LOG_TAG = "Celldata"; 
	    static constexpr const char* LOG_TAG = "Celldata";

};
