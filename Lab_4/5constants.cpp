//5constants.cpp
//demonstrate constant mem functions and objects.

#include<string>
#include <iostream>
using namespace std;

class testClass{
    private:
        int number;
    public:
        testClass(int n){
            number = n;
        }

        void displayNum(){
            cout<<number;
        }

        void displayNumplus2() const{
            cout <<number+2;
        }
};

int main() {
    // Non-constant object
    testClass obj1(10);

    // Constant object
    const testClass obj2(20);

    // i) const_object.non_const_mem_function
    // Uncommenting the following line will cause a compilation error because a constant object cannot call a non-constant member function.
    // obj2.displayNum();

    // ii) const_object.const_mem_function
    // A constant object can call a constant member function.
    obj2.displayNumplus2();

    // iii) non_const_object.non_const_mem_function
    // A non-constant object can call a non-constant member function.
    obj1.displayNum();

    // iv) non_const_object.const_mem_function
    // A non-constant object can also call a constant member function.
    obj1.displayNumplus2();

    return 0;
}