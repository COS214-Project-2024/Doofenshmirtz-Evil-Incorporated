#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include "Citizen.h"
#include "CitizenLocationState.h"
#include "Residential.h"
#include "Commercial.h"

TEST_CASE("Example Test")
{
    CHECK(1 == 1);
}

/*
TEST_CASE("CitizenUnitTest")
{

    SUBCASE("Citizen Constructor Initializes correctly")
    {
        Residential* homeUnit;
        Commercial* jobUnit;

        // Initialize citizen with home and job
        Citizen citizen(homeUnit, jobUnit);

        // Check if citizen's home and job are correctly assigned
        CHECK(citizen.getHome() == &homeUnit);
        CHECK(citizen.getJob() == &jobUnit);
        CHECK(citizen.isEmployed() == true);

        // Ensure the initial state is AtHomeState
        CHECK(dynamic_cast<AtHomeState*>(citizen.getLocationState()) != nullptr);
    }

    SUBCASE("Citizen travelTo updates location state to CommuteState") 
    {
        // Assuming ResidentialUnit is a subclass of CityUnit
        Residential* homeUnit;
        Commercial* destinationUnit;

        // Create citizen with home but no job (unemployed)
        Citizen citizen(homeUnit, nullptr);

        // Make citizen travel to a new destination
        citizen.travelTo(destinationUnit);

        // Ensure the location state has been updated to CommuteState
        CHECK(dynamic_cast<CommuteState*>(citizen.getLocationState()) != nullptr);
    }
}
*/
