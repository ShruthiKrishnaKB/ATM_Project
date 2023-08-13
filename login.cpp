#include<iostream>
#include<fstream>
#include "function_task3.cpp"
#include "ATM_process.cpp"
using namespace std;

void login(){
    //To check account number and password
    int acc_no, pin_no;
    cout<<"Enter your account number: ";
    cin>>acc_no;
    cout<<"Enter your pin: ";
    cin>>pin_no;

    fstream file;
    int account_no, pin,counts=0;
    string name;
    long long int bal;
    file.open("Customer Details.txt",ios::in);
    while(file>> account_no >> name >> pin >> bal){
        if(account_no == acc_no && pin == pin_no){
            counts++;
            //when username and password are checked , the next step
            ATM_process(acc_no); //function definition in ATM_process.cpp
        }
    }
    if(counts==0){
        cout<<"Your account number and pin does not match"<<endl;
    }
    file.close();
}
