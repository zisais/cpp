/**
 * Name Search
 * 
 * This exercise will use the following files:
 * 
 *   GirlNames.txt—This file contains a list of the 200 most popular names given to girls born in the United States from 2000 to 2009.
 * 
 *   BoyNames.txt—This file contains a list of the 200 most popular names given to boys born in the United States from 2000 to 2009.
 * 
 * Write a program that reads the contents of the two files into two separate arrays or vectors. The user
 * should be able to enter a boy’s name, a girl’s name, or both, and the application should display messages
 * indicating whether the names were among the most popular.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    ifstream inputFile;

    string girlNames[200];
    string boyNames[200];

    inputFile.open("GirlNames.txt");
    string girlName;
    for(int i=0;i<200;i++)
    {
        inputFile >> girlName;
        girlNames[i] = girlName;
    }
    inputFile.close();

    inputFile.open("BoyNames.txt");
    string boyName;
    for (int i=0;i<200;i++)
    {
        inputFile >> boyName;
        boyNames[i] = boyName;
    }
    inputFile.close();

    vector<string> findNames;
    string name;
    char answer;
    bool again = true;
    while(again)
    {
        cout << "Enter a name to search for.\n";
        cin >> name;
        findNames.push_back(name);

        cout << "Add another name to the search? y/n\n";
        cin >> answer;

        if(answer == 'y')
        {
            again = true;
        } else if (answer == 'n')
        {
            again = false;
        }
    }

    bool found = false;
    for(int i=0;i<findNames.size();i++)
    {
        for(int j=0;j<200;j++)
        {
            if(findNames[i] == boyNames[j] || findNames[i] == girlNames[j])
            {
                cout << "Found " << findNames[i] << endl;
                found = true;
            }
        }
    }

    if(!found)
    {
        cout << "No names found.";
    }

    return 0;
}