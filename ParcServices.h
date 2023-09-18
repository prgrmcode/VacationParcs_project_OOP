#ifndef PARCSERVICES_H
#define PARCSERVICES_H

class ParcServices {
private:
    bool subtropicSwimmingPool;
    bool sportsInfrastructure;
    bool bowlingAlley;
    bool bicycleRent;
    bool childrensParadise;
    bool waterBikes;

public:
    ParcServices(); // Default constructor
    ParcServices(bool subtropicSwimmingPool, bool sportsInfrastructure, bool bowlingAlley,
        bool bicycleRent, bool childrensParadise, bool waterBikes);

    // Getters
    bool getSubtropicSwimmingPool() const;
    bool getSportsInfrastructure() const;
    bool getBowlingAlley() const;
    bool getBicycleRent() const;
    bool getChildrensParadise() const;
    bool getWaterBikes() const;

    // Setters
    void setSubtropicSwimmingPool(bool newSubtropicSwimmingPool);
    void setSportsInfrastructure(bool newSportsInfrastructure);
    void setBowlingAlley(bool newBowlingAlley);
    void setBicycleRent(bool newBicycleRent);
    void setChildrensParadise(bool newChildrensParadise);
    void setWaterBikes(bool newWaterBikes);
};

#endif // PARCSERVICES_H
