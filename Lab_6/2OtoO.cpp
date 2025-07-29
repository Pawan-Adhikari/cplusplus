//OtoO.cpp
//store distances in meter-centimeter and feet-inch systems respectively. Write conversions functions so that the program can convert objects of both types.

#include <iostream>

using namespace std;

class DistanceCGS {
private:
    int cm;
    int m;
public:
    DistanceCGS(){
        cm =0;
        m=0;
    }
    DistanceCGS(int mm, int ccm){
        cm = ccm;
        m = mm;
    }
    DistanceCGS(float d){
        m = int(d);
        cm = int((d-m)*100);
    }
    int getcm(){return cm;}
    int getm(){return m;}
    void showdata(){
        cout<< m << " Metre "<< cm <<" CentiMetre"<<endl;
    }

    
};

class DistanceFPS {
private:
    int f;
    int in;
public:
    DistanceFPS(){
        f =0;
        in=0;
    }
    DistanceFPS(int ff, int inn){
        f = ff;
        in = inn;
    }
    DistanceFPS(DistanceCGS dcgs){
        float i = ((dcgs.getcm() + dcgs.getm()*100)*25)/64;
        f = i / 12;
        in = int(i - f*12);
    }
    operator DistanceCGS(){
        float c = (f * 12 + in)*2.54;
        int m = int(c) / 100;
        int cm = int(c - m*100);
        DistanceCGS tempcgs(m,cm);
        return tempcgs;
    }
    void showdata(){
        cout<< f << " feet "<< in <<" inches"<<endl;
    }
    
};

int main() {
    DistanceCGS dc1(1,82);
    DistanceFPS df1(5,10);
    dc1.showdata();
    df1.showdata();
    DistanceFPS df2 = dc1;
    DistanceCGS dc2 = df1;
    df2.showdata();
    dc2.showdata();
    return 0;
}