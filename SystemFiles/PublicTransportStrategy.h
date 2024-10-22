#ifndef PUBLICTRANSPORTSTRATEGY_H
#define PUBLICTRANSPORTSTRATEGY_H

#include "CommuteStrategy.h"	
class PublicTransportStrategy : public CommuteStrategy {


public:
	PublicTransportStrategy();

	~PublicTransportStrategy();

	void handleCommuteState();

	std::string getTravelStrategyName();
};

#endif
