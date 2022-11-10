//  main.cpp
//  cs2Hw1
//  Created by Derek D'Arcy on 8/25/22.

#include "Header.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

void stats();
float average(vector<float>&);
void cString();
int countVowels(string);

int main() {
    //call function to process stats.txt
    char whichProgram;

    cout << "Please type 's' for stats program, type 'c' for c-strings, type 'v' for vowel recursion counter, type 'h' for Customer class: " << endl;
    cin >> whichProgram;
    while (whichProgram != 's' && whichProgram != 'c' && whichProgram != 'v' && whichProgram != 'h') {
        cout << "Input not allowed, please try again." << "Type 's' for stats program, type 'c' for c-strings, type 'v' for vowel recursion counter, type 'h' for Customer class: " << endl;
        cin >> whichProgram;
    }

    switch (whichProgram) {
        case 's':
        {
            stats();
            break;
        }
        case 'c':
        {
            cString();
            break;
        }
        case 'v': {
            string userInput;
            cout << "Please type a string you would like to count the vowels: ";
            std::cin.sync();
            std::cin.get();
            std::getline(cin, userInput);
            transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
            cout << "Number of vowels in string: " << countVowels(userInput) << endl;
            break;
        }
        
        case 'h' :
            ifstream custFile;
            ifstream relFile;
            custFile.open("./Cust.txt");
            relFile.open("./CustRel-1.txt");
            if (custFile.fail() || relFile.fail()) {
                cout << "Input failed to open \n";
                system("pause");
                exit(1);
            }

            const int numCustomers = 5;
            string tempName;
            string tempId;
            string tempRel;

            Customer* custs[numCustomers];

            while (custFile >> tempId >> tempName) {
                new Customer(tempId, tempName);
            }

            for (int i = 0; i < numCustomers; i++) {
                custs[i]->printCustomer();
            }

            int count = 0;
            while (relFile >> tempRel) {
                custs[count]->setRelated(tempRel);
            }

            break;
        }

    system("pause");
    return 0;
}

//function that calculates stat.txt file
void stats() {
    int numFileInts;
    int nextLine;

    ifstream Input;
    Input.open("./Stat.txt");

    if (Input.fail()) {
        cout << "Input failed to open \n";
        system("pause");
        exit(1);
    }

    Input >> numFileInts;
    //check if stats.txt N is negative
    if (numFileInts < 0) {
        cout << "N is negative";
        system("pause");
        exit(1);
    }
    cout << "There are " << numFileInts << " numbers in this file \n";

    std::vector<float> statVector;

    while (Input >> nextLine) {
        statVector.push_back(nextLine);
    }

    if (statVector.size() == 0) {
        cout << "The file is empty";
        system("pause");
        exit(1);
    }

    if (numFileInts != statVector.size()) {
        cout << "The file does not contain N numbers";
        system("pause");
        exit(1);
    }


    //sorts stat vector
    sort(statVector.begin(), statVector.end());

    //prints out required information
    cout << "The lowest value in the file is " << statVector.at(0) << "\n";
    cout << "The highest value in the file is " << statVector.at(numFileInts - 1) << "\n";
    cout << "The average of the values is " << setprecision(3) << average(statVector) << "\n";
}

//function that calculates and returns average
float average(vector<float>& vect) {
    float runningTotal = 0;
    float numItems = vect.size();

    for (int i = 0; i < numItems; i++) {
        runningTotal += vect.at(i);
    }
    return (runningTotal / numItems);
}

void cString() {
    string hello = "Hello ";
    string world = "World! \n";
    std::vector<std::string> stringVec;

    stringVec.push_back(hello);
    stringVec.push_back(world);

    for (int i = 0; i < stringVec.size(); i++) {
        cout << stringVec.at(i);
    }
}

int countVowels(string str) {
    string vowels = "AEIOU";
    if (str.empty()) {
        return 0;
    }
    string subString = str.substr(1, str.length() - 1);
    char first = str[0];
    if (vowels.find(first) != string::npos) {
        return 1 + countVowels(subString);
    }
    return countVowels(subString);
}

