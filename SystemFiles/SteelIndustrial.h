#ifndef STEELINDUSTRIAL_H
#define STEELINDUSTRIAL_H

#include "Industrial.h"

class SteelIndustrial : public Industrial {
public:
	SteelIndustrial(int totalCap, int usedCap, double taxR) : Industrial(totalCap, usedCap, taxR) {};
	~SteelIndustrial() override = default;
	std::map<std::string, int> collectResources() override {
        std::map<std::string, int> resources;
        resources["Steel"] = this->usedCapacity;
        this->usedCapacity = 0;
        return resources;
    }
    void update() override {
    }
};

#endif