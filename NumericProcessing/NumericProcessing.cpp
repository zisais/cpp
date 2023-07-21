/**
 * Using Files—Numeric Processing
 * 
 * If you have downloaded the source code, you will find a file named Random.txt in the Chapter 5 folder
 * (it is also present in Canvas). This file contains a long list of random numbers. Copy the file to your
 * hard drive and then write a program that opens the file, reads all the numbers from the file, and
 * calculates the following:
 * 
 *   The number of numbers in the file
 * 
 *   The sum of all the numbers in the file (a running total)
 * 
 *   The average of all the numbers in the file
 * 
 * The program should display the number of numbers found in the file, the sum of the numbers, and the
 * average of the numbers
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    int number = 0;
    int numberOfNumbers = 0;
    int sumOfNumbers = 0;
    int avgOfNumbers = 0;

    inputFile.open("Random.txt");

    while(inputFile >> number) 
    {
        numberOfNumbers++;
        sumOfNumbers += number;
    }

    avgOfNumbers = sumOfNumbers / numberOfNumbers;

    cout << "There are " << numberOfNumbers << " numbers in the file." << endl
         << "The sum of the numbers is " << sumOfNumbers << endl
         << "The average of the numbers is " << avgOfNumbers << endl;
    
    return 0;
}