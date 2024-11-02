#include "WebSocketNotifier.h"
#include "SimulationRunnerFacade.h"
#include "CityUnit.h"
#include "District.h"
#include "Residential.h"
#include "Commercial.h"
#include "Industrial.h"
#include "Landmark.h"
#include "Power.h"
#include "Water.h"
#include "Sewage.h"
#include "Waste.h"
#include "Government.h"
#include <iostream>
#include <bits/this_thread_sleep.h>

/**
 * @brief Implementation of the simulation loop
 *
 * @details This method runs the main simulation loop. During each iteration:
 * - Checks if the simulation should continue
 * - Creates a JSON messages
 * - Sends the messages through the WebSocketNotifier
 * - Waits a certain time before the next iteration
 *
 * The simulation continues until the stopFlag_ is set to true.
 *
 * @note This method blocks until the simulation is stopped
 *
 * @see WebSocketNotifier::log() for message transmission details
 */
void SimulationRunnerFacade::runSimulation()
{	

	// Create a basic starter city
	CityUnit* myCity = new District();
	myCity->add(new Residential(30, 30));
	myCity->add(new Commercial(20, 0));
	myCity->add(new Industrial(50, 0));
	myCity->add(new Landmark(30, 0));
	myCity->add(new Power(40, 0));
	myCity->add(new Water(20, 0));
	myCity->add(new Waste(40, 0));
	myCity->add(new Sewage(30, 0));

	Government myGov(20000);
	myGov.attach(myCity);

	while (!(*stopFlag_))
	{	
		// Core simulation loop logic
		nlohmann::json message = {
			{"type", "news"},
			{"data", "Simulation is running..."}};
		WebSocketNotifier::get_mutable_instance().log(message);

		// Update all city units 
		myGov.notify();

		// Collect taxes
		myGov.collectTaxes();

		// Collect resources
		myGov.collectResources();

		// Evaulate Traffic condtions
		myGov.evaluateTrafficConditions();

		// Evaluate Happiness of citizens
		myGov.evaluateHappiness();

		if (*EducationFlag_)
		{
			std::cout << "Education policy is set" << std::endl;
			std::cout << "Short Work Week policy is removed" << std::endl;
		}
		if (*ShortWorkFlag_)
		{
			std::cout << "Short Work Week policy is set" << std::endl;
			std::cout << "Education policy is removed" << std::endl;
		}
		if (*TaxFlag_)
		{
			std::cout << "Tax rate is set to " << taxRate_ << std::endl;
			*TaxFlag_ = false;
		}
		
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
}