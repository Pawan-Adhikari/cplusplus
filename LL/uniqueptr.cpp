#include<memory>
#include<iostream>
using namespace std;
int main(int argc, char **argv) {
    unique_ptr<int> x(new int(5));
    cout << "x: " << x.get() << endl;
    //unique_ptr<int> y(x.release()); // x abdicates ownership to y
    int *y = x.release();
    cout << "x: " << x.get() << endl;
    //cout << "y: " << y.get() << endl;
    cout << "y: " << y << endl;

    unique_ptr<int> z(new int(10));
    // y transfers ownership of its pointer to z.
    // z's old pointer was delete'd in the process.

    //z.reset(y.release());
    
    cout << "x: " << x.get() << endl;
    //cout << "y: " << y.get() << endl;
    cout << "y: " << y << endl;
    //cout << "z: " << z.get() <<endl;

    return EXIT_SUCCESS;
}