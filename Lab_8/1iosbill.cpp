//1iosbill.cpp

using namespace std;
#include <iostream>

class item{
private:
    char *iname;
    int price;
public:
    item(char *iname_= "Test", int price_ = 0) : iname(iname_), price(price_){}
    friend class bill;
};

class bill {
private:
    char *name;
    item *items;
public:
    bill(){
        int item_no = 3;
        items = new item[item_no];
        items[0] = item("Cauli",55);
        items[1] = item("Banda", 30);
        items[2] = item("Mango", 210);
        name = "Ram Prasad";


        cout << "Customer name: " << name <<"\n"<< endl;
        for (int i = -1; i<item_no; i++){
            if (i == -1){
                cout.width(2);cout << "SN";
                cout.width(10);cout.setf(ios::internal,ios::adjustfield); cout <<"Item";
                cout.width(10);cout.setf(ios::right, ios::adjustfield);cout <<"Price"<<endl;
            }
            else{
                cout.width(2);cout.fill('0');cout << i+1;cout.fill(' ');
                cout.width(10);cout.setf(ios::internal,ios::adjustfield); cout <<items[i].iname;
                cout.width(10);cout<<items[i].price<<endl;
            }
        }
    }
};

int main(){
    bill mybill;
}