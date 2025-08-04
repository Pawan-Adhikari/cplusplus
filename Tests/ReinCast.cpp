//ReinCast.cpp
//Testing out reinterpret_cast<>

#include <iostream>

using namespace std;

int main() {
    int dumNum = 10;
    int *num = &dumNum;
    *num = 100;

    cout << typeid(num).name() << endl;

    cout << typeid(reinterpret_cast<char*>(num)).name() << endl;

    cout << typeid(num).name() << endl;

    return 0;
}