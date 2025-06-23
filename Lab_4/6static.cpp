//6static.cpp
//illustrate the use of static data members

#include <iostream>
using namespace std;

class SerialNumber {
private:
    int serial; // Holds the serial number for the object
    static int count; // Static data member to track the number of objects created

public:
    // Constructor
    SerialNumber() {
        count++;       // Increment the static counter
        serial = count; // Assign the current count as the serial number
    }

    // Static member function to get the total number of objects created
    static int getCount() {
        return count;
    }

    // Member function to display the serial number of the object
    void displaySerial() const {
        cout << "Serial Number: " << serial << endl;
    }
};

// Initialize the static data member
int SerialNumber::count = 0;

int main() {
    // Create objects
    SerialNumber obj1, obj2, obj3;

    // Display serial numbers for each object
    obj1.displaySerial();
    obj2.displaySerial();
    obj3.displaySerial();

    // Use the static member function to display the total number of objects created
    cout << "Total objects created: " << SerialNumber::getCount() << endl;

    return 0;
}