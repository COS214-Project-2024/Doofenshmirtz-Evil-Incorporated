#ifndef WASTE_H
#define WASTE_H

#include "Utility.h"
class Waste : public Utility {


public:
	Waste(int totalCap, int usedCap);

	~Waste();

	void update();

	std::string getUtilityType() const override {
        return "WasteSite";
    }

	std::map<std::string, int> collectResources() override;
	
	std::map<std::string, double> collectUtilities() override;

	nlohmann::json getJSONrepresentation() override;
};

#endif
