#include "src/exports/CSV/CSV.h"
#include "src/exports/FreematicsHub/FreematicsHub.h"
#include "src/exports/Traccar/Traccar.h"



extern CSV export_csv;
extern FreematicsHub export_freematicshub;
extern Traccar export_traccar;



class Exports {

	public:

		void begin(void);
		void update(void);
};
