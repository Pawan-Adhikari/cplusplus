//2_3D.cpp
//Perform on 3D coordinates using overloaded operators

#include <iostream>

using namespace std;

class Coordinates;
Coordinates operator + (Coordinates &, Coordinates &);
Coordinates operator - (Coordinates &, Coordinates &);

class Coordinates {
private:
    int x,y,z;
public:
    Coordinates(){
        x=0;
        y=0;
        z=0;
    }
    Coordinates(int a, int b, int c){
        x=a;
        y=b;
        z=c;
    }
    void DisplayCoor(){
        cout << x << ","<< y <<endl;
    }    
    friend Coordinates operator + (Coordinates &, Coordinates &);
    friend Coordinates operator - (Coordinates &, Coordinates &);

};

Coordinates operator + (Coordinates &a, Coordinates &b){
    Coordinates temp;
    temp.x = a.x + b.x;
    temp.y = a.y + b.y;
    temp.z = a.z + b.z;
    return temp;
}
Coordinates operator - (Coordinates &a, Coordinates &b){
    Coordinates temp;
    temp.x = a.x - b.x;
    temp.y = a.y - b.y;
    temp.z = a.z - b.z;
    return temp;
}

int main() {
    Coordinates a,b;
    Coordinates c(3,4,5),d(2,5,3);

    a = c + d;
    b = c - d;

    a.DisplayCoor();
    b.DisplayCoor();

    return 0;
}