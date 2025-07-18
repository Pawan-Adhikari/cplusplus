#include <iostream>
#include <thread>

using namespace std;

class SumFunctor {
private:
    int data;
public:
    SumFunctor(int n) : data(n){};
    void operator() (){
        cout << "Hello from thread!"<<endl;
    }
};

int main() {
    int i =5;
    thread t(SumFunctor(5));
    t.join();
    thread t1([](int i){
        cout << i;
    },i);
    t1.join();
    return 0;
}