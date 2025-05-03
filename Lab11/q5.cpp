#include <iostream>
#include <string>
using namespace std;

char* string_to_char_pointer(string s){
    int l=s.length();
    char* c=new char[l+1];
    for (int i=0; i<l; i++){
        c[i]=s[i];
    }
    c[l]='\0';
    return c;
}

template <typename T>
class insufficientFundsException:public exception{
    T t;
    public:
    insufficientFundsException(T deficit){
        t=deficit;
    }
    const char* what() const noexcept override{
        string s= "InsufficientFundsException - Deficit: $"+to_string(t);
        return string_to_char_pointer(s);
    }
};

template <typename T>
class BankAccount{
    T balance;
    public:
    BankAccount(T amount){
        balance=amount;
    }
    bool withdraw(T amount){
        try{
            if (amount>balance) throw(insufficientFundsException(amount - balance));
            balance-=amount;
            cout<<"Amount withdrawed successfully\n";
            return true;
        }
        catch (insufficientFundsException<T> &e){
            cout<<e.what()<<endl;
            return false;
        }
    }
};

int main(){
    BankAccount b(500.00);
    cout<<"Balance: $500\nWithdraw $600: ";
    b.withdraw(600);
}