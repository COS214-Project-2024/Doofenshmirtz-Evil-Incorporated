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
#include "CityUnit.h"
#include "Building.h"
#include "Residential.h"

TEST_CASE("Example Test")
{
    CHECK(1 == 1);
}

// Create mock CityUnits
class MockCityUnit : public CityUnit {
public:
    // Mock implementation for distance calculation
    int calculateDistanceTo(CityUnit* other) override {
        return 10; // Arbitrary mock value
    }

    // Stubs to satisfy pure virtual functions
    void add(CityUnit* newUnit) override {}
    void remove(CityUnit* unit) override {}
    int getRemainingCapacity() override { return 0; }
    int getUsedCapacity() override { return 0; }
    void update() override {}
    Iterator* createIterator() override { return nullptr; }
    double getEmploymentRate() override { return 0.0; }
    int evaluateHappiness() override { return 0; }
    int countCitizens() override { return 0; }
    // Implement the additional pure virtual methods
    void employResidents() override {}
    double setTaxRate(double amount) override { return amount; }
    double payTaxes(double rate) override { return 0.0; }

    // Implement the getResidents method to return the list of mock residents
    std::vector<Citizen*>& getResidents() override {
        return mockResidents;
    }

    // Method to add a mock resident for testing purposes
    void addMockResident(Citizen* citizen) {
        mockResidents.push_back(citizen);
    }

    // Destructor to clean up dynamically allocated mock residents
    ~MockCityUnit() {
        for (auto resident : mockResidents) {
            delete resident;  // Free each dynamically allocated Citizen
        }
        mockResidents.clear();  // Clear the vector to avoid dangling pointers
    }

    private:
        std::vector<Citizen*> mockResidents;  // Mock list of residents
};

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

    delete residential;
    delete commercial;
    delete leisure;
}

TEST_CASE("CitizenLocationStateUnitTesting")
{
    SUBCASE("getStateName")
    {
        AtHomeState home;
        AtWorkState work;
        AtLeisureState leisure;

        CHECK(home.getStateName() == "AtHomeState");
        CHECK(work.getStateName() == "AtWorkState");
        CHECK(leisure.getStateName() == "AtLeisureState");
    }

    SUBCASE("travelTesting")
    {
        // Create a citizen to use
        CityUnit* residential = new MockCityUnit();
        CityUnit* commercial = new MockCityUnit();
        CityUnit* leisure = new MockCityUnit();

        Citizen* citizen = new Citizen(residential, commercial, leisure);

        // Travel from home to work
        AtHomeState home;
        home.travel(citizen);
        CHECK(citizen->getCitzenLocationSate()->getStateName() == "AtWorkState");
        
        // Travel from work to leisure
        AtWorkState work;
        work.travel(citizen);
        CHECK(citizen->getCitzenLocationSate()->getStateName() == "AtLeisureState");

        // Travel from leisure to home
        AtLeisureState leisureState;
        leisureState.travel(citizen);
        CHECK(citizen->getCitzenLocationSate()->getStateName() == "AtHomeState");


        delete citizen; delete residential; delete commercial; delete leisure;
    }
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
        MESSAGE(district.getEmploymentRate());
        // No manual deletion needed since District manages memory
    }

    SUBCASE("Count Citizens") {

        CityUnit* unit1 = new Residential();
        CityUnit* unit2 = new Residential();

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
}