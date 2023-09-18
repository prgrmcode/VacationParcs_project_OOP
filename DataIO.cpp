// DataIO.cpp
#include "DataIO.h"
#include "Booking.h"
#include <fstream>
#include <memory> // Include this for shared_ptr
#include <iostream>
#include <sstream>

void DataIO::saveAccommodationsToFile(const std::vector<Accommodations*>& accommodations, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const Accommodations* acc : accommodations) {
        outFile << acc->getInfo() << "\n";
    }

    outFile.close();
}

void DataIO::loadAccommodationsFromFile(std::vector<Accommodations*>& accommodations, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
        return;
    }

    accommodations.clear();

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int ID, nrPeople, size;
        bool bathroomWithBath;
        int BBQ, surroundSystem, breakfastService, cleaningService;
        std::string accommodationKind;

        if (iss >> ID >> nrPeople >> size >> bathroomWithBath >> BBQ >> surroundSystem >> breakfastService >> cleaningService >> accommodationKind) {
            LuxuryLevel luxuryLevel(static_cast<bool>(BBQ), static_cast<bool>(surroundSystem),
                static_cast<bool>(breakfastService), static_cast<bool>(cleaningService),
                accommodationKind);
            // Construct the appropriate derived class instance
            if (accommodationKind == "HotelRoom") {
                int floor, nrBeds;
                bool childrenBed;
                // Read floor, nrBeds, childrenBed from the input stream
                iss >> floor >> nrBeds >> childrenBed;
                accommodations.emplace_back(new HotelRoom(ID, nrPeople, size, bathroomWithBath, luxuryLevel, floor, "", nrBeds, childrenBed));
            }
            else if (accommodationKind == "Cabin") {
                int bedrooms;
                // Read bedrooms from the input stream
                iss >> bedrooms;
                accommodations.emplace_back(new Cabin(ID, nrPeople, size, bathroomWithBath, luxuryLevel, bedrooms));
            }
        }
    }

    inFile.close();
}


void DataIO::saveCustomersToFile(const std::vector<Customer>& customers, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const Customer& customer : customers) {
        outFile << customer.getInfo() << "\n"; 
    }

    outFile.close();
}

void DataIO::loadCustomersFromFile(std::vector<Customer>& customers, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
        return;
    }

    customers.clear();

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << filename << std::endl;
        std::istringstream iss(line);
        std::string name, address, mail;
        // Read data using getline or other methods
        std::getline(iss, name);
        std::getline(iss, address);
        std::getline(iss, mail);

        Customer newCustomer(name, address, mail);

        customers.push_back(newCustomer);

        //if (std::getline(iss, name) && std::getline(iss, address) && std::getline(iss, mail)) {
        //    // Create a new customer using the parsed data
        //    Customer newCustomer(name, address, mail);

        //    // Load booking information for the current customer
        //    //std::string bookingLine;
        //    //while (std::getline(inFile, bookingLine) && !bookingLine.empty()) {
        //    //    std::istringstream bookingIss(bookingLine);
        //    //    int bookingID, accommodationIndex;
        //    //    bool activityPass, sportsPass, bicycleRent, swimmingPass;

        //    //    // Parse booking information from the line
        //    //    if (bookingIss >> bookingID >> accommodationIndex >> activityPass >> sportsPass >> bicycleRent >> swimmingPass) {
        //    //        // Now, get the accommodation pointer based on the index
        //    //        if (accommodationIndex >= 0 && accommodationIndex < accommodations.size()) {
        //    //            Accommodations* accommodationPtr = accommodations[accommodationIndex];

        //    //            // Create the Booking object using the constructor
        //    //            Booking* newBooking = new Booking(bookingID, newCustomer, accommodationPtr,
        //    //                activityPass, sportsPass, bicycleRent, swimmingPass);

        //    //            // Add the Booking object to the customer's bookings
        //    //            newCustomer.addBooking(newBooking);
        //    //        }
        //    //    }
        //    //}

        //    // (parsing and adding bookings based on your file format)
        //    customers.push_back(newCustomer);
        //    std::cout << "Customers loaded from the file!" << std::endl;
        //} else
        //    std::cerr << "Failed to load customer data from file: " << filename << std::endl;

    }

    inFile.close();
}


void DataIO::saveBookingsToFile(const std::vector<Booking>& bookings, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open file for writing: " << filename << std::endl;
        return;
    }

    for (const Booking& booking : bookings) {
        outFile << booking.getInfo() << "\n"; 
    }

    outFile.close();
}


void DataIO::loadBookingsFromFile(std::vector<Booking>& bookings, const std::vector<Customer>& customers, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Failed to open file for reading: " << filename << std::endl;
        return;
    }

    bookings.clear();

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        int bookingID;
        std::string customerName;
        // Read other attributes as needed

        if (iss >> bookingID >> customerName) {
            // Find the corresponding customer object by name
            const Customer* foundCustomer = nullptr;
            for (const Customer& customer : customers) {
                if (customer.getName() == customerName) {
                    foundCustomer = &customer;
                    break;
                }
            }

            if (foundCustomer) {
                Booking newBooking;
                newBooking.setID(bookingID);
                newBooking.setCustomer(*foundCustomer); // Pass by const reference
                // Set other booking attributes as needed

                bookings.push_back(newBooking);
            }
            else {
                std::cerr << "Customer not found for booking: " << line << std::endl;
            }
        }
    }

    inFile.close();
}