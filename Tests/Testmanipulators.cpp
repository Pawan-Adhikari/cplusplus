//testmanipulators.cpp
#include<iostream>
using namespace std;

class Spacer {
    int count;
public:
    Spacer(int n) : count(n) {}
    friend ostream& operator<<(ostream& os, const Spacer& s) {
        for(int i = 0; i < s.count; ++i) 
            os << ' ';
        return os;
    }
};

Spacer addSpaces(int n) {
    return Spacer(n);
}

ostream& addSpace(ostream& os){
    os << " " << flush;
    return os;
}

int main(){
    cout << addSpaces(5) << "Ram" << endl;
    cout << "Ram" << addSpace << "Prasad" << endl;
}