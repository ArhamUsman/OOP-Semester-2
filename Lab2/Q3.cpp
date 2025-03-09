/*
Write a C++ program that:
- Dynamically allocates a 2D array using pointers (not using vector or standard containers).
- Fills the array with random integers between 1 and 100.
- Pass the 2D array to function to perform these tasks:
- Calculates and prints The sum of all elements in the array.
- Calculates and prints The sum of each row and each column.
- Calculates and prints The row and column with the highest sum.
- Pass the 2D array to a function to transpose the matrix and print the resulting matrix.
Free the dynamically allocated memory.
Note:
Use functions to perform the calculations and matrix operations (do not write all code inside main()).
Handle edge cases, such as when the array has no elements or is improperly allocated.
Sample Output:
Original Matrix:
[ 12 35 56 ]
[ 8 45 67 ]
[ 23 54 34 ]
Sum of all elements: 434
Row sums: 103, 120, 111
Column sums: 43, 134, 157
Row with highest sum: Row 2
Column with highest sum: Column 3
Transposed Matrix:
[ 12 8 23 ]
[ 35 45 54 ]
[ 56 67 34 ]
*/
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;

void total_sum(int **&arr){
    cout<<"Sum of all elements: ";
    int s=0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            s+=arr[i][j];
        }
    }
    cout<<s<<endl;
}

int sum_row(int **&arr){
    cout<<"Row sums: ";
    int s=0, index=-1, max_sum=0;
    for (int i=0; i<3; i++){
        s=0;
        for (int j=0; j<3; j++){
            s+=arr[i][j];
        }
        if (i!=2) cout<<s<<", ";
        else cout<<s<<endl;
        if (max_sum<s){
            max_sum=s;
            index=i;
        }
    }
    return index;
}

int sum_col(int **&arr){
    cout<<"Column sums: ";
    int s=0, index=-1, max_sum=0;
    for (int i=0; i<3; i++){
        s=0;
        for (int j=0; j<3; j++){
            s+=arr[j][i];
        }
        if (i!=2) cout<<s<<", ";
        else cout<<s<<endl;
        if (max_sum<s){
            max_sum=s;
            index=i;
        }
    }
    return index;
}

int** transpose(int **&arr){
    int **t= new int*[3];
    if (t==NULL){
        cout<<"Memory allocation Failed:(";
        return t;
    }
    for (int i=0; i<3; i++){
        t[i]=new int[3];
        if (t[i]==NULL){
            cout<<"Memory allocation Failed:(";
            return t;
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            t[i][j]=arr[j][i];
        }
    }
    return t;
}

void print_arr(int **&arr){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void master_function(int **&arr){
    cout<<"Original Matrix:\n";
    print_arr(arr);
    cout<<endl;
    total_sum(arr);
    int row=sum_row(arr);
    int col=sum_col(arr);
    cout<<"Row with highest sum: Row "<<row+1<<endl;
    cout<<"Column with highest sum: Column "<<col+1<<endl;
    cout<<endl;
    int **transposed_matrix=transpose(arr);
    cout<<"Transposed Matrix:\n";
    print_arr(transposed_matrix);
    delete []transposed_matrix;
}

int main(){
    int **arr= new int*[3];
    if (arr==NULL){
        cout<<"Memory allocation Failed:(";
        return -1;
    }
    for (int i=0; i<3; i++){
        arr[i]=new int[3];
        if (arr[i]==NULL){
            cout<<"Memory allocation Failed:(";
            return -1;
        }
        for (int j=0; j<3; j++){
            arr[i][j]=rand()%101;
            while (arr[i][j]<1) arr[i][j]=rand()%101;
        }
    }
    master_function(arr);
    delete []arr;
}