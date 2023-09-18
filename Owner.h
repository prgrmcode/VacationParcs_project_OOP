#ifndef OWNER_H
#define OWNER_H

#include <iostream>
#include <string>
#include <vector> // Include the necessary header for using std::vector
#include "Parcs.h" // Include the Parc class header
#include "Accommodations.h" // Include the Accommodation class header
#include "HotelRoom.h"

// Forward declaration of HotelRoom class (if not already present)
class HotelRoom;

class Owner {
private:
    std::string name;
    std::string role;
    std::vector<Parcs> parks; // Vector to store parks
    // Create a vector to store accommodations (you can add accommodations later)
    std::vector<Accommodations*> accommodations;
public:
    Owner(const std::string& name, const std::string& role); // Constructor declaration

    void createPark(std::vector<Parcs>& parks);
    void modifyPark(std::vector<Parcs>& parks);
    void deletePark(std::vector<Parcs>& parks);
    Parcs selectPark(std::vector<Parcs>& parks);

    void createAccommodation(std::vector<Parcs>& parks, std::vector<Accommodations*>& accommodations);
    void modifyAccommodation(std::vector<Parcs>& parks/*, std::vector<Accommodations*>& accommodations*/);
    void deleteAccommodation(std::vector<Parcs>& parks/*, std::vector<Accommodations*>& accommodations*/);
    // Add other owner-specific methods as needed
};

#endif // OWNER_H
