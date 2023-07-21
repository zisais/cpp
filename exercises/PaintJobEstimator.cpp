/**
 * Paint Job Estimator
 * 
 * A painting company has determined that for every 110 square feet of wall space, one gallon of paint and
 * eight hours of labor will be required. The company charges $25.00 per hour for labor. Write a modular
 * program that allows the user to enter the number of rooms that are to be painted and the price of the paint
 * per gallon. It should also ask for the square feet of wall space in each room. It should then display the
 * following data:
 * 
 *   The number of gallons of paint required
 * 
 *   The hours of labor required
 * 
 *   The cost of the paint
 * 
 *   The labor charges
 * 
 *   The total cost of the paint job
 * 
 * Input validation: Do not accept a value less than 1 for the number of rooms. Do not accept a value less than
 * $10.00 for the price of paint. Do not accept a negative value for square footage of wall space.
*/

#include <iostream>
using namespace std;

int main () {
    const int sqFtPerGal = 110;
    const float sqFtperHour = 13.75; // 110 / 8
    const float pricePerHour = 25.00;
//inputs
    int numRooms = 0;
    float pricePerGal = 0.00;
    int sqFtPerRoom = 0;
    int totalSqFt;
//outputs
    int numGalReq = 0;
    float hoursLaborReq = 0.00;
    float costOfPaint = 0.00;
    float costOfLabor = 0.00;
    float totalCost = 0.00;

    bool invalidRooms = true;
    while (invalidRooms) {
        int placeholder;
        cout << "How many rooms? ";
        cin >> placeholder;
        if (placeholder < 1) {
            invalidRooms = true;
            cout << "Need at least one room." << endl ;
        } else {
            numRooms = placeholder;
            invalidRooms = false;
        }
    }

    bool invalidPrice = true;
    while (invalidPrice) {
        float placeholder;
        cout << "What is the price per gallon? ";
        cin >> placeholder;
        if (placeholder < 10.00) {
            invalidPrice = true;
            cout << "Price must be at least $10.00" << endl;
        } else {
            pricePerGal = placeholder;
            invalidPrice = false;
        }
    }

    bool invalidSqFt = true;
    while (invalidSqFt) {
        int placeholder;
        cout << "How many square feet of wall space in each room? ";
        cin >> placeholder;
        if (placeholder < 0) {
            invalidSqFt = true;
            cout << "Area can't be negative." << endl;
        } else {
            sqFtPerRoom = placeholder;
            invalidSqFt = false;
        }
    }

    totalSqFt = numRooms * sqFtPerRoom;
    if (totalSqFt % sqFtPerGal == 0) {
        numGalReq = totalSqFt / sqFtPerGal;
    } else {numGalReq = (totalSqFt / sqFtPerGal) + 1;}
    hoursLaborReq = totalSqFt / sqFtperHour;
    costOfPaint = numGalReq * pricePerGal;
    costOfLabor = hoursLaborReq * pricePerHour;
    totalCost = costOfLabor + costOfPaint;

    cout << "Gallons of paint required: " << numGalReq << endl << "Hours of labor required: " << hoursLaborReq << endl
        << "Cost of paint: $" << costOfPaint << endl << "Cost of labor: $" << costOfLabor << endl << "Total cost: $" << totalCost;

    return 0;
}