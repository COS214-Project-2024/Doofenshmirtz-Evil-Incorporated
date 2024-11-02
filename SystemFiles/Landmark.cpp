#include "Landmark.h"
#include "WebSocketNotifier.h"

// Note: This currently calls the parent constructor with a set number. Whoever is implementing this, it should be a random number [10,100]
Landmark::Landmark(int totalCap, int usedCap) : Building(totalCap, usedCap) {

	// Front end update
    nlohmann::json message = {
	{"type", "valueUpdate"},
	{"data", 	{
					{"id", "landmarks"},
					{"value", "1++"}
				}
				}};
	WebSocketNotifier::get_mutable_instance().log(message);
}

Landmark::~Landmark()
{
}

void Landmark::update() {
	for (auto person:resident){
		person->updateSatisfaction("Visit landmark", 20);
	}
}
