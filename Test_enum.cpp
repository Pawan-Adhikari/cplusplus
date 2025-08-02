//test_enum.cpp
//testing what the data types of values of enums and others.

#include <iostream>


using namespace std;

string test = "Im Testing";

enum Days{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main() {
    Days *d = new Days;
    int a = 5;
    //Days d1 = 5;
    Days d1 = Friday;
    cout << typeid(d).name() << endl; 
    cout << typeid(Sunday).name() << endl;
    cout << Sunday << endl;
    cout << *d << endl;
    //cout << Days << endl;
    delete d;
    return 0;
}