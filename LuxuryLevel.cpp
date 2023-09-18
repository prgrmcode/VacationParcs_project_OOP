#include "LuxuryLevel.h"

LuxuryLevel::LuxuryLevel() {
    // Default constructor
}

LuxuryLevel::LuxuryLevel(bool BBQ, bool surroundSystem, bool breakfastService,
    bool cleaningService, const std::string& accommodationKind)
    : BBQ(BBQ), surroundSystem(surroundSystem), breakfastService(breakfastService),
    cleaningService(cleaningService), accommodationKind(accommodationKind) {
    // Constructor with parameters
}

// Getters
bool LuxuryLevel::getBBQ() const {
    return BBQ;
}

bool LuxuryLevel::getSurroundSystem() const {
    return surroundSystem;
}

bool LuxuryLevel::getBreakfastService() const {
    return breakfastService;
}

bool LuxuryLevel::getCleaningService() const {
    return cleaningService;
}

std::string LuxuryLevel::getAccommodationKind() const {
    return accommodationKind;
}

// Setters
void LuxuryLevel::setBBQ(bool newBBQ) {
    BBQ = newBBQ;
}

void LuxuryLevel::setSurroundSystem(bool newSurroundSystem) {
    surroundSystem = newSurroundSystem;
}

void LuxuryLevel::setBreakfastService(bool newBreakfastService) {
    breakfastService = newBreakfastService;
}

void LuxuryLevel::setCleaningService(bool newCleaningService) {
    cleaningService = newCleaningService;
}

void LuxuryLevel::setAccommodationKind(const std::string& newAccommodationKind) {
    accommodationKind = newAccommodationKind;
}
