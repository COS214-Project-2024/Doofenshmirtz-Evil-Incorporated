#ifndef POWER_H
#define POWER_H

#include "Utility.h"

class Power : public Utility {


public:
	Power(int totalCap, int usedCap);

	~Power();

	void update();

	std::string getUtilityType() const override {
        return "PowerPlant";
    }

	std::map<std::string, int> collectResources() override;
	std::map<std::string, double> collectUtilities() override;


	nlohmann::json getJSONrepresentation() override;
};

#endif
