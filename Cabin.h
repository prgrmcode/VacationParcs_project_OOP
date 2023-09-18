#ifndef CABIN_H
#define CABIN_H

#include "Accommodations.h"

class Cabin : public Accommodations {
private:
    int bedrooms;

public:
    //Cabin(); // Default constructor
    Cabin(int ID, int nrPeople, int size, bool bathroomWithBath, LuxuryLevel luxuryLevel, int bedrooms);

    // Implement the pure virtual functions
    std::string getType() const override;
    void displayDetails() const override;

    // Getter
    int getBedrooms() const;

    // Setter
    void setBedrooms(int newBedrooms);
};

#endif // CABIN_H
