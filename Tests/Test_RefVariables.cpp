//Test_RefVariables.cpp
//Testing reference variables

#include <iostream>

using namespace std;

int main() {
    int num = 0;
    int num1 = 5;
    //&num1 = &num; error 
    int &nump = num;
    //nump=num1; //fine, just testing. Caveat: This changes the value of nump, as well as num, 
    //but doesnot update the adress nump was "aliasing?" to.
    
    cout << "Adressess:" << endl;
    cout << "num: " << &num << endl;
    cout << "nump: " << &nump << endl; //same as &num
    cout << "-------" << endl;

    cout << "Values:" << endl;
    cout << "num: " << num << endl; 
    cout << "nump: " << nump << endl; // same as num. 
    cout << "-------" << endl;
    //So, nump is essentially just num. Same address, same value. 
    //Lets check one last thing.

    cout << "Types:" << endl;
    cout << "num: " << typeid(num).name() << endl;  
    cout << "nump: " << typeid(nump).name() << endl;
    cout << "-------" << endl;
    //Even the data types are same.

    //but if we do:
    int *numptr;
    cout << "numptr: " << typeid(numptr).name() << endl;
    //doing int *a; is a new type not int but int &a; is an int.
    //wow.

    //In conclusion, reference variables are basically original variables. They are not even like "shortcuts"
    //like shortcuts to a directory or file in OS; They are indistinguishable to original variable identifier.
    //So yes, they are indeed an "Alias"!
    //So they are basically constant pointers that get dereferenced everytime used.
    //Thus, they functionally behave the same as the identifier "num" eventhough their origin is different.
    return 0;
}