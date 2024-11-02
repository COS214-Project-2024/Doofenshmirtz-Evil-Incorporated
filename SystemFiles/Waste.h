#ifndef WASTE_H
#define WASTE_H

#include "Utility.h"
class Waste : public Utility {


public:
	Waste(int totalCap, int usedCap);

	~Waste();

	void update();
};

#endif
