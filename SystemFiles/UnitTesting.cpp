#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Citizen.h"
#include "CitizenLocationState.h"
#include "CityUnit.h"
#include "AtHomeState.h"
#include "AtWorkState.h"
#include "AtLeisureState.h"
#include <random>
#include "CommuteStrategy.h"
#include "RailwayStrategy.h"
#include "RoadStrategy.h"
#include "AirportStrategy.h"
#include "PublicTransportStrategy.h"
#include "District.h"
#include "Building.h"
#include "Residential.h"
#include "Government.h"
#include "Industrial.h"
#include "BuildingFactory.h"
#include "SewageSystemFactory.h"
#include "WasteSiteFactory.h"
#include "WaterPlantFactory.h"
#include "PowerPlantFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "LandmarkFactory.h"
#include "IndustrialFactory.h"
#include "ConcreteIterator.h"   // Include your ConcreteIterator implementation
#include "Iterator.h"           // Include the Iterator class
#include <vector>
#include <map>

// Define MockCityUnit class for testing purposes
class MockCityUnit : public CityUnit {
public:
    int id; // Unique identifier for testing

    // Constructor with default parameters
    MockCityUnit(int id_ = 0, int totalCap = 100, int usedCap = 0, double taxR = 0.1)
        : CityUnit(totalCap, usedCap, taxR), id(id_) {}

    // Implement pure virtual functions with minimal behavior

    void add(CityUnit* newUnit) override {
        // Minimal implementation: Do nothing
    }

    void remove(CityUnit* unit) override {
        // Minimal implementation: Do nothing
    }

    int calculateDistanceTo(CityUnit* destination) override {
        return 10; // Arbitrary mock value
    }

    int getRemainingCapacity() override {
        return totalCapacity - usedCapacity;
    }

    int getUsedCapacity() override {
        return usedCapacity;
    }

    void update() override {
        // Minimal implementation: Do nothing
    }

    void employResidents() override {
        // Minimal implementation: Do nothing
    }

    Iterator* createIterator() override {
        return nullptr; // No iteration support in mock
    }

    double getEmploymentRate() override {
        return 0.0; // Mock employment rate
    }

    double setTaxRate(double amount) override {
        taxRate = amount;
        return taxRate;
    }

    double payTaxes(double rate) override {
        return 0.0; // Mock tax payment
    }

    int evaluateHappiness() override {
        return 0; // Mock happiness evaluation
    }

    int countCitizens() override {
        return resident.size();
    }

    // Override getResidents to return the resident list
    std::vector<Citizen*>& getResidents() override {
        return resident;
    }

    // Additional helper methods for testing

    // Method to add a mock resident for testing purposes
    void addMockResident(Citizen* citizen) {
        resident.push_back(citizen);
    }

    // Destructor to clean up dynamically allocated mock residents
    ~MockCityUnit() override {
        for (auto citizen : resident) {
            delete citizen; // Free each dynamically allocated Citizen
        }
        resident.clear(); // Clear the vector to avoid dangling pointers
    }

private:
    // If you prefer using a separate mockResidents vector, uncomment the following line:
    // std::vector<Citizen*> mockResidents; // Mock list of residents
};

//////////////////////
// Test Cases Below //
//////////////////////

// Test case: ConcreteIterator with an empty collection
TEST_CASE("ConcreteIterator with Empty Collection") {
    std::vector<CityUnit*> cityUnits = {};
    ConcreteIterator iterator(cityUnits);
    
    iterator.first();
    CHECK(iterator.isDone() == true);
    CHECK(iterator.currentItem() == nullptr);
    
    iterator.next();
    CHECK(iterator.isDone() == true);
    
    iterator.previous();
    CHECK(iterator.isDone() == true);
}

// Test case: CitizenUnitTesting
TEST_CASE("CitizenUnitTesting") {

    CityUnit* residential = new MockCityUnit();
    CityUnit* commercial = new MockCityUnit();
    CityUnit* leisure = new MockCityUnit();

    SUBCASE("Citizen with job is initialized correctly") {
        Citizen citizen(residential, commercial, leisure);

        CHECK(citizen.getHome() == residential);
        CHECK(citizen.getJob() == commercial);
        CHECK(citizen.getLeisure() == leisure);
        CHECK(citizen.getJob() != nullptr); // Citizen is employed
    }

    SUBCASE("Citizen without job is initialized correctly") {
        Citizen citizen(residential, nullptr, leisure);

        CHECK(citizen.getHome() == residential);
        CHECK(citizen.getJob() == nullptr); // Citizen is unemployed
        CHECK(citizen.getLeisure() == leisure);
    }

    SUBCASE("Citizen without job is employed")
    {
        Citizen citizen(residential, nullptr, leisure);
        CityUnit* mockJob = new MockCityUnit();

        // Employ the citizen
        CHECK(citizen.employCitizen(mockJob) == true);
        CHECK(citizen.getJob() == mockJob);

        // Attempt to employ again (should fail)
        CHECK(citizen.employCitizen(mockJob) == false);
        CHECK(citizen.getJob() == mockJob); // Job did not change

        delete mockJob;
    }

    SUBCASE("Citizen member functions working as expected")
    {
        Citizen citizen(residential, commercial, leisure);

        // Satisfaction initialized in range [40, 70]
        CHECK(citizen.getSatisfaction() >= 40);
        CHECK(citizen.getSatisfaction() <= 70);
        MESSAGE("Citizen satisfaction score: " << citizen.getSatisfaction());

        // Bank balance initialized in range [20 000, 100 000]
        CHECK(citizen.getBalance() >= 20000);
        CHECK(citizen.getBalance() <= 100000);
        MESSAGE("Citizen balance: " << citizen.getBalance());
    }

    SUBCASE("Routine affects satisfaction") {

        Citizen citizen(residential, commercial, leisure);
        MESSAGE("Citizen satisfaction before routine: " << citizen.getSatisfaction());

        int prevSatisfaction = citizen.getSatisfaction();
        citizen.followRoutine();
        int satisfactionDiff = prevSatisfaction - citizen.getSatisfaction();
        CHECK(satisfactionDiff >= 0);    // Satisfaction should not increase at Work
        CHECK(satisfactionDiff <= 10);   // Satisfaction should decrease by no more than 10
        MESSAGE("Citizen satisfaction after followRoutine (AtHomeState => AtWorkState): " << citizen.getSatisfaction());

        prevSatisfaction = citizen.getSatisfaction();
        citizen.followRoutine();
        satisfactionDiff = citizen.getSatisfaction() - prevSatisfaction;
        CHECK(satisfactionDiff >= 0); // Satisfaction should increase at leisure
        CHECK(satisfactionDiff <= 20); // Satisfaction should increase by no more than 20
        MESSAGE("Citizen satisfaction after followRoutine (AtWorkState => AtLeisureState): " << citizen.getSatisfaction());

        prevSatisfaction = citizen.getSatisfaction();
        citizen.followRoutine();
        satisfactionDiff = prevSatisfaction - citizen.getSatisfaction();
        CHECK(satisfactionDiff >= -10);
        CHECK(satisfactionDiff <= 10); // Satisfaction should change at home
        MESSAGE("Citizen satisfaction after followRoutine (AtLeisureState => AtHomeState): " << citizen.getSatisfaction());
    }

    // Clean up dynamically allocated CityUnits
    delete residential;
    delete commercial;
    delete leisure;
}

// Test case: ConcreteIterator with a single element
TEST_CASE("ConcreteIterator with Single Element") {
    MockCityUnit unit1(1);
    std::vector<CityUnit*> cityUnits = { &unit1 };
    ConcreteIterator iterator(cityUnits);
    
    // Initial state
    iterator.first();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit1);
    
    // Move next (should be done)
    iterator.next();
    CHECK(iterator.isDone() == true);
    CHECK(iterator.currentItem() == nullptr);
    
    // Move previous (back to first)
    iterator.previous();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit1);
}

// Test case: ConcreteIterator with multiple elements
TEST_CASE("ConcreteIterator with Multiple Elements") {
    MockCityUnit unit1(1);
    MockCityUnit unit2(2);
    MockCityUnit unit3(3);
    std::vector<CityUnit*> cityUnits = { &unit1, &unit2, &unit3 };
    ConcreteIterator iterator(cityUnits);
    
    // Initial state
    iterator.first();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit1);
    
    // Move to second element
    iterator.next();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit2);
    
    // Move to third element
    iterator.next();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit3);
    
    // Move beyond last element
    iterator.next();
    CHECK(iterator.isDone() == true);
    CHECK(iterator.currentItem() == nullptr);
    
    // Move back to third element
    iterator.previous();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit3);
    
    // Move back to second element
    iterator.previous();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit2);
    
    // Move back to first element
    iterator.previous();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit1);
    
    // Move before first element (should remain at first)
    iterator.previous();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit1);
}

// Test case: ConcreteIterator navigation beyond bounds
TEST_CASE("ConcreteIterator Navigation Beyond Bounds") {
    MockCityUnit unit1(1);
    MockCityUnit unit2(2);
    std::vector<CityUnit*> cityUnits = { &unit1, &unit2 };
    ConcreteIterator iterator(cityUnits);
    
    // Initial state
    iterator.first();
    CHECK(iterator.currentItem() == &unit1);
    
    // Move next to second element
    iterator.next();
    CHECK(iterator.currentItem() == &unit2);
    
    // Move next beyond last element
    iterator.next();
    CHECK(iterator.isDone() == true);
    CHECK(iterator.currentItem() == nullptr);
    
    // Move next again (should remain done)
    iterator.next();
    CHECK(iterator.isDone() == true);
    CHECK(iterator.currentItem() == nullptr);
    
    // Move previous back to second element
    iterator.previous();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit2);
    
    // Move previous back to first element
    iterator.previous();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit1);
    
    // Move previous beyond first element (should remain at first)
    iterator.previous();
    CHECK(iterator.isDone() == false);
    CHECK(iterator.currentItem() == &unit1);
}

// Test case: ConcreteIterator first() method
TEST_CASE("ConcreteIterator First Method") {
    MockCityUnit unit1(1);
    MockCityUnit unit2(2);
    MockCityUnit unit3(3);
    std::vector<CityUnit*> cityUnits = { &unit1, &unit2, &unit3 };
    ConcreteIterator iterator(cityUnits);
    
    // Move to last element
    iterator.next();
    iterator.next();
    CHECK(iterator.currentItem() == &unit3);
    
    // Reset to first
    iterator.first();
    CHECK(iterator.currentItem() == &unit1);
}

// Test case: ConcreteIterator isDone() method
TEST_CASE("ConcreteIterator IsDone Method") {
    MockCityUnit unit1(1);
    std::vector<CityUnit*> cityUnits = { &unit1 };
    ConcreteIterator iterator(cityUnits);
    
    // Not done initially
    iterator.first();
    CHECK(iterator.isDone() == false);
    
    // After moving next
    iterator.next();
    CHECK(iterator.isDone() == true);
    
    // After moving previous
    iterator.previous();
    CHECK(iterator.isDone() == false);
}

// Test case: ConcreteIterator currentItem() method
TEST_CASE("ConcreteIterator CurrentItem Method") {
    MockCityUnit unit1(1);
    MockCityUnit unit2(2);
    std::vector<CityUnit*> cityUnits = { &unit1, &unit2 };
    ConcreteIterator iterator(cityUnits);
    
    // Initial state
    iterator.first();
    CHECK(iterator.currentItem() == &unit1);
    
    // After next
    iterator.next();
    CHECK(iterator.currentItem() == &unit2);
    
    // After next (done)
    iterator.next();
    CHECK(iterator.currentItem() == nullptr);
}

TEST_CASE("TransportStrategyUnitTesting")
{   
    //create all four concrete strategies
    CommuteStrategy* roadTest = new RoadStrategy();
    CommuteStrategy* railTest = new RailwayStrategy();
    CommuteStrategy* AirTest = new AirportStrategy();
    CommuteStrategy* publicTest = new PublicTransportStrategy();

    SUBCASE("returnStrategyNameTesting")
    {
        CHECK(roadTest->getTravelStrategyName() == "RoadStrategy");
        CHECK(railTest->getTravelStrategyName() == "RailwayStrategy");
        CHECK(AirTest->getTravelStrategyName() == "AirportStrategy");
        CHECK(publicTest->getTravelStrategyName() == "PublicTransportStrategy");

        MESSAGE("roadTest: " << roadTest->getTravelStrategyName());
        MESSAGE("railTest: " << railTest->getTravelStrategyName());
        MESSAGE("AirTest: " << AirTest->getTravelStrategyName());
        MESSAGE("publicTest: " << publicTest->getTravelStrategyName());
    }

    SUBCASE("returnStrategyNameTesting")
    {
        CHECK(roadTest->handleCommuteState() == 8);
        CHECK(railTest->handleCommuteState() == 10);
        CHECK(AirTest->handleCommuteState() == 15);
        CHECK(publicTest->handleCommuteState() == 4);

    }

    delete publicTest;
    delete AirTest;
    delete railTest;
    delete roadTest;

    //note these subcases can fail due to random factor
    SUBCASE("CorrectStrategyChosen")
    {
        AtHomeState home;
        home.chooseStrategy(5);
        CHECK(home.getTravelMethod() == "RoadStrategy");
        // home.chooseStrategy(10);
        // CHECK(home.getTravelMethod() == "PublicTransportStrategy");
        home.chooseStrategy(15);
        CHECK(home.getTravelMethod() == "RailwayStrategy");
        home.chooseStrategy(30);
        CHECK(home.getTravelMethod() == "AirportStrategy");
    }
    SUBCASE("RandomCommuteTesting")
    {
        //this is a very very small chance, hence the amount of times I test it
        AtHomeState home;
        for(int i = 0; i < 100; i++)
        {
            home.chooseStrategy(5);
            // MESSAGE("5: " << home.getTravelMethod());
        }
    }

}

TEST_CASE("District Tests") {
    District district;

    SUBCASE("Add and Remove Units") {
        CityUnit* unit1 = new MockCityUnit();
        CityUnit* unit2 = new MockCityUnit();

        CHECK_NOTHROW(district.add(unit1));
        CHECK_NOTHROW(district.add(unit2));

        // Attempt to remove the units and check
        CHECK_NOTHROW(district.remove(unit1));
        CHECK_NOTHROW(district.remove(unit2));

        // Since District is managing memory, no manual deletion is necessary
    }

    SUBCASE("Employment Rate Calculation") {
        // Create specialized mock units with a set employment rate
        class MockCityUnitWithEmployment : public MockCityUnit {
        public:
            double getEmploymentRate() override { return 0.5; }
        };

        CityUnit* unit1 = new MockCityUnitWithEmployment();
        CityUnit* unit2 = new MockCityUnitWithEmployment();

        district.add(unit1);
        district.add(unit2);

        // Check the average employment rate
        CHECK(district.getEmploymentRate() == doctest::Approx(0.5));
        MESSAGE("Employment rate: " << district.getEmploymentRate());
        // No manual deletion needed since District manages memory
    }

    SUBCASE("Count Citizens") {

        CityUnit* unit1 = new Residential(100, 50, 0.1);
        CityUnit* unit2 = new Residential(200, 100, 0.2);

        district.add(unit1);
        district.add(unit2);
        MESSAGE("Unit 1: " << unit1->getResidents().size());
        MESSAGE("Unit 2: " << unit2->getResidents().size());
        // Since each Residential unit initializes with a random number of residents,
        // you may want to set a fixed number for this test or check based on totalCapacity

        int expectedCount = unit1->getResidents().size() + unit2->getResidents().size();
        CHECK(district.countCitizens() == expectedCount);
        MESSAGE(district.countCitizens());
        // No manual deletion needed if District manages the memory
    }
    SUBCASE("Tax Payment Calculation") {
        // Create Residential units and add them to the District
        Residential* residentialUnit1 = new Residential(100, 50, 0.1);
        Residential* residentialUnit2 = new Residential(200, 100, 0.2);

        // Create citizens with controlled initial balances
        Citizen* citizen1 = new Citizen(residentialUnit1, nullptr, nullptr);
        Citizen* citizen2 = new Citizen(residentialUnit2, nullptr, nullptr);

        // Set controlled balances to ensure predictability
        citizen1->recieveSalary(1000 - citizen1->getBalance()); // Ensure final balance is exactly 1000
        citizen2->recieveSalary(2000 - citizen2->getBalance()); // Ensure final balance is exactly 2000

        // Verify that initial balances are as expected
        CHECK(citizen1->getBalance() == doctest::Approx(1000.0));
        CHECK(citizen2->getBalance() == doctest::Approx(2000.0));

        residentialUnit1->getResidents().push_back(citizen1);
        residentialUnit2->getResidents().push_back(citizen2);

        district.add(residentialUnit1);
        district.add(residentialUnit2);

        double rate = 0.1; // 10% tax rate
        double taxCollected = district.payTaxes(rate);

        // Expected total tax = (1000 * 0.1) + (2000 * 0.1) = 300
        CHECK(taxCollected == doctest::Approx(300.0));
        MESSAGE("Total tax collected: R" << taxCollected);

        // Check if citizens' balances are reduced correctly
        CHECK(citizen1->getBalance() == doctest::Approx(900.0)); // 1000 - 100
        CHECK(citizen2->getBalance() == doctest::Approx(1800.0)); // 2000 - 200

        // No manual deletion needed if District manages the memory
    }
}

TEST_CASE("Government") {
    Government government(50000);

    SUBCASE("Collect Taxes") {
        // Create mock CityUnits with a set used capacity
        class MockCityUnitWithTaxes : public MockCityUnit {
        public:
            double payTaxes(double rate) override { return 1000; }
            int getUsedCapacity() override { return 100; }
        };

        CityUnit* unit1 = new MockCityUnitWithTaxes();
        CityUnit* unit2 = new MockCityUnitWithTaxes();

        government.attach(unit1);
        government.attach(unit2);

        // Collect taxes and check the government balance
        government.collectTaxes();
        CHECK(government.getGovernmentBalance() == 2000);
    }

    SUBCASE("Collect Resources") {
        // Create mock CityUnits with a set used capacity
        Industrial* industrial = new Industrial(100, 50, 0.1);

        government.attach(industrial);

        // Collect resources and check the government balance
        government.collectResources();
        std::map<std::string, int> resources = government.getResources();
        CHECK(resources["Steel"] == 50);
        CHECK(resources["Wood"] == 50);
        CHECK(resources["Concrete"] == 50);
        CHECK(resources["Bricks"] == 50);
    }

    // No manual deletion needed if Government manages the memory
}

TEST_CASE("FactoryTesting")
{
    BuildingFactory* sewageSystemFactory = new SewageSystemFactory();
    BuildingFactory* wasteSiteFactory = new WasteSiteFactory();
    BuildingFactory* waterPlantFactory = new WaterPlantFactory();
    BuildingFactory* powerPlantFactory = new PowerPlantFactory();
    BuildingFactory* residentialFactory = new ResidentialFactory();
    BuildingFactory* commercialFactory = new CommercialFactory();
    BuildingFactory* landmarkFactory = new LandmarkFactory();
    BuildingFactory* industrialFactory = new IndustrialFactory();

    Building* sewageSystem = sewageSystemFactory->build();
    Building* wasteSite = wasteSiteFactory->build();
    Building* waterPlant = waterPlantFactory->build();
    Building* powerPlant = powerPlantFactory->build();
    Building* residential = residentialFactory->build();
    Building* commercial = commercialFactory->build();
    Building* landmark = landmarkFactory->build();
    Building* industrial = industrialFactory->build();

    SUBCASE("Factories instantiated")
    {
        CHECK(sewageSystem != nullptr);
        CHECK(wasteSite != nullptr);
        CHECK(waterPlant != nullptr);
        CHECK(powerPlant != nullptr);
        CHECK(residential != nullptr);
        CHECK(commercial != nullptr);
        CHECK(landmark != nullptr);
        CHECK(industrial != nullptr);
    }

    SUBCASE("Factory resourceCost")
    {
        CHECK(sewageSystemFactory->getResourceCost()["Wood"] == 50);
        CHECK(sewageSystemFactory->getResourceCost()["Steel"] == 50);
        CHECK(sewageSystemFactory->getResourceCost()["Bricks"] == 50);
        CHECK(sewageSystemFactory->getResourceCost()["Concrete"] == 50);

        CHECK(wasteSiteFactory->getResourceCost()["Wood"] == 50);
        CHECK(wasteSiteFactory->getResourceCost()["Steel"] == 50);
        CHECK(wasteSiteFactory->getResourceCost()["Bricks"] == 50);
        CHECK(wasteSiteFactory->getResourceCost()["Concrete"] == 50);

        CHECK(waterPlantFactory->getResourceCost()["Wood"] == 50);
        CHECK(waterPlantFactory->getResourceCost()["Steel"] == 50);
        CHECK(waterPlantFactory->getResourceCost()["Bricks"] == 50);
        CHECK(waterPlantFactory->getResourceCost()["Concrete"] == 50);

        CHECK(powerPlantFactory->getResourceCost()["Wood"] == 50);
        CHECK(powerPlantFactory->getResourceCost()["Steel"] == 50);
        CHECK(powerPlantFactory->getResourceCost()["Bricks"] == 50);
        CHECK(powerPlantFactory->getResourceCost()["Concrete"] == 50);

        CHECK(residentialFactory->getResourceCost()["Wood"] == 50);
        CHECK(residentialFactory->getResourceCost()["Steel"] == 50);
        CHECK(residentialFactory->getResourceCost()["Bricks"] == 50);
        CHECK(residentialFactory->getResourceCost()["Concrete"] == 50);

        CHECK(commercialFactory->getResourceCost()["Wood"] == 50);
        CHECK(commercialFactory->getResourceCost()["Steel"] == 50);
        CHECK(commercialFactory->getResourceCost()["Bricks"] == 50);
        CHECK(commercialFactory->getResourceCost()["Concrete"] == 50);

        CHECK(landmarkFactory->getResourceCost()["Wood"] == 50);
        CHECK(landmarkFactory->getResourceCost()["Steel"] == 50);
        CHECK(landmarkFactory->getResourceCost()["Bricks"] == 50);
        CHECK(landmarkFactory->getResourceCost()["Concrete"] == 50);

        CHECK(industrialFactory->getResourceCost()["Wood"] == 50);
        CHECK(industrialFactory->getResourceCost()["Steel"] == 50);
        CHECK(industrialFactory->getResourceCost()["Bricks"] == 50);
        CHECK(industrialFactory->getResourceCost()["Concrete"] == 50);
    }

    SUBCASE("Factory cost")
    {
        CHECK(sewageSystemFactory->getCost() == 50);
        CHECK(wasteSiteFactory->getCost() == 50);
        CHECK(waterPlantFactory->getCost() == 50);
        CHECK(powerPlantFactory->getCost() == 50);
        CHECK(residentialFactory->getCost() == 50);
        CHECK(commercialFactory->getCost() == 50);
        CHECK(landmarkFactory->getCost() == 50);
        CHECK(industrialFactory->getCost() == 50);
    }

    delete sewageSystem;
    delete wasteSite;
    delete waterPlant;
    delete powerPlant;
    delete residential;
    delete commercial;
    delete landmark;
    delete industrial;

    delete sewageSystemFactory;
    delete wasteSiteFactory;
    delete waterPlantFactory;
    delete powerPlantFactory;
    delete residentialFactory;
    delete commercialFactory;
    delete landmarkFactory;
    delete industrialFactory;   
}
