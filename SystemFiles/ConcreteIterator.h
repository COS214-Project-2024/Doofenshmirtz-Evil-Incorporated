#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

#include "Iterator.h"

class ConcreteIterator : public Iterator {


public:
	ConcreteIterator();

	~ConcreteIterator();

	void first();

	void next();

	void isDone();

	void currentItem();
};

#endif
