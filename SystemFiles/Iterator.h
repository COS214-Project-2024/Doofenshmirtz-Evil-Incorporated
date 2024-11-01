#ifndef ITERATOR_H
#define ITERATOR_H

class CityUnit;

/**
 * @class Iterator
 * @brief Abstract base class for iterating over CityUnit objects.
 */
class Iterator {
public:
    /**
     * @brief Constructs an Iterator.
     */
    Iterator();

    /**
     * @brief Virtual destructor.
     */
    virtual ~Iterator();

    /**
     * @brief Moves the iterator to the first element.
     */
    virtual void first() = 0;

    /**
     * @brief Advances the iterator to the next element.
     */
    virtual void next() = 0;

    /**
     * @brief Moves the iterator to the previous element.
     */
    virtual void previous() = 0;

    /**
     * @brief Checks if the iteration is complete.
     * @return True if all elements have been iterated over, false otherwise.
     */
    virtual bool isDone() = 0;

    /**
     * @brief Retrieves the current CityUnit.
     * @return Pointer to the current CityUnit, or nullptr if iteration is done.
     */
    virtual CityUnit* currentItem() = 0;
};

#endif // ITERATOR_H
