#ifndef SEWAGE_H
#define SEWAGE_H

#include "Utility.h"
class Sewage : public Utility {


public:
	Sewage(int totalCap, int usedCap);

	~Sewage();

	void update();
};

#endif
