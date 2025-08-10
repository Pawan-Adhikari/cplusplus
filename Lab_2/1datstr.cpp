//1datstr.cpp
//Write a program to set a structure to hold a date (mm,dd and yy), assign values to the members of the structure and print out the values in the format 11/28/2004 by function. Pass the structure to the function

#include<iostream>
using namespace std;

struct date {
    int day, month, year;
    void display(){
        cout << month << "/";
        cout << day << "/";
        cout << year << endl;
    }
};

int main(){
    struct date d1;
    d1.day = 30;
    d1.month = 11;
    d1.year = 2006;
    d1.display();
}