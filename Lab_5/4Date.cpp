//4Date.cpp
//Create a Date class, overload increment operator to increase date by a day

#include <iostream>

using namespace std;


class Date {
private:
        int day;
        int month;
        int year;
public:
    Date(){
        day =0;
        month = 0;
        year = 0;
    }
    Date(int y, int m, int d){
        day =d;
        month = m;
        year = y;
    }

    bool isLeapYear(int year){
        if (year % 4 == 0){
            if (year % 100 == 0){
                if (year % 400 == 0){
                    return true;
                }
                else return false;
            }
            else return true;
        }
        else return false;  
    }

    int getdays(int month){
        switch(month) {
            case 1:  // January
            case 3:  // March
            case 5:  // May
            case 7:  // July
            case 8:  // August
            case 10: // October
            case 12: // December
                return 31;
                break;
            
            case 4:  // April
            case 6:  // June
            case 9:  // September
            case 11: // November
                return 30;
                break;
            
            case 2:  // February
                if (isLeapYear(year)) {
                    return 29;
                } else {
                    return 28;
                }
                break;
            
            default:
                cout << "Invalid month!" << endl;
                return 0;
                break;
        }
    }

    void operator ++(){
        if ((month == 12)&&(day == getdays(month))){
            year++;
            month = 1;
            day = 1;
        }
        else if (day == getdays(month)){
            month++;
            day = 1;
        }
        else day++;
    }    
    void operator ++(int){                      //int dummy parameter to differentiate postfix operator
        if ((month == 12)&&(day == getdays(month))){
            year++;
            month = 1;
            day = 1;
        }
        else if (day == getdays(month)){
            month++;
            day = 1;
        }
        else if (day > getdays(month) || month > 12){
            cout << "Not a valid date" << endl;
        }
        else day++;
    }  

    void displayDate(){
        cout << "Year:" <<year << "\nMonth:" <<month <<"\nDay:" <<day <<"\n"<<endl;
    }
};


int main() {
    Date d1(2005, 11, 29), d2(2006, 11, 30), d3(2025, 12, 31);
    Date d;
    d1.displayDate();
    d2.displayDate();
    d3.displayDate();

    d1++;d2++,d3++;

    d1.displayDate();
    d2.displayDate();
    d3.displayDate();
    d.displayDate();

    return 0;
}