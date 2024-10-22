#ifndef ATHOMESTATE_H
#define ATHOMESTATE_H

#include "CitizenLocationState.h"

class CityUnit;

class AtHomeState : public CitizenLocationState {


public:
	AtHomeState();

	~AtHomeState();

	void handleState(CityUnit* citizenHome, CityUnit* cititzenJob);
};

#endif
