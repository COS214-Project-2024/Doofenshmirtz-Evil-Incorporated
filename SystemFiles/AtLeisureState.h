#ifndef ATLEISURESTATE_H
#define ATLEISURESTATE_H

#include "CitizenLocationState.h"

class CityUnit;

class AtLeisureState : public CitizenLocationState {


public:
	AtLeisureState();

	~AtLeisureState();

	void travel(Citizen* citizen);
};

#endif
