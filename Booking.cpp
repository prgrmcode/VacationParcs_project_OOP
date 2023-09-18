#include "Booking.h"
#include "Customer.h"
#include <memory>
#include <sstream>    // Include for string manipulation



Booking::Booking() : ID(0), customer(*new Customer()), accommodations(std::vector<Accommodations*>()),
activityPass(false), sportsPass(false), bicycleRent(false), swimmingPass(false) {
	// Default constructor
}

Booking::Booking(int ID, Customer& customer, const std::vector<Accommodations*>& accommodations,
	bool activityPass, bool sportsPass, bool bicycleRent, bool swimmingPass)
	: ID(ID), customer(customer), accommodations(accommodations),
	activityPass(activityPass), sportsPass(sportsPass),
	bicycleRent(bicycleRent), swimmingPass(swimmingPass) {
	// Constructor with parameters
}

// Define the copy constructor for Booking
Booking::Booking(const Booking & other)
    : ID(other.ID), customer(other.customer), activityPass(other.activityPass),
    sportsPass(other.sportsPass), bicycleRent(other.bicycleRent),
    swimmingPass(other.swimmingPass) {
    for (const auto& acc : other.accommodations) {
        accommodations.push_back(acc); // Push back the raw pointer
    }
}

// Define the copy assignment operator for Booking
Booking& Booking::operator=(const Booking & other) {
    if (this != &other) {
        // Copy non-reference members
        ID = other.ID;
        accommodations.clear();
        for (const auto& acc : other.accommodations) {
            accommodations.push_back(acc); // Push back the raw pointer
        }
        activityPass = other.activityPass;
        sportsPass = other.sportsPass;
        bicycleRent = other.bicycleRent;
        swimmingPass = other.swimmingPass;

        // Copy the reference member using the existing reference
        customer = other.customer; // This will call the copy assignment operator of the Customer class
    }
    return *this;
}

//Booking::Booking(const Booking& other)
//	: ID(other.ID), customer(other.customer), activityPass(other.activityPass),
//	sportsPass(other.sportsPass), bicycleRent(other.bicycleRent),
//	swimmingPass(other.swimmingPass) {
//	for (const auto& acc : other.accommodations) {
//		accommodations.push_back(std::make_unique<Accommodations>(*acc));
//	}
//}

// Getters
int Booking::getID() const {
	return ID;
}

Customer Booking::getCustomer() const {
	return customer;
}

std::vector<Accommodations*> Booking::getAccommodations() const {
	return accommodations;
}

bool Booking::getActivityPass() const {
	return activityPass;
}

bool Booking::getSportsPass() const {
	return sportsPass;
}

bool Booking::getBicycleRent() const {
	return bicycleRent;
}

bool Booking::getSwimmingPass() const {
	return swimmingPass;
}

std::string Booking::getInfo() const {
    std::stringstream infoStream;

    infoStream << "Booking ID: " << ID << "\n";
    infoStream << "Customer Name: " << customer.getName() << "\n";

    infoStream << "Accommodations:\n";
    for (const Accommodations* accommodation : accommodations) {
        infoStream << " - Accommodation ID: " << accommodation->getID() << "\n";
        // Add other relevant accommodation details
    }

    infoStream << "Activity Pass: " << (activityPass ? "Yes" : "No") << "\n";
    infoStream << "Sports Pass: " << (sportsPass ? "Yes" : "No") << "\n";
    infoStream << "Bicycle Rent: " << (bicycleRent ? "Yes" : "No") << "\n";
    infoStream << "Swimming Pass: " << (swimmingPass ? "Yes" : "No") << "\n";

    return infoStream.str();
}

// Setters
void Booking::setID(int newID) {
	ID = newID;
}

void Booking::setCustomer(const Customer& newCustomer) {
	customer = newCustomer;
}

void Booking::setAccommodations(const std::vector<Accommodations*>& newAccommodations) {
	accommodations = newAccommodations;
}


void Booking::setActivityPass(bool newActivityPass) {
	activityPass = newActivityPass;
}

void Booking::setSportsPass(bool newSportsPass) {
	sportsPass = newSportsPass;
}

void Booking::setBicycleRent(bool newBicycleRent) {
	bicycleRent = newBicycleRent;
}

void Booking::setSwimmingPass(bool newSwimmingPass) {
	swimmingPass = newSwimmingPass;
}