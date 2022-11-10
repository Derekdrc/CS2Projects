//Derek D'Arcy
//9/14/22

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int NUM_PLAYERS = 12;

struct SoccerPlayer {
    string name = "";
    int number = 0;
    int points = 0;
};

void getPlayers(SoccerPlayer&);
void showStats(SoccerPlayer);
int  teamTotal(SoccerPlayer[], int);
void printHigh(SoccerPlayer[], int);
void writeToFile(SoccerPlayer[]);

int main() {
    SoccerPlayer playerArr[NUM_PLAYERS];
    
    string path = "input.txt";

    fstream file;

    file.open(path, fstream::in | fstream::out | fstream::app);
    if (!file) {
        cout << "Couldn't create file" << endl;
    }
    else {
        cout << "File ready" << endl;
    }

    if (file.is_open()) {
        string tmpName =" ";
        int tmpNum = 0;
        int tmpPts = 0;
        for (int i = 0; i < NUM_PLAYERS; i++) {
            file >> tmpName;
            file >> tmpNum;
            file >> tmpPts;
            playerArr[i].name = tmpName;
            playerArr[i].number = tmpNum;

            int currentPoints = playerArr[i].points;
            playerArr[i].points = tmpPts + currentPoints;
        }
    }
    file.close();

    for (int i = 0; i < NUM_PLAYERS; i++) {
        cout << "\nPLAYER #" << (i + 1) << "\n";
        cout << "---------\n";
        getPlayers(playerArr[i]);
        cin.get();
    }
    file.open(path);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        file << playerArr[i].name << " " << playerArr[i].number << " " << playerArr[i].points << " \n";
    }
    file.close();

    cout.width(20);
    cout.setf(ios::left);
    cout << "\nNAME";
    cout.width(10);
    cout << "NUMBER";
    cout.width(10);
    cout << "POINTS SCORED\n";
    for (int i = 0; i < NUM_PLAYERS; i++) {
        showStats(playerArr[i]);
    }
    cout << "TOTAL POINTS: " << teamTotal(playerArr, NUM_PLAYERS) << endl;
    printHigh(playerArr, NUM_PLAYERS);

    string userInput;
    cout << "Please enter your desired text file name (ie. text.txt): ";
    cin >> userInput;

    ofstream userFile;
    userFile.open(userInput);
    if (!userFile) {
        cout << "Couldn't create file" << endl;
    }
    else {
        cout << "File created" << endl;
    }

    for (int i = 0; i < NUM_PLAYERS; i++) {
        userFile << playerArr[i].name << " " << playerArr[i].number << " " << playerArr[i].points << " \n";
    }

    userFile.close();

}


void getPlayers(SoccerPlayer& player) {
    cout << "Player name: ";
    cin >> player.name;
    cout << "Player's number: ";
    cin >> player.number;
    int points;
    cout << "Points scored: ";
    cin >> points;
    while (points < 0) {
        cout << "Invalid number of points" << endl;
        cin >> points;
    }
    player.points += points;
}


void showStats(SoccerPlayer player) {
    cout << setw(20) << player.name;
    cout << setw(10) << player.number;
    cout << setw(10) << player.points << endl;
}


int teamTotal(SoccerPlayer players[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++)
        total += players[i].points;
    return total;
}


void printHigh(SoccerPlayer players[], int size) {
    int highest = 0, highPoints = players[0].points;

    for (int index = 1; index < size; index++) {
        if (players[index].points > highPoints) {
            highest = index;
            highPoints = players[index].points;
        }
    }
    cout << "The player who scored the most points is: ";
    cout << players[highest].name << endl;
}
