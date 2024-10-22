#ifndef RAILWAYSTRATEGY_H
#define RAILWAYSTRATEGY_H

#include "CommuteStrategy.h"
class RailwayStrategy : public CommuteStrategy {


public:
	RailwayStrategy();

	~RailwayStrategy();

	void handleCommuteState();

	std::string getTravelStrategyName();
};

#endif
