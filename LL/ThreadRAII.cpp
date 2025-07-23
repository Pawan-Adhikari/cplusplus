#include <thread>
#include <iostream>

using namespace std;

class ThreadGuard {
private:
    std::thread& t;
public:
    explicit ThreadGuard(std::thread& _t): t(_t){}
    ~ThreadGuard(){
        if (t.joinable()){
            t.join();
        }
    }
ThreadGuard(ThreadGuard const&)=delete; // Dor overriding default copy and assignment constructors
ThreadGuard& operator=(ThreadGuard const&)=delete; // So that a thread gaurd may not outlive the thread and cause exceptions
};

int main() {
    
    return 0;
}