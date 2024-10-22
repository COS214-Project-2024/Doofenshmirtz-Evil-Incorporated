#ifndef ROADSTRATEGY_H
#define ROADSTRATEGY_H

#include "CommuteStrategy.h"
class RoadStrategy : public CommuteStrategy {


public:
	RoadStrategy();

	~RoadStrategy();

	void handleCommuteState();

	std::string getTravelStrategyName();
};

#endif
