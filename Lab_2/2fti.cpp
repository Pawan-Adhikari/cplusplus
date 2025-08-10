//2fti.cpp
//Program using function overloading to convert feet to inches
//Using no argument, one argument, and two arguments with pass by reference

#include<iostream>
using namespace std;

double feetToInches() {
    double defaultFeet = 1.0;
    return defaultFeet * 12.0;
}

double feetToInches(double feet) {
    return feet * 12.0;
}

void feetToInches(double feet, double &inches) {
    inches = feet * 12.0;
}

int main() {
    cout << "Function Overloading: Feet to Inches\n";
    
    cout << "No args: " << feetToInches() << " inches\n";
    cout << "One arg (5.5): " << feetToInches(5.5) << " inches\n";
    
    double inches;
    feetToInches(3.25, inches);
    cout << "Two args (3.25): " << inches << " inches\n";
    
    return 0;
}
