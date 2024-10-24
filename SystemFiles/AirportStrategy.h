#ifndef AIRPORTSTRATEGY_H
#define AIRPORTSTRATEGY_H

#include "CommuteStrategy.h"
#include <string>

class AirportStrategy : public CommuteStrategy {


public:
	AirportStrategy();

	~AirportStrategy();

	std::string getTravelStrategyName();
};

#endif
