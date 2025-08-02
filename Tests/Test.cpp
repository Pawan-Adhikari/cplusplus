//test.cpp
//Need to test whether you do or dont need default constructor if you have parameterized constructor with default parameters.

#include <iostream>

using namespace std;

class Cartesian {
private:
    int x,y;
public:
    Cartesian(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void display() const{
        cout << "x = " << x << endl;
        cout << "y = " << y <<endl;
        cout << "_______" << endl;
    }
    friend Polar;
};

class Polar{
    int r, theta;
    Polar( int _r = 0, int _theta = 0) : r(_r), theta(_theta) {}
    void display () const {
        cout << "r = " << r << endl;
        cout << "theta = " << theta << endl;
    }
};

int main() {

    return 0;
}