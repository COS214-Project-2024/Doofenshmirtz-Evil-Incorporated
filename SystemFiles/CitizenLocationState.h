#ifndef CITIZENLOCATIONSTATE_H
#define CITIZENLOCATIONSTATE_H

class CityUnit;

class CitizenLocationState {


public:
	CitizenLocationState();

	virtual ~CitizenLocationState();

	void setState(CitizenLocationState* newState);

	virtual void handleState(CityUnit* citizenHome, CityUnit* cititzenJob) = 0;
};

#endif
