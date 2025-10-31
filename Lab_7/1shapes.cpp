//1shapes.cpp
//base class Shape with virtual functions and virtual destructor, and derived classes Circle, Rectangle, and Trapezoid that override area() and display() to demonstrate polymorphism.

#include <iostream>

using namespace std;

class Shape {
protected:
    int a;
    int b;
public:
    Shape(){}
    Shape(int a1, int b1): a(a1), b(b1){}

    virtual float area(){
        return (a*b);
    }
    virtual void display(){
        cout << a << endl;
        cout << b <<endl;
    }
    
    virtual ~Shape(){cout<<"Base destructor"<<endl;}
};

class circle : public Shape{
private:
    int radius;
public:
    circle(int r): radius(r){}
    float area(){
        return (3.14*radius*radius);
    }
    void display(){
        cout << radius << endl;
    }
    ~circle(){cout<<"Circle destructor"<<endl;}
};

class rectangle:public Shape {
public:
    rectangle(int a1, int b1): Shape(a1, b1){} //Discussion 1
    float area(){
        return (a*b);
    }
    void display(){
        cout << a << endl;
        cout << b <<endl;
    }
    ~rectangle(){cout<<"Rectangle destructor"<<endl;}
};

int main() {
    Shape *circ, *rec;
    //circle c(5);
    //rectangle r(10,5);
    //circ = &c;
    //rec = &r;
    circ = new circle(5);
    rec = new rectangle(10,5);
    circ->display();
    rec->display();
    cout << "Area of circle: " << circ->area() <<endl; 
    cout << "Area of rectangle: " << rec->area() <<endl; 
    delete circ;
    delete rec;
    return 0;
}