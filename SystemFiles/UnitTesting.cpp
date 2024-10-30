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
    // int payTaxes(int amount) override { return 0; }
    int evaluateHappiness() override { return 0; }
    int countCitizens() override { return 0; }

    // Implement the additional pure virtual methods
    void employResidents() override {}
    double setTaxRate(double amount) override { return amount; }
    double payTaxes(double rate) override { return 0.0; }
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
        home.chooseStrategy(10);
        CHECK(home.getTravelMethod() == "PublicTransportStrategy");
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
            MESSAGE("5: " << home.getTravelMethod());
        }
    }
}




// Mock Citizen class for testing
// Mock Citizen class for testing
// class MockCitizen : public Citizen {
// public:
//     MockCitizen() : Citizen(nullptr, nullptr, nullptr) {}
//     double getBalance() const override { return 100.0; }
//     bool employCitizen(Commercial* job) override { setJob(job); return true; }
// };

// // Mock Residential class for testing
// class MockResidential : public Residential {
// public:
//     void addMockResident(Citizen* citizen) { resident.push_back(citizen); }
//     double getEmploymentRate() const override { return 0.5; }
//     int evaluateHappiness() const override { return 80; }

//     // Implement pure virtual function from CityUnit
//     Iterator* createIterator() override { return nullptr; }  // Placeholder for testing
// };

// // Mock Commercial class for testing
// class MockCommercial : public Commercial {
// public:
//     double getEmploymentRate() const override { return 0.75; }
//     int evaluateHappiness() const override { return 70; }

//     // Implement pure virtual function from CityUnit
//     Iterator* createIterator() override { return nullptr; }  // Placeholder for testing
// };
// TEST_SUITE("District") {

//     TEST_CASE("Add and Remove Units") {
//         District district;
//         CityUnit* residential = new MockResidential();
//         CityUnit* commercial = new MockCommercial();

//         SUBCASE("Add units") {
//             CHECK_NOTHROW(district.add(residential));
//             CHECK_NOTHROW(district.add(commercial));
//         }

//         SUBCASE("Remove units") {
//             district.add(residential);
//             district.add(commercial);

//             CHECK_NOTHROW(district.remove(residential));
//             CHECK_THROWS_AS(district.remove(residential), const char*); // Removing already removed unit
//         }

//         delete residential;
//         delete commercial;
//     }

//     TEST_CASE("Update Units") {
//         District district;
//         CityUnit* residential = new MockResidential();
//         district.add(residential);
//         CHECK_NOTHROW(district.update());
//         delete residential;
//     }

//     TEST_CASE("Employ Residents") {
//         District district;
//         MockResidential* residential = new MockResidential();
//         MockCommercial* commercial = new MockCommercial();

//         district.add(residential);
//         district.add(commercial);

//         // Add unemployed citizens to residential
//         MockCitizen* citizen1 = new MockCitizen();
//         residential->addMockResident(citizen1);

//         SUBCASE("Employ resident") {
//             district.employResidents();
//             CHECK(citizen1->getJob() != nullptr);  // Ensure citizen got a job
//         }

//         delete citizen1;
//         delete residential;
//         delete commercial;
//     }

//     TEST_CASE("Calculate Employment Rate") {
//         District district;
//         MockCommercial* commercial1 = new MockCommercial();
//         MockCommercial* commercial2 = new MockCommercial();

//         district.add(commercial1);
//         district.add(commercial2);

//         CHECK(district.getEmploymentRate() == doctest::Approx(0.75));  // Average employment rate

//         delete commercial1;
//         delete commercial2;
//     }

//     TEST_CASE("Pay Taxes") {
//         District district;
//         MockResidential* residential = new MockResidential();
//         district.add(residential);

//         // Add citizens to residential
//         MockCitizen* citizen1 = new MockCitizen();
//         MockCitizen* citizen2 = new MockCitizen();
//         residential->addMockResident(citizen1);
//         residential->addMockResident(citizen2);

//         SUBCASE("Calculate total tax") {
//             double taxRate = 0.1;
//             CHECK(district.payTaxes(taxRate) == doctest::Approx(20.0));  // Each citizen pays 100 * 0.1 = 10, so 2 * 10 = 20
//         }

//         delete citizen1;
//         delete citizen2;
//         delete residential;
//     }

//     TEST_CASE("Evaluate Happiness") {
//         District district;
//         MockResidential* residential1 = new MockResidential();
//         MockCommercial* commercial1 = new MockCommercial();

//         residential1->setHappiness(80);
//         commercial1->setHappiness(70);

//         district.add(residential1);
//         district.add(commercial1);

//         CHECK(district.evaluateHappiness() == 75);  // Average happiness

//         delete residential1;
//         delete commercial1;
//     }

//     TEST_CASE("Count Citizens") {
//         District district;
//         MockResidential* residential = new MockResidential();
//         MockCitizen* citizen1 = new MockCitizen();
//         MockCitizen* citizen2 = new MockCitizen();

//         // Add citizens to residential
//         residential->addMockResident(citizen1);
//         residential->addMockResident(citizen2);

//         district.add(residential);

//         CHECK(district.countCitizens() == 2);  // Total count of residents

//         delete citizen1;
//         delete citizen2;
//         delete residential;
//     }
// }