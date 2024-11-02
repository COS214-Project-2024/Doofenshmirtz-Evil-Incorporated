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
