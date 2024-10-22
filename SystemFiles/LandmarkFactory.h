#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include "BuildingFactory.h"

class LandmarkFactory : public BuildingFactory {


protected:
	LandmarkFactory();

	Building* factoryMethod();

public:
	~LandmarkFactory();
};

#endif
