//2conc.
//Concatenate two string objects.

using namespace std;
#include <iostream>
#include <string>

class CharArr {
    private:
        char *value;
    public:
        CharArr(){
            value = new char[2];
            strcpy(value," ");
        }
        CharArr(char c[]){
            value = new char[strlen(c)+1];
            strcpy(value,c);
        }
        char* join(CharArr &other1, CharArr &other2) {
            char* result= new char[strlen(other1.value)+strlen(other2.value)+2]; 
            strcpy(result, other2.value);

            
            int l = strlen(result);
            int i;
            for (i=0;i<strlen(other1.value);i++){
                result[l + i] = other1.value[i];
            }
            result[l + i +1] = '\n';

            return result;

        }
        ~CharArr(){
           delete[] value;
        }
};


int main(){
    CharArr c0;
    CharArr c1("Engineers are"), c2(" creatures of logic.");

    //char * resultHere = c1.join(c2,c1);
    char * resultHere = c0.join(c2,c1);

    cout << resultHere <<endl;

    delete[] resultHere;

    return 0;

}

