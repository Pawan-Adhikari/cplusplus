//2vbase.cpp
//

#include <iostream>

using namespace std;

class Person {
private:
    string name;
public:
    Person(){};
    Person(string n) : name(n){}
    void display(){cout << name << endl;}
};

class Student : virtual public Person {
protected:
    int roll;
public:
    Student(){};
    Student(string n, int r) : roll(r), Person(n){}
    void display(){
        Person::display();
        cout << roll << endl;
    }
};

class Employee : virtual public Person {
protected:
    int id;
public:
    Employee(){};
    Employee(string n, int i) : id(i), Person(n){}
    void display(){
        Person::display();
        cout << id << endl;
    }
};

class Manager : public Student, public Employee {
private:
    string team_name;
public:
    Manager(){};
    Manager(string n, int r, int i, string team): Person(n), Employee(n,i), Student(n,r){
        team_name = team;
    }
    void display() {
        Person::display();
        cout << "Roll: " << roll << endl;
        cout << "ID: " << id << endl;
        cout << "Team: " << team_name << endl;
    }
};

int main() {
    Manager m("John Doe", 123, 456, "Development");
    m.display();
    return 0;
}