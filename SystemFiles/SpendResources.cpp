/**
 * @file SpendResources.cpp
 * @brief Implements the SpendResources class.
 */

#include "SpendResources.h"
#include "SewageSystemFactory.h"
#include "WaterPlantFactory.h"
#include "WasteSiteFactory.h"
#include "PowerPlantFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "LandmarkFactory.h"

/**
 * @brief Constructs a SpendResources command with specified parameters.
 */
SpendResources::SpendResources(
    CityUnit* district, 
    double employmentRate, 
    std::map<std::string, int>& resources, 
    int& balance,
    double citizenSatisfaction, 
    std::map<std::string, double> utilities
) : GovernmentCommand(district)
    , balance(balance)  
    , resources(resources)
    , employmentRate(employmentRate)
    , citizenSatisfaction(citizenSatisfaction)
    , utilities(utilities) 
{
    this->SewageFact = new SewageSystemFactory();
    this->WaterFact = new WaterPlantFactory();
    this->WasteFact = new WasteSiteFactory();
    this->PowerFact = new PowerPlantFactory();
    this->CommercialFact = new CommercialFactory();
    this->LandmarkFact = new LandmarkFactory();
}

/**
 * @brief Destructor for SpendResources. Cleans up factory pointers.
 */
SpendResources::~SpendResources() {
    delete this->SewageFact;
    delete this->WaterFact;
    delete this->WasteFact;
    delete this->PowerFact;
    delete this->CommercialFact;
    delete this->LandmarkFact;
}

/**
 * @brief Executes the resource spending command, determining and building the highest priority structure.
 */
void SpendResources::executeCommand() {
    // Determine priorities for employment, citizen satisfaction, and utility needs
    int EmploymentPriority = employmentPriority(employmentRate);
    int citizenSatisfactionPriority = citizenPriority(citizenSatisfaction);
    int PowerPriority = utilPriority(utilities["PowerPlant"]);
    int WaterPriority = utilPriority(utilities["WaterPlant"]);
    int WastePriority = utilPriority(utilities["WasteSite"]);
    int SewagePriority = utilPriority(utilities["SewageSystem"]);

    // Identify the highest priority item to build
    int roulette[6] = {EmploymentPriority, citizenSatisfactionPriority, PowerPriority, WaterPriority, WastePriority, SewagePriority};
    int decisionVal = 0;
    int highNum = 999;
    for (int i = 0; i < 6; i++) {
        if (roulette[i] < highNum) {
            decisionVal = i;
            highNum = roulette[i];
        }
    }

    // Construct the chosen building if sufficient balance and resources are available
    switch (decisionVal) {
        case 0:
            if (balance >= CommercialFact->getCost() && checkResources(resources, CommercialFact->getResourceCost())) {
                balance -= CommercialFact->getCost();
                CityUnit* temp = this->CommercialFact->build();
                this->reciever->add(temp);
                this->reciever->employResidents();
            }
            break;
        case 1:
            if (balance >= LandmarkFact->getCost() && checkResources(resources, LandmarkFact->getResourceCost())) {
                balance -= LandmarkFact->getCost();
                CityUnit* temp = this->LandmarkFact->build();
                this->reciever->add(temp);
                this->reciever->partyResidents();
            }
            break;
        case 2:
            if (balance >= PowerFact->getCost() && checkResources(resources, PowerFact->getResourceCost())) {
                balance -= PowerFact->getCost();
                CityUnit* temp = this->PowerFact->build();
                this->reciever->add(temp);
            }
            break;
        case 3:
            if (balance >= WaterFact->getCost() && checkResources(resources, WaterFact->getResourceCost())) {
                balance -= WaterFact->getCost();
                CityUnit* temp = this->WaterFact->build();
                this->reciever->add(temp);
            }
            break;
        case 4:
            if (balance >= WasteFact->getCost() && checkResources(resources, WasteFact->getResourceCost())) {
                balance -= WasteFact->getCost();
                CityUnit* temp = this->WasteFact->build();
                this->reciever->add(temp);
            }
            break;
        case 5:
            if (balance >= SewageFact->getCost() && checkResources(resources, SewageFact->getResourceCost())) {
                balance -= SewageFact->getCost();
                CityUnit* temp = this->SewageFact->build();
                this->reciever->add(temp);
            }
            break;
        default:
            break;
    }
}

/**
 * @brief Determines priority based on employment rate.
 */
int SpendResources::employmentPriority(double employmentRate) {
    double tmp = (employmentRate * 10);
    int bucket = static_cast<int>(tmp);
    std::map<int, int> value = {{0, 1}, {1, 4}, {2, 7}, {3, 10}, {4, 13}, {5, 16}, {6, 19}, {7, 22}, {8, 25}, {9, 28}, {10, 28}};
    return value[bucket];
}

/**
 * @brief Determines priority based on citizen satisfaction.
 */
int SpendResources::citizenPriority(double citizenSatisfaction) {
    double tmp = citizenSatisfaction * 10;
    int bucket = static_cast<int>(tmp);
    std::map<int, int> value = {{0, 2}, {1, 5}, {2, 8}, {3, 11}, {4, 14}, {5, 17}, {6, 20}, {7, 23}, {8, 26}, {9, 29}, {10, 29}};
    return value[bucket];
}

/**
 * @brief Determines priority based on utility levels.
 */
int SpendResources::utilPriority(double dk) {
    double tmp = (dk * 10);
    int bucket = static_cast<int>(tmp);
    std::map<int, int> value = {{0, 3}, {1, 6}, {2, 9}, {3, 12}, {4, 15}, {5, 18}, {6, 21}, {7, 24}, {8, 27}, {9, 30}, {10, 30}};
    return value[bucket];
}

/**
 * @brief Checks if sufficient resources are available.
 */
bool SpendResources::checkResources(std::map<std::string, int>& haveResources, std::map<std::string, int> needResources) {
    for (const auto& resource : needResources) {
        if (haveResources[resource.first] < resource.second) {
            return false;
        }
    }
    for (const auto& resource : needResources) {
        haveResources[resource.first] -= resource.second;
    }
    return true;
}
