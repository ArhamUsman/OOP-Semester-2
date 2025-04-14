#include <iostream>
using namespace std;

class Account{
    double balance;
    string accountNumber;
    string accountHolder;
    public:
    Account(string number, string holder, double balance){
        accountNumber=number;
        accountHolder=holder;
        this->balance=balance;
    }
    
    double getBalance() const {return balance;}
    string getHolder() const {return accountHolder;}
    void setBalance(double amount){balance = amount;}
    double operator+(const Account a) const {
        return balance+a.getBalance();
    }
    double operator+(const double a) const {
        return balance+a;
    }
    Account operator=(double amount){
        balance+=amount;
        return *this;
        //return (this->accountNumber, this->accountHolder, this->balance+amount);
    }
    bool operator>(Account a){
        return balance>a.getBalance();
    }
    friend ostream& operator<<(ostream& os, Account& a);
};
ostream& operator<<(ostream& os, Account& a){
    os<<"Account Number: "<<a.accountNumber<<" | Holder: "<< a.accountHolder<< " | Balance: $"<<a.balance<<endl;
    return os;
}


int main(){
    Account a1("101", "Shafique Rehma", 5000), a2("102", "Talha", 3000);
    // cout<<a1;
    // cout<<a2;
    // a2=2000;
    // a1.setBalance(a1.getBalance()-2000);
    // cout<<"Balance a1="<<a1.getBalance()<<endl;
    // cout<<"Balance a2="<<a2.getBalance();
    cout<<"Total Balance (After Addition): "<<a1+a2;
    cout<<endl<<endl;
    a1.setBalance(a1.getBalance()-2000);
    a2=2000;
    cout<<"After Transfer: \n";
    cout<<a1.getHolder()<< "'s New Balance: "<<a1.getBalance()<<endl;
    cout<<a2.getHolder()<< "'s New Balance: "<<a2.getBalance()<<endl<<endl;
    cout<<"Comparison:\n";
    if (a1>a2){
        cout<<a2.getHolder() <<" has less balance than "<< a1.getHolder();
    }
    else{
        cout<<a1.getHolder() <<" has less balance than "<< a2.getHolder();
    }
    cout<<endl<<endl;
    cout<<"Final Account Details:\n";
    cout<<a1<<a2;
}
Task2.cpp
Displaying Task2.cpp.
Lab 08 - Lab Tasks
Shafique Rehman
•
Mar 24 (Edited Mar 24)
8 points
Due Mar 24, 11:59 PM

OOP_LAB#08 - Lab Taks-BCS-2F - Spring 2025_.pdf
PDF
Class comments
Your work
Turned in late

Task2.cpp
Text

Task1.cpp
Text

OOP-Semester-2/Lab8 at main · ArhamUsman/OOP-Semester-2 · GitHub
https://github.com/ArhamUsman/OOP-Semester-2/tree/main/Lab8
Private comments
