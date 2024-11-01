#ifndef WATER_H
#define WATER_H

#include "Utility.h"
class Water : public Utility {


public:
	Water(int totalCap, int usedCap);

	~Water();

	void update();
};

#endif
