#ifndef BRICKINDUSTRIAL_H
#define BRICKINDUSTRIAL_H

#include "Industrial.h"

class BrickIndustrial : public Industrial {
public:
	BrickIndustrial(int totalCap, int usedCap, double taxR) : Industrial(totalCap, usedCap, taxR) {};
	~BrickIndustrial() override = default;
	std::map<std::string, int> collectResources() override {
        std::map<std::string, int> resources;
        resources["Brick"] = this->usedCapacity;
        this->usedCapacity = 0;
        return resources;
    }
    void update() override {
    }
};

#endif