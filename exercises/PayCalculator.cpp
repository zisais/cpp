/**
 * Multipurpose Payroll
 * 
 * Write a program that calculates pay for either an hourly paid worker or a salaried 
 * worker. Hourly paid workers are paid their hourly pay rate times the number of 
 * hours worked. Salaried workers are paid their regular salary plus any bonus they 
 * may have earned. The program should declare two structures for the following data:
 * 
 * Hourly Paid:
 *  Hours Worked
 *  HourlyRate
 * 
 * Salaried:
 *  Salary
 *  Bonus
 * 
 * The program should also declare a union with two members. Each member should be a 
 * structure variable: one for the hourly paid worker and another for the salaried 
 * worker. The program should ask the user whether he or she is calculating the pay 
 * for an hourly paid worker or a salaried worker. Regardless of which the user 
 * selects, the appropriate members of the union will be used to store the data that 
 * will be used to calculate the pay.
*/

#include <iostream>
#include <iomanip>
using namespace std;

struct HourlyWorker
{
    float hoursWorked;
    float hourlyRate;
};

struct SalariedWorker
{
    float salary;
    float bonus;
};

union Worker
{
    HourlyWorker hourly;
    SalariedWorker salaried;
};

void calcHourly();
void calcSalary();

int main()
{
    bool isHourly;
    char ans;
    cout << "Calculating pay for hourly or salaried worker? h/s: ";
    cin >> ans;

    if (toupper(ans) == 'H') {isHourly = true;}
    else if (toupper(ans) == 'S') {isHourly = false;}
    else {
        cout << "Invalid entry.\n";
        return 0;
    }

    switch (isHourly)
    {
    case true:
        calcHourly();
        break;
    case false:
        calcSalary();
        break;
    }

    return 0;
}

void calcHourly()
{
    Worker empl;
    float tempHours;
    float tempPay;
    bool invalid = false;
    do
    {
        cout << "How many hours have you worked?\n";
        cin >> tempHours;
        if (tempHours < 0 || tempHours > 80)
        {
            cout << "Invalid input, must be positive value with a maximum value of 80.\n";
            invalid = true;
        } else 
        {
            empl.hourly.hoursWorked = tempHours;
            invalid = false;
            cout << "What is your hourly pay rate?\n";
            cin >> tempPay;
            if (tempPay < 0)
            {
                cout << "Invalid input, must be a positive value.\n";
                invalid = true;
            } else
            {
                empl.hourly.hourlyRate = tempPay;
                invalid = false;
            }
        }
    } while (invalid);
    
    cout << "Your pay for the week: $" << fixed << setprecision(2) << empl.hourly.hoursWorked * empl.hourly.hourlyRate;
}

void calcSalary()
{
    Worker empl;
    float tempSalary;
    float tempBonus;
    bool invalid;
    do
    {
        cout << "What is your salary?\n";
        cin >> tempSalary;
        if (tempSalary < 0)
        {
            cout << "Invalid entry, must be a positive value.\n";
            invalid = true;
        } else
        {
            empl.salaried.salary = tempSalary;
            invalid = false;
            cout << "What is your bonus for the pay period?\n";
            cin >> tempBonus;
            if (tempBonus < 0)
            {
                cout << "Invalid input, must be a positive value.\n";
                invalid = true;
            } else
            {
                empl.salaried.bonus = tempBonus;
                invalid = false;
            }
        }
    } while (invalid);

    cout << "Your pay for the week: $" << fixed << setprecision(2) << (empl.salaried.salary / 52) + empl.salaried.bonus;
}