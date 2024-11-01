#ifndef BETTEREDUCATIONPOLICY_H
#define BETTEREDUCATIONPOLICY_H

#include "ImplementPolicy.h"
#include "CityUnit.h"
class BetterEducationPolicy : public ImplementPolicy {
private:
	CityUnit* Reciever;

public:
	BetterEducationPolicy(CityUnit* Reciever);

	~BetterEducationPolicy();

	void excecuteCommand(int& balance);
};

#endif
