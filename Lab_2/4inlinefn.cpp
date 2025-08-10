//4inlinefn.cpp
//demostrate inline functions

#include <iostream>
using namespace std;

inline float net(int salary){return (0.9*salary);}

int main(){
    int salary;
    cout << "Enter salary: " ; cin >> salary;
    cout << "Net payment: " << net(salary) <<endl;
    return 0;
}