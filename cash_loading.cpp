#include<iostream>
using namespace std;

class Cash_loading{
public:
    int money_denomination;
    int money_number;
    int money_value;

    void cash_loading_2000(){
        cout<<"Enter the number of 2000 rupees notes to be fed in ATM : ";
        cin>>money_number;
        money_denomination=2000;
        money_value = money_denomination * money_number;
    }
    void cash_loading_500(){
        cout<<"Enter the number of 500 rupees notes to be fed in ATM : ";
        cin>>money_number;
        money_denomination=500;
        money_value = money_denomination * money_number;
    }
    void cash_loading_100(){
        cout<<"Enter the number of 100 rupees notes to be fed in ATM : ";
        cin>>money_number;
        money_denomination=100;
        money_value = money_denomination * money_number;
    }
};
