/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#ifndef SEWAGE_H
#define SEWAGE_H

#include "Utility.h"
class Sewage : public Utility {


public:
 /**
     * @brief Constructs a Sewage object with specified total and used capacity.
     * @param totalCap The total capacity of the sewage system.
     * @param usedCap The current used capacity of the sewage system.
     */
	Sewage(int totalCap, int usedCap);

    /**
     * @brief Destructor for the Sewage class.
     * 
     * Cleans up resources used by the Sewage object.
     */
	~Sewage();
/**
     * @brief Updates the state of the sewage system.
     * 
     * This method may involve refreshing internal states or triggering
     * updates based on external conditions.
     */
	void update();
 /**
     * @brief Returns the type of utility represented by this class.
     * @return A string indicating the utility type ("SewageSystem").
     */
	std::string getUtilityType() const override {
        return "SewageSystem";
    }
/**
     * @brief Collects resources from the sewage system.
     * @return A map containing the resources collected from the system.
     */
	std::map<std::string, int> collectResources() override;
	    /**
     * @brief Collects utility data from the sewage system.
     * @return A map containing utility data collected from the system.
     */
	std::map<std::string, double> collectUtilities() override;
/**
     * @brief Provides a JSON representation of the sewage system.
     * @return A JSON object representing the state of the sewage system.
     */
	nlohmann::json getJSONrepresentation() override;
};

#endif
