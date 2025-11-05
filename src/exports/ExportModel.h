#include <Arduino.h>



class ExportModel {

	public:
		uint64_t	total;
		uint64_t	used;
		uint64_t	free;

		void begin(void);
		void update(void);

};
