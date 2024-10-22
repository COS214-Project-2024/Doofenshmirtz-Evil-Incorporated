#ifndef AIRPORTSTRATEGY_H
#define AIRPORTSTRATEGY_H

#include "CommuteStrategy.h"
#include <string>

class AirportStrategy : public CommuteStrategy {


public:
	AirportStrategy();

	~AirportStrategy();

	void handleCommuteState();

	std::string getTravelStrategyName();
};

#endif
