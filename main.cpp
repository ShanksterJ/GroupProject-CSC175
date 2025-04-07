#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

string SlotSelect() {
    struct Symbol {
        string emoji;
        int weight;
    } symbols[] = {
        {"🍒", 30},
        {"🍋", 25},
        {"🔔", 20},
        {"🌟", 15},
        {"🔥", 10}
    };

    int percent = 100;
    int random = rand() % percent;

    int totalpercent = 0;
    for (const auto& symbol : symbols) {
        totalpercent += symbol.weight;
        if (random < totalpercent) {
            return symbol.emoji;
        }
    }
    return "❓";
}

int points(string slot1, string slot2, string slot3) {
    if (slot1 == slot2 && slot2 == slot3) {
        if (slot1 == "🔥") return 50;
        if (slot1 == "🌟") return 30;
        if (slot1 == "🔔") return 20;
        if (slot1 == "🍋") return 10;
        if (slot1 == "🍒") return 5;
    }
    else if (slot1 == slot2 || slot2 == slot3 || slot1 == slot3) {
        return 2;
    }
    return 0;
}

int main() {
    srand(time(0));
    char again = 'y';

    cout << "\nWelcome Player! lets Spin The Wheel!\n" << endl;


    while (again == 'y' || again == 'Y') {

        string slot1 = SlotSelect();
        string slot2 = SlotSelect();
        string slot3 = SlotSelect();

        int pointsout = points(slot1, slot2, slot3);

        cout << "   ──────── \n"
        << "│  ─SLOTS!─  │\n"
        << "│  ────────  │\n"
        << "│" << slot1 << " │ " << slot2 << " │ " << slot3 << "│ \n"
        << "│  ────────  │ \n"
        << "│   " << setw(3) << pointsout << "      │\n" // Payout with fixed width
        << "   ────────  \n" << endl;
        cout << "Would you like to play again? (y/n): ";
        cin >> again;
    }
    cout << "Thanks for playing!" << endl;

    return 0;
}
