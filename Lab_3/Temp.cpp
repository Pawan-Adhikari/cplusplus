//Temp.cpp
//Program that converts temp in Celsius scale to farhenheit scale and vice versa using separate classes for Celsius and fahreheit with private members that hold temp value and make conversion functions in each class for conversion from one to another.

#include <iostream>
using namespace std;
class Celsius{
    private:
        float celsius_temp;
    public:
        Celsius(float temp) : celsius_temp(temp) {}
        float to_fahrenheit(){
            return ((celsius_temp * 9/5)+32);
        }
};

class Fahrenheit{
    private:
        float fahrenheit_temp;
    public:
        Fahrenheit(float temp) : fahrenheit_temp(temp) {}
        float to_celsius(){
            return ((fahrenheit_temp - 32) * 5/9);
        }
};

int main(){
    float input;
    int prompt;

    cout<<"Enter 1 if you want C to F and 2 if you want F to C.";
    cin>>prompt;

    switch (prompt){
        case 1:{
            cout<<"Enter temp in celsius."<<endl;
            cin>>input;
            Celsius c1(input);
            cout<<"The temp in fahrenheit is: "<<c1.to_fahrenheit()<<endl;
            break;
        }
        case 2:{
            cout<<"Enter temp in fahrenheit."<<endl;
            cin>>input;
            Fahrenheit f1(input);
            cout<<"The temp in celsius is: "<<f1.to_celsius();
            break;
        }
        default:
            cout<<"Enter either 1 or 2 only.";
    };
    return 0;
}

