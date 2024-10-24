#ifndef COMMUTESTRATEGY_H
#define COMMUTESTRATEGY_H

#include <string>
#include <iostream>

class CommuteStrategy {


public:
	CommuteStrategy();

	virtual ~CommuteStrategy();

	virtual int handleCommuteState() =0;

	virtual std::string getTravelStrategyName() = 0;
};

#endif
