//3absClass.cpp
//Write a program with an abstract class Student and create derive classes Engineering, Medicine and Science from base class Student. Create the objects of the derived classes and process them and access them using an array of pointers of type base class Student

#include <iostream>

using namespace std;

class Student {
protected:
    char *name;
    char faculty[2] = "";
public:
    Student(){
        name = new char[2];
        name = "";
    }
    Student(char* nam){
        name = new char[30];
        name = nam;
    }
    virtual void displayFaculty() = 0;
    ~Student(){
        delete[] name;
    };
};
class Engineering : public Student{
    private:
        char faculty[30] = "Engineering";
    public:
        Engineering(){
        name = "";
        }
        Engineering(char* nam) : Student(nam) {}
        void displayFaculty() {
            cout << faculty << endl;
        }
};

class Biology : public Student{
    private:
        char faculty[30] = "Biology";
    public:
        Biology(){
        name = "";
        }
        Biology(char* nam) : Student(nam) {}
        void displayFaculty() {
            cout << faculty << endl;
        }
};

class Science : public Student{
    private:
        char faculty[30] = "Science";
    public:
        Science(){
        name = "";
        }
        Science(char* nam) : Student(nam) {}
        void displayFaculty() {
            cout << faculty << endl;
        }
};

int main() {
    Student *students[3];
    students[0] = new Engineering;
    students[1] = new Biology;
    students[2] = new Science;
    for (int i = 0; i < 3; i ++){
        students[i] -> displayFaculty();
    }
    return 0;
}