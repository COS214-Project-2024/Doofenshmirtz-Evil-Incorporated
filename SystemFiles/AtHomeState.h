#ifndef ATHOMESTATE_H
#define ATHOMESTATE_H

#include "CitizenLocationState.h"

class CityUnit;

class AtHomeState : public CitizenLocationState {


public:
	AtHomeState();

	~AtHomeState();

	void travel(Citizen* citizen);
};

#endif
