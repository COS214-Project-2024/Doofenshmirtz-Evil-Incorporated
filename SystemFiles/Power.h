#ifndef POWER_H
#define POWER_H

#include "Utility.h"

class Power : public Utility {


public:
	Power(int totalCap, int usedCap, double taxR);

	~Power();

	void update();
};

#endif
