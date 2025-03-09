/*
Q1: Write a C++ program to check whether a given number is prime or not. Allow
the user to input a number and display whether it's prime or not?
*/

#include <iostream>
using namespace std;

int main(){
    int num, p=0, i;
    cout << "Enter a number: ";
    cin >> num;
    for (i=2; i<num/2 ; i++){
        if (num%i==0){
            p=1;
            break;
        }
    }
    if (p==1) cout<<"Number is not prime!";
    else cout<<"Number is prime!";
}