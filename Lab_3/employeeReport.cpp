//employeeReport.cpp

#include <iostream>
using namespace std;
class employee{
    private:
        int eid;
        int bonus;
        int overtime;
    public:
        void setpara(int ei, int bon, float ot){
            eid = ei;
            bonus = bon;
            overtime = ot;
        }

        void setpara(){
            cout<<"Enter the employee id: \t";
            cin >> eid;
            cout<<"Enter the total bonus: \t";
            cin >> bonus;
            cout<<"Enter the over time hours: \t";
            cin >> overtime;
        }
        void displayreport(){
            cout<<"employee id: "<<eid<<" with total bonus: "<<bonus<<" has over time: "<<overtime<<endl;
        }
   
};

int main(){
    int employee_n;

    cout<<"Enter the number of employee:\t";
    cin>>employee_n;

    employee* employees = new employee[employee_n];

    for (int i=0; i<employee_n;i++){
        employees[i].setpara();
    }

    for (int i=0; i<employee_n;i++){
        employees[i].displayreport();
    }

}

