#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include "BuildingFactory.h"

class CommercialFactory : public BuildingFactory {


protected:
	CommercialFactory();

	Building* factoryMethod();

public:
	~CommercialFactory();
};

#endif
