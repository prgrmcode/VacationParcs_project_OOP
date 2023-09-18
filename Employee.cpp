#include "Employee.h"
#include "Booking.h"

// Constructor
Employee::Employee(const std::string& name, const std::string& role)
    : name(name), role(role) {
    // Initialize other member variables if needed
}

// Modify accommodations
void Employee::modifyAccommodations(std::vector<Accommodations*>& accommodations) {
    // Display list of accommodations and allow employee to choose an accommodation to modify
    std::cout << "List of Accommodations:" << std::endl;
    for (size_t i = 0; i < accommodations.size(); ++i) {
        std::cout << i + 1 << ". Accommodation ID: " << accommodations[i]->getID() << std::endl;
    }

    int selectedAccommodationIndex;
    std::cout << "Enter the number of the accommodation to modify: ";
    std::cin >> selectedAccommodationIndex;

    if (selectedAccommodationIndex >= 1 && selectedAccommodationIndex <= accommodations.size()) {
        Accommodations* selectedAccommodation = accommodations[selectedAccommodationIndex - 1];

        // Modify the attributes of the selected accommodation
        int newNrPeople;
        std::cout << "Enter the new number of people: ";
        std::cin >> newNrPeople;
        selectedAccommodation->setNrPeople(newNrPeople);

        int newSize;
        std::cout << "Enter the new size: ";
        std::cin >> newSize;
        selectedAccommodation->setSize(newSize);

        // You can continue to modify other attributes based on your class definition
        // ...

        std::cout << "Accommodation modified successfully." << std::endl;
    }
    else {
        std::cout << "Invalid accommodation selection." << std::endl;
        // Handle this case as needed
    }
}


//// Manage customers
//void Employee::manageCustomers(std::vector<Customer>& customers) {
//    // Display list of customers and allow employee to choose a customer to manage
//    std::cout << "List of Customers:" << std::endl;
//    for (size_t i = 0; i < customers.size(); ++i) {
//        std::cout << i + 1 << ". Customer Name: " << customers[i].getName() << std::endl;
//    }
//
//    int selectedCustomerIndex;
//    std::cout << "Enter the number of the customer to manage: ";
//    std::cin >> selectedCustomerIndex;
//
//    if (selectedCustomerIndex >= 1 && selectedCustomerIndex <= customers.size()) {
//        Customer& selectedCustomer = customers[selectedCustomerIndex - 1];
//
//        int choice;
//        std::cout << "Customer Management Menu:" << std::endl;
//        std::cout << "1. Create Customer" << std::endl;
//        std::cout << "2. Modify Customer" << std::endl;
//        std::cout << "3. Delete Customer" << std::endl;
//        std::cout << "Enter your choice: ";
//        std::cin >> choice;
//
//        switch (choice) {
//        case 1:
//            createCustomer(customers);
//            break;
//        case 2:
//            modifyCustomer(customers);
//            break;
//        case 3:
//            deleteCustomer(customers);
//            break;
//        default:
//            std::cout << "Invalid choice." << std::endl;
//        }
//        // For example:
//        // Modify the attributes of the selected customer
//        // selectedCustomer.setAddress(newAddress);
//        // selectedCustomer.setMail(newMail);
//        // ...
//        std::cout << "Customer managed successfully." << std::endl;
//    }
//    else {
//        std::cout << "Invalid customer selection." << std::endl;
//        // Handle this case as needed
//    }
//}

void Employee::manageCustomers(std::vector<Customer>& customers) {
    int choice;
    std::cout << "Customer Management Menu:" << std::endl;
    std::cout << "1. Create Customer" << std::endl;
    std::cout << "2. Modify Customer" << std::endl;
    std::cout << "3. Delete Customer" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        createCustomer(customers);
        break;
    case 2:
        modifyCustomer(customers);
        break;
    case 3:
        deleteCustomer(customers);
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
    }
}

// Create customer
void Employee::createCustomer(std::vector<Customer>& customers) {
    std::string name, address, mail;
    std::cout << "Enter customer name: ";
    std::cin >> name;
    std::cout << "Enter customer address: ";
    std::cin >> address;
    std::cout << "Enter customer mail: ";
    std::cin >> mail;

    Customer newCustomer(name, address, mail);
    customers.push_back(newCustomer);

    std::cout << "Customer created successfully." << std::endl;
}

// Modify customer
void Employee::modifyCustomer(std::vector<Customer>& customers) {
    std::cout << "List of Customers:" << std::endl;
    for (size_t i = 0; i < customers.size(); ++i) {
        if (i % 3 == 0) {
            std::cout << (i / 3) + 1 << ". " << customers[i].getName() << std::endl;
        }
        else {
            std::cout << "   " << customers[i].getName() << std::endl;
        }
        
    }

    int selectedCustomerIndex;
    std::cout << "Enter the number of the customer to modify: ";
    std::cin >> selectedCustomerIndex;

    if (selectedCustomerIndex >= 1 && selectedCustomerIndex <= customers.size()) {
        Customer& selectedCustomer = customers[selectedCustomerIndex - 1];

        // Modify the attributes of the selected customer
        std::string newName, newAddress, newMail;
        std::cout << "Enter the new customer name: ";
        std::cin >> newName;
        selectedCustomer.setName(newName);

        std::cout << "Enter the new customer address: ";
        std::cin >> newAddress;
        selectedCustomer.setAddress(newAddress);

        std::cout << "Enter the new customer mail: ";
        std::cin >> newMail;
        selectedCustomer.setMail(newMail);

        std::cout << "Customer modified successfully." << std::endl;
    }
    else {
        std::cout << "Invalid customer selection." << std::endl;
    }
}

// Delete customer
void Employee::deleteCustomer(std::vector<Customer>& customers) {
    std::cout << "List of Customers:" << std::endl;
    for (size_t i = 0; i < customers.size(); ++i) {
        std::cout << i + 1 << ". Customer Name: " << customers[i].getName() << std::endl;
    }

    int selectedCustomerIndex;
    std::cout << "Enter the number of the customer to delete: ";
    std::cin >> selectedCustomerIndex;

    if (selectedCustomerIndex >= 1 && selectedCustomerIndex <= customers.size()) {
        customers.erase(customers.begin() + selectedCustomerIndex - 1);
        std::cout << "Customer deleted successfully." << std::endl;
    }
    else {
        std::cout << "Invalid customer selection." << std::endl;
    }
}

// Manage bookings (create, modify, delete)
void Employee::manageBookings(std::vector<Booking>& bookings,
                              const std::vector<Accommodations*>& accommodations,
                              const std::vector<Customer>& customers) {
    int choice;
    std::cout << "Booking Management Menu:" << std::endl;
    std::cout << "1. Create Booking" << std::endl;
    std::cout << "2. Modify Booking" << std::endl;
    std::cout << "3. Delete Booking" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        createBooking(bookings, accommodations, customers);
        break;
    case 2:
        modifyBooking(bookings);
        break;
    case 3:
        deleteBooking(bookings);
        break;
    default:
        std::cout << "Invalid choice." << std::endl;
    }
}

void Employee::createBooking(std::vector<Booking>& bookings,
    const std::vector<Accommodations*>& accommodations,
    const std::vector<Customer>& customers) {
    // Display list of accommodations and allow employee to choose an accommodation
    std::cout << "List of Accommodations:" << std::endl;
    for (size_t i = 0; i < accommodations.size(); ++i) {
        std::cout << i + 1 << ". Accommodation ID: " << accommodations[i]->getID() << std::endl;
    }
    int accommodationChoice;
    std::cout << "Choose an accommodation to book (enter the number): ";
    std::cin >> accommodationChoice;

    if (accommodationChoice >= 1 && static_cast<size_t>(accommodationChoice) <= accommodations.size()) {
        Accommodations* selectedAccommodation = accommodations[accommodationChoice - 1];

        // Display list of customers and allow employee to choose a customer
        std::cout << "List of Customers:" << std::endl;
        for (size_t i = 0; i < customers.size(); ++i) {
            std::cout << i + 1 << ". Customer Name: " << customers[i].getName() << std::endl;
        }
        int customerChoice;
        std::cout << "Choose a customer for the booking (enter the number): ";
        std::cin >> customerChoice;

        if (customerChoice >= 1 && static_cast<size_t>(customerChoice) <= customers.size()) {
            Customer selectedCustomer = customers[customerChoice - 1];

            // Allow employee to configure additional options for the booking
            bool activityPass, sportsPass, bicycleRent, swimmingPass;
            std::cout << "Do you want to add an activity pass? (1 for yes, 0 for no): ";
            std::cin >> activityPass;
            std::cout << "Do you want to add a sports pass? (1 for yes, 0 for no): ";
            std::cin >> sportsPass;
            std::cout << "Do you want to add bicycle rental? (1 for yes, 0 for no): ";
            std::cin >> bicycleRent;
            std::cout << "Do you want to add swimming pass? (1 for yes, 0 for no): ";
            std::cin >> swimmingPass;

            // Create a new booking and add it to the bookings vector
            std::vector<Accommodations*> selectedAccommodations;
            selectedAccommodations.push_back(selectedAccommodation);
            Booking newBooking(static_cast<int>(bookings.size()) + 1, selectedCustomer, selectedAccommodations,
                activityPass, sportsPass, bicycleRent, swimmingPass);
            bookings.push_back(newBooking);

            std::cout << "Booking created successfully!" << std::endl;
        }
        else {
            std::cout << "Invalid customer choice." << std::endl;
        }
    }
    else {
        std::cout << "Invalid accommodation choice." << std::endl;
    }
}

void Employee::modifyBooking(std::vector<Booking>& bookings) {
    // Display list of bookings and allow employee to choose a booking to modify
    std::cout << "List of Bookings:" << std::endl;
    for (size_t i = 0; i < bookings.size(); ++i) {
        std::cout << i + 1 << ". Booking ID: " << bookings[i].getID() << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the booking to modify: ";
    std::cin >> choice;

    if (choice >= 1 && choice <= static_cast<int>(bookings.size())) {
        Booking& selectedBooking = bookings[choice - 1];

        // Modify the selected booking details (customer, accommodations, etc.)
        // For example, let's modify the activityPass status
        bool newActivityPass;
        std::cout << "Enter new activity pass status (0 for no, 1 for yes): ";
        std::cin >> newActivityPass;
        selectedBooking.setActivityPass(newActivityPass);

        // Similarly, you can modify other attributes of the booking as needed

        std::cout << "Booking modified successfully." << std::endl;
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }
}

void Employee::deleteBooking(std::vector<Booking>& bookings) {
    // Display list of bookings and allow employee to choose a booking to delete
    std::cout << "List of Bookings:" << std::endl;
    for (size_t i = 0; i < bookings.size(); ++i) {
        std::cout << i + 1 << ". Booking ID: " << bookings[i].getID() << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the booking to delete: ";
    std::cin >> choice;

    if (choice >= 1 && choice <= static_cast<int>(bookings.size())) {
        bookings.erase(bookings.begin() + choice - 1); // Remove the selected booking
        std::cout << "Booking deleted successfully." << std::endl;
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }
}