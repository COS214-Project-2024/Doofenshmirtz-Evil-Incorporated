#ifndef UTILITY_H
#define UTILITY_H

#include "Building.h"
class Utility : public Building {


public:
	Utility();

	virtual ~Utility();

	virtual void update() = 0;
};

#endif
