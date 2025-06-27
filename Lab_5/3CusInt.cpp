//3CusInt.cpp
//Create a custom int class and overload relational operators.

#include <iostream>

using namespace std;

class MyInt {
private:
    int a;
public:
    MyInt(){
        a = 0;
    }
    MyInt(int x){
        a = x;
    }

    void DisplayInt(){
        cout << a << endl;
    }

    bool operator == (MyInt &x){
            return (this->a == x.a); 
        }
    bool operator >= (MyInt &x){
            return (this->a >= x.a); 
        }
    bool operator != (MyInt &x){
            return (this->a != x.a); 
        }
    bool operator <= (MyInt &x){
            return (this->a <= x.a); 
        }
    bool operator < (MyInt &x){
            return (this->a < x.a); 
        }
    bool operator > (MyInt &x){
            return (this->a > x.a); 
        }
};

int main() {
    MyInt a(4),b(5);

    a.DisplayInt();
    b.DisplayInt();

    cout << "==\t" << (a == b) << endl;
    cout << ">=\t" << (a >= b) << endl;
    cout << "!=\t" << (a != b) << endl;
    cout << "<=\t" << (a <= b) << endl;
    cout << "<\t" << (a < b) << endl;
    cout << ">\t" << (a > b) << endl;

    return 0;
}