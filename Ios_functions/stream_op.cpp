#include<iostream>
using namespace std;

class Time
{
    private:
        int hour,min,sec;
    public:
        Time(int hr=0,int mn=0,int sc=0){hour=hr;min=mn;sec=sc;}
        ostream& operator<<(ostream& os, Time &tm){
            os<<hour<<":"<<min<<":"<<sec<<flush;
            return os;
        }
        friend istream& operator>>(istream& is, Time& tm);
};

istream& operator>>(istream& is, Time& tm){
    is>>tm.hour>>tm.min>>tm.sec;
    return is;
}
int main()
{ 
    Time t1;
    cout<<"Enter current time: ";
    cin>>t1;
    cout<<"Time entered is: "<<t1<<endl;
}