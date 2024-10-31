#ifndef SPENDRESOURCES_H
#define SPENDRESOURCES_H

#include "GovernmentCommand.h"
#include <map>
#include <string>
#include "BuildingFactory.h"

class SpendResources : public GovernmentCommand {

private:
	BuildingFactory* SewageFact;
	BuildingFactory* WaterFact;
	BuildingFactory* WasteFact ;
	BuildingFactory* PowerFact ;
	BuildingFactory* ResidentialFact ;
	BuildingFactory* CommercialFact ;
	BuildingFactory* LandmarkFact ;
	CityUnit* reciever;

public:
	SpendResources(CityUnit* district);

	~SpendResources();

	void excecuteCommand(double employmentRate, std::map<std::string, int> resources, int& balance,int citizenSatisfaction,std::map<std::string, int> utilities);

	int employmentPriority(double employmentRate);

	int citizenPriority(double citizenSatisfacction);

	int utilPriority(double dk);

	bool checkResources( std::map<std::string, int> haveResources,std::map<std::string, int> needResources);

};

#endif
