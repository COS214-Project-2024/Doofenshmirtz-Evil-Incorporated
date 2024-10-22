#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Building.h"
class Residential : public Building {


public:
	Residential();

	~Residential();

	void update();
};

#endif
