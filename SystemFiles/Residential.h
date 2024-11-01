#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
class Residential : public Building {


public:
	Residential(int totalCap, int usedCap);

	~Residential();

	void update();
};

#endif
