#include "VacationParcs.h"

VacationParcs::VacationParcs() {
	// def constructor
}

VacationParcs::VacationParcs(const std::string& name, const std::string& address, const std::string& VAT)
	: name(name), address(address), VAT(VAT) {
	// constructor with params
}

// Getters
std::string VacationParcs::getName() const {
	return name;
}

std::string VacationParcs::getAddress() const {
	return address;
}

std::string VacationParcs::getVAT() const {
	return VAT;
}

std::vector<Parcs> VacationParcs::getParcs() const {
	return parcs;
}

std::vector<Customer> VacationParcs::getCustomers() const {
	return customers;
}

// Setters
void VacationParcs::setName(const std::string& newName) {
	name = newName;
}

void VacationParcs::setAddress(const std::string& newAddress) {
	address = newAddress;
}

void VacationParcs::setVAT(const std::string& newVAT) {
	VAT = newVAT;
}

void VacationParcs::setParcs(const std::vector<Parcs>& newParcs) {
	parcs = newParcs;
}

void VacationParcs::setCustomers(const std::vector<Customer>& newCustomers) {
	customers = newCustomers;
}
