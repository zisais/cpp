/**
 * Hotel Occupancy
 * 
 * Write a program that calculates the occupancy rate for a hotel. The program should start by asking the user
 * how many floors the hotel has. A loop should then iterate once for each floor. In each iteration, the loop
 * should ask the user for the number of rooms on the floor and how many of them are occupied. After all the
 * iterations, the program should display how many rooms the hotel has, how many of them are occupied, how many
 * are unoccupied, and the percentage of rooms that are occupied. The percentage may be calculated by dividing
 * the number of rooms occupied by the number of rooms.
 * 
 * Input Validation: Do not accept a value less than 1 for the number of floors. Do not accept a number less
 * than 10 for the number of rooms on a floor.
 * 
 * NOTE- It is traditional that most hotels do not have a thirteenth floor. The loop in this program should
 * skip the entire thirteenth iteration.
*/

#include <iostream>
using namespace std;

int main() {
    int floors = 0;
    int roomsPerFloor[] = {0};
    int occupiedPerFloor[] = {0};

    int totalRooms = 0;
    int totalOccupied = 0;
    int totalVacant = 0;
    float percentOccupied = 00.00;

    {
        bool valid = false;
        while (!valid) {
            int temp = 0;
            cout << "How many floors?" << endl;
            cin >> temp;

            if (temp >= 1) {
                valid = true;
                floors = temp;
            } else {cout << "Must be at least one." << endl;}
        }
    }

    {
        int floor = 1;
        for (int i=0;i<floors;i++) {
            if (floor == 13) {
                floor ++;
            }

            bool valid = false;
            while (!valid) {
                int temp = 0;
                cout << "How many rooms are on floor " << floor << '?' << endl;
                cin >> temp;
                
                if (temp >= 10) {
                    valid = true;
                    roomsPerFloor[i] = temp;
                    totalRooms += temp;
                } else {cout << "Must be at least 10." << endl;}
            }
            
            cout << "How many on this floor are occupied?" << endl;
            cin >> occupiedPerFloor[i];
            totalOccupied += occupiedPerFloor[i];
            floor++;
        }
    }

    totalVacant = totalRooms - totalOccupied;
    percentOccupied = (static_cast<float>(totalOccupied) / static_cast<float>(totalRooms)) * 100;

    cout << "The hotel has " << totalRooms << " rooms." << endl;
    cout << totalOccupied << " of the rooms are occupied, and " << totalVacant << " of them are vacant." << endl;
    cout << "This means the hotel is " << percentOccupied << "% filled." << endl;

    return 0;
}