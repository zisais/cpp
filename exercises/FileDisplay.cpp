/**
 * File Display Program
 *
 * Write a program that asks the user for the name of a file. The program should display the contents
 * of the file on the screen. If the file’s contents won’t fit on a single screen, the program should
 * display 24 lines of output at a time, and then pause. Each time the program pauses, it should wait
 * for the user to strike a key before the next 24 lines are displayed.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int numLines = 0;
    string line = "";
    string fileName = "";
    vector<string> lines;

    cout << "Enter a file name: ";
    cin >> fileName;

    ifstream file(fileName);
    cin.ignore();
    while (getline(file, line))
    {
        numLines++;
        lines.push_back(line);
    }
    file.close();

    for (int index = 0; index < lines.size(); index++)
    {
        if (index > 0 && index % 23 == 0) // 23 because index 24 is the 25th line
        {
            cout << lines[index] << endl;
            cout << "CONTINUE\n";
            cin.get();
        }
        else
        {
            cout << lines[index] << endl;
        }
    }

    return 0;
}