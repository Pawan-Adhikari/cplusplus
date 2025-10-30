#include <iostream>

using namespace std;

class base {
    int priNum;
protected:
    int proNum;
public:
    void read_BpriNum(){
        cout << "Enter Base Private Number:" << endl;
        cin >> priNum;
    }
    void show_BpriNum(){
        cout << "Base Private Number:"<< priNum << endl;
    }
};

class derived : public base {
    int priNum;
public:
    void read_DpriNum(){
        cout << "Enter Derived Private Number: " <<endl;
        cin >> priNum;
    }
        void show_DpriNum(){
        cout << "Derived Private Number:"<< priNum << endl;
    }
};

int main(){
    base b1;
    derived d1;
    d1.read_BpriNum();
    d1.show_BpriNum();
    d1.read_DpriNum();
    d1.show_DpriNum();
}