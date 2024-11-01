#ifndef SHORTWORKWEEKPOLICY_H
#define SHORTWORKWEEKPOLICY_H

#include "ImplementPolicy.h"
#include "CityUnit.h"
class ShortWorkWeekPolicy : public ImplementPolicy {
private:
	CityUnit* Reciever;

public:
	ShortWorkWeekPolicy(CityUnit* Reciever);

	~ShortWorkWeekPolicy();

	void excecuteCommand(int& balance);
};

#endif
