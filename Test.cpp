//test.cpp
//Need to test whether you do or dont need default constructor if you have parameterized constructor with default parameters.

#include <iostream>

using namespace std;

class TestClass {
private:
    int x,y;
public:
    TestClass(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void display() const{
        cout << "x = " << x << endl;
        cout << "y = " << y <<endl;
        cout << "_______" << endl;
    }
};

int main() {
    TestClass t1{}, t2, t3(1), t4(1,2);
    t1.display(); 
    t2.display();
    t3.display();
    t4.display();
    return 0;
}