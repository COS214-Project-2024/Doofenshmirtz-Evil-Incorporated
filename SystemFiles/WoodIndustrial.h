#ifndef WOODINDUSTRIAL_H
#define WOODINDUSTRIAL_H

#include "Industrial.h"

class WoodIndustrial : public Industrial {
public:
	WoodIndustrial(int totalCap, int usedCap, double taxR) : Industrial(totalCap, usedCap, taxR) {};
	~WoodIndustrial() override = default;

	std::map<std::string, int> collectResources() override {
        std::map<std::string, int> resources;
        resources["Wood"] = this->usedCapacity;
        this->usedCapacity = 0;
        return resources;
    }

    void update() override {
    }
};

#endif