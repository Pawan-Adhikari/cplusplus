//1Cartesian.cpp
//Demonstration of friend function and friend classes

#include <iostream>

using namespace std;

class Coordinates;

class Adder {

    private:

    public:
        Coordinates sumcor(Coordinates &a, Coordinates &b);  
    };

class Calculator {

    private:

    public:
        Coordinates mulcor(Coordinates &a, Coordinates &b);  
        Coordinates divcor(Coordinates &a, Coordinates &b);  
    };


class Coordinates {
    private:
        int x,y;
    public:
        friend Coordinates Adder::sumcor(Coordinates &, Coordinates &);
        friend class Calculator;
        Coordinates(){
            x =0;
            y =0;
        }

        Coordinates(int xcor, int ycor){
            x =xcor;
            y =ycor;
        }

        void DisplayCoords(){
            cout << "(" << x << ", " << y << ")";
        }        
};


Coordinates Adder::sumcor(Coordinates &a, Coordinates &b){
    Coordinates temp;
    temp.x = a.x + b.x;  
    temp.y = a.y + b.y;
    return temp;
}

Coordinates Calculator::mulcor(Coordinates &a, Coordinates &b){
    Coordinates temp;
    temp.x = a.x * b.x;  
    temp.y = a.y * b.y;
    return temp;
}

Coordinates Calculator::divcor(Coordinates &a, Coordinates &b){
    Coordinates temp;
    temp.x = a.x / b.x;  
    temp.y = a.y / b.y;
    return temp;
}


int main() {

    Coordinates a,b,c;
    Coordinates d(5,6),e(2,3);
    Adder add;
    Calculator calc;

    cout << "Before: ";
    a.DisplayCoords();
    cout << endl;
    
    a = add.sumcor(d,e);  // Assign the result back to a
    b = calc.mulcor(d,e);
    c = calc.divcor(d,e);

    cout << "After: ";
    a.DisplayCoords();
    b.DisplayCoords();
    c.DisplayCoords();
    cout << endl;

    return 0;
}