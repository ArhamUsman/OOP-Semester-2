/*
You are required to write a C++ program that will creates a function named unique that will take array
as input . the array may contains the duplicates values but you have to process on the array and have to
return the array which must contains only unique values not duplicates.
*/

#include <iostream>
using namespace std;

int present(int *arr, int size, int value){
    for (int i=0; i<size; i++){
        if (arr[i]==value) return 1;
    }
    return 0;
}

int* unique(int *arr, int &size){
    int* revised=new int[size], new_size=0;
    for (int i=0; i<size; i++){
        if (present(revised, new_size, arr[i])==0){
            revised[new_size++]=arr[i];
        }
    }
    size=new_size;
    return revised;
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int *arr= new int[size];
    for (int i=0; i<size; i++){
        cin>>arr[i];
    }
    arr=unique(arr, size);
    cout<<"Unique elements in the array are: ";
    for (int i=0; i<size; i++){
        cout << arr[i]<< " "; 
    }
    delete[]arr;
}