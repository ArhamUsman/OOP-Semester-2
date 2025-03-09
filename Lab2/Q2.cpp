/*
Write a C++ program that:
- Reads n strings from the user and stores them in a dynamically allocated array of char*.
- Prints the strings in reverse order using pointer arithmetic.
- Finds and prints the string with the most vowels (a, e, i, o, u).
- Calculates and prints the average length of all the strings.
Note: Use pointer notation wherever possible.
If there are multiple strings with the same number of vowels, print the first one encountered
*/

#include <iostream>
#include <string>
using namespace std;

void print_str_in_rev(char *c, int size){
    for (int i=size-1; i>=0; i--){
        cout<<c[i];
    }
    cout<<endl;
}

int vowels(char *c){
    int v=0;
    for (int i=0; c[i]!='\0'; i++){
        if (c[i]=='A'||c[i]=='E'||c[i]=='I'||c[i]=='O'||c[i]=='U'||c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'){
            v++;
        }
    }
    return v;
}

int max_vowels(char**c, int size){
    int v=-1; int index=-1; int num;
    for (int i=0; i<size; i++){
        num=vowels(c[i]);
        if (num>v){
            index=i;
            v=num;
        }
    }
    return index;
}

float average(int *arr, int size){
    float avg=0;
    for (int i=0; i<size; i++){
        avg+=arr[i];
    }
    return avg/size;
}

int main(){
    int size;
    cout<<"Enter number of strings that you want to input: ";
    cin>>size;
    char **sptr= new char*[size];
    int *sizes=new int[size];
    string gg;
    for (int i=0; i<size; i++){
        cout<<"Enter string: ";
        cin>>gg;
        sizes[i]=gg.length()+1;
        sptr[i]=new char[sizes[i]];
        for (int j=0; j<sizes[i];j++){
            sptr[i][j]=gg[j];
        }
    }
    cout<<"Print strings in reverse\n";
    for (int i=0; i<size; i++){
        print_str_in_rev(sptr[i], sizes[i]-1);
    }
    cout<<"\nString with most vowels: ";
    int max=max_vowels(sptr, size);
    for (int i=0; sptr[max][i]!='\0'; i++){
        cout<<sptr[max][i];
    }
    cout<<"\nAverage Length: "<<average(sizes, size);
}