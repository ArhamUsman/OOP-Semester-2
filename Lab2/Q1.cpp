/*
Write a C++ program that reads a group of n numbers from the user and stores them in a dynamically
allocated array of type float. Then, the program should:
- Calculate the average of the numbers.
- Find the number closest to the average.
- Print the average and the number closest to it.
- Use pointer notation wherever possible.
*/

#include <iostream>
using namespace std;

float number(float *arr, float avg, int size){
    float num, diff=999999.9;
    for (int i=0; i<size; i++){
        float diff2=arr[i]-avg;
        if (diff2<0) diff2*=-1;
        if (diff2<diff) {
            num=arr[i]; diff=diff2;
        }
    }
    return num;
}

int main(){
    int size=0;
    cout<<"Enter number of values that you want to input: ";
    cin>>size;
    float *userInput=new float[size], sum=0;
    for (int i=0; i<size; i++){
        cout << "Enter value "<<i+1<<" : ";
        cin>>userInput[i];
        sum+=userInput[i];
    }
    float average=sum/size, num=number(userInput, average, size);

    cout<<"Average: "<<average<<"\nNumber closest to average: "<<num;
}