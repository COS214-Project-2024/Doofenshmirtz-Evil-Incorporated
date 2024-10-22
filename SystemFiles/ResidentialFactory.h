#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include "BuildingFactory.h"
class ResidentialFactory : public BuildingFactory {


protected:
	ResidentialFactory();

	Building* factoryMethod();

public:
	~ResidentialFactory();
};

#endif
