#ifndef ATWORKSTATE_H
#define ATWORKSTATE_H

#include "CitizenLocationState.h"

class CityUnit;

class AtWorkState : public CitizenLocationState {


public:
	AtWorkState();

	~AtWorkState();

	void handleState(CityUnit* citizenHome, CityUnit* cititzenJob);
};

#endif
