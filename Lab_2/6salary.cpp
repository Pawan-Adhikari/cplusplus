//6salary.cpp
//Function to increase salary and display salaries

#include<iostream>
using namespace std;

double calculateNewSalary(double salary, double incrementPercent = 10.0) {
    return salary + (salary * incrementPercent / 100.0);
}

int main() {
    cout << "2010 Salaries:" << endl;
    cout << "CEO: Rs. " << calculateNewSalary(35000, 9.0) << endl;
    cout << "Info Officer: Rs. " << calculateNewSalary(25000, 10.0) << endl;
    cout << "System Analyst: Rs. " << calculateNewSalary(24000, 12.0) << endl;
    cout << "Programmer: Rs. " << calculateNewSalary(18000, 12.0) << endl;
    
    return 0;
}

