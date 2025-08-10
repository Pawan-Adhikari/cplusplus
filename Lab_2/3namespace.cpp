//3namespace.cpp
//Demostrating namespace use

#include <iostream>
using namespace std;

namespace Cube{
    int num;
    int fun(int n) {return n*n*n;}
}

namespace Square{
    int num;
    int fun(int n) {return n*n;}
}

int main(){
    Cube::num = 4;
    Square::num = 3;
    cout << "Cube: " << Cube::fun(Square::num) <<endl;
    cout << "Square: " << Square::fun(Cube::num) <<endl;
}