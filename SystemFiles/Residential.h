#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
class Residential : public Building {


public:
	Residential(int totalCap, int usedCap, double taxR);

	~Residential();

	void update();
};

#endif
