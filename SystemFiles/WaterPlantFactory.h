#ifndef WATERPLANTFACTORY_H
#define WATERPLANTFACTORY_H

#include "BuildingFactory.h"
class WaterPlantFactory : public BuildingFactory {


public:
	WaterPlantFactory();

	~WaterPlantFactory();

protected:
	Building* factoryMethod();
};

#endif
