#include "Cabin.h"
#include <iostream>

Cabin::Cabin(int ID, int nrPeople, int size, bool bathroomWithBath, LuxuryLevel luxuryLevel, int bedrooms)
    : Accommodations(ID, nrPeople, size, bathroomWithBath, luxuryLevel), bedrooms(bedrooms) {}

std::string Cabin::getType() const {
    return "Bungalow Cabin";
}

void Cabin::displayDetails() const {
    std::cout << "Accommodation Type: Bungalow Cabin" << std::endl;
    // Display other details specific to Bungalow
}

// Getter
int Cabin::getBedrooms() const {
    return bedrooms;
}

// Setter
void Cabin::setBedrooms(int newBedrooms) {
    bedrooms = newBedrooms;
}
