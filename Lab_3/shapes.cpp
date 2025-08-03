#include <iostream>
#include <cmath>
using namespace std;

class circle{
    int radius;
public:
    void setdim(int r){ radius = r; }
    void setdim(){ cout<<"Enter the radius: \t"; cin >> radius; }
    void displaydim(){ cout<<"Radius: "<<radius<<endl; }
    float findArea(){ return (3.14*radius*radius); }
    float findPerimeter(){ return (2 * 3.14 * radius); }
};

class rectangle{
    int length, breadth;
public:
    void setdim(int l, int b){ length = l; breadth = b; }
    void setdim(){ cout<<"Enter the length: \t"; cin >> length; cout<<"Enter the breadth: \t"; cin >> breadth; }
    void displaydim(){ cout<<"length: "<<length<<" breadth :"<<breadth<<endl; }
    float findArea(){ return (length * breadth); }
    float findPerimeter(){ return (2 * (length + breadth)); }
};

class traingle{
    int a, b, c;
public:
    void setdim(int a1, int b1, int c1){ a = a1; b = b1; c = c1; }
    void setdim(){ cout<<"Enter the length of first side: \t"; cin >> a; cout<<"Enter the length of second side: \t"; cin >> b; cout<<"Enter the length of third side: \t"; cin >> c; }
    void displaydim(){ cout<<"first side: "<<a<<" second side :"<<b<<" third side :"<<c<<endl; }
    float findArea(){ float s = (a+b+c)/2; return (sqrt(s*(s-a)*(s-b)*(s-c))); }
    float findPerimeter(){ return (a + b + c); }
};

int main(){
    circle c1;
    rectangle r1;
    traingle t1;
    c1.setdim(5);
    cout<<c1.findArea();
}

