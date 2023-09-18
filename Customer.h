#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Parcs.h"
#include "Booking.h" // Include the Booking class header
#include "Accommodations.h"
using namespace std;

// Forward declaration of Booking and Accommodations classes
class Booking;
class Accommodations;

class Customer {
private:
	std::string name;
	std::string address;
	std::string mail;

	std::vector<Booking*> bookings;

public:
	Customer(); // default constructor
	Customer(const std::string& name, const string& address, const string& mail);

	//// Copy assignment operator for Customer
	//Customer& operator=(const Customer& other) {
	//	if (this != &other) {
	//		// Copy members appropriately
	//		name = other.name;
	//		address = other.address;
	//		mail = other.mail;
	//		// You can add more member assignments if needed
	//	}
	//	return *this;
	//}

	// Getters
	string getName() const;
	string getAddress() const;
	string getMail() const;

	std::string getInfo() const; // Add this member function
	void addBooking(Booking* booking); // Add this member function

	// Setters
	void setName(const string& name);
	void setAddress(const string& address);
	void setMail(const string& mail);

	// Customer-specific functionalities
	static void registerCustomer(std::vector<Customer>& customers);
	void modifyCustomerData(Customer& customer);
	void bookAccommodation(std::vector<Booking>& bookings, const std::vector<Accommodations*>& accommodations,
		const Parcs& selectedPark);
	void modifyBooking(std::vector<Booking>& bookings);
};

#endif // CUSTOMER_H

