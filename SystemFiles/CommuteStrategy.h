#ifndef COMMUTESTRATEGY_H
#define COMMUTESTRATEGY_H

#include <string>

class CommuteStrategy {


public:
	CommuteStrategy();

	virtual ~CommuteStrategy();

	virtual void handleCommuteState() = 0;

	virtual std::string getTravelStrategyName() = 0;
};

#endif
