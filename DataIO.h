#pragma once
#include <vector>
#include <string>
#include "Accommodations.h" 
#include "Customer.h" 
#include "Booking.h" 
#include "HotelRoom.h"
#include "Cabin.h"

class DataIO {
public:
    static void saveAccommodationsToFile(const std::vector<Accommodations*>& accommodations, const std::string& filename);
    static void saveCustomersToFile(const std::vector<Customer>& customers, const std::string& filename);
    static void saveBookingsToFile(const std::vector<Booking>& bookings, const std::string& filename);
    // Similar functions for loading data
    static void loadAccommodationsFromFile(std::vector<Accommodations*>& accommodations, const std::string& filename);
    static void loadCustomersFromFile(std::vector<Customer>& customers, const std::string& filename);
    static void loadBookingsFromFile(std::vector<Booking>& bookings, const std::vector<Customer>& customers, const std::string& filename);
};
