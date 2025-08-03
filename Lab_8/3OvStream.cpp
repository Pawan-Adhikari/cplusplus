//3OvStream.cpp
//overload stream operators to read a complex number and display the complex number in a+ib format.

#include <iostream>

using namespace std;

class Complex {
private:
    int real, img;
public:
    Complex(int real_ = 0, int img_ = 0): real(real_), img(img_){}
    friend ostream& operator << (ostream &os, Complex &cp);
    friend istream& operator >> (istream &is, Complex &cp);
};
ostream& operator << (ostream &os, Complex &cp){
    os << cp.real << showpos << cp.img << "i";
    return os;
}
istream& operator >> (istream &is, Complex &cp){
    cout << "Enter real part: ";
    is >> cp.real;
    cout << "Enter imaginary part: ";
    is >> cp.img;
    return is;
}
int main() {
    Complex myComp;
    cin >> myComp;
    cout << myComp << endl;
    return 0;
}