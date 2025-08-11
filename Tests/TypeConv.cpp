//TypeConv.cpp

#include <iostream>

using namespace std;

class engdist {
private:
    int feet;
    int inch;
public:
    void getdist(){
        cout << "Enter feet: "; cin >> feet;
        cout << "Enter inches: "; cin >> inch;
    }    
    operator float(){
        return feet * 12 + inch;
    }
    ~engdist();
    
};

int main() {
    const int a = 5;
    int* p = const_cast<int*>(&a);  // Removing constness
    *p = 10; 
    return 0;
}