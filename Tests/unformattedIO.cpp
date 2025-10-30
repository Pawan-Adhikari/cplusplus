#include <iostream>
#include <limits>

using namespace std;
int main(){
    /*cout << "Demonstrating get() method.... " << endl;

    char oneChar1, oneChar;
    cout << "Trying to get a single character using no arg get()...." << endl;
    oneChar = cin.get();
    cout << "The single character input was: " <<oneChar <<endl;
    cin.ignore(); 

    cout << "Trying to get a char using get(char c)...." <<endl;
    cin.get(oneChar1);
    cout << "The single character input was: " <<oneChar1 <<endl;
    cin.ignore();

    char nodelimString[256];
    cout << "Trying to get a string using get(char *c, streamsize n)...." <<endl;
    cin.get(nodelimString, 256); 
    cout << "The string input was: " <<nodelimString <<endl;
    cin.ignore(10);

    char delimString[256];
    cout << "Trying to get a string using get(char *c, streamsize n, char delim)...." <<endl;
    cin.get(delimString, 256, 's'); 
    cout << "The string input was: " <<delimString <<endl;*/


    cout << "Demonstrating getline() method...." << endl;

    char nodelimString1[256];
    cout << "Trying to get a string using getline(char *c, streamsize n)...." <<endl;
    cin.getline(nodelimString1, 256); 
    cout << "The string input was: " <<nodelimString1 <<endl;

    char delimString1[256];
    cout << "Trying to get a string using getline(char *c, streamsize n, char delim)...." <<endl;
    cin.getline(delimString1, 256, 's'); 
    cout << "The string input was: " <<delimString1 <<endl;
}