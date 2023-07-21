/**
 * Change for a Dollar Game
 *
 * Create a change-counting game that gets the user to enter the number of coins required to make exactly
 * one dollar. The program should ask the user to enter the number of pennies, nickels, dimes, and quarters.
 * If the total value of the coins entered is equal to one dollar, the program should congratulate the user
 * for winning the game. Otherwise, the program should display a message indicating whether the amount entered
 * was more than or less than one dollar.
*/

#include <iostream>
using namespace std;

int main() {
    int quarters, dimes, nickels, pennies;
    
    cout << "How many quarters?";
    cin >> quarters;

    cout << "How many dimes?";
    cin >> dimes;

    cout << "How many nickels?";
    cin >> nickels;

    cout << "How many pennies?";
    cin >> pennies;

    int value = (quarters * 25) + (dimes * 10) + (nickels * 5) + pennies;

    if (value == 100) {
        cout << "You entered one dollar!";
    } else if (value < 100) {
        cout << "You entered less than one dollar.";
    } else {
        cout << "You entered more than one dollar.";
    }

    return 0;
}