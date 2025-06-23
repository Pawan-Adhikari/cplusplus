//3depart.cpp
//departclass with destructor and constructor and order of call.

#include<string>
#include <iostream>

using namespace std;

class Depart{
    private:
        char name[30];
        int ID;
    public:
        Depart(char n[],int id){
            strcpy(name,n);
            cout << "Object declared.\n";
        }
        ~Depart(){
            cout << "Object goes out of the scope.\n";
        }

};

int main(){
    Depart p("Hari bahadur",3491);
}