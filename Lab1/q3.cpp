/*
Q3: Given an array of integers nums and an integer target, return indices of the
two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may
not use the same element twice.You can return the answer in any order.
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include <iostream>
using namespace std;

int main(){
    int num, i, j, target;
    cout << "Enter size of array: ";
    cin >> num;
    int num_arr[num];
    for (i=0; i<num; i++){
        cout << "Enter array element " << i+1 << ": ";
        cin >> num_arr[i];
    }
    cout << "\nEnter Target: ";
    cin >> target;
    for (i=0; i<num; i++){
        for (j=i+1; j<num; j++){
            if (num_arr[i]+num_arr[j]==target){
                cout << "\nOutput: [" << i << "," << j << "]";
                return 0;
            }
        }
    }
    cout << "Error!";
}