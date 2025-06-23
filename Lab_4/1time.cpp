//time.cpp
//Write a program that has a class to represent time. The class should have constructors to initialize data members hour, minute, and second to 0 and to initialize them to values passed as arguments. The class should have a member function to add time objects and return the result as a time object. There should be functions to display time in 12-hour and 24-hour format.

using namespace std;
#include <iostream>

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
        string handle;
    public:
        Time(){
            hours = 0;
            minutes = 0;
            seconds =0;
            handle = "";
        }
        Time(int h, int m, int s){
            hours = h;
            minutes= m;
            seconds = s;
            handle ="";
        }
        void Display24(){
            cout << "The time is: \n";
            cout << hours << ":" << minutes <<":" << seconds<<"\n";
        }
        
        void Display12(){
            cout << "The time is: \n";

            if (hours > 12) {
                handle = "P.M";
                hours -= 12;
            }
            else if (handle == "A.M");
            else handle = "A.M";

            cout << hours << ":" << minutes <<":" << seconds<<handle<<"\n";
        }
};


int main(){

    Time t1(19,42,0);
    Time t2;

    t1.Display24();
    t1.Display12();

}