#ifndef BUILLDINGFACTORY_H
#define BUILLDINGFACTORY_H

#include "Building.h"

class BuildingFactory {

private:
	Building* product;

public:
	BuildingFactory();
	void build();
	virtual ~BuildingFactory();

protected:
	virtual Building* factoryMethod() = 0;

	//adding random function
	//wamp wamp
};

#endif
