#ifndef BETTEREDUCATIONPOLICY_H
#define BETTEREDUCATIONPOLICY_H

#include "ImplementPolicy.h"
#include "CityUnit.h"
class BetterEducationPolicy : public ImplementPolicy {
private:
	CityUnit* Reciever;

public:
	BetterEducationPolicy(CityUnit* district);

	~BetterEducationPolicy();

	void executeCommand(int& balance);
};

#endif
