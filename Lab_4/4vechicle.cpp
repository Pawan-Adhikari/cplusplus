//4vechicle.cpp
//vehicle management with copy constructor

#include<string>
#include <iostream>

using namespace std;

class vehicle{
    private:
        int num_vehicle, hour, rate;
    public:
        vehicle(int num,int h, int r){
            num_vehicle = num;
            hour = h;
            rate = r;
        }

        vehicle(vehicle& v){
            num_vehicle = v.num_vehicle;
            hour = v.hour;
            rate = v.rate;
        }

        void DisplayCharge(){
            int charge=0;
            int discount=0;
            if (num_vehicle > 10){
                discount = 10;
            }
            charge = (hour * rate);
            charge -= charge * discount/100; 

            cout<<charge;
        }


};

int main(){
    vehicle v1(101, 5, 20);
    cout << "Charge of v1:\n";
    v1.DisplayCharge();

    vehicle v2(v1);
    cout << "Charge of v2 (copied from v1):\n";
    v2.DisplayCharge();
}
