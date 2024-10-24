#ifndef PUBLICTRANSPORTSTRATEGY_H
#define PUBLICTRANSPORTSTRATEGY_H

#include "CommuteStrategy.h"	
class PublicTransportStrategy : public CommuteStrategy {


public:
	PublicTransportStrategy();

	~PublicTransportStrategy();

	std::string getTravelStrategyName();
};

#endif
