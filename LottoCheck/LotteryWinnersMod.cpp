/**
 * Lottery Winners Modification
 *
 * Modify the program you wrote for Programming Challenge 2 (Lottery Winners) so it performs a binary search
 * instead of a linear search. Here are the numbers:
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

    int first = 0,
        last = size - 1,
        middle;
    bool found = false;
    while(!found)
    {
        middle = (first + last) / 2;
        if(lottoNums[middle] == winner)
        {
            found = true;
        } else if(winner < lottoNums[middle])
        {
            last = middle;
        } else if(winner > lottoNums[middle])
        {
            first = middle;
        }
    }

    if(found)
    {
        cout << "WINNER\n";
    } else {cout << "No winner";}

    return 0;
}