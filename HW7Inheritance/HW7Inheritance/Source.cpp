// Derek D'Arcy
// 10/5/22
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Original Employee Class
class Employee {
private:
	string name;
	int number;
	string hireDate;

public:
	//default constructor
	Employee() {
		name = "John Doe";
		number = 0;
		hireDate = "1/1/2000";
	}

	//constructor with all information
	Employee(string empName, int empNumber, string empHireDate) {
		name = empName;
		number = empNumber;
		hireDate = empHireDate;
	}

	//get name method
	string getEmployeeName() {
		return name;
	}

	//get number method
	int getEmployeeNumber() {
		return number;
	}

	//get date method
	string getEmployeeDate() {
		return hireDate;
	}

	//set name method
	void setEmployeeName(string empName) {
		name = empName;
	}

	//set number method
	void setEmployeeNumber(int empNum) {
		number = empNum;
	}

	//set date method
	void setEmployeeDate(string empDate) {
		hireDate = empDate;
	}

	//print method
	virtual void printEmployee() {
		cout << "Employee name is: " << getEmployeeName() << endl;
		cout << "Employee number is: " << getEmployeeNumber() << endl;
		cout << "Employee hire date is: " << getEmployeeDate() << endl << endl;
	}

};

class ProductionWorker : public Employee {
private:
	int shift;
	double hourlyPay;

public:
	//default contructor
	ProductionWorker() {
		shift = 0;
		hourlyPay = 0;
	}

	//parameter constructor
	ProductionWorker(string name, int number, string hireDate, int shiftNum, double pay) : Employee(name, number, hireDate) {
		shift = shiftNum;
		hourlyPay = pay;
	}

	//shift getter
	int getShift() {
		return shift;
	}

	//pay getter
	double getPay() {
		return hourlyPay;
	}

	//shift setter
	void setShift(int num) {
		shift = num;
	}

	//pay setter
	void setPay(double wage) {
		hourlyPay = wage;
	}

	//print function overiding base
	virtual void printEmployee() {
		cout << "Employee name is: " << getEmployeeName() << endl;
		cout << "Employee number is: " << getEmployeeNumber() << endl;
		cout << "Employee hire date is: " << getEmployeeDate() << endl;
		if (getShift() == 1) {
			cout << "Employee is on day shift" << endl;
		}
		else if (getShift() == 2) {
			cout << "Employee is on night shift" << endl;
		}
		cout << "Emplyee wage is: $" << getPay() << "/hr" << endl << endl;
	}

};

int main() {
	const int numEmployees = 3;

	Employee* emps[numEmployees] =
	{ new Employee("Derek Drc", 1010, "10/4/22"),
		new ProductionWorker("John Doe", 1011, "10/3/22", 1, 12.75),
		new ProductionWorker("Jane Doe", 1012, "10/1/22", 2, 15.25)
	};

	for (int i = 0; i < numEmployees; i++) {
		emps[i]->printEmployee();
	}
	return 0;
}