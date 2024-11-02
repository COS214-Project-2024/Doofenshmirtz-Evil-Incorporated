#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"

class Commercial : public Building {


public:
	Commercial(int totalCap, int usedCap);

	~Commercial();

	void update();
};

#endif