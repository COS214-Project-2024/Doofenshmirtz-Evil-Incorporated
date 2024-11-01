#include "ConcreteIterator.h"

/**
 * @brief Constructs a ConcreteIterator with the given collection of CityUnits.
 * @param cityUnitsParam The collection of CityUnit pointers to iterate over.
 */
ConcreteIterator::ConcreteIterator(const std::vector<CityUnit*>& cityUnitsParam) 
    : cityUnits(cityUnitsParam), index(0) {
}

/**
 * @brief Destructor for ConcreteIterator.
 */
ConcreteIterator::~ConcreteIterator()
{
}

/**
 * @brief Moves the iterator to the first CityUnit in the collection.
 */
void ConcreteIterator::first() {
    index = 0;
}

/**
 * @brief Advances the iterator to the next CityUnit.
 * If the iterator is already at the end, it remains unchanged.
 */
void ConcreteIterator::next() {
    if (index < cityUnits.size()) {
        ++index;
    }
}

/**
 * @brief Moves the iterator to the previous CityUnit.
 * If the iterator is already at the beginning, it remains unchanged.
 */
void ConcreteIterator::previous() {
    if (index > 0) {
        --index;
    }
}

/**
 * @brief Checks if the iteration has completed.
 * @return True if the iterator has reached or surpassed the end of the collection, false otherwise.
 */
bool ConcreteIterator::isDone() {
    return index >= cityUnits.size();
}

/**
 * @brief Retrieves the current CityUnit.
 * @return Pointer to the current CityUnit, or nullptr if the iteration is done.
 *
 * @note The check `index < 0` is unnecessary since `index` is of type `size_t` (unsigned).
 */
CityUnit* ConcreteIterator::currentItem() {
    if (isDone()) {
        return nullptr;
    }
    return cityUnits[index];
}
