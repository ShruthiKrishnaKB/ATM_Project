#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

class Customer{
public:
    int acc_no;
    string acc_holder;
    int pin_number;
    long long int balance;

    void setter(int no, string name, int pin, long long int bal){
        acc_no=no;
        acc_holder=name;
        pin_number=pin;
        balance=bal;
    }
};

void customer_details(){
    Customer person1, person2, person3, person4, person5;
    person1.setter(101, "Suresh", 2343, 25324);
    person2.setter(102, "Ganesh", 5432, 34123);
    person3.setter(103, "Magesh", 7854, 26100);
    person4.setter(104, "Naresh", 2345, 80000);
    person5.setter(105, "Harish", 1907, 103400);
    vector<Customer> customer_info;
    customer_info.push_back(person1);
    customer_info.push_back(person2);
    customer_info.push_back(person3);
    customer_info.push_back(person4);
    customer_info.push_back(person5);

    fstream file;
    file.open("Customer Details.txt", ios::out);
    if(file.is_open()){
        for(int i=0;i<customer_info.size();i++){
            file << customer_info[i].acc_no <<" "<< customer_info[i].acc_holder<<" "<<customer_info[i].pin_number<<" "<<customer_info[i].balance<<endl;
        }
    }else{
        cout<<"Error"<<endl;
    }
    file.close();

    int account,pin;
    string name;
    long long int acc_balance;
    file.open("Customer Details.txt", ios::in);
    cout<<endl;
    cout<<setw(25)<<left<<"Account Number"<<setfill(' ')<<setw(30)<<"Account Holder Name"<<setfill(' ')<<setw(25)<<"Pin Number"<<setfill(' ')<<setw(30)<<"Account Balance"<<endl;
    while(file>> account>> name>> pin>> acc_balance){
        cout<<setw(25)<<left<<account<<setfill(' ')<<setw(30)<<name<<setfill(' ')<<setw(25)<<pin<<setfill(' ')<<setw(30)<<acc_balance<<endl;
    }
    file.close();
}


