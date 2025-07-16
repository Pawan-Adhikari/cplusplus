#include <iostream>

using namespace std;
class X
{
public:
    int a; void fa(); // visible to all: users of X,
    // X itself, and derived classes
protected:
    int b; void fb(); // visible to derived classes and X,
    // but not to users of class X!
private:
    int c; void fc(); // of X
    // only visible to member functions
    };
    // Y "is an" X
class Y : public X 
{
    void foo() { Y y;
    a = 0; fa(); // OK x.a = 0; // OK
    b = 0; fb(); // OK y.a = 0; // OK
    } 
    int d;
};
int main(){
    X x;
    Y y;
}