//SubclassMemory.cpp
//Understand how memory is allocated for subclasses in single inheritance.

#include <iostream>

using namespace std;

class Base {
private:
    int a;
protected:
    int b;
public:
    int c;
    void AddDisplay(){
        cout <<"A: " << &a << endl;
        cout <<"B: " << &b << endl;
        cout <<"C: " << &c << endl;
    }
    Base() : a(0),b(0),c(0) {}
};

class Derived: public Base {
private:
    int d;
    int e;
public:
    Derived() :  d(0), e(0) {
        b = 0;
        c = 0;
    }
    void AddDisplay(){
        Base::AddDisplay();
        cout <<"D: " << &d << endl;
        cout <<"E: " << &e << endl;
    }
};  

int main(void) {
    Base b1;
    Derived d1;
    cout << "Base Class Addresses: " <<endl;
    b1.AddDisplay();
    cout << "Derived Class Addresses: " <<endl;
    d1.AddDisplay();
}

