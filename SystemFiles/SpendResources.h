/**
 * @file SpendResources.h
 * @brief Declares the SpendResources class, which manages the spending of resources and construction of buildings in a CityUnit.
 */

#ifndef SPENDRESOURCES_H
#define SPENDRESOURCES_H

#include "GovernmentCommand.h"
#include <map>
#include <string>
#include "BuildingFactory.h"

/**
 * @class SpendResources
 * @brief Command that controls resource spending and construction within a CityUnit.
 *
 * This class checks priorities based on employment, citizen satisfaction, and utility needs
 * to decide which buildings to construct and adjusts resources and balance accordingly.
 */
class SpendResources : public GovernmentCommand {
private:
    BuildingFactory* SewageFact;       ///< Factory for building sewage systems.
    BuildingFactory* WaterFact;        ///< Factory for building water plants.
    BuildingFactory* WasteFact;        ///< Factory for building waste sites.
    BuildingFactory* PowerFact;        ///< Factory for building power plants.
    BuildingFactory* CommercialFact;   ///< Factory for building commercial units.
    BuildingFactory* LandmarkFact;     ///< Factory for building landmarks.
    int& balance;                      ///< Reference to the current financial balance.
    double employmentRate;             ///< Current employment rate in the district.
    std::map<std::string, int>& resources; ///< Map of available resources and their quantities.
    double citizenSatisfaction;        ///< Current citizen satisfaction level.
    std::map<std::string, double> utilities; ///< Map of utility needs.

public:
    /**
     * @brief Constructs a SpendResources command.
     * @param district Pointer to the CityUnit where resources are managed.
     * @param employmentRate The employment rate of the district.
     * @param resources Map of current resources.
     * @param balance Reference to the current financial balance.
     * @param citizenSatisfaction The satisfaction level of the citizens.
     * @param utilities Map of utilities and their current levels.
     */
    SpendResources(CityUnit* district, double employmentRate, std::map<std::string, int>& resources, int& balance, double citizenSatisfaction, std::map<std::string, double> utilities);

    /**
     * @brief Destructor for SpendResources.
     * Cleans up allocated building factories.
     */
    ~SpendResources();

    /**
     * @brief Executes the command by assessing priorities and constructing buildings.
     */
    void executeCommand();

    /**
     * @brief Calculates the priority based on employment rate.
     * @param employmentRate The current employment rate.
     * @return Priority value based on employment rate.
     */
    int employmentPriority(double employmentRate);

    /**
     * @brief Calculates the priority based on citizen satisfaction.
     * @param citizenSatisfaction The current citizen satisfaction level.
     * @return Priority value based on citizen satisfaction.
     */
    int citizenPriority(double citizenSatisfaction);

    /**
     * @brief Calculates the priority based on utility needs.
     * @param dk The current level of the utility.
     * @return Priority value based on utility level.
     */
    int utilPriority(double dk);

    /**
     * @brief Checks if enough resources are available for construction.
     * @param haveResources Available resources.
     * @param needResources Required resources.
     * @return True if resources are sufficient, otherwise false.
     */
    bool checkResources(std::map<std::string, int>& haveResources, std::map<std::string, int> needResources);
};
#endif
