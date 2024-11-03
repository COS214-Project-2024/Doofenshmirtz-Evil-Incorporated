#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Building.h"

class Commercial : public Building {


public:
	Commercial(int totalCap, int usedCap);

	~Commercial();

	void update();

	std::map<std::string, int> collectResources() override;

	std::map<std::string, double> collectUtilities() override;


	nlohmann::json getJSONrepresentation();
};

#endif