#ifndef SEWAGE_H
#define SEWAGE_H

#include "Utility.h"
class Sewage : public Utility {


public:
	Sewage(int totalCap, int usedCap, double taxR);

	~Sewage();

	void update();
};

#endif
