#ifndef CITIZENLOCATIONSTATE_H
#define CITIZENLOCATIONSTATE_H

class Citizen;
class CommuteStrategy;
class CityUnit;

class CitizenLocationState {

private:

	CommuteStrategy* strategy;

public:
	CitizenLocationState();

	void chooseStrategy(int travelDistance);

	virtual ~CitizenLocationState();

	virtual void travel(Citizen* citizen) = 0;

};

#endif
