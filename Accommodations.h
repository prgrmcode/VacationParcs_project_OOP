#ifndef ACCOMMODATIONS_H
#define ACCOMMODATIONS_H

// enum LuxuryLevel { Comfort, Premium, VIP }; // Enum for luxury levels
#include "LuxuryLevel.h"
#include <string>


class Accommodations {
private:
    int ID;
    int nrPeople;
    int size;
    bool bathroomWithBath;
    LuxuryLevel luxuryLevel;

public:
    Accommodations(int ID, int nrPeople, int size, bool bathroomWithBath, LuxuryLevel luxuryLevel);
    virtual ~Accommodations() = default; // Virtual destructor for proper polymorphic behavior

    // Abstract methods for getting accommodation-specific details
    virtual std::string getType() const = 0; // Return the type of accommodation (HotelRoom or Bungalow)
    virtual void displayDetails() const = 0; // Display details specific to each type

    // Getters
    int getID() const;
    int getNrPeople() const;
    int getSize() const;
    bool getBathroomWithBath() const;
    LuxuryLevel getLuxuryLevel() const;

    std::string getInfo() const;

    // Setters
    void setID(int newID);
    void setNrPeople(int newNrPeople);
    void setSize(int newSize);
    void setBathroomWithBath(bool newBathroomWithBath);
    void setLuxuryLevel(LuxuryLevel newLuxuryLevel);
};

#endif // ACCOMMODATIONS_H
