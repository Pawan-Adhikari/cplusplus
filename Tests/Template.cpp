#include <iostream>
#include <string>
using namespace std;


template <typename T>
T add(T a, T b){
    return (a+b);
}

int main() {
    // Example 1: Calling the add function with integers.
    // The compiler automatically deduces that T should be 'int'.
    int intSum = add(5, 10);
    std::cout << "Integer sum: " << intSum << std::endl;

    // Example 2: Calling the add function with floating-point numbers.
    // The compiler automatically deduces that T should be 'double'.
    double doubleSum = add(3.5, 7.2);
    std::cout << "Double sum: " << doubleSum << std::endl;

    // Example 3: Calling the add function with strings.
    // The compiler automatically deduces that T should be 'std::string'.
    // The '+' operator for strings performs concatenation.
    std::string stringSum = add(std::string("Hello, "), std::string("World!"));
    std::cout << "String concatenation: " << stringSum << std::endl;

    cout << "Sum of 2 and 3: " << add<int>(2,3) <<endl;

    return 0;
}