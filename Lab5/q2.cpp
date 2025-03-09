/*
Task-02:
Create a class called LoanHelper, which helps the user calculate their loan payments. The class
should have a variable that stores interest rate for the loan as a user defined constant value. Aside
from the that, it also stores the amount for the loan taken and amount of months that the user will
repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate
should be applied over the monthly return amount. The output should be something like:
“You have to pay 999 every month for 12 monthsto repay your loan”
Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate
should be a value between 0-0.5%
*/

#include <iostream>
using namespace std;

class LoanHelper{
    float interest_rate;
    float amount_of_loan, amount_of_months;

    public:
    //Constructor
    LoanHelper(float InterestRate=0, float LoanAmount=0, float Months=0){
        
    }
    //Setter
    void setInterest(float InterestRate){
        if (InterestRate>=0&&InterestRate<=0.5){
            interest_rate=InterestRate;
        }
        else{
            cout<<"ERROR! Interest Rate should be 0-0.5.\n";
        }
    }
    void setLoanAmount(float LoanAmount){
        if (LoanAmount<0){
            cout<<"ERROR! Loan Amount should be a positive integer.\n";
        }
        else{
            amount_of_loan=LoanAmount;
        }
    }
    void setMonths(float Months){
        if ((Months==0&&amount_of_loan==0)||Months>0){
            amount_of_months=Months;
        }
        else{
            cout<<"Error! Months should be greater than 0\n";
        }
    }
    //Methods
    void calculateLoan(){
        if (amount_of_loan==0){
            cout<<"You have repaid all your loan.\n";
        }
        else{
            if (amount_of_months==0){
                cout <<"MONTHS should be greater than 0.\n";
            }
            else {
                cout <<"You have to pay "<<(amount_of_loan*(1+(interest_rate/100)))/amount_of_months<<" every month for "<< amount_of_months<<" months to repay your loan.\n";
            }
        }
    }
};

int main(){
    LoanHelper l1;
    l1.setInterest(0.5);
    l1.setLoanAmount(12000);
    l1.setMonths(12);
    l1.calculateLoan();
}