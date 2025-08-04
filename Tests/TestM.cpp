#include <iostream>
#include <iomanip>

using namespace std;

class testm {
    private:
        int n;
    public:
        testm(int num):n(num){}
        friend ostream& operator<<(ostream& os,const testm& tm);
    };
ostream& operator<<(ostream& os, const testm& tm){
    for(int i=0;i<tm.n;++i)
    os<<' ';
    os<<flush;
    return os;
}

testm sp(int n)
{
    return testm(n);
}
int main()
{
    int a=1,b=2,c=3,d=4;
    cout<<a<<sp(1)<<b<<sp(2)<<c<<testm(3)<<d<<endl;
    return 0;
}