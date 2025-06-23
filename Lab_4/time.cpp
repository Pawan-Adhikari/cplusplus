//time.cpp
//Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.

using namespace std;
#include <iostream>

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
    public:
        Time(){
            hours = 0;
            minutes = 0;
            seconds =0;
        }
        Time(int h, int m, int s){
            hours = h;
            minutes= m;
            seconds = s;
        }
        void Display24(){
            cout << "The time in 24hr format is: \n";
            cout << hours << ":" << minutes <<":" << seconds<<"\n";
    }
        
        void Display12(){
            cout << "The time is: \n";

            if (hours > 12) {
                cout << hours << ":" << minutes <<":" << seconds<<"P.M"<<"\n";
            }
            else if (handle == "A.M");
            else handle = "A.M";

            cout << hours << ":" << minutes <<":" << seconds<<<"\n";
        }
};


int main(){

    Time t1(19,42,0);
    Time t2(0,0,0);

    t1.Display24();
    t1.Display12();
    t1.Display24();
    t1.Display12();

    t2.Display24();
    t2.Display12();
    t2.Display24();
    t2.Display12();
    
}