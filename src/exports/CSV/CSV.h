#pragma once

struct CSVLine {			// Structure declaration
	int myNum;				// TODO: Member (int variable)
	char myString[256];		// TODO: Member (string variable)
}; 

class CSV {
	public:
		void begin(void);
		void update(void);
		void exportdata(void);
};
