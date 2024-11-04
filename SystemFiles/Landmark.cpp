/**
 * @file Landmark.cpp
 * @brief Defines the Landmark class for creating landmark objects.
 * 
 * This file contains the declaration of the Landmark class, which inherits 
 * from the Building class. The Landmark class is responsible for 
 * generating its JSON representation.
 */


#include "Landmark.h"
#include "WebSocketNotifier.h"

// Note: This currently calls the parent constructor with a set number. Whoever is implementing this, it should be a random number [10,100]
/**
     * @brief Constructs a Landmark object.
     * 
     * @param totalCap The total capacity of the landmark.
     * @param usedCap The currently used capacity of the landmark.
     */
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

/**
     * @brief Destroys the Landmark object.
     */
Landmark::~Landmark()
{
}

 /**
     * @brief Updates the state of the landmark.
     * 
     * This function is called to perform any necessary updates 
     * on the landmark, such as recalculating resources or utilities.
     */
void Landmark::update() {
	for (auto person:resident){
		person->updateSatisfaction("Visit landmark", 20);
	}
}

/**
     * @brief Collects resources from the landmark.
     * 
     * This function overrides the collectResources function in 
     * the Building class and returns a map of resources collected 
     * from the landmark.
     * 
     * @return std::map<std::string, int> A map containing the 
     * collected resources with their corresponding quantities.
     */
std::map<std::string, int> Landmark::collectResources()
{
    return std::map<std::string, int>();
}

 /**
     * @brief Collects utility data from the landmark.
     * 
     * This function overrides the collectUtilities function in 
     * the Building class and returns a map of utility data 
     * associated with the landmark.
     * 
     * @return std::map<std::string, double> A map containing 
     * the collected utility data with their corresponding values.
     */
std::map<std::string, double> Landmark::collectUtilities()
{
	return std::map<std::string, double>();
}

/**
     * @brief Generates a JSON representation of the landmark.
     * 
     * This function creates a JSON object containing relevant 
     * information about the landmark, which can be used for 
     * visualization purposes in the frontend.
     * 
     * @return nlohmann::json A JSON object representing the 
     * landmark and its properties.
     */
nlohmann::json Landmark::getJSONrepresentation()
{
    nlohmann::json building = {
        {"name" , "Landmark"},
        {"value", this->totalCapacity}
    };    

    return building;
}
