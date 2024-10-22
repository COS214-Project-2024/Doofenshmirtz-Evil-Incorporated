#ifndef LANDMARK_H
#define LANDMARK_H

#include "Building.h"

class Landmark : public Building {


public:
	Landmark();

	~Landmark();

	void update();
};

#endif
