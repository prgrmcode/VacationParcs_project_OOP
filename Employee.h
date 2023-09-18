#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <vector>
#include "Accommodations.h" // Include the header for the Accommodations class
#include "Customer.h"       // Include the header for the Customer class
#include "Booking.h"        // Include the header for the Booking class

class Employee {
public:
    // Constructor
    Employee(const std::string& name, const std::string& role);

    // Modify accommodations
    void modifyAccommodations(std::vector<Accommodations*>& accommodations);

    // Manage customers
    void manageCustomers(std::vector<Customer>& customers);
    

    // Manage bookings
    void manageBookings(std::vector<Booking>& bookings, const std::vector<Accommodations*>& accommodations,
                        const std::vector<Customer>& customers);

    

private:
    std::string name;
    std::string role;
    // You can add more member variables if needed
    void createCustomer(std::vector<Customer>& customers);
    void modifyCustomer(std::vector<Customer>& customers);
    void deleteCustomer(std::vector<Customer>& customers);

    void modifyBooking(std::vector<Booking>& bookings);
    void deleteBooking(std::vector<Booking>& bookings);
    void createBooking(std::vector<Booking>& bookings, const std::vector<Accommodations*>& accommodations,
        const std::vector<Customer>& customers);
};

#endif // EMPLOYEE_H
