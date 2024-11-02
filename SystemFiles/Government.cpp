#include "Government.h"
#include "Industrial.h"
#include "WebSocketNotifier.h"
#include <iostream>

Government::Government(int governmentBalance) {
	this->governmentBalance = governmentBalance;

	nlohmann::json message = {
	{"type", "valueUpdate"},
	{"data", 	{
					{"id", "money"},
					{"value", std::to_string(governmentBalance)}
				}
				}};
	WebSocketNotifier::get_mutable_instance().log(message);

	// Intialize Map
	resources["wood"] = 0;
    resources["concrete"] = 0;
    resources["steel"] = 0;
    resources["bricks"] = 0;

}

void Government::evaluateTrafficConditions()
{
	for (CityUnit* unit : observerList) 
	{
		unit->evaluateTrafficConditions();
	}

}

void Government::evaluateHappiness()
{
	for (CityUnit* unit : observerList) 
	{
		int cityHappiness = unit->evaluateHappiness();

		nlohmann::json message = {
		{"type", "valueUpdate"},
		{"data", 	{
						{"id", "satisfaction"},
						{"value", std::to_string(cityHappiness)}
					}
					}};
		WebSocketNotifier::get_mutable_instance().log(message);
	}

}

Government::~Government()
{
    for (auto it = observerList.begin(); it != observerList.end(); it++) {
		delete *it;
	}
	for (auto it = myCommand.begin(); it != myCommand.end(); it++) {
		delete *it;
	}
}

void Government::collectTaxes() {
	for (CityUnit* unit : observerList) {
		this->governmentBalance += unit->payTaxes();;
	}

	// Front end update
    nlohmann::json message = {
	{"type", "valueUpdate"},
	{"data", 	{
					{"id", "money"},
					{"value", std::to_string(governmentBalance)}
				}
				}};
	WebSocketNotifier::get_mutable_instance().log(message);
}

void Government::attach(CityUnit * myObserver) {
	observerList.push_back(myObserver);
}


void Government::detach(CityUnit* myObserver) {
	for (auto it = observerList.begin(); it != observerList.end(); it++) {
		if (*it == myObserver) {
			observerList.erase(it);
			delete myObserver;
			break;
		}
	}
}

void Government::notify() {
	for (CityUnit* unit : observerList) {
		unit->update();
	}
}

void Government::collectResources() {
	for (CityUnit* unit : observerList) 
	{
    	if (Industrial* industrialUnit = dynamic_cast<Industrial*>(unit)) 
		{
    	    // This is safe; you can call the overridden method directly
    	    std::map<std::string, int> unitResources = industrialUnit->collectResources();

			// Log the collected resources for debugging
        	std::cout << "Unit: " << unit << " collected resources: ";
        	for (const auto& resource : unitResources) {
        	    std::cout << "[" << resource.first << ": " << resource.second << "] ";
        	}
        	std::cout << std::endl;

        	for (const auto& resourcePair : unitResources) {
        	    this->resources[resourcePair.first] += resourcePair.second;
        	}
		}

    }
    // Send the current state of resources to the frontend
    for (const auto& resourcePair : this->resources) {
        nlohmann::json message = {
            {"type", "valueUpdate"},
            {"data", {
                        {"id", resourcePair.first},
                        {"value", std::to_string(resourcePair.second)}
                    }
            }};
        
        std::cout << message << std::endl;
        WebSocketNotifier::get_mutable_instance().log(message);
    }
}




int Government::getGovernmentBalance() {
	return this->governmentBalance;
}