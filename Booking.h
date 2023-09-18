#ifndef BOOKING_H
#define BOOKING_H

#include "Customer.h"
#include "Accommodations.h"
#include <vector>
#include <memory> // Include for smart pointers

class Customer; // Forward declaration of the Customer class

class Accommodations;

class Booking {
private:
	int ID;
	Customer& customer;
	//std::vector<std::shared_ptr<Accommodations>> accommodations;
	std::vector<Accommodations*> accommodations; // Use pointers to Accommodations
	bool activityPass;
	bool sportsPass;
	bool bicycleRent;
	bool swimmingPass;
	//Booking& operator=(const Booking& other) = delete; // Make it private or delete it

public:
	Booking(); // Default constructor
	Booking(int ID, Customer& customer, const std::vector<Accommodations*>& accommodations,
		bool activityPass, bool sportsPass, bool bicycleRent, bool swimmingPass);

	// Copy constructor
	Booking(const Booking& other);
	// Copy assignment operator
	Booking& operator=(const Booking& other);

	//Booking(const Booking& other);
	//Booking& operator=(const Booking& other) {
	//	if (this != &other) {
	//		// Copy non-reference members
	//		ID = other.ID;
	//		accommodations = other.accommodations;
	//		activityPass = other.activityPass;
	//		sportsPass = other.sportsPass;
	//		bicycleRent = other.bicycleRent;
	//		swimmingPass = other.swimmingPass;

	//		// Copy the reference member using the existing reference
	//		customer = other.customer; // This will call the copy assignment operator of the Customer class
	//	}
	//	return *this;
	//}

	// Getters
	int getID() const;
	Customer getCustomer() const;
	std::vector<Accommodations*> getAccommodations() const;
	bool getActivityPass() const;
	bool getSportsPass() const;
	bool getBicycleRent() const;
	bool getSwimmingPass() const;

	std::string getInfo() const;

	// Setters
	void setID(int newID);
	void setCustomer(const Customer& newCustomer);
	// Use smart pointers for setting accommodations
	//void setAccommodations(std::vector<std::unique_ptr<Accommodations>> newAccommodations);
	void setAccommodations(const std::vector<Accommodations*>& newAccommodations);
	void setActivityPass(bool newActivityPass);
	void setSportsPass(bool newSportsPass);
	void setBicycleRent(bool newBicycleRent);
	void setSwimmingPass(bool newSwimmingPass);	
};

#endif // BOOKING_H

