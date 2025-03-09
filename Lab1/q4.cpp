/*
You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49.
*/

#include <iostream>
using namespace std;

int lower(int a, int b){
    if (a<b) return a;
    return b;
}

int max_area(int arr[], int n){
    int max, max_max=0, vol, i, j;
    for (i=0; i<n; i++){
        max=0;
        for (j=i+1; j<n; j++){
            vol=(j-i)*lower(arr[i], arr[j]);
            if (vol>max) max=vol;
        }
        if (max>max_max) max_max=max;
    }
    return max_max;
}

int main(){
    int num, i, j, target;
    cout << "Enter size of array: ";
    cin >> num;
    int height[num];
    for (i=0; i<num; i++){
        cout << "Enter height " << i+1 << ": ";
        cin >> height[i];
    }
    cout << "Maximum area of water is " << max_area(height, num);
}