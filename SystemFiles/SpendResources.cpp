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

    /*
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
    */
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
    std::map<int, int> value = {{0,1},{1,5},{2,9},{3,13},{4,18},{5,23},{6,28},{7,33},{8,38},{9,43},{10,48}};
    return value[bucket];
}

/**
 * @brief Determines priority based on citizen satisfaction.
 */
int SpendResources::citizenPriority(double citizenSatisfaction) {
    double tmp = citizenSatisfaction * 10;
    int bucket = static_cast<int>(tmp);
    std::map<int, int> value = {{0,2},{1,6},{2,10},{3,14},{4,19},{5,24},{6,29},{7,34},{8,39},{9,44},{10,49}};
    return value[bucket];
}

/**
 * @brief Determines priority based on utility levels.
 */
int SpendResources::utilPriority(double dk) {
    double tmp = (dk * 10);
    int bucket = static_cast<int>(tmp);
    std::map<int, int> value = {{0, 51},{1, 46},{2, 41},{3,36},{4,31}, {5,26}, {6,21}, {7,16}, {8,12}, {9,8}, {10,4}};
            
    return value[bucket];
}

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

    std::map<int, int> value = {{0, 3}, {1,7}, {2,11}, {3,15}, {4,20}, {5,25}, {6,30}, {7,35}, {8,40}, {9,45}, {10,50}}; 

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
    std::map<int, int> value = {{0,67},{1,62},{2,57},{3,52},{4,47},{5,42},{6,37},{7,32},{8,27},{9,22},{10,17}};
    return value[bucket];
}

/**s
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



