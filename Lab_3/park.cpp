//park.cpp
//Use class and objects to store and display car parking status

#include <iostream>
using namespace std;
class carpark{
    private:
        int carid;
        int charge;
        float time;
    public:
        void setdata(int ci, int chr, float tm){
            carid = ci;
            charge = chr;
            time = tm;
        }

        void setdata(){
            cout<<"Enter the carid: \t";
            cin >> carid;
            cout<<"Enter the charge per hour: \t";
            cin >> charge;
            cout<<"Enter the parked time in decimal: \t";
            cin >> time;
        }
        void showdata(){
            cout<<"carid: "<<carid<<" in rate: "<<charge<<" per hour has parked for time: "<<time<<endl;
        }
   
};

int main(){
    carpark c1,c2;
    c1.setdata(22,5,2.5);
    c1.showdata();
}

