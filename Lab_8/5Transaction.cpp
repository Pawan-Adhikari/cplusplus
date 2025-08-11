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
            fptr.seekg(0);
            if(fptr.read(reinterpret_cast<char*>(&no_record),sizeof(int))){
                cout << "Read current entry count!" << endl;
            }
            else {
                cout << "The file is empty! Initializing entry count = 0!" << endl;
                no_record = 0;
                ChangeRecordNumber(no_record);
            }
            cout << "No. of entries: " << no_record << endl;;

        }
        void ChangeRecordNumber(int newR){
            fptr.clear();
            fptr.seekp(0);
            if(fptr.write(reinterpret_cast<char*>(&newR), sizeof(newR))){
                cout << "Changed no of record successfully!" << endl;
            }
        }
        void AddEntry(int addpos = (no_record*sizeof(Account)) + sizeof(int)){
            cout << "To add position: " << addpos << endl;
            fptr.seekp(addpos);
            Account acc;
            acc.SetValues();
            if(fptr.write(reinterpret_cast<char *> (&acc), sizeof(acc))){
                cout << "Wrote successfully and p pointer reached: " << fptr.tellp() << endl;
            }
            ++no_record;
            cout << "Added at: " << int(fptr.tellp()) - int(sizeof(Account)) << endl;
            this ->ChangeRecordNumber(no_record);
            cout << "No. of entries: " << no_record << endl;
            cout << "\n";
        }
        
        void DeleteEntry(int an){
            Account temp;
            fptr.seekg(sizeof(int), ios::beg);
            
            while (fptr.read(reinterpret_cast<char *> (&temp), sizeof(Account)) && (fptr.tellg() <= (sizeof(Account)*no_record) + sizeof(int))){
                if (temp.account_number == an) {
                    temp.DisplayInfo();
                    int found_pos = int(fptr.tellg())-int(sizeof(Account));
                    cout << "Found to be deleted entry's start at: " << found_pos << endl;
                    fptr.seekg(((no_record-1)*sizeof(Account))+sizeof(int), ios::beg);
                    cout << "Last entry's start at: " << fptr.tellg() << endl;
                    fptr.read(reinterpret_cast<char *> (&temp), sizeof(Account));
                    temp.DisplayInfo();
                    fptr.seekp(found_pos);
                    cout << "Overwriting with ^^ at: " << fptr.tellp() << endl;
                    fptr.write(reinterpret_cast<char *> (&temp), sizeof(Account));
                    no_record -= 1;
                    this ->ChangeRecordNumber(no_record);
                    cout << "No. of entries: " << no_record << endl;
                    cout << "Deleted your entry!\n" << endl;
                    break;
                }
            }
        }
        void UpdateEntry(int an){
            Account temp;
            fptr.seekg(sizeof(int), ios::beg);
            while (fptr.read(reinterpret_cast<char *> (&temp), sizeof(Account)) && fptr.tellg() <= (sizeof(Account) * no_record) + sizeof(int)){
                if (temp.account_number == an) {
                    cout << "Found your entry at: " << fptr.tellg() << endl;
                    int found_pos = int(fptr.tellg())-int(sizeof(Account));
                    this -> AddEntry(found_pos);
                    no_record -= 1;
                    cout << "No. of entries: " << no_record << endl;
                    cout << "Updated Successfully!\n" << endl;
                    break;
                }
            }
        }
        void DisplayEntry(int an){
            Account temp;
            fptr.seekg(sizeof(int), ios::beg);
            while (fptr.read(reinterpret_cast<char *> (&temp), sizeof(Account)) && fptr.tellg() <= (sizeof(Account) * no_record) + sizeof(int)){
                if (temp.account_number == an) {
                    cout << "Found your entry at: " << fptr.tellg() << endl;
                    temp.DisplayInfo();
                    cout << "No. of entries: " << no_record << endl;
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