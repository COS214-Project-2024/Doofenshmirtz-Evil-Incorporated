#ifndef ITERATOR_H
#define ITERATOR_H

class CityUnit {
public:
    int id;
    CityUnit(int id) : id(id) {}
};

class Iterator {


public:
	Iterator();

	virtual ~Iterator();

	virtual void first() = 0;

	virtual void next() = 0;

	virtual void previous() = 0;

	virtual bool isDone() = 0;

	virtual CityUnit* currentItem() = 0;
};

#endif
