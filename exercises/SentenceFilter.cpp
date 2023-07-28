/**
 * Sentence Filter
 *
 * Write a program that asks the user for two file names. The first file will be
 * opened for input and the second file will be opened for output. (It will be
 * assumed that the first file contains sentences that end with a period.) The
 * program will read the contents of the first file and change all the letters to
 * lowercase except the first letter of each sentence, which should be made
 * uppercase. The revised contents should be stored in the second file.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    string file1 = "";
    string file2 = "";
    string lineIn = "";
    string lineOut = "";

    cout << "Enter the read file: ";
    cin >> file1;
    cout << "Enter the write file: ";
    cin >> file2;

    ifstream iFile(file1);
    ofstream oFile(file2);
    cin.ignore();
    while (getline(iFile, lineIn))
    {
        bool startingChar = true;
        for (int i = 0; i < lineIn.length(); i++)
        {
            if (isalpha(lineIn[i]) && startingChar)
            {
                lineOut.push_back(toupper(lineIn[i]));
                startingChar = false;
            }
            else
            {
                lineOut.push_back(tolower(lineIn[i]));
            }

            if (lineIn[i] == '.' || lineIn[i] == '!' || lineIn[i] == '?')
            {
                startingChar = true;
            }
        }

        oFile << lineOut << endl;
        lineOut = "";
    }
    iFile.close();
    oFile.close();

    cout << "Done.";

    return 0;
}