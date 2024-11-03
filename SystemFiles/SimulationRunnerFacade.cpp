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
	CityUnit *myCity = new District();
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

	// Core simulation loop logic
	nlohmann::json message = {
		{"type", "news"},
		{"data", "Basic Starter city created, lets build!"}};
	WebSocketNotifier::get_mutable_instance().log(message);

	while (!(*stopFlag_))
	{	
		// Employ Citizens
		myGov.findEmployment();
		std::cout << "EMPLOYMENT RATE: " << myCity->getEmploymentRate() << std::endl;
		// Render city
		std::cout << "Called renderCity()\n";
		myGov.renderCity();
		std::cout << "render city done\n";

		std::this_thread::sleep_for(std::chrono::seconds(1));
		// Update all city units
		myGov.notify();

		// Collect taxes
		myGov.collectTaxes();
		message = {
			{"type", "news"},
			{"data", "Collected taxes from city!"}};
		WebSocketNotifier::get_mutable_instance().log(message);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		// Collect resources
		myGov.collectResources();
		message = {
			{"type", "news"},
			{"data", "Collected resources from industrial buildings!"}};
		WebSocketNotifier::get_mutable_instance().log(message);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		myGov.updateUtilitiesUsage();
		message = {
			{"type", "news"},
			{"data", "Updated Utilities usage"}};
		std::this_thread::sleep_for(std::chrono::seconds(1));


		// Evaulate Traffic condtions
		myGov.evaluateTrafficConditions();
		message = {
			{"type", "news"},
			{"data", "Traffic conditions evaluated!"}};
		WebSocketNotifier::get_mutable_instance().log(message);
		std::this_thread::sleep_for(std::chrono::seconds(1));

		// Evaluate Happiness of citizens
		myGov.evaluateHappiness();
		message = {
			{"type", "news"},
			{"data", "City happiness evaluated!"}};
		WebSocketNotifier::get_mutable_instance().log(message);

		myGov.executeSpendResources();

		if (*EducationFlag_)
		{
			myGov.executeEductation();
			message = {
			{"type", "news"},
			{"data", "Education Policy is active"}};
			WebSocketNotifier::get_mutable_instance().log(message);
		}
		if (*ShortWorkFlag_)
		{
			myGov.executeShortWorkWeek();
			message = {
			{"type", "news"},
			{"data", "Short Work Week Policy is active"}};
			WebSocketNotifier::get_mutable_instance().log(message);
		}
		if (*TaxFlag_)
		{
			double taxRateDouble = static_cast<double>(taxRate_);
			myGov.executeNewTax(taxRateDouble/100);
			message = {
                {"type", "news"},
                {"data", "Tax rate updated"}};
            WebSocketNotifier::get_mutable_instance().log(message);
			*TaxFlag_ = false;
		}
	}
	delete myCity;
}