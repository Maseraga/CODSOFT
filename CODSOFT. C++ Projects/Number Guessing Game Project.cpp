#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	srand(time(0));

	int randomNumber = rand() % 100 + 1;

	int userGuess;
	int attempts = 0;

	cout << "WELCOME TO NUMBER GUESSING GAME" << endl;

	do {

		cout << "Guess the number (between 1 and 100): ";
		cin >> userGuess;


		attempts++;


		if (userGuess < randomNumber) {
			cout << "Too low." << endl;
		}
		else if (userGuess > randomNumber) {
			cout << "Too high." << endl;
		}
		else {
			cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
		}

	} while (userGuess != randomNumber);

	return 0;
}
