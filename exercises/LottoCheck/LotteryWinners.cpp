/**
 * Lottery Winners
 * 
 * A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit “lucky” combinations.
 * Write a program that initializes an array or a vector with these numbers and then lets the player enter this
 * week’s winning 5-digit number. The program should perform a linear search through the list of the player’s
 * numbers and report whether or not one of the tickets is a winner this week. Here are the numbers:
 * 
 *   13579 26791 26792 33445 55555
 *   62483 77777 79422 85647 93121
*/

#include <iostream>
using namespace std;
int main()
{
    const int size = 10;
    int lottoNums[size] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};

    int winner;
    cout << "Enter winning numbers";
    cin >> winner;

    int index = 0;
    bool found = false;
    while(!found && index < size)
    {
        for(int i=0;i<size;i++)
        {
            if(winner == lottoNums[i])
            {
                found = true;
                break;
            }
        }
        index++;
    }

    if(found)
    {
        cout << "WINNER\n";
    } else {cout << "No winner";}

    return 0;
}