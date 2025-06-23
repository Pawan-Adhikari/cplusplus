//primeornot.cpp
//Check whether the number is prime or not

#include <iostream>
using namespace std;
class Number{
    private:
        int num;
    public:
        Number(int num) : num(num) {}
        int check=0;
        bool check_prime(){
            for (int i = 0; i<(num/2); i++){
                if ((num%i)==0) check += 1;
            }
            if (check > 2) return false;
            else return true;
        }
};


int main(){
    float input;
    char prompt='y';

    do {
        cout<<"Enter y if you want to check a prime number and n if you want to stop:\t";
        cin>>prompt;
        cout<<"Enter your number."<<endl;
        cin>>input;
        Number n1(input);
        bool result = n1.check_prime();
        if (result) cout<<"The number is prime\n";
        else cout<<"The number is composite\n";
    }while (prompt!='n');
    return 0;
}

