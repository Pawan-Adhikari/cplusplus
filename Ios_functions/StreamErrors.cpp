//StreamErrors.cpp
//Testing out ios stream member functions and flags.


#include<fstream>
#include<iostream>
using namespace std;


int main()
{
    ofstream myFile("this.dat", ios::binary);
    char *charArr1;
    char charArr[8];
    charArr1 = "InKMan";

    if (myFile.write(charArr1, sizeof(charArr1)))
        cout << "Successfully wrote!" << endl;

    myFile.close();

    ifstream myFile1("this.dat", ios::binary);

    if (myFile1.read(charArr, sizeof(charArr1)))
        cout << "Successfully read!" << endl;
    cout << charArr <<endl;

    //Simulate bad bits.

    myFile1.setstate(ios::badbit | myFile1.rdstate());

    
    if (ios::badbit & myFile1.rdstate())
        cout << "Currently a bad state" << endl;

    if (myFile1.ios::bad())
        cout << "Currently a bad state" << endl;

    myFile1.close();
}