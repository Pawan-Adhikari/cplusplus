#include <iostream>

using namespace std;

class Grandparent{
    protected:
        int a;
    public:
        Grandparent(int a_ = 0) : a(a_) {}
        void display(){
            cout << "I am Grandparent and my value is: " << a << endl;
        }
};

class Parent1 : public Grandparent {
    public:
        Parent1(int a_ = 0) : Grandparent(a_) {}
        void display() override{
            cout << "I am Parent1 and my value is: " << a << endl;
        }
};

class Parent2 : public Grandparent {
    public:
        Parent2(int a_ = 0) : Grandparent(a_) {}
        void display(){
            cout << "I am Parent2 and my value is: " << a << endl;
        }
};

class Child : public Parent1, public Parent2{
    public:
        Child(int a_ = 0) : Parent1(a_), Parent2(a_) {}
        /*
        void display(){
            cout << "I am the child and my value is: " << a;
        }
        */
        
};

int main(){
    Child c1(5);
    //c1.display(); //ambiguous if Child doesnot have overridden display()
    c1.Parent1::display(); //not ambiguous at all
    //c1.Grandparent::display(); //ambiguous without virtual inheritance. Wouldnot have been if we just added virtual when Parents were inherited.
    //c1.Parent2::Grandparent::display(); //still ambiguous. Why ? Because, there are still two copies of "Grandparent" object in the child class. Though we are specifying the path to the function, it is still ambiguous since there are two Grandparent classes and the compiler will still does not understand which one to choose even if we specift the path.
    

    /*
        Proximity Rule:
            If the display() fn is overridden in Child class as well,
            calling dislpay() through Child class object, grants the closest proximity to the
            child class display().
    */

    return 0;
}