//4StuStru.cpp
//stores the information about students (name, student id, department, and address) in a structure and then transfers the information to a file in your directory. Finally, retrieve the information from your file and print it in the proper format on your output screen.

#include<iostream>
#include<fstream>

using namespace std;

struct Student{
    char name[20];
    int id;
    char address[10];
};

int main(){
    short testInt = 10000;

    ofstream testWriteFile;
    //testWriteFile.open("test.bin", ios::out|ios::binary);
    testWriteFile.open("test.txt", ios::out);
    
    if (!testWriteFile){
        cout << "Error opening the file." << endl;
    }
    if (!testWriteFile.write(reinterpret_cast<char *>(&testInt), sizeof(short))){
        cout << "Error writing into the file." << endl;
    }

    testWriteFile.close();

    ifstream testReadFile;
    //testReadFile.open("test.bin", ios::in | ios::binary);
    testReadFile.open("test.txt", ios::in);

    short readInt;
    if (!testReadFile.read(reinterpret_cast<char *>(&readInt), sizeof(short))){
        cout << "Error reading from the file." << endl;
    }
    
    cout << readInt << endl;
    return 0;
}