//3instruments.cpp
//Instruments array class and derived class 

#include <iostream>

using namespace std;

class Instruments {
private:
    string *string_ins;
    string *wind_ins;
    string *perc_ins;
public:
    void strings(){
        string_ins = new string[5];
        string_ins[0] = "veena";
        string_ins[1] = "guitar";
        string_ins[2] = "sitar";
        string_ins[3] = "sarod";
        string_ins[4] = "mandolin";
    }
    void wind(){
        wind_ins = new string[5];
        wind_ins[0] = "flute";
        wind_ins[1] = "clarinet";
        wind_ins[2] = "saxophone";
        wind_ins[3] = "nadhaswaram";
        wind_ins[4] = "piccolo";
    }
    void perc(){
        perc_ins = new string[5];
        perc_ins[0] = "tabla";
        perc_ins[1] = "mridangam";
        perc_ins[2] = "bangos";
        perc_ins[3] = "drums";
        perc_ins[4] = "tambour";
    }
    void show_strings(){
        for (int i=0;i<5;i++){
            cout << string_ins[i]<<endl;
        }
    }
    void show_wind(){
        for (int i=0;i<5;i++){
            cout << wind_ins[i]<<endl;
        }
    }
    void show_perc(){
        for (int i=0;i<5;i++){
            cout << perc_ins[i]<<endl;
        }
    }
    ~Instruments(){
        delete[] string_ins;
        delete[] wind_ins;
        delete[] perc_ins;

    }
};

class TypeIns:public Instruments{
private:
    char choice;
public:
    void get(){
        cout << "Type of instruments to be displayed" <<endl;
        cout << "a. String instruments" <<endl;
        cout << "b. Wind instruments" <<endl;
        cout << "c. Percussion instruments" <<endl;
        cin >> choice;
    }
    void show(){
        switch (choice) {
            case 'a': 
                Instruments::strings();
                Instruments::show_strings();
                break;
            
            case 'b': 
                Instruments::wind();
                Instruments::show_wind(); 
                break;
            
            case 'c': 
                Instruments::perc();
                Instruments::show_perc();
                break;
            
            default :
                cout << "Enter either a,b or c.";
                break;
        }
    }
};
int main() {
    TypeIns i;
    i.get();
    i.show();
    return 0;
}