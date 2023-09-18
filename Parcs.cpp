#include "Parcs.h"
#include <fstream>
#include <iostream>
#include <sstream>

// Make sure that when you create a Parcs object, you pass a vector of pointers to Accommodations objects.
// std::vector<Accommodations*> accommodationsList;
// Populate accommodationsList with pointers to Accommodations objects
// Parcs parc("Park Name", "Park Address", parcServicesObject, accommodationsList);


Parcs::Parcs() {
	// Default constructor
}

Parcs::Parcs(const string& name, const string& address, const ParcServices& services,
	const vector<Accommodations*>& accommodations)
	: name(name), address(address), services(services), accommodations(accommodations) {
	// Constructor with parameters
}

void Parcs::saveParcsToFile(const std::vector<Parcs>& parcs, const std::string& filename) {
	std::ofstream outFile(filename);
	if (!outFile) {
		std::cerr << "Error opening file for writing: " << filename << std::endl;
		return;
	}

	for (const Parcs& parc : parcs) {
		outFile << parc.getName() << "," << parc.getAddress() << "," /* other data */ << std::endl;
	}

	outFile.close();
}

void Parcs::loadParcsFromFile(std::vector<Parcs>& parcs, const std::string& filename) {
	std::ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "Error opening file for reading: " << filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		std::istringstream iss(line);
		std::string name, address;
		// Read data using getline or other methods
		std::getline(iss, name, ',');
		std::getline(iss, address, ',');
		// Create Parcs object and add it to the vector
		Parcs newParc(name, address, ParcServices(/* initialize with appropriate data */), std::vector<Accommodations*>());
		parcs.push_back(newParc);
	}

	inFile.close();

	// Call these functions at the beginning of your program to load the data from files into your data structures.
	//// Example of loading data
	//loadParcsFromFile(allParcs, "parcs.txt");
	//loadAccommodationsFromFile(allAccommodations, "accommodations.txt");
	//loadCustomersFromFile(allCustomers, "customers.txt");
	//loadBookingsFromFile(allBookings, "bookings.txt");
}



// Getters
string Parcs::getName() const {
	return name;
}

string Parcs::getAddress() const {
	return address;
}

ParcServices Parcs::getServices() const {
	return services;
}

//vector<Accommodations> Parcs::getAccommodations() const {
//	return accommodations;
//}

// Setters
void Parcs::setName(const string& newName) {
	name = newName;
}

void Parcs::setAddress(const string& newAddress) {
	address = newAddress;
}

void Parcs::setServices(const ParcServices& newServices) {
	services = newServices;
}

//void Parcs::setAccommodations(const vector<Accommodations>& newAccommodations) {
//	accommodations = newAccommodations;
//}



// Implement methods to manage accommodations
void Parcs::addAccommodation(Accommodations* newAccommodation) {
	accommodations.push_back(newAccommodation);
}

void Parcs::modifyAccommodation(int index, Accommodations* updatedAccommodation) {
	if (index >= 0 && index < accommodations.size()) {
		delete accommodations[index];
		accommodations[index] = updatedAccommodation;
	}
}

void Parcs::deleteAccommodation(int index) {
	if (index >= 0 && index < accommodations.size()) {
		delete accommodations[index];
		accommodations.erase(accommodations.begin() + index);
	}
}

// Implement getter and setter methods for accommodations
const std::vector<Accommodations*>& Parcs::getAccommodations() const {
	return accommodations;
}

void Parcs::setAccommodations(const std::vector<Accommodations*>& newAccommodations) {
	// Clear existing accommodations and copy the new ones
	for (Accommodations* accommodation : accommodations) {
		delete accommodation;
	}
	accommodations.clear();

	for (Accommodations* newAccommodation : newAccommodations) {
		accommodations.push_back(newAccommodation);
	}
}