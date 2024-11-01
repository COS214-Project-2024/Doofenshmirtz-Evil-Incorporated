#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

class Landmark : public Building {


public:
	Landmark(int totalCap, int usedCap);

	~Landmark();

	void update();
};

#endif
