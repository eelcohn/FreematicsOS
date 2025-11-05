#include "src/exports/Exports.h"
#include "src/exports/CSV/CSV.h"
#include "src/exports/FreematicsHub/FreematicsHub.h"
#include "src/exports/Traccar/Traccar.h"



CSV export_csv;
FreematicsHub export_freematicshub;
Traccar export_traccar;



void Exports::begin(void) {
	
}

void Exports::update(void) {
	export_csv.update();
	export_freematicshub.update();
	export_traccar.update();
}
