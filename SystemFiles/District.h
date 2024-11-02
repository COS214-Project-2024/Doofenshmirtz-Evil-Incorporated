#ifndef DISTRICT_H
#define DISTRICT_H

#include "CityUnit.h"
#include "ConcreteIterator.h"

class District : public CityUnit {
private:
    std::vector<CityUnit*> containedCityUnit; ///< Vector holding contained CityUnits.
    float educationPolicyMultiplier = 1; ///< Multiplier for education policy effects.
    float shortweekPolicyMultiplier = 1; ///< Multiplier for short workweek policy effects.

public:
    District();

    /**
     * @brief Adds a new CityUnit to the district.
     * @param newUnit The CityUnit to be added.
     */
    void add(CityUnit* newUnit);

    /**
     * @brief Removes a specified CityUnit from the district.
     * @param unit The CityUnit to be removed.
     * @throws std::exception if the unit is not found in the district.
     */
    void remove(CityUnit* unit);

    /**
     * @brief Destructor for the District class.
     *
     * Cleans up dynamically allocated CityUnits and clears the containedCityUnit vector.
     */
    ~District();

    /**
     * @brief Updates all CityUnits within the district and employs residents.
     */
    void update();

    /**
     * @brief Employs residents from residential units in available commercial units.
     */
    void employResidents();

    /**
     * @brief Allows residents to relax at available landmarks.
     */
    void partyResidents();

    /**
     * @brief Creates an iterator for the district.
     * @return A pointer to the created Iterator.
     */
    Iterator* createIterator();

    /**
     * @brief Calculates the average employment rate for the district.
     * @return The average employment rate as a double.
     */
    double getEmploymentRate();

    /**
     * @brief Collects taxes from residents in the district.
     * @return The total amount of tax collected.
     */
    double payTaxes();

    /**
     * @brief Evaluates the average happiness level of the district.
     * @return The average happiness as an integer.
     * @throws std::exception if total happiness is negative.
     */
    int evaluateHappiness();

    /**
     * @brief Counts the total number of citizens in all residential units within the district.
     * @return The total number of citizens.
     */
    int countCitizens();

    /**
     * @brief Sets the tax rate for the district.
     * @param amount The new tax rate to be set.
     */
    void setTaxRate(double amount);

    /**
     * @brief Updates the education policy multiplier.
     * @param mult The new multiplier to set for the education policy.
     */
    void updateEducationMultiplier(float mult);

    /**
     * @brief Updates the short week policy multiplier.
     * @param mult The new multiplier to set for the short week policy.
     */
    void updateWeekMultiplier(float mult);
};

#endif // DISTRICT_H
