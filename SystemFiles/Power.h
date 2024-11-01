#ifndef POWER_H
#define POWER_H

#include "Utility.h"

class Power : public Utility {


public:
	Power(int totalCap, int usedCap);

	~Power();

	void update();
};

#endif
