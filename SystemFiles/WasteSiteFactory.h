#ifndef WASTESITEFACTORY_H
#define WASTESITEFACTORY_H

#include "BuildingFactory.h"
class WasteSiteFactory : public BuildingFactory {


public:
	WasteSiteFactory();

	~WasteSiteFactory();

protected:
	Building* factoryMethod();
};

#endif
