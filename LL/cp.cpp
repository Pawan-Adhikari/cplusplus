#include<iostream>
std::string ReturnFoo(void) {
    std::string x("foo");
    return x; // this return might copy
}
int main(int argc, char **argv) {
    std::string a("hello");
    std::string b(a); // copy a into b
    b = ReturnFoo(); // copy return value into b
    int c = 0;
    return EXIT_SUCCESS;
}