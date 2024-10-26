#include "ConcreteIterator.h"

ConcreteIterator::ConcreteIterator(const std::vector<CityUnit*>& cityUnitsParam) : cityUnits(cityUnitsParam), index(0) {
}

ConcreteIterator::~ConcreteIterator()
{

}

void ConcreteIterator::first() {
	index = 0;
}

void ConcreteIterator::next() {
	if (index < cityUnits.size()) {
        ++index;
    }
}
void ConcreteIterator::previous() {
	if (index > 0) {
        --index;
    }
}

bool ConcreteIterator::isDone() {
	if(index >= cityUnits.size()){
		return true;
	}
	return false;
}

CityUnit* ConcreteIterator::currentItem() {
	if(isDone() || index < 0){
		return nullptr;
	}
	return cityUnits[index];
}
