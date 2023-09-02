#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int game(int maxTarget) {
    // Modulo limits the generated number between 0 and maxTarget-1
    // We want to guess between 1 and maxTarget so we add 1 to target
    int target = rand() % maxTarget + 1;
    int guess;
    int attempts = 0;

    cout << "Guess a random number I'm thinking of between 1 and " << maxTarget << endl;

    do {
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (guess < target) cout << "Your guess was too low" << endl;
        else if (guess > target) cout << "Your guess was too high" << endl;

        attempts++;
    } while (guess != target);

    cout << "Your guess was correct!" << endl;

    return attempts;
}

int main() {
    // Initialize rng with the current timestamp.
    srand(std::time(0));
    int maxTarget;

    do {
        cout << "Enter a positive integer: ";
        cin >> maxTarget;
        // Clear errors and input buffer between after input has been saved.
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (maxTarget < 1);

    int attempts = game(maxTarget);
    cout << "It took you " << attempts << " attempt(s) to guess right." << endl;
    cout << "Press any key to exit." << endl;

    // Clear the input buffer before waiting for the user to press any key.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
