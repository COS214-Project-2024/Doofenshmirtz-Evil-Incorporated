#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Building.h"

class Industrial : public Building {


public:
	Industrial(int totalCap, int usedCap, double taxR);

	virtual ~Industrial();

	virtual std::map<std::string, int> collectResources() = 0;

	virtual void update() override;
};

#endif
