#ifndef ATWORKSTATE_H
#define ATWORKSTATE_H

#include "CitizenLocationState.h"

class CityUnit;

class AtWorkState : public CitizenLocationState {


public:
	AtWorkState();

	~AtWorkState();

	void travel(Citizen* citizen);
};

#endif
