#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
    vector<string> transactionHistory; // To store transaction records

public:
    // Constructor
    Account(string accNum, double initialBalance, string holderName, string type = "General")
        : accountNumber(accNum), balance(initialBalance), accountHolderName(holderName), accountType(type) {}

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back("Deposited: $" + to_string(amount));
        } else {
            cout << "Amount should be greater than 0.\n";
        }
    }

    // Withdraw function
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionHistory.push_back("Withdrew: $" + to_string(amount));
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    // Virtual function to calculate interest (to be overridden by derived classes)
    virtual void calculateInterest() {
        // Default behavior (generic interest rate, for example)
        double interestRate = 0.02; // 2% default interest
        double interest = balance * interestRate;
        balance += interest;
        transactionHistory.push_back("Interest Added: $" + to_string(interest));
    }

    // Print account statement
    virtual void printStatement() {
        cout << "Account Statement for " << accountHolderName << " (Account No: " << accountNumber << ")\n";
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Transaction History: \n";
        for (const auto& txn : transactionHistory) {
            cout << txn << endl;
        }
    }

    // Getter for account information
    void getAccountInfo() {
        cout << "Account Info: \n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
    private:
        double interestRate;
        double minimumBalance;
    
    public:
        // Constructor for SavingsAccount
        SavingsAccount(string accNum, double initialBalance, string holderName, double rate, double minBalance)
            : Account(accNum, initialBalance, holderName, "Savings"), interestRate(rate), minimumBalance(minBalance) {}
    
        // Override withdraw to check minimum balance
        void withdraw(double amount) override {
            if (balance - amount < minimumBalance) {
                cout << "Withdrawal would drop balance below the minimum required balance of $" << minimumBalance << ".\n";
            } else {
                Account::withdraw(amount);
            }
        }
    
        // Override calculateInterest to apply interest specific to savings account
        void calculateInterest() override {
            double interest = balance * interestRate;
            balance += interest;
            transactionHistory.push_back("Interest Added: $" + to_string(interest) + " at " + to_string(interestRate*100) + "% interest rate");
        }
    
        // Override print statement to reflect SavingsAccount specifics
        void printStatement() override {
            Account::printStatement();
            cout << "Interest Rate: " << interestRate * 100 << "%\n";
            cout << "Minimum Balance: $" << minimumBalance << endl;
        }
};


class CheckingAccount : public Account {
    private:
        double overdraftLimit;
    
    public:
        // Constructor for CheckingAccount
        CheckingAccount(string accNum, double initialBalance, string holderName, double limit)
            : Account(accNum, initialBalance, holderName, "Checking"), overdraftLimit(limit) {}
    
        // Override withdraw to handle overdraft
        void withdraw(double amount) override {
            if (amount > balance + overdraftLimit) {
                cout << "Amount exceeds overdraft limit of $" << overdraftLimit << ".\n";
            } else {
                Account::withdraw(amount);
            }
        }
    
        // Override print statement to include overdraft limit
        void printStatement() override {
            Account::printStatement();
            cout << "Overdraft Limit: $" << overdraftLimit << endl;
        }
};

class FixedDepositAccount : public Account {
    private:
        double fixedInterestRate;
        time_t maturityDate;
    
    public:
        // Constructor for FixedDepositAccount
        FixedDepositAccount(string accNum, double initialBalance, string holderName, double interestRate, time_t maturity)
            : Account(accNum, initialBalance, holderName, "Fixed Deposit"), fixedInterestRate(interestRate), maturityDate(maturity) {}
    
        // Override calculateInterest to apply fixed interest rate
        void calculateInterest() override {
            if (time(0) < maturityDate) {
                cout << "Account has not yet matured. No interest is added.\n";
            } else {
                double interest = balance * fixedInterestRate;
                balance += interest;
                transactionHistory.push_back("Interest Added: $" + to_string(interest) + " at " + to_string(fixedInterestRate * 100) + "% fixed interest rate");
            }
        }
    
        // Override withdraw to prevent withdrawal before maturity
        void withdraw(double amount) override {
            if (time(0) < maturityDate) {
                cout << "Cannot withdraw before maturity date.\n";
            } else {
                Account::withdraw(amount);
            }
        }
    
        // Override print statement to include fixed deposit specifics
        void printStatement() override {
            Account::printStatement();
            cout << "Fixed Interest Rate: " << fixedInterestRate * 100 << "%\n";
            cout << "Maturity Date: " << ctime(&maturityDate);
        }
};

int main() {
    // Example usage:
    SavingsAccount savAcc("SA123", 5000, "John Doe", 0.03, 1000);
    CheckingAccount chkAcc("CA123", 2000, "Jane Smith", 500);
    FixedDepositAccount fdAcc("FD123", 10000, "Alice Johnson", 0.05, time(0) + 60*60*24*365); // Matures in 1 year

    // Perform some operations
    savAcc.deposit(1000);
    savAcc.withdraw(200);
    savAcc.calculateInterest();
    savAcc.printStatement();

    chkAcc.deposit(500);
    chkAcc.withdraw(2500); // Should fail due to overdraft limit
    chkAcc.printStatement();

    fdAcc.deposit(5000);
    fdAcc.calculateInterest(); // No interest added yet due to maturity
    fdAcc.printStatement();

    return 0;
}
