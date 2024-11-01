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

// TEST_CASE("Example Test")
// {
//     CHECK(1 == 1);
// }

// // Create mock CityUnits
// class MockCityUnit : public CityUnit {
// public:
//     // We can mock this distance method to return a value before cityunit is implemented
//     int calculateDistanceTo(CityUnit* other) override {
//         return 10; //don't worry lol
//     }

//     // Necessary Stubs so MockCityUnit is not an abstract class
//     void add(CityUnit* newUnit) {};
// 	void remove(CityUnit* unit) {};
// 	int getRemainingCapacity() {};
// 	int getUsedCapacity() {};
// 	void update() {};
// 	Iterator* createIterator() {};
// 	double getEmploymentRate() {};
//     int payTaxes(int amount) {};
// 	int evaluateHappiness() {};
// 	int countCitizens() {};
// };

// TEST_CASE("CitizenUnitTesting") {

//     CityUnit* residential = new MockCityUnit();
//     CityUnit* commercial = new MockCityUnit();
//     CityUnit* leisure = new MockCityUnit();

//     SUBCASE("Citizen with job is initialized correctly") {
//         Citizen citizen(residential, commercial, leisure);

//         CHECK(citizen.getHome() == residential);
//         CHECK(citizen.getJob() == commercial);
//         CHECK(citizen.getLeisure() == leisure);
//         CHECK(citizen.getJob() != nullptr); // Citizen is employed
//     }

//     SUBCASE("Citizen without job is initialized correctly") {
//         Citizen citizen(residential, nullptr, leisure);

//         CHECK(citizen.getHome() == residential);
//         CHECK(citizen.getJob() == nullptr); // Citizen is unemployed
//         CHECK(citizen.getLeisure() == leisure);
//     }

//     SUBCASE("Citizen without job is employed")
//     {
//         Citizen citizen(residential, nullptr, leisure);
//         CityUnit* mockJob = new MockCityUnit();

//         // Employ the citizen
//         CHECK(citizen.employCitizen(mockJob) == true);
//         CHECK(citizen.getJob() == mockJob);

//         // Attempt to employ again (should fail)
//         CHECK(citizen.employCitizen(mockJob) == false);
//         CHECK(citizen.getJob() == mockJob); // Job did not change

//         delete mockJob;
//     }

//     SUBCASE("Citizen member functions working as expected")
//     {
//         Citizen citizen(residential, commercial, leisure);  

//         // Satisfaction initialized in range [40, 70]
//         CHECK(citizen.getSatisfaction() >= 40);
//         CHECK(citizen.getSatisfaction() <= 70);
//         MESSAGE("Citizen satisfaction score: " << citizen.getSatisfaction());

//         // Bank balance initialized in range [20 000, 100 000]
//         CHECK(citizen.getBalance() >= 20000);
//         CHECK(citizen.getBalance() <= 100000);
//         MESSAGE("Citizen balance: " << citizen.getBalance());
//     }

//     SUBCASE("Routine affects satisfaction") {

//         Citizen citizen(residential, commercial, leisure);
//         MESSAGE("Citizen satisfaction before routine: " << citizen.getSatisfaction());  

//         int prevSatisfaction = citizen.getSatisfaction();
//         citizen.followRoutine();
//         int satisfactionDiff = prevSatisfaction - citizen.getSatisfaction();
//         CHECK(satisfactionDiff >= 0);    // Satisfaction should not increase at Work
//         CHECK(satisfactionDiff <= 10);   // Satisfaction should decrease by no more than 10
//         MESSAGE("Citizen satisfaction after followRoutine (AtHomeState => AtWorkState): " << citizen.getSatisfaction());

//         prevSatisfaction = citizen.getSatisfaction();
//         citizen.followRoutine();
//         satisfactionDiff = citizen.getSatisfaction() - prevSatisfaction;
//         CHECK(satisfactionDiff >= 0); // Satisfaction should increase at leisure
//         CHECK(satisfactionDiff <= 20); // Satisfaction should increase by no more than 20
//         MESSAGE("Citizen satisfaction after followRoutine (AtWorkState => AtLeisureState): " << citizen.getSatisfaction());

//         prevSatisfaction = citizen.getSatisfaction();
//         citizen.followRoutine();
//         satisfactionDiff = prevSatisfaction - citizen.getSatisfaction();
//         CHECK(satisfactionDiff >= -10); 
//         CHECK(satisfactionDiff <= 10); // Satisfaction should change at home
//         MESSAGE("Citizen satisfaction after followRoutine (AtLeisureState => AtHomeState): " << citizen.getSatisfaction());
        
//     }
    

//     delete residential;
//     delete commercial;
//     delete leisure;
// }

// TEST_CASE("CitizenLocationStateUnitTesting")
// {
//     SUBCASE("getStateName")
//     {
//         AtHomeState home;
//         AtWorkState work;
//         AtLeisureState leisure;

//         CHECK(home.getStateName() == "AtHomeState");
//         CHECK(work.getStateName() == "AtWorkState");
//         CHECK(leisure.getStateName() == "AtLeisureState");
//     }

//     SUBCASE("travelTesting")
//     {
//         // Create a citizen to use
//         CityUnit* residential = new MockCityUnit();
//         CityUnit* commercial = new MockCityUnit();
//         CityUnit* leisure = new MockCityUnit();

//         Citizen* citizen = new Citizen(residential, commercial, leisure);

//         // Travel from home to work
//         AtHomeState home;
//         home.travel(citizen);
//         CHECK(citizen->getCitzenLocationSate()->getStateName() == "AtWorkState");
        
//         // Travel from work to leisure
//         AtWorkState work;
//         work.travel(citizen);
//         CHECK(citizen->getCitzenLocationSate()->getStateName() == "AtLeisureState");

//         // Travel from leisure to home
//         AtLeisureState leisureState;
//         leisureState.travel(citizen);
//         CHECK(citizen->getCitzenLocationSate()->getStateName() == "AtHomeState");


//         delete citizen; delete residential; delete commercial; delete leisure;
//     }
// }

// TEST_CASE("TransportStrategyUnitTesting")
// {   
//     //create all four concrete strategies
//     CommuteStrategy* roadTest = new RoadStrategy();
//     CommuteStrategy* railTest = new RailwayStrategy();
//     CommuteStrategy* AirTest = new AirportStrategy();
//     CommuteStrategy* publicTest = new PublicTransportStrategy();

//     SUBCASE("returnStrategyNameTesting")
//     {
//         CHECK(roadTest->getTravelStrategyName() == "RoadStrategy");
//         CHECK(railTest->getTravelStrategyName() == "RailwayStrategy");
//         CHECK(AirTest->getTravelStrategyName() == "AirportStrategy");
//         CHECK(publicTest->getTravelStrategyName() == "PublicTransportStrategy");

//         MESSAGE("roadTest: " << roadTest->getTravelStrategyName());
//         MESSAGE("railTest: " << railTest->getTravelStrategyName());
//         MESSAGE("AirTest: " << AirTest->getTravelStrategyName());
//         MESSAGE("publicTest: " << publicTest->getTravelStrategyName());
//     }

//     SUBCASE("returnStrategyNameTesting")
//     {
//         CHECK(roadTest->handleCommuteState() == 8);
//         CHECK(railTest->handleCommuteState() == 10);
//         CHECK(AirTest->handleCommuteState() == 15);
//         CHECK(publicTest->handleCommuteState() == 4);

//     }

//     delete publicTest;
//     delete AirTest;
//     delete railTest;
//     delete roadTest;

//     //note these subcases can fail due to random factor 
//     SUBCASE("CorrectStrategyChosen")
//     {
//         AtHomeState home;
//         home.chooseStrategy(5);
//         CHECK(home.getTravelMethod() == "RoadStrategy");
//         home.chooseStrategy(10);
//         CHECK(home.getTravelMethod() == "PublicTransportStrategy");
//         home.chooseStrategy(15);
//         CHECK(home.getTravelMethod() == "RailwayStrategy");
//         home.chooseStrategy(30);
//         CHECK(home.getTravelMethod() == "AirportStrategy");
//     }
//     SUBCASE("RandomCommuteTesting")
//     {
//         //this is a very very small chance, hence the amount of times I test it
//         AtHomeState home;
//         for(int i = 0; i < 100; i++)
//         {
//             home.chooseStrategy(5);
//             MESSAGE("5: " << home.getTravelMethod());
//         }
//     }
// }



#include "Iterator.h"
#include "ConcreteIterator.h"

// Define a DummyCityUnit class for testing purposes
class DummyCityUnit : public CityUnit {
public:
    int id; // Unique identifier for testing

    // Constructor
    DummyCityUnit(int id_) : CityUnit(), id(id_) {}

    // Implement pure virtual functions with minimal behavior
    void add(CityUnit* newUnit) override {}

    void remove(CityUnit* unit) override {}

    int calculateDistanceTo(CityUnit* destination) override { return 0; }

    int getRemainingCapacity() override { return totalCapacity - usedCapacity; }

    int getUsedCapacity() override { return usedCapacity; }

    void update() override {}

    Iterator* createIterator() override { return nullptr; }

    double getEmploymentRate() override { return 0.0; }

    int payTaxes(int amount) override { return 0; }

    int evaluateHappiness() override { return 0; }

    int countCitizens() override { return resident.size(); }
};

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

// Test case: ConcreteIterator with a single element
TEST_CASE("ConcreteIterator with Single Element") {
    DummyCityUnit unit1(1);
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
    DummyCityUnit unit1(1);
    DummyCityUnit unit2(2);
    DummyCityUnit unit3(3);
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
    DummyCityUnit unit1(1);
    DummyCityUnit unit2(2);
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
    DummyCityUnit unit1(1);
    DummyCityUnit unit2(2);
    DummyCityUnit unit3(3);
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
    DummyCityUnit unit1(1);
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
    DummyCityUnit unit1(1);
    DummyCityUnit unit2(2);
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
