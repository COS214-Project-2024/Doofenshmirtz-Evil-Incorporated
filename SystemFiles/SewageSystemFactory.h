#ifndef SEWAGESYSTEMFACTORY_H
#define SEWAGESYSTEMFACTORY_H

#include "BuildingFactory.h"
class SewageSystemFactory : public BuildingFactory {


public:
	SewageSystemFactory();

	~SewageSystemFactory();

protected:
	Building* factoryMethod();
};

#endif
