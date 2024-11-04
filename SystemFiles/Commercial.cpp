#include "Commercial.h"
#include "WebSocketNotifier.h"

Commercial::Commercial(int totalCap, int usedCap) : Building(totalCap, usedCap) {

	// Front end update
    nlohmann::json message = {
	{"type", "valueUpdate"},
	{"data", 	{
					{"id", "commercial"},
					{"value", "1++"}
				}
				}};
	WebSocketNotifier::get_mutable_instance().log(message);
}

Commercial::~Commercial()
{
}

void Commercial::update() {
	double salary = (rand()%1000)+100;
	for ( auto person:resident)
	{
		person->recieveSalary(salary);
	}
}

std::map<std::string, int> Commercial::collectResources()
{
    return std::map<std::string, int>();
}

std::map<std::string, double> Commercial::collectUtilities()
{
    return std::map<std::string, double>();
}

nlohmann::json Commercial::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Commercial"},
        {"value", this->totalCapacity}
    };    

    return building;
}