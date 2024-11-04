/**
 * @file BuildingFactory.h
 * @brief Defines the BuildingFactory class for creating building objects.
 */

#ifndef WATER_H
#define WATER_H

#include "Utility.h"
class Water : public Utility {


public:
	Water(int totalCap, int usedCap);

	~Water();

	void update();

	std::string getUtilityType() const override {
        return "WaterPlant";
    }

	std::map<std::string, int> collectResources() override;

	std::map<std::string, double> collectUtilities() override;

	nlohmann::json getJSONrepresentation() override;
};

#endif
