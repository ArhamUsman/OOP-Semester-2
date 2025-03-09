/*
You are required to write a c++ function swap_string that shifts the last n characters of a string to the
front n times. It will take str and int as parameters. And will return the new string after shifting.
Note: You have to work with pointers.
*/

#include <iostream>
using namespace std;

string swap_string(string &s, int num){
    int len=s.length();
    string c; 
    int index=len-num;
    if (num>len) num=len;
    for (int i=0; i<num; i++){
        c+=s[index++];
    }
    for (int i=num; i<len; i++){
        c+=s[i-num];
    }
    return c;
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    int num;
    cout<<"Enter the number of characters to shift: ";
    cin>>num;
    cout<<"Shifted string after shifting last "<<num<<" characters: "<<swap_string(s, num);
}