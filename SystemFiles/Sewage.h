#ifndef SEWAGE_H
#define SEWAGE_H

#include "Utility.h"
class Sewage : public Utility {


public:
	Sewage(int totalCap, int usedCap);

	~Sewage();

	void update();

	std::string getUtilityType() const override {
        return "SewageSystem";
    }

	std::map<std::string, int> collectResources() override;
	std::map<std::string, double> collectUtilities() override;

	nlohmann::json getJSONrepresentation() override;
};

#endif
