//testmanipulators.cpp
#include<iostream>
using namespace std;
class mm{
    int w;
    public:
    mm(int i = 0){
        w = i;
    }
    friend ostream& operator << (ostream& os, const mm &a);
};

ostream& operator << (ostream& os, const mm &a){
    for(int i=0;i<a.w;++i) 
        os<<' '; 
    os<<flush; 
    return os; 
}
int main(){
    cout << mm(5) << "Ram";
}