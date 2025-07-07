//1distance.cpp

#include <iostream>

using namespace std;

class Distance {
private:
    int cm;
    int m;
public:
    Distance(){
        cm =0;
        m=0;
    }
    Distance(int mm, int ccm){
        cm = ccm;
        m = mm;
    }
    Distance(float d){
        m = int(d);
        cm = int((d-m)*100);
    }
    operator float(){
        return (m + float(cm)/100);
    }
    void showdata(){
        cout<< m << " Metre "<< cm <<" CentiMetre"<<endl;
    }
    
};

int main() {
    Distance d1(5,10);
    Distance d2 = 5.9;
    d1.showdata();
    d2.showdata();
    float dist = d1 + d2 + 5.8;
    cout << dist <<endl;
    return 0;
}