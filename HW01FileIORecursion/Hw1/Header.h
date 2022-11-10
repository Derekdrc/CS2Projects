//Header file for Customer class
#include <iostream>
using namespace std;

//Original Customer Class
class Customer {

private:
    string custId;
    string custName;
    Customer* related;
    string getId();
    string getName();
    void setId(string);
    void setName(string);
    void setRelated(Customer);
    void printCustomer();

public:
    //default constructor
    Customer() {
        custId = 123;
        custName = "First Last";
        related = nullptr;
    }

    //constructor with both fields
    Customer(string ID, string name) {
        custId = ID;
        custName = name;
        related = nullptr;
    }

    //constructor just id
    Customer(string ID) {
        custId = ID;
        related = nullptr;
    }

    //constructor just name
    Customer(string name) {
        custName = name;
        related = nullptr;
    }

    //get ID method
    string getId() {
        return custId;
    }

    //get name method
    string getName() {
        return custName;
    }

    //set id method
    void setId(string Id) {
        custId = Id;
        return;
    }

    //set name method
    void setName(string name) {
        custName = name;
        return;
    }

    //set related method
    void setRelated(Customer cust) {
        related = &cust;
    }

    //print method
    virtual void printCustomer() {
        std::cout << "Customer ID is: " << getId() << endl;
        std::cout << "Customer Name is: " << getName() << endl;
        std::cout << "Related Customer name is: " << endl; //fix this line
    }
};