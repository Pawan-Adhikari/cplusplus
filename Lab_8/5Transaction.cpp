//5Transaction.cpp
//Transaction processing to a random access file

#include <iostream>
#include <fstream>

using namespace std;

class Account{
    private:
        int account_number;
        char last_name[10];
        char first_name[10];
        int balance;
    public:
        void SetValues(){
            cout << "Enter account number: "; cin >> account_number;
            cout << "Enter First name: "; cin >> first_name;
            cout << "Enter Last name: "; cin >> last_name;
            cout << "Enter balance: "; cin >> balance;
        }
        void DisplayInfo(){
            cout << "Account Number: " << account_number <<endl;
            cout << "Last Name: " << last_name <<endl;
            cout << "First Name: " << first_name << endl;
            cout << "Balance: " << balance << endl;
        }
        friend class FileHandler;
};

class FileHandler{
    private:
        fstream fptr;
        static int no_record;
    public:
        FileHandler(string file_dir = "Transaction.dat", ios::open_mode mode = ios::binary | ios::in | ios::out){
            fptr.open(file_dir, mode);
            fptr.seekg(0, ios::end);
            no_record = fptr.tellg() / sizeof(Account);
        }
        void AddEntry(int addpos = no_record * sizeof(Account)){
            fptr.seekp(addpos);
            Account acc;
            acc.SetValues();
            fptr.write(reinterpret_cast<char *> (&acc), sizeof(acc));
            ++no_record;
            cout << "\n";
        }
        void DeleteEntry(int an){
            Account temp;
            fptr.seekg(0);
            while (fptr.read(reinterpret_cast<char *> (&temp), sizeof(Account)) && fptr.tellg() <= sizeof(Account) * no_record){
                if (temp.account_number == an) {
                    cout << "Found your entry!" << endl;
                    int found_pos = (fptr.tellg());
                    fptr.seekp(found_pos-sizeof(Account));
                    fptr.seekg(-static_cast<std::streamoff>(sizeof(Account)), ios::end);
                    fptr.read(reinterpret_cast<char *> (&temp), sizeof(Account));
                    fptr.write(reinterpret_cast<char *> (&temp), sizeof(Account));
                    cout << "Deleted your entry!\n" << endl;
                    no_record -= 1;
                    break;
                }
            }
        }
        void UpdateEntry(int an){
            Account temp;
            fptr.seekg(0);
            while (fptr.read(reinterpret_cast<char *> (&temp), sizeof(Account)) && fptr.tellg() <= sizeof(Account) * no_record){
                if (temp.account_number == an) {
                    cout << "Found your entry!" << endl;
                    int found_pos = int(fptr.tellg())-int(sizeof(Account));
                    this -> AddEntry(found_pos);
                    no_record -= 1;
                    cout << "Updated Successfully!\n" << endl;
                    break;
                }
            }
        }
        void DisplayEntry(int an){
            Account temp;
            fptr.seekg(0);
            while (fptr.read(reinterpret_cast<char *> (&temp), sizeof(Account)) && fptr.tellg() <= sizeof(Account) * no_record){
                if (temp.account_number == an) {
                    cout << "Found your entry!" << endl;
                    temp.DisplayInfo();
                    cout << "\n";
                    break;
                }
            }
        }
};
int FileHandler::no_record = 0;
int main(){
    FileHandler myFile;
    int menu;
    while (menu != 5){
        cout << "Select from the following: " << endl;
        cout << R"(1. Add Entry. 
2. Remove Entry.
3. Update Entry.
4. Display Entry.
5. Exit)" << endl;
        cin >> menu;
        switch (menu){
            case 1:
                myFile.AddEntry();
                break;
            case 2:{
                int acn;
                cout << "Enter Account number to Delete: "; cin >> acn;
                myFile.DeleteEntry(acn);
                break;
            }
            case 3:{
                int acn; 
                cout << "Enter Account number to Update: "; cin >> acn;
                myFile.UpdateEntry(acn);
                break;
            }
            case 4: {
                int acn; 
                cout << "Enter Account number to Display: "; cin >> acn;
                myFile.DisplayEntry(acn);
                break;
            }
            case 5: {break;}
            default:
                cout << "Enter from 1-5 only" << endl;
                break;
        }
    }   
    return 0;
}