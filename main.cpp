#include <iostream>
#include <cstdlib>
#include <ctime>
#include "slots.cpp"
#include "craps.cpp"


using namespace std;

extern void playSlots();
extern void playCraps();

int main() {
    srand(time(0));
    char choice;

    do {
        cout << "1. Slots 🎰" << endl;
        cout << "2. Craps 🎲" << endl;
        cout << "3. Quit" << endl;
        cout << "Pick a game: ";
        cin >> choice;

        if (choice == '1') {
            playSlots();
        } else if (choice == '2') {
            playCraps();
        } else if (choice == '3') {
            cout << "Thanks for playing!" << endl;
        } else {
            cout << "Invalid" << endl;
        }

    } while (choice != '3');

    return 0;
}
