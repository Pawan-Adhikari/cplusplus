//2Umanip.cpp
//Create user defined manipulator that formats output by setting width, precision and fill character

#include <iostream>
#include <iomanip>

using namespace std;

class myManip {
private:
    int precision, width;
    char fill;
public:
    myManip(int precision_=3, int width_=0, char fill_=' ') : precision(precision_), width(width_), fill(fill_){}
    friend ostream& operator << (ostream& os, const myManip& mp);
};

ostream& operator << (ostream& os, const myManip& mp){
    os << setw(mp.width) << setprecision(mp.precision) << setfill(mp.fill);
    return os;
}

int main() {
    cout << myManip() << 4.56 <<endl;
    return 0;
}