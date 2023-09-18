#ifndef PARCS_H
#define PARCS_H

#include <string>
#include <vector>
#include "ParcServices.h"
#include "Accommodations.h"

using namespace std;

class Parcs {
private:
	string name;
	string address;
	ParcServices services;
	vector<Accommodations*> accommodations; // Use pointers to the base class

public:
	Parcs(); // Default constructor
	Parcs(const string& name, const string& address, const ParcServices& services,
		const vector<Accommodations*>& accommodations);

	// Function to save parcs data to a file
	static void saveParcsToFile(const std::vector<Parcs>& parcs, const std::string& filename);

	// Function to load parcs data from a file
	static void loadParcsFromFile(std::vector<Parcs>& parcs, const std::string& filename);

	// Getters
	string getName() const;
	string getAddress() const;
	ParcServices getServices() const;
	//vector<Accommodations> getAccommodations() const;

	// Setters
	void setName(const string& name);
	void setAddress(const string& address);
	void setServices(const ParcServices& services);
	//void setAccommodations(const vector<Accommodations>& accommodations);

	// Add methods to manage accommodations
	void addAccommodation(Accommodations* newAccommodation);
	void modifyAccommodation(int index, Accommodations* updatedAccommodation);
	void deleteAccommodation(int index);

	// Getter and setter methods for accommodations
	const std::vector<Accommodations*>& getAccommodations() const;
	void setAccommodations(const std::vector<Accommodations*>& newAccommodations);

};

#endif // PARCS_H

