#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Citizen.h"
#include "CitizenLocationState.h"
#include "CityUnit.h"
#include "AtHomeState.h"
#include "AtWorkState.h"
#include "AtLeisureState.h"

TEST_CASE("Example Test")
{
    CHECK(1 == 1);
}

TEST_CASE("CitizenUnitTesting") {

    // Create mock CityUnits
    class MockCityUnit : public CityUnit {
    public:
        // We can mock this distance method to return a constant value
        int calculateDistanceTo(CityUnit* other) override {
            return 10;  // Arbitrary fixed distance for testing
        }

        // Necessary Stubs so MockCityUnit is not an abstract class
        void add(CityUnit* newUnit) {};
	    void remove(CityUnit* unit) {};
	    int getRemainingCapacity() {};
	    int getUsedCapacity() {};
	    void update() {};
	    Iterator* createIterator() {};
	    double getEmploymentRate() {};
        int payTaxes(int amount) {};
	    int evaluateHappiness() {};
	    int countCitizens() {};
    };

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
