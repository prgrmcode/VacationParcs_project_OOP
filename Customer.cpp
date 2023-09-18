#include "Customer.h"
#include <iostream>
#include "HotelRoom.h"
#include "Cabin.h"
using namespace std;

Customer::Customer() {
	// Default constructor
}

Customer::Customer(const string& name, const string& address, const string& mail)
	: name(name), address(address), mail(mail) {
	// Constructor with parameters
}

// Getters
string Customer::getName() const {
	return name;
}

string Customer::getAddress() const {
	return address;
}

string Customer::getMail() const {
	return mail;
}

void Customer::addBooking(Booking* booking) {
    bookings.push_back(booking);
}

std::string Customer::getInfo() const {
    std::string info = "Name: " + name + "\n" +
        "Address: " + address + "\n" +
        "Email: " + mail + "\n" +
        "Bookings:\n";

    for (const Booking* booking : bookings) {
        info += booking->getInfo() + "\n";
    }

    return info;
}

// Setters
void Customer::setName(const string& newName) {
	name = newName;
}

void Customer::setAddress(const string& newAddress) {
	address = newAddress;
}

void Customer::setMail(const string& newMail) {
	mail = newMail;
}

// Customer specific functions
void Customer::registerCustomer(std::vector<Customer>& customers) {
    std::string newName, newAddress, newMail;

    std::cout << "Enter your name: ";
    std::cin.ignore(); // Clear the newline character from the previous input
    std::getline(std::cin, newName);

    std::cout << "Enter your address: ";
    std::getline(std::cin, newAddress);

    std::cout << "Enter your email: ";
    std::cin >> newMail;

    Customer newCustomer(newName, newAddress, newMail);
    customers.push_back(newCustomer);

    std::cout << "Registration successful!" << std::endl;
}

void Customer::modifyCustomerData(Customer& customer) {
    std::string newName, newAddress, newMail;

    std::cout << "Enter your new name: ";
    std::cin.ignore(); // Clear the newline character from the previous input
    std::getline(std::cin, newName);

    std::cout << "Enter your new address: ";
    std::getline(std::cin, newAddress);

    std::cout << "Enter your new email: ";
    std::cin >> newMail;

    customer.setName(newName);
    customer.setAddress(newAddress);
    customer.setMail(newMail);

    std::cout << "Customer data updated!" << std::endl;
}

//void Customer::bookAccommodation(std::vector<Booking>& bookings, const std::vector<Accommodations*>& accommodations,
//    const Parcs& selectedPark) {
//    // Display list of accommodations and allow customer to choose an accommodation to book
//    std::cout << "List of Accommodations:" << std::endl;
//    for (size_t i = 0; i < accommodations.size(); ++i) {
//        std::cout << i + 1 << ". Accommodation ID: " << accommodations[i]->getID() << std::endl;
//    }
//
//    int choice;
//    std::cout << "Enter the number of the accommodation to book: ";
//    std::cin >> choice;
//
//    if (choice > 0 && choice <= static_cast<int>(accommodations.size())) {
//        Accommodations* selectedAccommodation = accommodations[static_cast<size_t>(choice) - 1];
//
//        // Create a new booking for the selected accommodation
//        std::vector<Accommodations*> selectedAccommodationsPtrs = { selectedAccommodation };
//        Booking newBooking(static_cast<int>(bookings.size()) + 1, *this, selectedAccommodationsPtrs,
//            false, false, false, false);
//
//        bookings.push_back(newBooking);
//        std::cout << "Booking successful!" << std::endl;
//    }
//    else {
//        std::cout << "Invalid choice." << std::endl;
//    }
//}

void Customer::bookAccommodation(std::vector<Booking>& bookings, const std::vector<Accommodations*>& accommodations,
    const Parcs& selectedPark) {
    // Display list of accommodations and allow customer to choose an accommodation to book
    std::cout << "List of Accommodations:" << std::endl;
    for (size_t i = 0; i < accommodations.size(); ++i) {
        std::cout << i + 1 << ". Accommodation ID: " << accommodations[i]->getID() << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the accommodation to book: ";
    std::cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(accommodations.size())) {
        Accommodations* selectedAccommodation = accommodations[static_cast<size_t>(choice) - 1];

        // Create a new booking for the selected accommodation
        std::vector<Accommodations*> selectedAccommodationsPtrs = { selectedAccommodation };
        Booking newBooking(static_cast<int>(bookings.size()) + 1, *this, selectedAccommodationsPtrs,
            false, false, false, false);

        // Set the selected accommodation directly to the Booking's accommodations member
        //newBooking.accommodations = { selectedAccommodation };


        // Check the type of accommodation and set specific attributes accordingly
        if (selectedAccommodation->getType() == "HotelRoom") {
            HotelRoom* selectedHotelRoom = dynamic_cast<HotelRoom*>(selectedAccommodation);
            if (selectedHotelRoom) {
                newBooking.setAccommodations({ selectedHotelRoom });
                newBooking.setActivityPass(false);
                newBooking.setSportsPass(false);
                newBooking.setBicycleRent(false);
                newBooking.setSwimmingPass(false);
            }
        }
        else if (selectedAccommodation->getType() == "Bungalow Cabin") {
            Cabin* selectedCabin = dynamic_cast<Cabin*>(selectedAccommodation);
            if (selectedCabin) {
                newBooking.setAccommodations({ selectedCabin });
                newBooking.setActivityPass(false);
                newBooking.setSportsPass(false);
                newBooking.setBicycleRent(false);
                newBooking.setSwimmingPass(false);
            }
        }

        bookings.push_back(newBooking);
        std::cout << "Booking successful!" << std::endl;
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }
}


void Customer::modifyBooking(std::vector<Booking>& bookings) {
    // Display list of bookings and allow customer to choose a booking to modify
    std::cout << "Your Bookings:" << std::endl;
    for (size_t i = 0; i < bookings.size(); ++i) {
        if (bookings[i].getCustomer().getName() == getName()) {
            std::cout << i + 1 << ". Booking ID: " << bookings[i].getID() << std::endl;
        }
    }

    int choice;
    std::cout << "Enter the number of the booking to modify: ";
    std::cin >> choice;

    if (choice >= 1 && choice <= static_cast<int>(bookings.size())) {
        Booking& selectedBooking = bookings[choice - 1];

        // Modify the selected booking details
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
