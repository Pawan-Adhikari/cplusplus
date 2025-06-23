//2conc.
//Concatenate two string objects.

using namespace std;
#include <iostream>
#include <string>

class CharArr {
    private:
        char *value = new char[30];
    public:
        CharArr(){
            strcpy(value,"");
        }
        CharArr(char c[]){
            strcpy(value,c);
        }
        char* join(CharArr other) {
            char* result= new char[60]; 
            strcpy(result, value);       
            strcat(result, other.value); 
            return result;
        }
        ~CharArr(){
            delete[] value;
        }
};


int main(){

CharArr c1("Engineers are"), c2(" creatures of logic.");

cout << c1.join(c2);

return 0;

}

