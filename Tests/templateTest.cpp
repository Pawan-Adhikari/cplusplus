#include <iostream>
#include <vector>

using namespace std;

template <class T, int MAX = 256>
class Stack{
    class EMP{};
    class BOUND{};
    vector<T> pile;
    int topIn;
public:
    Stack(){topIn = -1;}
    void push(T value);
    void pop(){
        try{
            if (!pile.empty()){
                pile.pop_back();
                topIn -= 1;
            }
            else {
                throw EMP();
        }
    }
        catch (EMP&){
            cout << "Stack Empty!" << endl;
            exit(1);
        }
    }
    void clear(){
        pile.clear();
    }
    T top(){
        try {
            if (!pile.empty()){
                return pile.back();
            }
            else {
                throw EMP();
            }
        }
        catch (EMP&){
            cout << "Stack Empty!" << endl;
            exit(1);
        }
    }
};
template <class T, int MAX>
void Stack<T, MAX>::push(T value){
    try{
        if (topIn+1 < MAX){
            pile.push_back(value);
            topIn += 1;
        }
        else throw BOUND();
    }
    catch (BOUND&){
        cout << "Stack Overflow!" << endl;
        exit(1);
    }
}

template <class T, int MAX = 256>
class arrStack{
    class EMP{};
    class BOUND{};
    T *arr;
    int topIn;
public:
    arrStack(){
        arr = new T[MAX];
        topIn = -1;
    }
    void push(T value);
    void pop(){
        try{
            if (topIn != -1){
                topIn -= 1;
            }
            else {
                throw EMP();
        }
    }
        catch (EMP&){
            cout << "Stack Empty!" << endl;
            exit(1);
        }
    }
    void clear(){
        topIn = -1;
    }
    T top(){
        try {
            if (topIn != -1){
                return arr[topIn];
            }
            else {
                throw EMP();
            }
        }
        catch (EMP&){
            cout << "Stack Empty!" << endl;
            exit(1);
        }
    }
};
template <class T, int MAX>
void arrStack<T, MAX>::push(T value){
    try{
        if (topIn+1 < MAX){
            topIn += 1;
            arr[topIn] = value;
        }
        else throw BOUND();
    }
    catch (BOUND&){
        cout << "Stack Overflow!" << endl;
        exit(1);
    }
}

int main(){
    Stack<int,20> myVStack;
    myVStack.push(5);
    cout << "Just added to vector Stack: " << myVStack.top() << endl;

    arrStack<int,20> myArrStack;
    myArrStack.push(6);
    cout << "Just added to Array Stack: " << myArrStack.top() << endl;

}