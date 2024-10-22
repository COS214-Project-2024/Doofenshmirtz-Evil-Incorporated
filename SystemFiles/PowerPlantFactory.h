#ifndef POWERPLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include "BuildingFactory.h"
class PowerPlantFactory : public BuildingFactory {


public:
	PowerPlantFactory();

	~PowerPlantFactory();

protected:
	Building* factoryMethod();
};

#endif
