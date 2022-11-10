//Derek D'Arcy
//10/23/22

#include <iostream>
#include <map>
using namespace std;

int main() {
	//create maps
	map <string, int> roomNumber;
	map <string, string> instructor;
	map <string, string> meetingTime;

	//map course numbers to rooms
	roomNumber.insert(pair<string, int>("CS101", 3004));
	roomNumber.insert(pair<string, int>("CS102", 4501));
	roomNumber.insert(pair<string, int>("CS103", 6755));
	roomNumber.insert(pair<string, int>("NT110", 1244));
	roomNumber.insert(pair<string, int>("CM241", 1411));

	//map course numbers to instructors
	instructor.insert(pair<string, string>("CS101", "Haynes"));
	instructor.insert(pair<string, string>("CS102", "Alvarado"));
	instructor.insert(pair<string, string>("CS103", "Rich"));
	instructor.insert(pair<string, string>("NT110", "Burke"));
	instructor.insert(pair<string, string>("CM241", "Lee"));

	//map course numbers to meeting times
	meetingTime.insert(pair<string, string>("CS101", "8:00 am"));
	meetingTime.insert(pair<string, string>("CS102", "9:00 am"));
	meetingTime.insert(pair<string, string>("CS103", "10:00 am"));
	meetingTime.insert(pair<string, string>("NT110", "11:00 am"));
	meetingTime.insert(pair<string, string>("CM241", "1:00 pm"));

	//loop to allow user to keep searching
	int contProgram = 1;
	while (contProgram != 0) {
		string courseNumber;
		cout << "Please enter a course number you wish to look up: ";
		cin >> courseNumber;
		map<string, int>::iterator roomIt = roomNumber.find(courseNumber);
		map<string, string>::iterator instIt = instructor.find(courseNumber);
		map<string, string>::iterator timeIt = meetingTime.find(courseNumber);
		
		//check maps for given course number and display corresponding value if found
		if (roomIt != roomNumber.end()) {
			cout << "Room number for course number " << roomIt -> first << " is room " << roomIt-> second << endl;
		}
		else {
			cout << "Unable to find room number corresponding to given course number" << endl;
		}

		if (instIt != instructor.end()) {
			cout << "Instructors name for course number "<< instIt-> first << " is Professor " << instIt-> second << endl;
		}
		else {
			cout << "Unable to find instructor corresponding to given course number" << endl;
		}

		if (timeIt != meetingTime.end()) {
			cout << "Meeting time of course number " << timeIt-> first << " is at " << timeIt-> second << endl;
		}
		else {
			cout << "Unable to find time corresponding to given course number" << endl;
		}

		//check if user wishes to continue
		cout << endl << "Do you want to look up another course?" << endl << "Enter 1 to search again, enter 0 to end program : ";
		cin >> contProgram;
	}
	system("pause");
	return 0;
}