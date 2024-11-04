/**
 * @file Government.h
 * @brief Defines the Government class for creating a government.
 */


#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <map>
#include <vector>
#include <string>
#include "GovernmentCommand.h"
#include "CityUnit.h"
#include "Utility.h"

/**
 * @class Government
 * @brief Represents a government entity that manages resources and commands in a city.
 */
class Government {

private:
	int governmentBalance; /**< The balance of the government's funds. */
	std::map<std::string, int> resources; /**< The resources managed by the government. */
	std::vector<GovernmentCommand*> myCommand; /**< The commands issued by the government. */
	std::vector<CityUnit*> observerList; /**< The list of city units observing the government. */
	static constexpr int TAX_RATE = 1000; /**< The tax rate applied by the government. */
	std::map<std::string, double> utilities; /**< Utility types managed by the government */
	int averageHappiness; /**< Average happiness of citizens */


public:
	
	/**
	 * @brief Constructs a Government object with the specified initial balance.
	 * @param governmentBalance The initial balance of the government's funds.
	 */
	Government(int governmentBalance);

	/**
	 * @brief Gets the balance of the government's funds.
	 * @return The balance of the government's funds.
	 */
	int getGovernmentBalance();

	/**
	 * @brief Collects taxes from all citizens associated with residential buildings.
	 * This method uses the observer pattern to notify all citizens to pay their taxes.
	 */
	void collectTaxes();

	/**
	 * @brief Attaches a city unit as an observer to the government.
	 * @param myObserver The city unit to be attached as an observer.
	 */
	void attach(CityUnit* myObserver);

	/**
	 * @brief Detaches a city unit from being an observer of the government.
	 * @param myObserver The city unit to be detached as an observer.
	 */
	void detach(CityUnit* myObserver);

	/**
	 * @brief Notifies all observers about changes in the government.
	 */
	void notify();

	/**
	 * @brief Collects resources from various sources to be managed by the government.
	 */
	void collectResources();

	/**
	 * @brief Updates the usage of the utilities in the city.
	 */
	void updateUtilitiesUsage();

	/**
	 * @brief Gets the resources managed by the government.
	 * @return The resources managed by the government.
	 */
	std::map<std::string, int>& getResources() {return resources;}
	/**
	 * @brief Gets the utilities managed by the government.
	 * @return The utilities managed by the government.
	 */
	std::map<std::string, double>& getUtilities() {return utilities;}

	/**
	 * @brief Returns info to the front end on how busy each method of transportation is
	 */
	void evaluateTrafficConditions();

	/**
	 * @brief Returns info to the front end on the average happiness of all the citizens
	 */
	void evaluateHappiness();

/**
     * @brief Renders the city's visuals by updating the frontend with city unit representations.
     */
	void renderCity();

/**
     * @brief Executes the Better Education policy for all city units.
     */
	void executeEductation();

/**
     * @brief Executes the Short Work Week policy for all city units.
     */
	void executeShortWorkWeek();

/**
     * @brief Executes a new tax policy for all city units.
     * @param tax The tax rate to be set.
     */
	void executeNewTax(double tax);

 /**
     * @brief Executes resource spending commands for all city units.
     */
	void executeSpendResources();

/**
     * @brief Finds employment for residents in all city units.
     */
	void findEmployment();

	/**
	 * @brief Destructor for the Government class.
	 */
	~Government();
};
#endif