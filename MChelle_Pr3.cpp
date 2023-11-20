#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    const int MIN_ROOMS = 1,
        MAX_ROOMS = 30,
        MIN_FLOORS = 1,
        MAX_FLOORS = 5,
        PROJECT_NUM = 3,
        SINGLE_ROOM_PRICE = 60,
        DOUBLE_ROOM_PRICE = 75,
        KING_ROOM_PRICE = 100,
        SUITE_ROOM_PRICE = 150;

    string location;
    const string PROGRAMMER = "Maya V.",
        DUE_DATE = "11/07/2021";

    int floorNum, totalRooms = 0, totalOccupiedRooms = 0, totalUnoccupiedRooms = 0,
        lowestRoomsFloor = 6, lowestRooms = 31;
    double totalIncome = 0, lowestOccupancyRate = 2, totalOccupancyRate;

    cout << setw(100) << setfill('=') << "\n"
        << setw(55) << setfill(' ') << "BlueMont Hotel\n"
        << setw(100) << setfill('=') << "\n\n";

    cout << "Enter the location of this hotel chain: ";
    getline(cin, location);

    cout << "Enter the total number of floors of this hotel chain: ";
    cin >> floorNum;

    while (floorNum < MIN_FLOORS || floorNum > MAX_FLOORS)
    {
        cout << "Error: The number of floors should be between " << MIN_FLOORS << " and " << MAX_FLOORS << "!! Please try again.\n\n";
        cout << "Enter the total number of floors of this hotel chain: ";
        cin >> floorNum;
    }

    for (int i = 1; i <= floorNum; i++)
    {
        int floorRooms, singleRooms, doubleRooms, kingRooms, suiteRooms;

        cout << "Enter the total number of rooms on floor " << i << ": ";
        cin >> floorRooms;
        totalRooms += floorRooms;

        while (floorRooms < MIN_ROOMS || floorRooms > MAX_ROOMS)
        {
            cout << "Error: The number of rooms should be between " << MIN_ROOMS << " and " << MAX_ROOMS << "!! Please try again.\n";
            cout << "Enter the total number of rooms on floor " << i << ": ";
            cin >> floorRooms;
        }

        // Initialize floorOccupiedRooms with an invalid value
        int floorOccupiedRooms = MAX_ROOMS + 1;

        do
        {
            cout << "How many SINGLE rooms are occupied in floor " << i << "? ";
            cin >> singleRooms;

            cout << "How many DOUBLE rooms are occupied in floor " << i << "? ";
            cin >> doubleRooms;

            cout << "How many KING rooms are occupied in floor " << i << "? ";
            cin >> kingRooms;

            cout << "How many SUITE rooms are occupied in floor " << i << "? ";
            cin >> suiteRooms;

            // Recalculate floorOccupiedRooms
            floorOccupiedRooms = suiteRooms + kingRooms + doubleRooms + singleRooms;

            if (floorOccupiedRooms > floorRooms)
            {
                cout << "Error: Total occupied rooms on floor " << i << " exceeds total rooms on floor!!\n";
            }

        } while (floorOccupiedRooms > floorRooms);

        totalOccupiedRooms += floorOccupiedRooms;
        totalIncome += (SINGLE_ROOM_PRICE * singleRooms) + (DOUBLE_ROOM_PRICE * doubleRooms) +
            (KING_ROOM_PRICE * kingRooms) + (SUITE_ROOM_PRICE * suiteRooms);

        if ((static_cast<double>(floorOccupiedRooms) / floorRooms) < lowestOccupancyRate)
        {
            lowestOccupancyRate = (static_cast<double>(floorOccupiedRooms) / floorRooms);
            lowestRoomsFloor = i;
        }

        if (floorRooms < lowestRooms)
        {
            lowestRooms = floorRooms;
            lowestRoomsFloor = i;
        }
    }

    totalUnoccupiedRooms = totalRooms - totalOccupiedRooms;
    totalOccupancyRate = (static_cast<double>(totalOccupiedRooms) / totalRooms) * 100;

    cout << setw(80) << setfill('=') << "\n"
        << setw(50) << setfill(' ') << "BlueMont Hotel located in " << location << "\n"
        << setw(55) << setfill(' ') << "TODAY'S ROOM RATES(US$/night)\n"
        << setw(25) << setfill(' ') << "Single room"
        << setw(15) << setfill(' ') << "Double room"
        << setw(15) << setfill(' ') << "King room"
        << setw(15) << setfill(' ') << "Suite room\n"
        << setw(25) << SINGLE_ROOM_PRICE
        << setw(15) << DOUBLE_ROOM_PRICE
        << setw(15) << KING_ROOM_PRICE
        << setw(15) << setfill(' ') << SUITE_ROOM_PRICE << endl
        << setw(80) << setfill('=') << "\n";

    cout << setw(41) << setfill(' ') << right << "Hotel Income: $" << setprecision(2) << fixed << totalIncome << "\n"
        << setw(40) << right << "Total # of rooms: " << totalRooms << "\n"
        << setw(40) << right << "Total # Occupied Rooms: " << totalOccupiedRooms << "\n"
        << setw(40) << right << "Total # Unoccupied Rooms: " << totalUnoccupiedRooms << "\n"
        << setw(40) << right << "Occupancy Rate: " << setprecision(2) << totalOccupancyRate << "%\n";

    cout << "Floor " << lowestRoomsFloor << " with " << lowestRooms << " rooms has the least number of rooms.\n";
    if (totalOccupancyRate < 60)
        cout << "Need to improve occupancy rate!!\n";

    cout << "\n\nThank you for testing my program!!\n"
        << "PROGRAMMER: " << PROGRAMMER << "\n"
        << "CMSC140 Common Project " << PROJECT_NUM << endl
        << "Due Date: " << DUE_DATE << endl
        << endl;

    return 0;
}