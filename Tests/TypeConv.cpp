//TypeConv.cpp

#include <iostream>

using namespace std;

class engDist {
private:
    int feet;
    int inch;
public:
    engDist(){
        cout << "Enter feet: "; cin >> feet;
        cout << "Enter inches: "; cin >> inch;
    }    
    engDist(int f, int i) : feet(f), inch(i) {}
    operator float(){
        return (feet * 12 + inch);
    }
    const void showData() const{
        cout << "Feet: " << feet << endl;
        cout << "Inches: " << inch << endl;
    }
};

class metricDist{
    int meter;
    int centimeter;
public:
    metricDist(){
        cout << "Enter meters: "; cin >> meter;
        cout << "Enter centimeters: "; cin >> centimeter;
    }
    operator engDist(){
        cout << "Converting Metric to Feet Inches....." << endl;
        int cm = (meter * 100) + centimeter;
        cout << "We have total centimeters: " << cm << endl;
        float inches = 0.394 * cm; 
        cout << "We have total inches: " << inches << endl;
        int feet = int(inches/12);
        cout << "We have total feet: " << feet << endl;
        inches = inches - feet * 12;
        cout << "We have remaining inches: " << inches << endl;
        cout << "Conversion Successfull!" << endl;
        return(engDist(feet, inches));
    }

    const void showData() const{
        cout << "Meter: " << meter << endl;
        cout << "CentiMeter: " << centimeter << endl;
    }
};


int main() {
    metricDist m1;
    engDist f1 = m1;
    m1.showData();
    f1.showData();
    return 0;
}