#include "Owner.h"

#include "Parcs.h"
#include <memory> // Include this for std::unique_ptr
#include "Cabin.h"


Owner::Owner(const std::string& name, const std::string& role)
    : name(name), role(role) {
    // Initialize other member variables if needed
}


void Owner::createPark(std::vector<Parcs>& parks) {
    std::string name, address;
    ParcServices services; // Assuming you have a ParcServices class with setters for each service

    // Gather input for the new park
    std::cout << "Enter the name of the new park: ";
    std::cin.ignore(); // Clear the newline character from previous input
    std::getline(std::cin, name);

    std::cout << "Enter the address of the new park: ";
    std::getline(std::cin, address);

    // Set services for the new park
    services.setSubtropicSwimmingPool(true); // Example
    services.setSportsInfrastructure(true);   // Example
    // Set other services...

    //// Create a vector to store accommodations (you can add accommodations later)
    //std::vector<Accommodations *> accommodations;

    // Create the new park
    Parcs newPark(name, address, services, accommodations);
    parks.push_back(newPark);
    std::cout << "New park created successfully!" << std::endl;
}

void Owner::modifyPark(std::vector<Parcs>& parks) {
    // Display list of parks and allow owner to choose a park to modify
    std::cout << "List of Parks:" << std::endl;
    for (size_t i = 0; i < parks.size(); ++i) {
        std::cout << i + 1 << ". " << parks[i].getName() << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the park you want to modify: ";
    std::cin >> choice;
    --choice; // Decrement to match vector indexing

    if (choice >= 0 && choice < parks.size()) {
        // Modify park details
        std::string newName, newAddress;
        std::cout << "Enter the new name for the park: ";
        std::cin.ignore();
        std::getline(std::cin, newName);

        std::cout << "Enter the new address for the park: ";
        std::getline(std::cin, newAddress);

        parks[choice].setName(newName);
        parks[choice].setAddress(newAddress);

        std::cout << "Park details modified successfully!" << std::endl;
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }
}

void Owner::deletePark(std::vector<Parcs>& parks) {
    // Display list of parks and allow owner to choose a park to delete
    std::cout << "List of Parks:" << std::endl;
    for (size_t i = 0; i < parks.size(); ++i) {
        std::cout << i + 1 << ". " << parks[i].getName() << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the park you want to delete: ";
    std::cin >> choice;
    --choice; // Decrement to match vector indexing

    if (choice >= 0 && choice < parks.size()) {
        // Delete the chosen park
        parks.erase(parks.begin() + choice);
        std::cout << "Park deleted successfully!" << std::endl;
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }
}

Parcs Owner::selectPark(std::vector<Parcs>& parks) {
    int parkIndex;

    // Assuming you have a vector of parks or some other way to identify parks
    // For this example, let's assume you have a vector called 'allParks'.
    // You would replace this with your actual data structure.
    // std::vector<Parcs> allParks = /* initialize your vector */;

    // Display a list of parks for selection
    std::cout << "Select a park:" << std::endl;
    for (int i = 0; i < parks.size(); ++i) {
        std::cout << i + 1 << ". " << parks[i].getName() << std::endl;
    }

    // Get user input for the selected park index
    std::cout << "Enter the number of the park: ";
    std::cin >> parkIndex;

    // Check if the user input is valid
    if (parkIndex >= 1 && parkIndex <= parks.size()) {
        return parks[parkIndex - 1]; // Return the selected park
    }
    else {
        std::cout << "Invalid park selection." << std::endl;
        // You might want to handle this case more gracefully in your actual implementation.
        exit(1); // Exit the program due to an error
    }
}



void Owner::createAccommodation(std::vector<Parcs>& parks, std::vector<Accommodations*>& accommodations) {
    int parkIndex;

    // Display a list of parks for the user to choose from
    std::cout << "Select a park to create an accommodation in:" << std::endl;
    for (size_t i = 0; i < parks.size(); ++i) {
        std::cout << i + 1 << ". " << parks[i].getName() << std::endl;
    }
    std::cout << "Enter the number of the park: ";
    std::cin >> parkIndex;

    if (parkIndex < 1 || parkIndex > parks.size()) {
        std::cout << "Invalid park selection." << std::endl;
        return;
    }

    Parcs& selectedPark = parks[parkIndex - 1];
    
    
    int ID, nrPeople, size;
    bool bathroomWithBath;
    LuxuryLevel luxuryLevel;

    // Gather input for the new accommodation
    std::cout << "Enter the ID for the new accommodation: ";
    std::cin >> ID;

    std::cout << "Enter the number of people the accommodation can accommodate: ";
    std::cin >> nrPeople;

    std::cout << "Enter the size of the accommodation: ";
    std::cin >> size;

    std::cout << "Does the accommodation have a bathroom with a bath? (1 for yes, 0 for no): ";
    std::cin >> bathroomWithBath;

    // Set luxury level for the new accommodation
    luxuryLevel.setBBQ(true);   // Example
    luxuryLevel.setBreakfastService(true);  // Example
    // Set other luxury features...

    int accommodationType;
    std::cout << "Select accommodation type: " << std::endl;
    std::cout << "1. Hotel Room" << std::endl;
    std::cout << "2. Cabin" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> accommodationType;

    if (accommodationType == 1) {
        // Creating a Hotel Room
        int floor, nrBeds, childrenBed;
        std::string location;

        // Gather input for Hotel Room specific attributes
        std::cout << "Enter the floor of the Hotel Room: ";
        std::cin >> floor;

        std::cout << "Enter the location of the Hotel Room: ";
        std::cin.ignore(); // Clear the newline character from the previous input
        std::getline(std::cin, location);

        std::cout << "Enter the number of beds in the Hotel Room: ";
        std::cin >> nrBeds;

        std::cout << "Does the Hotel Room have a children's bed? (1 for yes, 0 for no): ";
        std::cin >> childrenBed;

        // Create the new Hotel Room accommodation
        std::unique_ptr<Accommodations> newAccommodation = std::make_unique<HotelRoom>(ID, nrPeople, size, bathroomWithBath, luxuryLevel,
            floor, location, nrBeds, childrenBed);
        selectedPark.addAccommodation(newAccommodation.get()); // Add to the selected park
        accommodations.push_back(newAccommodation.release());  // Add to the accommodations vector

        std::cout << "New Hotel Room created successfully!" << std::endl;
    }
    else if (accommodationType == 2) {
        // Creating a Cabin
        int nrBedrooms;

        // Gather input for Cabin specific attributes
        std::cout << "Enter the number of bedrooms in the Cabin: ";
        std::cin >> nrBedrooms;

        // ... (gather input for other Cabin specific attributes)

        // Create the new Cabin accommodation
        std::unique_ptr<Accommodations> newAccommodation = std::make_unique<Cabin>(ID, nrPeople, size, bathroomWithBath, luxuryLevel,
            nrBedrooms);
        selectedPark.addAccommodation(newAccommodation.get()); // Add to the selected park
        accommodations.push_back(newAccommodation.release()); // Add to the accommodations vector

        std::cout << "New Cabin created successfully!" << std::endl;
    }
    else {
        std::cout << "Invalid accommodation type choice." << std::endl;
    }
}



//void Owner::createAccommodation(std::vector<Accommodations*>& accommodations) {
//    int ID, nrPeople, size;
//    bool bathroomWithBath;
//    LuxuryLevel luxuryLevel; 
//
//    // Gather input for the new accommodation
//    std::cout << "Enter the ID for the new accommodation: ";
//    std::cin >> ID;
//
//    std::cout << "Enter the number of people the accommodation can accommodate: ";
//    std::cin >> nrPeople;
//
//    std::cout << "Enter the size of the accommodation: ";
//    std::cin >> size;
//
//    std::cout << "Does the accommodation have a bathroom with a bath? (1 for yes, 0 for no): ";
//    std::cin >> bathroomWithBath;
//
//    // Set luxury level for the new accommodation
//    // You can prompt for the individual luxury features here
//    luxuryLevel.setBBQ(true);   // Example
//    luxuryLevel.setBreakfastService(true);  // Example
//    // Set other luxury features...
//
//    Parcs selectedPark = selectPark(); 
//
//    // Create the new accommodation
//    std::unique_ptr<Accommodations> newAccommodation = std::make_unique<HotelRoom>(ID, nrPeople, size, bathroomWithBath, luxuryLevel, // HotelRoom constructor arguments
//        0, "", 0, false);  // HotelRoom-specific arguments (floor, location, nrBeds, childrenBed)
//    // Add the new accommodation to the accommodations vector of the selected park
//    //selectedPark.getAccommodations().push_back(newAccommodation.release()); // Note the use of std::move
//    selectedPark.addAccommodation(newAccommodation.release());
//
//    std::cout << "New accommodation created successfully!" << std::endl;
//}


void Owner::modifyAccommodation(std::vector<Parcs>& parks/*, std::vector<Accommodations*>& accommodations*/) {
    Parcs selectedPark = selectPark(parks);
    const std::vector<Accommodations*>& accommodations = selectedPark.getAccommodations();
    //const std::vector<Accommodations*>& accommodations = selectedPark.getAccommodations();

    //accommodations = selectedPark.getAccommodations();
    // Display list of accommodations and allow owner to choose an accommodation to modify
    std::cout << "List of Accommodations:" << std::endl;
    for (size_t i = 0; i < accommodations.size(); ++i) {
        std::cout << i + 1 << ". Accommodation ID: " << accommodations[i]->getID() << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the accommodation you want to modify: ";
    std::cin >> choice;
    --choice; // Decrement to match vector indexing

    if (choice >= 0 && choice < accommodations.size()) {
        // Modify accommodation details
        int newID, newNrPeople, newSize;
        bool newBathroomWithBath;
        LuxuryLevel newLuxuryLevel; // Assuming you have an enum for LuxuryLevel

        std::cout << "Enter the new ID for the accommodation: ";
        std::cin >> newID;

        std::cout << "Enter the new number of people the accommodation can accommodate: ";
        std::cin >> newNrPeople;

        std::cout << "Enter the new size of the accommodation: ";
        std::cin >> newSize;

        std::cout << "Does the new accommodation have a bathroom with a bath? (1 for yes, 0 for no): ";
        std::cin >> newBathroomWithBath;

        // Set luxury level for the modified accommodation
        // You can prompt for the individual luxury features here
        newLuxuryLevel.setBBQ(true);   // Example
        newLuxuryLevel.setBreakfastService(true);  // Example
        // Set other luxury features...

        accommodations[choice]->setID(newID);
        accommodations[choice]->setNrPeople(newNrPeople);
        accommodations[choice]->setSize(newSize);
        accommodations[choice]->setBathroomWithBath(newBathroomWithBath);
        accommodations[choice]->setLuxuryLevel(newLuxuryLevel);

        // Update the vector of accommodations for the selected park
        selectedPark.modifyAccommodation(choice, accommodations[choice]);

        std::cout << "Accommodation details modified successfully!" << std::endl;
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }
}

void Owner::deleteAccommodation(std::vector<Parcs>& parks/*, std::vector<Accommodations*>& accommodations*/) {
    Parcs selectedPark = selectPark(parks);
    //std::vector<Accommodations*> accommodations = selectedPark.getAccommodations();
    const std::vector<Accommodations*>& accommodations = selectedPark.getAccommodations();


    // Display list of accommodations and allow owner to choose an accommodation to delete
    std::cout << "List of Accommodations:" << std::endl;
    for (size_t i = 0; i < accommodations.size(); ++i) {
        std::cout << i + 1 << ". Accommodation ID: " << accommodations[i]->getID() << std::endl;
    }

    int choice;
    std::cout << "Enter the number of the accommodation you want to delete: ";
    std::cin >> choice;
    --choice; // Decrement to match vector indexing

    if (choice >= 0 && choice < accommodations.size()) {
        // Delete the chosen accommodation
        //accommodations.erase(accommodations.begin() + choice);
        selectedPark.deleteAccommodation(choice);
        
        std::cout << "Accommodation deleted successfully!" << std::endl;
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }
}

// Implement other owner-specific methods here
