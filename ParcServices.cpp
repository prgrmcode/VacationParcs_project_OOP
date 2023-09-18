#include "ParcServices.h"

ParcServices::ParcServices() {
    // Default constructor
}

ParcServices::ParcServices(bool subtropicSwimmingPool, bool sportsInfrastructure, bool bowlingAlley,
                           bool bicycleRent, bool childrensParadise, bool waterBikes)
    : subtropicSwimmingPool(subtropicSwimmingPool), sportsInfrastructure(sportsInfrastructure),
      bowlingAlley(bowlingAlley), bicycleRent(bicycleRent),
      childrensParadise(childrensParadise), waterBikes(waterBikes) {
    // Constructor with parameters
}

// Getters
bool ParcServices::getSubtropicSwimmingPool() const {
    return subtropicSwimmingPool;
}

bool ParcServices::getSportsInfrastructure() const {
    return sportsInfrastructure;
}

bool ParcServices::getBowlingAlley() const {
    return bowlingAlley;
}

bool ParcServices::getBicycleRent() const {
    return bicycleRent;
}

bool ParcServices::getChildrensParadise() const {
    return childrensParadise;
}

bool ParcServices::getWaterBikes() const {
    return waterBikes;
}

// Setters
void ParcServices::setSubtropicSwimmingPool(bool newSubtropicSwimmingPool) {
    subtropicSwimmingPool = newSubtropicSwimmingPool;
}

void ParcServices::setSportsInfrastructure(bool newSportsInfrastructure) {
    sportsInfrastructure = newSportsInfrastructure;
}

void ParcServices::setBowlingAlley(bool newBowlingAlley) {
    bowlingAlley = newBowlingAlley;
}

void ParcServices::setBicycleRent(bool newBicycleRent) {
    bicycleRent = newBicycleRent;
}

void ParcServices::setChildrensParadise(bool newChildrensParadise) {
    childrensParadise = newChildrensParadise;
}

void ParcServices::setWaterBikes(bool newWaterBikes) {
    waterBikes = newWaterBikes;
}
