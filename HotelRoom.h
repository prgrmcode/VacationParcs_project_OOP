#ifndef HOTELROOM_H
#define HOTELROOM_H

#include "Accommodations.h"

class HotelRoom : public Accommodations {
private:
    int floor;
    std::string location;
    int nrBeds;
    bool childrenBed;

public:
    //HotelRoom(); // Default constructor
    HotelRoom(int ID, int nrPeople, int size, bool bathroomWithBath, LuxuryLevel luxuryLevel,
        int floor, const std::string& location, int nrBeds, bool childrenBed);
    
    std::string getType() const override;
    void displayDetails() const override;

    // Getters for HotelRoom-specific attributes
    int getFloor() const;
    std::string getLocation() const;
    int getNrBeds() const;
    bool getChildrenBed() const;

    // Setters for HotelRoom-specific attributes
    void setFloor(int newFloor);
    void setLocation(const std::string& newLocation);
    void setNrBeds(int newNrBeds);
    void setChildrenBed(bool hasChildrenBed);
};

#endif // HOTELROOM_H
