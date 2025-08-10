//4lartemp.cpp
// function that passes two temperatures by reference and sets the larger of the two numbers to a value entered by user by using return by reference.

#include <iostream>
using namespace std;

int& larger(int &t1, int&t2){
    if (t1>t2) return t1;
    else return t2;
}

int main(){
    int temp1 = 0;
    int temp2 = 100;
    int &large = larger(temp1, temp2);
    cout << large << endl;

    cout << &temp1 << endl;
    cout << &temp2 << endl;
    cout << &large << endl;
}