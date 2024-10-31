#ifndef CONCRETEINDUSTRIAL_H
#define CONCRETEINDUSTRIAL_H

#include "Industrial.h"

class ConcreteIndustrial : public Industrial {
public:
	ConcreteIndustrial(int totalCap, int usedCap, double taxR) : Industrial(totalCap, usedCap, taxR) {};
	~ConcreteIndustrial() override = default;
	std::map<std::string, int> collectResources() override {
        std::map<std::string, int> resources;
        resources["Concrete"] = this->usedCapacity;
        this->usedCapacity = 0;
        return resources;
    }
    void update() override {
    }
};

#endif