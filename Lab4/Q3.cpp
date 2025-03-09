/*
You are building a bank account management system. Create a class `Account` to manage bank
accounts.
Requirements:
1. Attributes:
- `accountNumber` (string)
- `accountHolderName` (string)
- `balance` (double)
2. Define a default constructor that initializes `balance` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
- `deposit(double amount)`: Adds the amount to the balance.
- `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are
available).
- `checkBalance()`: Displays the current balance.
5. Create a few `Account` objects and test the methods.
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

    void deposit(double amount){
        balance+=amount;
        cout<<"\nAmount deposited successfully in Account "<< accountNumber<<endl;
    }
    void withdraw(double amount){
        if (amount<=balance){
            balance-=amount;
            cout<<"\nAmount withdrawed successfully from Account "<< accountNumber<<endl;
        }
        else{
            cout<<"\nTransaction Failed! Insufficient Balance in account "<< accountNumber<<endl;
        }
    }
    void checkBalance(){
        cout<<"\n-------------";
        cout<<"\nAccount Title: "<<accountHolderName;
        cout<<"\nBalance: "<<balance;
        cout<<"\n-------------\n";
    }
};

int main(){
    Account *a= new Account[5];
    a[0]=Account("PK1014", "Darwin", 1014);
    a[1]=Account("PK1010", "Ali", 1010);
    a[2]=Account("PK1011", "Ahmed", 1011);
    a[3]=Account("PK1012", "Bilal", 1012);
    a[4]=Account("PK1013", "Charlie", 1013);
    a[1].deposit(1000.50);
    a[2].withdraw(1011);
    a[3].withdraw(1014);
    for (int i=0; i<5; i++){
        a[i].checkBalance();
    }
    delete[] a;
}