#ifndef ROADSTRATEGY_H
#define ROADSTRATEGY_H

#include "CommuteStrategy.h"
class RoadStrategy : public CommuteStrategy {


public:
	RoadStrategy();

	~RoadStrategy();

	std::string getTravelStrategyName();
};

#endif
