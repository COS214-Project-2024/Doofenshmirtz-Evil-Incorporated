#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

#include "Iterator.h"
#include "CityUnit.h"

class ConcreteIterator : public Iterator {
private:
	const std::vector<CityUnit*>& cityUnits;
	size_t index;

public:
	ConcreteIterator(const std::vector<CityUnit*>& cityUnitsParam);

	~ConcreteIterator();

	void first();

	void next();
	void previous();

	bool isDone();

	CityUnit* currentItem();
};

#endif
