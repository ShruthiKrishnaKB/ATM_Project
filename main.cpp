#include<iostream>
#include "function.cpp"
#include "customer_details.cpp"
#include "login.cpp"
using namespace std;

int main(){
    int main_menu_task;
    cout<<"Please select the task to be performed from the following"<<endl;
    cout<<"1. Load Cash to ATM"<<endl<<"2. Show customer details"<<endl<<"3. Show ATM Operations"<<endl;
    cout<<"Enter the respective number corresponding to the task: ";
    cin>>main_menu_task;
    switch(main_menu_task){
    case 1:{
        cash_loading_ATM(); //function definition in function.cpp
        cash_loading_file();//function definition in function.cpp
        write_to_file();//function definition in function.cpp
        display_output();//function definition in function.cpp
        break;
    }
    case 2:{
        customer_details();//function definition in customer_details.cpp
        break;
    }
    case 3:{
        login(); //function definition in login.cpp
        break;
    }
    default:
        cout<<"Please enter a valid number between 1 and 3 "<<endl;
    }
    return 0;
}
