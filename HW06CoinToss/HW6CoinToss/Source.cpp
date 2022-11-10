//Derek D'Arcy
//9/21/22

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Coin {
private:
	string sideUp;

public:
	//constructor
	Coin() {
		srand(time(NULL));
		int rng = rand() % 1;
		if (rng == 0) {
			sideUp = "Heads";
		}
		else {
			sideUp = "Tails";
		}
	}

	void toss() {
		int rng = rand() % 2;
		if (rng == 0) {
			sideUp = "Heads";
		}
		else {
			sideUp = "Tails";
		}
	}

	string getSideUp() {
		return sideUp;
	}
};

int main() {
	Coin coin;
	int numHeads = 0;
	int numTails = 0;
	cout << "The side initially facing up is: " << coin.getSideUp() << endl << endl;

	cout << "Flipping coin 20 times and displaying results: " << endl;
	for (int i = 0; i < 20; i++) {
		coin.toss();
		cout << coin.getSideUp() << endl;;
		if (coin.getSideUp() == "Heads") {
			numHeads++;
		}
		else {
			numTails++;
		}
	}

	cout << "There have been " << numHeads << " heads and there have been " << numTails << " tails" << endl;
	system("pause");
	return 0;
}