//feet_to_inches.cpp
//Program using function overloading to convert feet to inches
//Using no argument, one argument, and two arguments with pass by reference

#include<iostream>
using namespace std;

// Function with no arguments - uses default value
double feetToInches() {
    double defaultFeet = 1.0;
    return defaultFeet * 12.0;
}

// Function with one argument - simple conversion
double feetToInches(double feet) {
    return feet * 12.0;
}

// Function with two arguments - uses pass by reference
void feetToInches(double feet, double &inches) {
    inches = feet * 12.0;
}

int main() {
    cout << "Function Overloading: Feet to Inches Conversion\n" << endl;
    
    // Using function with no arguments
    cout << "1. No argument function (default 1 foot):" << endl;
    cout << "Result: " << feetToInches() << " inches" << endl;
    cout << endl;
    
    // Using function with one argument
    cout << "2. One argument function (5.5 feet):" << endl;
    cout << "Result: " << feetToInches(5.5) << " inches" << endl;
    cout << endl;
    
    // Using function with two arguments (pass by reference)
    cout << "3. Two arguments function with pass by reference (3.25 feet):" << endl;
    double feet = 3.25;
    double inches;
    feetToInches(feet, inches);
    cout << feet << " feet = " << inches << " inches" << endl;
    cout << endl;
    
    // Interactive example
    cout << "Enter feet to convert: ";
    double userFeet;
    cin >> userFeet;
    
    cout << "Using one argument function: " << feetToInches(userFeet) << " inches" << endl;
    
    double resultInches;
    feetToInches(userFeet, resultInches);
    cout << "Using two argument function: " << resultInches << " inches" << endl;
    
    return 0;
}
