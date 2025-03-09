/*
Task-04:
Create a BankAccount class. Which contains following details and functionalties:
Attributes: The BankAccount class has three private member variables: accountNumber,
accountHolderName, and balance.
Create Constructor: The class has a constructor that takes parameters to initialize the account
details (accountNumber, accountHolderName, and balance).
Create following Member Functions:
• deposit(double amount): Adds the specified amount to the account balance.
• withdraw(double amount): Subtracts the specified amount from the account balance, if
sufficient funds are available.
• display(): Displays the account details including the account number, account holder name,
and balance.
In the main() function, create an array accounts of BankAccount objects. The array contains three
elements, each representing a different bank account.
Initialize Each BankAccount object with specific account details such as account number, holder
name, and initial balance.
Perform following operations:
• Iterate through each account in the accounts array.
• For each account, display the account details using the display() function.
• Perform Two Transactions:
• Deposits 500.0 rupees into the account.
• Withdraws 200.0 rupees from the account.
• After each transaction, display the updated account details, including the new balance.
*/

#include <iostream>
using namespace std;

class BankAccount{
    string accountNumber, accountHolderName;
    double balance;
    public:
    BankAccount(string AccountNumber="", string AccountHolderName="", double Balance){ 
        accountHolderName=AccountHolderName;
        accountNumber=AccountNumber;
        balance=Balance;
    }
    void deposit(const double amount){
        balance+=amount;
        cout<<amount<<" is deposited successfully.\n";
    }
    bool withdraw(const double amount){
        if (amount>balance){
            cout<<"Transaction failed! Sufficient balance not available.\n";
            return false;
        }
        balance-=amount;
        cout<<amount<<"is withdrawed successfully.\n";
        return true;
    }
    void display() const{
        cout<<"-----\n";
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Account Holder Name: "<<accountHolderName<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"-----\n";
    }
};
int main() {
    BankAccount bop[]={BankAccount("0105 0203 04", "Ali", 100),
        BankAccount("0100 0200 07", "Bilal", 150),
        BankAccount("0109 0205 09", "Charlie", 200)
    };
    for (int i=0; i<3; i++){
        bop[i].display();
        bop[i].deposit(500.0);
        bop[i].withdraw(200.0);
        bop[i].display();
    }
}