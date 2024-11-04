/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#ifndef UTILITY_H
#define UTILITY_H

#include "Building.h"
class Utility : public Building {


public:
	Utility(int totalCap, int usedCap);

	virtual ~Utility();

	virtual void update() = 0;

	virtual std::string getUtilityType() const = 0;

	std::map<std::string, int> collectResources() override;

	std::map<std::string, double> collectUtilities() override;

	nlohmann::json getJSONrepresentation() override;
};



#endif
