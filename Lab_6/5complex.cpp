//5complex.cpp

#include <iostream>

using namespace std;

class CompBase {
protected:
    int realP;
    int imgP;
public:
    void input() {
        cout << "Enter real and imag part: ";
        cin >> realP >> imgP;
    }
};

class CompDerv:public CompBase {
    public:
    void add() {
        cout << "Sum: " << CompBase::realP + realP << " + " << CompBase::imgP + imgP << "i\n";
    }
    friend class FriendSubtractor;
};

class FriendSubtractor {
    private:
        int real;
        int img;
    public:
    void input() {
        cout << "Enter real and imag part: ";
        cin >> real >> img;
    }
    void sub(CompDerv d) {
        cout << "Difference: " << d.realP - real << " + " << d.realP - real << "i\n";
    }
};
int main() {
    CompBase c;
    c.input();
    CompDerv d;
    d.input();
    d.add();
    FriendSubtractor fs;
    fs.input();
    fs.sub(d);
    return 0;
}