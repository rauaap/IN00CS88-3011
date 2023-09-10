#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

Game::Game(int maxNumber) : maxNumber(maxNumber) {
    cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber
         << " as a maximum value" << endl;
}

Game::~Game() {
    cout << "GAME DESTRUCTOR: object cleared from stack memory" << endl;
}

void Game::play() {
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;

    do {
        cout << "Give your guess between 1-" << maxNumber << endl;
        cin >> playerGuess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (playerGuess > randomNumber) cout << "Your guess is too big" << endl;
        else if (playerGuess < randomNumber) cout << "Your guess is too small" << endl;
        else cout << "Your guess is right = " << playerGuess << endl;

        numOfGuesses++;
    } while (playerGuess != randomNumber);

    printGameResult();
}

void Game::printGameResult() {
    cout << "You guessed the right answer = " << randomNumber
         << " with " << numOfGuesses << " guesses" << endl;
}
