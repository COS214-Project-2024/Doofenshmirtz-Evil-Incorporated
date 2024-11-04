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
#include "IndustrialFactory.h"
#include "CommercialFactory.h"
#include "LandmarkFactory.h"
#include "WebSocketNotifier.h"

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
    this->IndustFact = new IndustrialFactory();
    this->ResedentialFact = new ResidentialFactory();


    std::cout << "\n\n\nINFO\n:";
    std::cout << "EmploymentRate: " << employmentRate << "\n";
    std::cout << "balance: " << balance << "\n";
    std::cout << "citizenSatisfaction: " << citizenSatisfaction << "\n";
    std::cout << "Utilities: " << "\n";
    for (const auto& util : utilities)
    {
        std::cout << util.first << " | " << util.second << "\n";
    }
    std::cout << "\n\n\n";
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
    delete this->IndustFact;
    delete this->ResedentialFact;
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
    int ResidentialPriority = resedentialPriority(citizenSatisfaction);
    int IndustrielPriority = resourcePriority(resources);

    // Identify the highest priority item to build
    int roulette[8] = {EmploymentPriority, citizenSatisfactionPriority, PowerPriority, WaterPriority, WastePriority, SewagePriority,ResidentialPriority,IndustrielPriority};
    std::cout << "++++++++++++++++++++++++++++" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << roulette[i] << " " ;
    }
    std::cout << "++++++++++++++++++++++++++++" << std::endl;


    int decisionVal = 0;
    int highNum = 999;
    for (int i = 0; i < 8; i++) {
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
                this->receiver->add(temp);
                this->receiver->employResidents();
            }
            break;
        case 1:
            if (balance >= LandmarkFact->getCost() && checkResources(resources, LandmarkFact->getResourceCost())) {
                balance -= LandmarkFact->getCost();
                CityUnit* temp = this->LandmarkFact->build();
                this->receiver->add(temp);
                this->receiver->partyResidents();
            }
            break;
        case 2:
            if (balance >= PowerFact->getCost() && checkResources(resources, PowerFact->getResourceCost())) {
                balance -= PowerFact->getCost();
                CityUnit* temp = this->PowerFact->build();
                this->receiver->add(temp);
            }
            break;
        case 3:
            if (balance >= WaterFact->getCost() && checkResources(resources, WaterFact->getResourceCost())) {
                balance -= WaterFact->getCost();
                CityUnit* temp = this->WaterFact->build();
                this->receiver->add(temp);
            }
            break;
        case 4:
            if (balance >= WasteFact->getCost() && checkResources(resources, WasteFact->getResourceCost())) {
                balance -= WasteFact->getCost();
                CityUnit* temp = this->WasteFact->build();
                this->receiver->add(temp);
            }
            break;
        case 5:
            if (balance >= SewageFact->getCost() && checkResources(resources, SewageFact->getResourceCost())) {
                balance -= SewageFact->getCost();
                CityUnit* temp = this->SewageFact->build();
                this->receiver->add(temp);
            }
            break;
        case 6:
            if (balance >= ResedentialFact->getCost() && checkResources(resources, ResedentialFact->getResourceCost())) {
                balance -= ResedentialFact->getCost();
                CityUnit* temp = this->ResedentialFact->build();
                this->receiver->add(temp);
            }
            break;
        case 7:
            if (balance >= IndustFact->getCost()) {
                balance -= IndustFact->getCost();
                CityUnit* temp = this->IndustFact->build();
                this->receiver->add(temp);
            }
            break;
        default:
            break;
    }

    // Reflect update to bank balance
    nlohmann::json message = {
        {"type", "valueUpdate"},
        {"data", {
                    {"id", "money"},
                    {"value", std::to_string(balance)}
                    }
        }};
    WebSocketNotifier::get_mutable_instance().log(message);
}

/**
 * @brief Determines priority based on employment rate.
 */
int SpendResources::employmentPriority(double employmentRate) {
    double tmp = (employmentRate * 10);
    int bucket = static_cast<int>(tmp);
    std::map<int, int> value = {{0,1},{1,6},{2,11},{3,16},{4,21},{5,26},{6,31},{7,36},{8,41},{9,46},{10,51}};
    return value[bucket];
}

/**
 * @brief Determines priority based on citizen satisfaction.
 */
int SpendResources::citizenPriority(double citizenSatisfaction) {
    double tmp = citizenSatisfaction * 10;
    int bucket = static_cast<int>(tmp);
    std::map<int, int> value = {{0,2},{1,7},{2,12},{3,17},{4,22},{5,27},{6,32},{7,37},{8,42},{9,47},{10,52}};
    return value[bucket];
}

/**
 * @brief Determines priority based on utility levels.
 */
int SpendResources::utilPriority(double dk) {
    double tmp = (dk * 10);
    int bucket = static_cast<int>(tmp);
    std::map<int, int> value = {{0, 54},{1, 49},{2, 44},{3,39},{4,34}, {5,29}, {6,24}, {7,19}, {8,14}, {9,9}, {10,4}};
            
    return value[bucket];
}

/**
 * @brief Determines the priority of resources based on the provided resource map.
 * 
 * This method evaluates the given resources and assigns a priority level 
 * based on predefined criteria. The higher the priority, the more critical 
 * the resource is deemed for operations.
 * 
 * @param resources A map containing resource names as keys and their 
 *                  corresponding quantities as values.
 * @return An integer representing the priority level of the resources.
 *         Lower values indicate higher priority.
 */
int SpendResources::resourcePriority(std::map<std::string, int> resources)
{
    int temp =0;
    for (const auto& resource : resources)
    {
        temp += resource.second;
    }
    double percentage = temp/200;//because every resource for a normal building costs 50
    double tmp = (percentage * 10);
    int bucket = static_cast<int>(tmp);

    std::map<int, int> value = {{0, 3}, {1,8}, {2,13}, {3,18}, {4,23}, {5,28}, {6,33}, {7,38}, {8,43}, {9,48}, {10,53}};

    if(percentage > 1)
    {
        return 53;
    }
    else
    {
        return value[bucket];
    }
    
}

int SpendResources::resedentialPriority(double satisfaction)
{
    double tmp = (satisfaction * 10);
    int bucket = static_cast<int>(tmp);
    std::map<int, int> value = {{0,55},{1,50},{2,45},{3,40},{4,35},{5,30},{6,25},{7,20},{8,15},{9,10},{10,5}};
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

        // Notify frontend of resource update
        nlohmann::json message = {
            {"type", "valueUpdate"},
            {"data", {
                        {"id", resource.first},
                        {"value", std::to_string((resource.second)) + "--"}
                    }
            }};
        
        WebSocketNotifier::get_mutable_instance().log(message);
    }
    return true;
}



