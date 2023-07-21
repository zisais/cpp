/**
 * Character Analysis
 * 
 * In Canvas, find a file called "text.txt". Write a program that reads the file’s contents and determines the following:
 * 
 *   The number of uppercase letters in the file
 * 
 *   The number of lowercase letters in the file
 * 
 *   The number of digits in the file
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int upperCount = 0;
    int lowerCount = 0;
    int digitCount = 0;

    string data = "";
    int lineCounter = 0;
    ifstream file("text.txt");
        while (getline(file, data))
        {
            lineCounter++;
        }
    file.close();

    file.open("text.txt");
        for(int i=0;i<lineCounter;i++)
        {
            getline(file, data);
            for(int j=0;j<data.length();j++)
            {
                if (isupper(data[j]))
                {
                    upperCount++;
                } else if (islower(data[j]))
                {
                    lowerCount++;
                } else if (isdigit(data[j]))
                {
                    digitCount++;
                }
            }
        }
    file.close();

    cout << "Total uppercase characters: " << upperCount << endl;
    cout << "Total lowercase characters: " << lowerCount << endl;
    cout << "Total digits: " << digitCount << endl;

    return 0;
}