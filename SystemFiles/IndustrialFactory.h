#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include "BuildingFactory.h"
class IndustrialFactory : public BuildingFactory {


protected:
	IndustrialFactory();

	Building* factoryMethod();

public:
	~IndustrialFactory();
};

#endif
