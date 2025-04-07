#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice () {
  return (rand() % 6 + 1) + (rand() % 6 + 1);
}

int main() {
  srand(time(0));
  int point = 0;
  char again = 'y';

  cout << "Welcome Shooter! lets roll the dice!" << endl;

  while (again == 'y' || again == 'Y') {
    int roll = rollDice();
    cout << "You rolled: " << roll << endl;

    if (roll == 7 || roll == 11) {
      cout << "You win!" << endl;
    } else if (roll == 2 || roll == 3 || roll == 12) {
      cout << "Craps! Sorry you lose!" << endl;
    } else {
      cout << "Point is " << roll << endl;
      int point = roll;
      int rollNext;

      do {
        rollNext = rollDice();
        cout << "You rolled: " << rollNext << endl;

        if (rollNext == point){
          cout << "You win!" << endl;
          break;
        } else if (rollNext == 7 ) {
          cout << "Sevens Out!! Sorry you lost!" << endl;
          break;
        }
      } while (true);
    }
    cout << "Would you like to play again? (y/n): ";
    cin >> again;
  }
  cout << "Thanks for playing!" << endl;

  return 0;
}
