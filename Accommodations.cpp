#include "Accommodations.h"


Accommodations::Accommodations(int ID, int nrPeople, int size, bool bathroomWithBath, LuxuryLevel luxuryLevel)
    : ID(ID), nrPeople(nrPeople), size(size), bathroomWithBath(bathroomWithBath), luxuryLevel(luxuryLevel) {
    // Constructor with parameters
}

// Getters
int Accommodations::getID() const {
    return ID;
}

int Accommodations::getNrPeople() const {
    return nrPeople;
}

int Accommodations::getSize() const {
    return size;
}

bool Accommodations::getBathroomWithBath() const {
    return bathroomWithBath;
}

LuxuryLevel Accommodations::getLuxuryLevel() const {
    return luxuryLevel;
}

std::string Accommodations::getInfo() const {
    std::string info = std::to_string(ID) + "," +
        std::to_string(nrPeople) + "," +
        std::to_string(size) + "," +
        (bathroomWithBath ? "1" : "0") + "," +
        std::to_string(static_cast<int>(luxuryLevel.getBBQ())) + "," +
        std::to_string(static_cast<int>(luxuryLevel.getSurroundSystem())) + "," +
        std::to_string(static_cast<int>(luxuryLevel.getBreakfastService())) + "," +
        std::to_string(static_cast<int>(luxuryLevel.getCleaningService())) + "," +
        luxuryLevel.getAccommodationKind();
    return info;
}

// Setters
void Accommodations::setID(int newID) {
    ID = newID;
}

void Accommodations::setNrPeople(int newNrPeople) {
    nrPeople = newNrPeople;
}

void Accommodations::setSize(int newSize) {
    size = newSize;
}

void Accommodations::setBathroomWithBath(bool newBathroomWithBath) {
    bathroomWithBath = newBathroomWithBath;
}

void Accommodations::setLuxuryLevel(LuxuryLevel newLuxuryLevel) {
    luxuryLevel = newLuxuryLevel;
}
