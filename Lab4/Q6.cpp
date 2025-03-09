/*
Scenario: A bank wants to develop a system for managing customer accounts. The system
should allow customers to:
1. Create a new account with an account number, owner’s name, and initial balance
(default balance is 0 if not provided).
2. Deposit money into their account.
3. Withdraw money from their account, ensuring they cannot withdraw more than the
available balance.
4. Display account details including account number, owner’s name, and current balance.
Your task is to implement a C++ program that fulfills these requirements.
*/

#include <iostream>
using namespace std;

class Account{
    string accountNumber;
    string accountHolderName;
    double balance;
    public:
    Account(string Account_Number="", string Holder_Name="", double Balance=0.0){
        accountNumber=Account_Number;
        accountHolderName=Holder_Name;
        balance=Balance;
    }
    string get_ID(){
        return accountNumber;
    }
    void deposit(double amount){
        balance+=amount;
        cout<<"\nAmount deposited successfully"<<endl;
    }
    void withdraw(double amount){
        if (amount<=balance){
            balance-=amount;
            cout<<"\nAmount withdrawed successfully"<<endl;
        }
        else{
            cout<<"\nTransaction Failed! Insufficient Balance"<<endl;
        }
    }
    void displayDetails(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Owner Name: "<<accountHolderName<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};

class Bank{
    Account *accounts;
    int noOfAccounts;
    public:
    Bank(){
        accounts=nullptr;
        noOfAccounts=0;
    }
    ~Bank(){
        delete[] accounts;
    }
    void newAccount(Account account){
        Account *temp_shifting=new Account[++noOfAccounts];
        int i, found=0;
        for (i=0; i<noOfAccounts-1; i++){
            if (accounts[i].get_ID()==account.get_ID()){
                found=1; break;
            }
            temp_shifting[i]=accounts[i];
        }
        if (found==0){
            temp_shifting[i]=account;
            delete[] accounts;
            accounts=temp_shifting;
            cout<<"\n-----Account added successfully-----\n";
        }
        else{
            delete[] temp_shifting;
            noOfAccounts--;
            cout<<"\n-----Error! Account must have a unique Account Number-----\n";
        }
    }
    void deposit_money(){
        cout<<"\n-----------------\n";
        cout<<"Enter account number: ";
        string ac;
        cin>>ac;
        for (int i=0; i<noOfAccounts; i++){
            if (ac==accounts[i].get_ID()){
                cout<<"Enter the amount you want to deposit: ";
                double temp;
                cin>>temp;
                accounts[i].deposit(temp);
                return;
            }
        }
        cout<<"Error! Account is not Found\n";
    }
    void withdraw_money(){
        cout<<"\n-----------------\n";
        cout<<"Enter account number: ";
        string ac;
        cin>>ac;
        for (int i=0; i<noOfAccounts; i++){
            if (ac==accounts[i].get_ID()){
                cout<<"Enter the amount you want to withdraw: ";
                double temp;
                cin>>temp;
                accounts[i].withdraw(temp);
                return;
            }
        }
        cout<<"Error! Account is not Found\n";
    }
    void display_account_details(){
        cout<<"\n-----------------\n";
        cout<<"Enter account number: ";
        string ac;
        cin>>ac;
        for (int i=0; i<noOfAccounts; i++){
            if (ac==accounts[i].get_ID()){
                accounts[i].displayDetails();
                return;
            }
        }
        cout<<"Error! Account is not Found\n";
    }
};

int main(){
    string choice, id, title;
    double balance;
    Bank State_Bank_Of_Pakistan;
    while (1){
        cout<<"\n=====Main Menu=====\n";
        cout<<"Press 1 to add a new account\nPress 2 to deposit money\nPress 3 to withdraw\nPress 4 to check account details\nPress any other key to exit :)\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        if (choice=="1"){
            cout<<"\n----------\n";
            cout<<"Enter Account Number: ";
            cin>>id;
            cout<<"Enter Owner Name: ";
            cin.ignore();
            getline(cin, title);
            cout<<"Enter Initial Balance: ";
            cin>>balance;
            State_Bank_Of_Pakistan.newAccount(Account(id, title, balance));
        }
        else if (choice=="2"){
            State_Bank_Of_Pakistan.deposit_money();
        }
        else if (choice=="3"){
            State_Bank_Of_Pakistan.withdraw_money();
        }
        else if (choice=="4"){
            State_Bank_Of_Pakistan.display_account_details();
        }
        else{
            cout<<"\n=====Thank You for using our service=====";
            break;
        }
    }
}