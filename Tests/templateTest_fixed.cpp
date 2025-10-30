#include <iostream>
#include <cstring>

using namespace std;

template <class T, int n = 5>
T add (T a, T b){
    T sum = T();  // Initialize to zero
    for (int i = 0; i < n; i++){
        sum += (a + b);
    }
    return sum;
}

// FULL specialization for char* with n=5 (you cannot do partial specialization)
template<>
char* add<char*, 5>(char *a, char*b){
    static char result[100] = "";  // Static storage
    strcpy(result, a);
    strcat(result, b);
    return result;
}

int main(){
    cout << "Int: 2+3 added 5 times: " << add<int>(2,3) << endl;  // (2+3)*5 = 25
    
    char a[] = "Hello ";
    char b[] = "World";
    cout << "String concatenation: " << add<char*>(a, b) << endl;  // Hello World
}
