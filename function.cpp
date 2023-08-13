#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include "cash_loading.cpp"
using namespace std;

vector<Cash_loading> money;


void cash_loading_ATM(){
    Cash_loading rs2000, rs500, rs100;
    char continue_money_loading;
    int denomination;

    //for loading amount in ATM
    rs2000.cash_loading_2000(); //function definition in  cash_loading.cpp
    money.push_back(rs2000);

    rs500.cash_loading_500();//function definition in  cash_loading.cpp
    money.push_back(rs500);

    rs100.cash_loading_100();//function definition in  cash_loading.cpp
    money.push_back(rs100);
    return;
}

//when amount is already present in ATM
void calculation_changes(vector<Cash_loading> already_existing){
    for(int i=0;i<already_existing.size();i++){
            for(int j=0;j<money.size();j++){
                if(already_existing[i].money_denomination==money[j].money_denomination){
                    money[j].money_number += already_existing[i].money_number;
                    money[j].money_value=money[j].money_denomination*money[j].money_number;
                }
            }
        }
}

void cash_loading_file(){
    ifstream file;
    vector<Cash_loading> already_existing;
    int file_denomination, file_number, file_value;
    Cash_loading already_existing_data;

    file.open("ATM Balance.txt",  ios::app | ios::in | ios::out);
    if(file.is_open()){
        while(file >> file_denomination >> file_number >> file_value){
            already_existing_data.money_denomination = file_denomination;
            already_existing_data.money_number = file_number;
            already_existing_data.money_value = file_value;

            already_existing.push_back(already_existing_data);
        }
        calculation_changes(already_existing);
        file.close();
    }
    else{
        cout<<"Error loading file";
    }
}


void write_to_file(){
    ofstream file("ATM Balance.txt", ios::in);
        for(int i=0;i<money.size();i++){
            file<<money[i].money_denomination<<" "<<money[i].money_number<<" "<<money[i].money_value<<endl;
        }
    file.close();
}

void display_output(){
    int file_denomination, file_number, file_value;
    ifstream file("ATM Balance.txt", ios::in);
    cout<<endl<<setw(15)<<left<<"Denomination"<<setfill(' ')<<setw(15)<<"Number"<<setfill(' ')<<"Value"<<endl;
    while(file >> file_denomination >> file_number >> file_value){
        cout<<setw(15)<<left<<file_denomination<<setfill(' ')<<setw(15)<<file_number<<setfill(' ')<<file_value<<endl;
    }
    file.close();
}


