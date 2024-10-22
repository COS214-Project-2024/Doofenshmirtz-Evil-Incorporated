#ifndef CITIZEN_H
#define CITIZEN_H

class CitizenLocationState;
class CityUnit;

class Citizen {

private:
	int satisfactionScore;
	bool isEmployed;
	CitizenLocationState* citizenLocation;
	CityUnit* citizenHome;
	CityUnit* citizenJob;
	int bankBalance;

public:
	Citizen(CityUnit* home, CityUnit* job);

	~Citizen();

	void travelTo(CityUnit* destination);
};

#endif
