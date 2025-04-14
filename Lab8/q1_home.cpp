#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Base class BankAccount
class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

    // Virtual function to calculate annual interest (to be overridden in derived classes)
    virtual double calculateInterest() const {
        return 0.0;  // Base class does not calculate interest
    }

    // Overload deposit method to handle different types of deposits
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " to account " << accountNumber << endl;
    }

    // Virtual method for withdrawal
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Insufficient funds for withdrawal in account " << accountNumber << endl;
        }
    }

    // Operator overloading for + (add two account balances)
    BankAccount operator+(const BankAccount& other) {
        return BankAccount(accountNumber, balance + other.balance);
    }

    // Operator overloading for - (subtract amount from balance)
    BankAccount& operator-(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient funds to subtract " << amount << " from account " << accountNumber << endl;
        }
        return *this;
    }

    // Operator overloading for * (apply interest on balance)
    BankAccount& operator*(double interestRate) {
        balance += balance * interestRate;
        return *this;
    }

    // Operator overloading for / (calculate equal installment payments)
    double operator/(int installments) {
        if (installments > 0) {
            return balance / installments;
        } else {
            cout << "Number of installments must be greater than zero!" << endl;
            return 0;
        }
    }

    // Display balance
    void displayBalance() const {
        cout << "Account " << accountNumber << " Balance: $" << balance << endl;
    }

    virtual ~BankAccount() {}
};

// Derived class SavingsAccount
class SavingsAccount : public BankAccount {
public:
    // Constructor
    SavingsAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance) {}

    // Overridden function to calculate interest (5% per year)
    double calculateInterest() const override {
        return balance * 0.05;
    }

    // Overloaded deposit method
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited " << amount << " to Savings Account " << accountNumber << endl;
    }

    // Overridden withdraw method
    void withdraw(double amount) override {
        if (balance - amount < 500) {
            cout << "Cannot withdraw. Balance cannot be less than $500 in Savings Account " << accountNumber << endl;
        } else {
            balance -= amount;
            cout << "Withdrew " << amount << " from Savings Account " << accountNumber << endl;
        }
    }

    ~SavingsAccount() {}
};

// Derived class CurrentAccount
class CurrentAccount : public BankAccount {
public:
    // Constructor
    CurrentAccount(string accountNumber, double balance) : BankAccount(accountNumber, balance) {}

    // Overridden function to calculate interest (no interest for Current Account)
    double calculateInterest() const override {
        return 0.0;
    }

    // Overloaded deposit method
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited " << amount << " to Current Account " << accountNumber << endl;
    }

    // Overridden withdraw method
    void withdraw(double amount) override {
        if (balance - amount < -1000) {
            cout << "Cannot withdraw. Overdraft limit of $1000 exceeded in Current Account " << accountNumber << endl;
        } else {
            balance -= amount;
            cout << "Withdrew " << amount << " from Current Account " << accountNumber << endl;
        }
    }

    ~CurrentAccount() {}
};

int main() {
    // Create objects for SavingsAccount and CurrentAccount
    SavingsAccount savingsAcc("S001", 2000.0);
    CurrentAccount currentAcc("C001", 500.0);

    // Demonstrate method overloading (deposit with different methods)
    savingsAcc.deposit(300);  // Cash deposit
    currentAcc.deposit(1000); // Cash deposit

    // Display balances
    savingsAcc.displayBalance();
    currentAcc.displayBalance();

    // Demonstrate method overriding (withdraw)
    savingsAcc.withdraw(1700);  // Should succeed
    savingsAcc.withdraw(1600);  // Should fail (balance below $500)
    
    currentAcc.withdraw(1200); // Should succeed
    currentAcc.withdraw(2000); // Should fail (overdraft limit exceeded)

    // Demonstrate operator overloading (+, -, *, /)
    SavingsAccount savingsAcc2("S002", 3000.0);
    CurrentAccount currentAcc2("C002", 1000.0);

    // + operator (combine two accounts' balances)
    BankAccount combinedAccount = savingsAcc + savingsAcc2;
    combinedAccount.displayBalance();

    // - operator (subtract an amount from the balance)
    savingsAcc - 500;
    savingsAcc.displayBalance();

    // * operator (apply interest)
    savingsAcc * 0.05;  // Apply 5% interest
    savingsAcc.displayBalance();

    // / operator (calculate equal installments)
    double installment = savingsAcc / 10; // Split balance into 10 equal installments
    cout << "Installment amount: $" << installment << endl;

    // Calculate interest for each account type
    cout << "Interest on Savings Account: $" << savingsAcc.calculateInterest() << endl;
    cout << "Interest on Current Account: $" << currentAcc.calculateInterest() << endl;

    return 0;
}
