#include<iostream>
#include<fstream>
#include<thread>
#include<chrono>
#include "money_transfer.cpp"
#include "transfer_history.cpp"
using namespace std;

void ATM_process(int acc_no){
    cout<<"Select the corresponding number of the process to proceed further"<<endl<<"MENU"<<endl<<"1. Check Balance"<<
        endl<<"2. Withdraw Money"<<endl<<"3. Transfer Money"<<endl<<"4. Check ATM Balance"<<endl<<"5. Mini Statement"<<
        endl<<"Enter the corresponding number: ";
    int process;
    cin>>process;
    switch(process){
        case 1:{
            auto acc_bal = balance_enquiry(acc_no); // in function_task3.cpp
            cout<<"Your current balance is Rs."<<acc_bal<<endl;
            break;
        }
        case 2:{
            thread t(money_withdrawal,acc_no);//in function_task3.cpp
            t.join();
            break;
        }
        case 3:{
            thread t (money_transfer,acc_no);// in money_transfer.cpp
            t.join();
            break;
        }
        case 4:{
            ATM_balance();// in function_task3.cpp
            break;
        }
        case 5:{
            transfer_history(acc_no); // in transfer_history.cpp
            break;
        }
        default :
            cout<<"Please enter a number between the range of 1 and 5"<<endl;
    }
}
