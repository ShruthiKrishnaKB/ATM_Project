#include<iostream>
#include<fstream>
using namespace std;

int count_i=0;

void money_transfer(int acc_no){
    int acc, pin;
    string name;
    long long int bal, bal_after_debit, bal_after_credit;
    bool check = false;
    cout<<"Enter the account number to which the money has to be transferred: ";
    int friend_account_number;
    cin>>friend_account_number;
    cout<<"Enter the amount to be transferred : ";
    int transfer_amount;
    cin>>transfer_amount;
    fstream file;
    file.open("Customer Details.txt",ios::in);
    while(file>>acc>>name>>pin>>bal){
        if(friend_account_number==acc )
            if(bal>transfer_amount){
                check = true;
            }else{
                cout<<"Not enough balance in the account"<<endl;
            }
    }
    file.close();
    if(check){
        if(transfer_amount>=1000 && transfer_amount<=10000){
            bal_after_debit=account_balance_deduction(acc_no, transfer_amount, true);
            file.open(to_string(acc_no)+"_transactions.txt", ios::app);
            if(file.is_open()){
                string desc1="Transferred to "+to_string(friend_account_number);
                string mode1="debit";
                int trans1=1001;
                this_thread::sleep_for(chrono::seconds(5));
                file<<trans1<<" "<<desc1<<" "<<mode1<<" "<<transfer_amount<<" "<<bal_after_debit<<endl;
                file.close();
            }
            else{
                cout<<"Error while opening file"<<endl;
            }

            bal_after_credit=account_balance_deduction(friend_account_number,transfer_amount,false);
            file.open(to_string(friend_account_number)+"_transactions.txt", ios::app);
            if(file.is_open()){
                string desc2 = "Transferred from "+to_string(acc_no);
                string mode2="credit";
                int trans2=2000;
                this_thread::sleep_for(chrono::seconds(5));
                file<<trans2<<" "<<desc2<<" "<<mode2<<" "<<transfer_amount<<" "<<bal_after_credit<<endl;
                file.close();
            }
            else{
                cout<<"Error while opening file"<<endl;
            }
            cout<<"Transferred successfully"<<endl;

        }
        else{
            cout<<"Maximum and transfer limit is Rs.10,000 and minimum transfer amount is Rs.1,000"<<endl;
        }
    }
    else{
        cout<<"the account number to which the money has to be transferred does not exist"<<endl;
    }
}
