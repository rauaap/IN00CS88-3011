#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    // Initialize rng with the current timestamp.
    srand(std::time(0));
    int maxTarget = 20;

    cout << "Guess a random number I'm thinking of between 1 and " << maxTarget << endl;

    // Modulo limits the generated number between 0 and maxTarget-1
    // We want to guess between 1 and maxTarget so we add 1 to target
    int target = rand() % maxTarget + 1;
    int guess;

    do {
        cin >> guess;

        if (guess < target) cout << "Your guess was too low" << endl;
        else if (guess > target) cout << "Your guess was too high" << endl;

    } while (guess != target);

    cout << "Your guess was correct!" << endl
         << "Press any key to exit." << endl;

    // Clear the input buffer before waiting for the user to press any key.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    return 0;
}
