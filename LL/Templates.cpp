//Templates.cpp
//Trying to create a template for vectors

#include <iostream>

template <class T> class vector{
    private:
        T* arr;
        int size;
    public:
        vector(T* ar, int siz) : size(siz){
            arr = new T(size);
            for (int i=0; i<size; i++){
                arr[i] = ar[i];
            }
        }
        ~vector(){
            delete[] arr;
        }
        void displayAll(){
            for (int i=0; i<size; i++){
                std::cout << arr[i] << std::endl;
            }
        }
};

int main(void){
    int mySize = 5;
    int* intArr{new int[mySize]{1,2,3,4,5}};
    char* charArr{new char[mySize]{'a','b','c','d','e'}};
    vector<int> myIntVec(intArr, mySize);
    myIntVec.displayAll();
    std::cout << "Now displaying Character Array: " << std::endl;
    vector<char> myCharVec(charArr, mySize);
    myCharVec.displayAll();
}