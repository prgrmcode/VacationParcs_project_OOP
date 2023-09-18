#ifndef LUXURYLEVEL_H
#define LUXURYLEVEL_H

#include <string>

class LuxuryLevel {
private:
    bool BBQ;
    bool surroundSystem;
    bool breakfastService;
    bool cleaningService;
    std::string accommodationKind;

public:
    LuxuryLevel(); // Default constructor
    LuxuryLevel(bool BBQ, bool surroundSystem, bool breakfastService,
        bool cleaningService, const std::string& accommodationKind);

    // Getters
    bool getBBQ() const;
    bool getSurroundSystem() const;
    bool getBreakfastService() const;
    bool getCleaningService() const;
    std::string getAccommodationKind() const;

    // Setters
    void setBBQ(bool newBBQ);
    void setSurroundSystem(bool newSurroundSystem);
    void setBreakfastService(bool newBreakfastService);
    void setCleaningService(bool newCleaningService);
    void setAccommodationKind(const std::string& newAccommodationKind);
};

#endif // LUXURYLEVEL_H
