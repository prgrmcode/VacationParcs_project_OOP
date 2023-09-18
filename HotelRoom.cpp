#include "HotelRoom.h"
#include <iostream>

//HotelRoom::HotelRoom() 
//    : Accommodations(int ID, int nrPeople, int size, bool bathroomWithBath, LuxuryLevel luxuryLevel), floor(0), nrBeds(0), childrenBed(false) {
//}

HotelRoom::HotelRoom(int ID, int nrPeople, int size, bool bathroomWithBath, LuxuryLevel luxuryLevel,
    int floor, const std::string& location, int nrBeds, bool childrenBed)
    : Accommodations(ID, nrPeople, size, bathroomWithBath, luxuryLevel),
    floor(floor), location(location), nrBeds(nrBeds), childrenBed(childrenBed) {}

std::string HotelRoom::getType() const
{
    return "HotelRoom";
}

void HotelRoom::displayDetails() const
{
    std::cout << "Accommodation Type: Hotel Room" << std::endl;
    // Display other details specific to HotelRoom
}

int HotelRoom::getFloor() const {
    return floor;
}

std::string HotelRoom::getLocation() const {
    return location;
}

int HotelRoom::getNrBeds() const {
    return nrBeds;
}

bool HotelRoom::getChildrenBed() const {
    return childrenBed;
}

void HotelRoom::setFloor(int newFloor) {
    floor = newFloor;
}

void HotelRoom::setLocation(const std::string& newLocation) {
    location = newLocation;
}

void HotelRoom::setNrBeds(int newNrBeds) {
    nrBeds = newNrBeds;
}

void HotelRoom::setChildrenBed(bool newChildrenBed) {
    childrenBed = newChildrenBed;
}
