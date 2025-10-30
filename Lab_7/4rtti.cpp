//4rtti.cpp
//Create a polymorphic class Vehicle and create other derived classes Bus, Car, and Bike from Vehicle. Illustrate RTTI by the use of dynamic_cast and typeid operators in this program.

#include <iostream>

using namespace std;

class Vehicle {
protected:
    int wheels;
public:
    Vehicle(int wh) : wheels(wh) {};
    virtual void displayWheels() = 0;
};

class Bus : public Vehicle{
    public:
    Bus(int wh) : Vehicle (wh) {};
    void displayWheels() {
        cout << wheels << endl;
    }
};

class Car : public Vehicle{
    public:
    Car(int wh) : Vehicle (wh) {};
    void displayWheels() {
        cout << wheels << endl;
    }
};
int main() {
    Vehicle *v1,*v2;
    Bus *b,b1(4);
    Car c1(4);
    v1 = &b1;
    v2 = &c1;
    b = dynamic_cast<Bus*>(v1);
    if (b) {
        cout << "v1 is a Bus type." << endl;
    }
    else{
        cout << "v1 is not Bus Type." << endl;
    }
    cout << "The unmangled type of v2 is :" << typeid(*v2).name() <<endl;
    return 0;
}