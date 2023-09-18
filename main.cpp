#include "main.h"
// This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
// #include "VacationParcs.h"
#include "Parcs.h"
#include "Owner.h"
#include "Employee.h"
#include "DataIO.h"
#include "HotelRoom.h"
#include "Cabin.h"

// Function prototypes
void ownerMenu(Owner& owner, std::vector<Parcs>& parks, std::vector<Accommodations*>& accommodations);
void employeeMenu(Employee& employee, std::vector<Accommodations*>& accommodations, std::vector<Customer>& customers, std::vector<Booking>& bookings);
void customerMenu(Customer& customer, std::vector<Accommodations*>& accommodations, std::vector<Booking>& bookings, Parcs& selectedPark);


// Function to save all data
void saveAllData(const std::vector<Parcs>& parcs,
    const std::vector<Accommodations*>& accommodations,
    const std::vector<Customer>& customers,
    const std::vector<Booking>& bookings) {
    Parcs::saveParcsToFile(parcs, "parcs.txt");
    DataIO::saveAccommodationsToFile(accommodations, "accommodations.txt");
    DataIO::saveCustomersToFile(customers, "customers.txt");
    DataIO::saveBookingsToFile(bookings, "bookings.txt");
    // Similar calls for other data types
}

// Function to load all data
void loadAllData(std::vector<Parcs>& parcs,
    std::vector<Accommodations*>& accommodations,
    std::vector<Customer>& customers,
    std::vector<Booking>& bookings) {
    Parcs::loadParcsFromFile(parcs, "parcs.txt");
    DataIO::loadAccommodationsFromFile(accommodations, "accommodations.txt");
    DataIO::loadCustomersFromFile(customers, "customers.txt");
    DataIO::loadBookingsFromFile(bookings, customers, "bookings.txt");        
    // Similar calls for other data types
}

int main()
{
    // Initialize data
    //std::vector<Parcs> allParks;

    // Create instances for owner, employee, and customer
    Owner owner("OwnerName", "Owner");
    Employee employee("EmployeeName", "Employee");
    Customer customer("CustomerName", "Address", "Email");

    //// Create instances of derived classes with LuxuryLevel
    //LuxuryLevel luxuryLevelHotel(true, true, true, true, "HotelRoom");
    //HotelRoom hotelRoomInstance(1, 2, 30, true, luxuryLevelHotel,
    //    3, "Second floor", 1, true);

    //LuxuryLevel luxuryLevelCabin(true, false, false, true, "Cabin");
    //Cabin cabinInstance(2, 4, 60, true, luxuryLevelCabin, 2);



    Parcs selectedPark; // Declare the selectedPark variable

    // Create vectors to store data
    std::vector<Parcs> parks;
    //std::vector<Accommodations> accommodations;
    std::vector<Customer> customers;
    std::vector<Booking> bookings;
    std::vector<Accommodations*> accommodationsPtr;
    // Populate the accommodationsPtr vector with pointers to Accommodations objects

    //// Add the derived class instances to the vector
    //accommodationsPtr.push_back(&hotelRoomInstance);
    //accommodationsPtr.push_back(&cabinInstance);

    // Load data from files
    loadAllData(parks, accommodationsPtr, customers, bookings);
    // Load data from files
    // loadParcsFromFile(allParks, "parcs.txt");
    // loadAccommodationsFromFile(allAccommodations, "accommodations.txt");
    // loadCustomersFromFile(allCustomers, "customers.txt");
    // loadBookingsFromFile(allBookings, "bookings.txt");

    int choice;

    
    do {
        // Display the main menu
        std::cout << "Welcome to the Vacation Park Management System!" << std::endl;
        std::cout << "Select your role from the main menu please." << std::endl;
        std::cout << "Main Menu:" << std::endl;
        std::cout << "1. Owner" << std::endl;
        std::cout << "2. Employee" << std::endl;
        std::cout << "3. Customer" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Based on the user's choice, display the appropriate menu
        switch (choice) {
        case 1:
            // Owner menu
            ownerMenu(owner, parks, accommodationsPtr);
            break;
        case 2:
            // Employee menu
            employeeMenu(employee, accommodationsPtr, customers, bookings);
            break;
        case 3:
            // Customer menu
            customerMenu(customer, accommodationsPtr, bookings, selectedPark);
            break;
        case 0:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (choice != 0);


    // Use polymorphism to call functions of derived classes
    for (const Accommodations* accommodationPtr : accommodationsPtr) {
        if (accommodationPtr) { // Check if the pointer is not null
            std::cout << "Accommodation Type: " << accommodationPtr->getType() << std::endl;
            accommodationPtr->displayDetails();
            std::cout << "Luxury Level Details:" << std::endl;
            LuxuryLevel luxuryLevel = accommodationPtr->getLuxuryLevel();
            std::cout << "BBQ: " << luxuryLevel.getBBQ() << std::endl;
            std::cout << "Surround System: " << luxuryLevel.getSurroundSystem() << std::endl;
            std::cout << "Breakfast Service: " << luxuryLevel.getBreakfastService() << std::endl;
            std::cout << "Cleaning Service: " << luxuryLevel.getCleaningService() << std::endl;
            std::cout << "Accommodation Kind: " << luxuryLevel.getAccommodationKind() << std::endl;
            std::cout << std::endl;
        }
        else {
            std::cout << "Null pointer encountered in accommodationsPtr!" << std::endl;
        }
    }

    // Save data back to files
    saveAllData(parks, accommodationsPtr, customers, bookings);
    // Save data back to files
    // saveParcsToFile(allParks, "parcs.txt");
    // saveAccommodationsToFile(allAccommodations, "accommodations.txt");
    // saveCustomersToFile(allCustomers, "customers.txt");
    // saveBookingsToFile(allBookings, "bookings.txt");

    return 0;
}

void ownerMenu(Owner& owner, std::vector<Parcs>& parks, std::vector<Accommodations*>& accommodations) {
    int ownerChoice;
    do {
        // Display the owner menu
        std::cout << "Owner Menu:" << std::endl;
        std::cout << "1. Create Park" << std::endl;
        std::cout << "2. Modify Park" << std::endl;
        std::cout << "3. Delete Park" << std::endl;
        std::cout << "4. Create Accommodation" << std::endl;
        std::cout << "5. Modify Accommodation" << std::endl;
        std::cout << "6. Delete Accommodation" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> ownerChoice;

        switch (ownerChoice) {
        case 1:
            owner.createPark(parks);
            break;
        case 2:
            owner.modifyPark(parks);
            break;
        case 3:
            owner.deletePark(parks);
            break;
        case 4:
            owner.createAccommodation(parks, accommodations);
            break;
        case 5:
            owner.modifyAccommodation(parks);
            break;
        case 6:
            owner.deleteAccommodation(parks);
            break;
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (ownerChoice != 0);
}

void employeeMenu(Employee& employee, std::vector<Accommodations*>& accommodations,
    std::vector<Customer>& customers, std::vector<Booking>& bookings) {
    int employeeChoice;
    do {
        // Display the employee menu
        std::cout << "Employee Menu:" << std::endl;
        std::cout << "1. Modify Accommodations" << std::endl;
        std::cout << "2. Manage Customers" << std::endl;
        std::cout << "3. Manage Bookings" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> employeeChoice;

        switch (employeeChoice) {
        case 1:
            employee.modifyAccommodations(accommodations);
            break;
        case 2:
            employee.manageCustomers(customers);
            break;
        case 3:
            employee.manageBookings(bookings, accommodations, customers);
            break;
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (employeeChoice != 0);
}

void customerMenu(Customer& customer, std::vector<Accommodations*>& accommodations, std::vector<Booking>& bookings, Parcs& selectedPark) {
    int customerChoice;
    do {
        // Display the customer menu
        std::cout << "Customer Menu:" << std::endl;
        std::cout << "1. Book Accommodation" << std::endl;
        std::cout << "2. Modify Booking" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> customerChoice;

        switch (customerChoice) {
        case 1:
        {
            /*std::vector<Accommodations*> accommodationsPtrs;
            for (Accommodations& accommodation : accommodations) {
                accommodationsPtrs.push_back(&accommodation);
            }*/
            customer.bookAccommodation(bookings, accommodations, selectedPark);
            break;
        }
        case 2:
            customer.modifyBooking(bookings);
            break;
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    } while (customerChoice != 0);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
