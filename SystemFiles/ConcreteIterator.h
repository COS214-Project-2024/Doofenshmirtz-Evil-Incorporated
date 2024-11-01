#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H

#include "Iterator.h"
#include "CityUnit.h" // Ensure CityUnit is included
#include <vector>

/**
 * @class ConcreteIterator
 * @brief Concrete implementation of the Iterator for CityUnit objects.
 */
class ConcreteIterator : public Iterator {
private:
    const std::vector<CityUnit*>& cityUnits; /**< Collection of CityUnit pointers to iterate over */
    size_t index; /**< Current index in the iteration */

public:
    /**
     * @brief Constructs a ConcreteIterator with the given collection of CityUnits.
     * @param cityUnitsParam The collection of CityUnit pointers to iterate over.
     */
    ConcreteIterator(const std::vector<CityUnit*>& cityUnitsParam);

    /**
     * @brief Destructor for ConcreteIterator.
     */
    ~ConcreteIterator();

    /**
     * @brief Moves the iterator to the first CityUnit.
     */
    void first() override;

    /**
     * @brief Advances the iterator to the next CityUnit.
     */
    void next() override;

    /**
     * @brief Moves the iterator to the previous CityUnit.
     */
    void previous() override;

    /**
     * @brief Checks if the iteration has reached the end of the collection.
     * @return True if all CityUnits have been iterated over, false otherwise.
     */
    bool isDone() override;

    /**
     * @brief Retrieves the current CityUnit.
     * @return Pointer to the current CityUnit, or nullptr if iteration is done.
     */
    CityUnit* currentItem() override;
};

#endif // CONCRETEITERATOR_H
