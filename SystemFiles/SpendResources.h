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
	BuildingFactory* CommercialFact ;
	BuildingFactory* LandmarkFact ;
	int& balance;
	double employmentRate;
	std::map<std::string, int>& resources;
	double citizenSatisfaction;
	std::map<std::string, double> utilities;

	

public:
	SpendResources(CityUnit* district,double employmentRate, std::map<std::string, int>& resources, int& balance,double citizenSatisfaction,std::map<std::string, double> utilities);

	~SpendResources();

	void executeCommand();

	int employmentPriority(double employmentRate);

	int citizenPriority(double citizenSatisfacction);

	int utilPriority(double dk);

	bool checkResources( std::map<std::string, int>& haveResources,std::map<std::string, int> needResources);

};

#endif
