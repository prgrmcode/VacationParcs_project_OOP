#ifndef VACATIONPARCS_H
#define VACATIONPARCS_H

#include <vector>
#include <string>
#include "Parcs.h"
#include "Customer.h"

// VacationParcs.h

class VacationParcs {
private:
    std::string name;
    std::string address;
    std::string VAT;
    std::vector<Parcs> parcs;
    std::vector<Customer> customers;

public:
    // Constructor, getters, setters, and methods to manage parks
    VacationParcs(); // Default constructor
    VacationParcs(const std::string& name, const std::string& address, const std::string& VAT);

    // Getters
    std::string getName() const;
    std::string getAddress() const;
    std::string getVAT() const;
    std::vector<Parcs> getParcs() const;
    std::vector<Customer> getCustomers() const;

    // Setters:
    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setVAT(const std::string & VAT);
    void setParcs(const std::vector<Parcs>& parcs);
    void setCustomers(const std::vector<Customer>& customers);

};

#endif // VACATIONPARCS_H

