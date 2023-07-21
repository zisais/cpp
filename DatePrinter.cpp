/**
 * Date Printer
 * 
 * Write a program that reads a string from the user containing a date in the form mm/dd/yyyy.
 * It should print the date in the form March 12, 2014.
*/

#include <iostream>
using namespace std;

char* getMonthName(int monthNum);

int main()
{
    const int SIZE = 11; // max space needed for holding date chars.
    const int smSIZE = 5; // space needed for YYYY.
    const int mnthSIZE = 10; // longest month name is 9 chars (september).

    char entry[SIZE] = "";
    char month[mnthSIZE] = "";
    
    int mm = 0;
    int dd = 0;
    int yyyy = 0;
    
    cout << "Enter a date in MM/DD/YYYY format: ";
    cin >> entry;

    char num[smSIZE] = "";
    int section = 0; // section of date. 0 is MM, 1 is DD, 2 is YYYY.
    for(int i=0;i<sizeof(entry);i++)
    {
        if (isdigit(entry[i]))
        {
            char* ptr = &entry[i];
            strncat(num, ptr, 1);
        }
        else if(ispunct(entry[i]) || i == sizeof(entry) - 1)
        {
            switch (section)
            {
                case 0:
                    mm = atoi(num);
                    break;
                case 1:
                    dd = atoi(num);
                    break;
                case 2:
                    yyyy = atoi(num);
                    break;
            }
            section++;
            num[0] = '\0';
        }
    }

    strcat(month, getMonthName(mm));

    cout << month << ' ' << dd << ", " << yyyy << ".\n";

    return 0;
}

char* getMonthName(int monthNum)
{
    char monthName[10] = "";

    switch (monthNum)
    {
        case 1:
            strcpy(monthName, "January");
            break;

        case 2:
            strcpy(monthName, "February");
            break;

        case 3:
            strcpy(monthName, "March");
            break;

        case 4:
            strcpy(monthName, "April");
            break;

        case 5:
            strcpy(monthName, "May");
            break;

        case 6:
            strcpy(monthName, "June");
            break;

        case 7:
            strcpy(monthName, "July");
            break;

        case 8:
            strcpy(monthName, "August");
            break;

        case 9:
            strcpy(monthName, "September");
            break;

        case 10:
            strcpy(monthName, "October");
            break;

        case 11:
            strcpy(monthName, "November");
            break;

        case 12:
            strcpy(monthName, "December");
            break;

        default:
            cout << "Month must be from 1 to 12." << endl;
            exit(0);
    }
    
    return monthName;
}