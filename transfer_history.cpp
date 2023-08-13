#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

void transfer_history(int acc_no){
    int amount, trans_id;
    string desc, mode;
    long long int closn_balance;
    cout<<setw(15)<<left<<"TransactionID"<<setfill(' ')<<setw(15)<<"Description"<<setfill(' ')<<setw(15)<<"Credit/Debit"<<setfill(' ')<<setw(15)<<"Amount"<<setfill(' ')<<setw(15)<<"Balance"<<endl;
    fstream file;
    file.open(to_string(acc_no)+"_transactions.txt", ios::in | ios::out);
    if(file.is_open()){
        int i=0;
         string value;
        while (file >> value && i<10) {
        cout << setw(10) << left << value;
        if (file.peek() == '\n') {
            cout << endl;
            i++;
        }
    }
        file.close();
    }
    else{
        cout<<"Error in opening file"<<endl;
    }
}
