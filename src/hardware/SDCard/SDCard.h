#pragma once

#include <SdFat.h>			// SDCard support (FAT16/FAT32/ExFAT)



#define SD_FAT_TYPE 3		// Support for FAT16, FAT32 and ExFAT



class SDCard {

	public:

		void begin(void);
		void update(void);
		bool checkVolume(void);
		bool writeln(const char *data);
		bool readln(char &data, const size_t buf_len);

	private:

		SdFs sd;
		SdFile file;

		/* Logging tag */
		static constexpr const char* LOG_TAG = "SDCard";
//		const inline static char *LOG_TAG = "SDCard"; 
};
