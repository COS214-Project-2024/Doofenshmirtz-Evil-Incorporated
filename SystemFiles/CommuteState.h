#ifndef COMMUTESTATE_H
#define COMMUTESTATE_H

#include "CitizenLocationState.h"

class CommuteStrategy;

class CommuteState : public CitizenLocationState {

public:
	CommuteStrategy* strategy;

	CommuteState();

	~CommuteState();

	void chooseStrategy(int travelDistance);

	void handleState(CityUnit* citizenHome, CityUnit* cititzenJob);
};

#endif
