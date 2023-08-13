#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
#include<string>
#include<chrono>
#include<thread>
using namespace std;

long long int bal;
int two_thousand=0;
int five_hundred=0;
int hundred=0;
int dispense_denomination[3];

long long int balance_enquiry(int acc_no){
    fstream file;
    int account_no, pin,counts=0;
    string name;
    file.open("Customer Details.txt", ios::in);
    while(file>> account_no >> name >> pin >> bal){
        if(account_no == acc_no){
            return bal;
        }
    }
}

void ATM_balance(){
    fstream file;
    int amount, number, value;
    long int total=0;
    file.open("ATM Balance.txt",ios::in);
    cout<<endl<<setw(15)<<left<<"Denomination"<<setfill(' ')<<setw(15)<<"Number"<<setfill(' ')<<setw(30)<<"Value"<<endl;
    while(file>>amount>>number>>value){
        cout<<setw(15)<<left<<amount<<setfill(' ')<<setw(15)<<number<<setfill(' ')<<setw(30)<<value<<endl;
        total += value;
    }
    cout<<endl<<"Total Amount available in ATM is Rs."<<total<<endl;
}

void amount_less_than_5000(int amount){

    if(amount>=3000){
        two_thousand+=1;
        amount-=2000;
    }
    if(amount>=1500){
        five_hundred += 2;
        amount-=1000;
    }
    if(amount>=1000){
        five_hundred+=1;
        amount-=500;
    }
    if(amount>=100){
        hundred=amount/100;
    }
    dispense_denomination[0]=two_thousand;
    dispense_denomination[1]=five_hundred;
    dispense_denomination[2]=hundred;
}

void amount_greater_than_5000(int amount){
    two_thousand=2;
    five_hundred=2;
    amount-=5000;
    amount_less_than_5000(amount);
}

long long int account_balance_deduction(int acc_no, int amount_entered, bool withdraw){
    fstream file;
    int acc, pin;
    string name;
    long long int balance, bal_mini_statement;
    vector<Customer> balance_deduct;
    Customer p1;
    file.open("Customer Details.txt",ios::in );
    while(file>>acc>>name>>pin>>balance){
            p1.setter(acc, name, pin, balance);
            balance_deduct.push_back(p1);
        }
    file.close();
    for(int i=0;i<balance_deduct.size();i++)
        if(balance_deduct[i].acc_no==acc_no){
            withdraw ? balance_deduct[i].balance -= amount_entered : balance_deduct[i].balance += amount_entered;
            bal_mini_statement = balance_deduct[i].balance;
    }
    file.open("Customer Details.txt", ios::out);
    for(int i=0;i<balance_deduct.size();i++){
        file << balance_deduct[i].acc_no <<" "<< balance_deduct[i].acc_holder<<" "<<balance_deduct[i].pin_number<<" "<<balance_deduct[i].balance<<endl;
    }
    file.close();
    return bal_mini_statement;
}

void ATM_balance_deduction(int dispense_denomination[], int cash[]){
    vector<Cash_loading> balance_after_dispense;
    Cash_loading rupees;
    int amount, number, value;
    fstream file_deduct;
    file_deduct.open("ATM Balance.txt", ios::in);
    while(file_deduct>>amount>>number>>value){
        rupees.money_denomination=amount;
        rupees.money_number=number;
        rupees.money_value=value;

        balance_after_dispense.push_back(rupees);
    }
    file_deduct.close();
    for(int i=0;i<balance_after_dispense.size();i++){
        if(balance_after_dispense[i].money_denomination==cash[i]){
        balance_after_dispense[i].money_number-=dispense_denomination[i];
        balance_after_dispense[i].money_value=balance_after_dispense[i].money_denomination* balance_after_dispense[i].money_number;
        }
    }
    file_deduct.open("ATM Balance.txt", ios::out);
        for(int i=0;i<balance_after_dispense.size();i++){
            file_deduct<<balance_after_dispense[i].money_denomination<<" "<<balance_after_dispense[i].money_number<<" "<<balance_after_dispense[i].money_value<<endl;
        }
    file_deduct.close();
}

void money_withdrawal(int acc_no){
    long int total=0;
    long long int debit_bal;
    bool withdraw=true;
    int amount, number, value;
    int cash[3]={2000,500,100};
    int flag=0;
    int count_i=0;

    fstream file_ATM_bal;
    file_ATM_bal.open("ATM Balance.txt",ios::in);
     while(file_ATM_bal>>amount>>number>>value){
        total += value;
    }
    file_ATM_bal.close();

    int amount_entered;
    cout<<"Enter the amount in multiples of 100 : ";
    cin>>amount_entered;
    if(amount_entered%100==0){
        if(amount_entered>=100 && amount_entered<=10000){
            if(amount_entered<=total){
                auto acc_bal = balance_enquiry(acc_no);
                if(amount_entered<acc_bal){
                    if(amount_entered<=5000){
                       amount_less_than_5000(amount_entered);
                    }
                    else{
                        amount_greater_than_5000(amount_entered);
                    }

                    file_ATM_bal.open("ATM Balance.txt",ios::in);
                     while(file_ATM_bal>>amount>>number>>value){
                        for(int i=0;i<3;i++){
                            if((amount == cash[i]) && (number>=dispense_denomination[i])){
                                flag++;
                            }
                        }
                    }
                    if(flag==3){
                        cout<<"The amount is dispensed: "<<endl<<"Rs.2000 - "<<two_thousand<<endl<<"Rs.500 - "<<five_hundred<<" "<<endl<<"Rs.100 - "<<hundred<<endl;
                        debit_bal=account_balance_deduction(acc_no,amount_entered,withdraw);
                        ofstream file;
                        file.open(to_string(acc_no)+"_transactions.txt",ios::app);
                        if(file.is_open()){
                            string desc="Cash Withdrawal";
                            string mode="debit";
                            int trans=3000;
                            this_thread::sleep_for(chrono::seconds(5));
                            file<<trans<<" "<<desc<<" "<<mode<<" "<<amount_entered<<" "<<debit_bal<<endl;
                            file.close();
                        }
                        else{
                            cout<<"Error while opening file";
                        }
                        ATM_balance_deduction(dispense_denomination,cash);
                    }
                    else{
                        cout<<"ATM does not have required denomination to vend"<<endl<<"flag - "<<flag;
                    }
                    file_ATM_bal.close();
                }
                else{
                    cout<<"Account balance is lower than the requested withdrawal amount"<<endl;
                }
            }
            else{
                cout<<"ATM does not have sufficient money to vend"<<endl;
            }
        }
        else{
            cout<<"Maximum withdrawal limit for single transaction is Rs.10000 and minimum is Rs.100"<<endl;
        }
    }
    else{
        cout<<"Money can be withdrawn only in multiples of 100"<<endl;
    }
}




