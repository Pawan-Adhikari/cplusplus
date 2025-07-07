#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    void inputName() {
        cout << "Name: "; cin >> name;
    }
    void printAddr() {
        cout << "Address: " << this << endl;
    }
};

class Student : public Person {
private:
    int roll;
public:
    void inputRoll() {
        cout << "Roll: "; cin >> roll;
    }
};

class Employee : public Person {
    int empID;
public:
    void inputEmpID() {
        cout << "ID: "; cin >> empID;
    }
};

int main() {
    Person p1, p2;
    Student s1, s2;
    Employee e1, e2;

    p1.printAddr(); p2.printAddr();
    s1.printAddr(); s2.printAddr();
    e1.printAddr(); e2.printAddr();

    cout << "\nSizes (bytes):\n";
    cout << "Person: " << sizeof(Person) << endl;
    cout << "Student: " << sizeof(Student) << endl;
    cout << "Employee: " << sizeof(Employee) << endl;

    return 0;
}
