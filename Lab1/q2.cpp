/*
Q2: Design a C++ program to manage student marks. Allow the user to input
marks for students in three subjects (Mathematics, English, and Science). The
program should calculate the total marks, average marks, and display the grade
for each student. The user can specify the number of students and then input
the marks for each subject for each student. Finally, display the marks, total,
average, and grade for each student. Assume a grading system with the
following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void display_grade(float num){
    if (num>=90){
        cout << "A";
    }
    else if (num>=80){
        cout << "B";
    }
    else if (num>=70){
        cout << "C";
    }
    else if (num>=60){
        cout << "D";
    }
    else{
        cout << "E";
    }
    cout << endl;
}

int main(){
    int num;
    cout<<"Enter number of students: ";
    cin>>num;
    float subject[num][3], total[num];
    for (int j=0; j<num; j++){
        total[j]=0;
        cout << "\n-----Enter data for Student "<<j+1<<" -----\n";
        for (int i=0; i<3; i++){
            cout << "Enter marks of Subject " << i+1 <<": ";
            cin >> subject[j][i];
            total[j] += subject[j][i];
        }
    }

    for (int j=0; j<num; j++){
        cout << "\n-----Grade Sheet for Student "<<j+1<<" -----\n";
        for (int i=0; i<3; i++){
            cout << "Marks of Subject " << i+1 <<": "<< fixed << setprecision(1) << subject[j][i]<<endl;
        }
        cout << "Total Marks: " << fixed << setprecision(1) << total[j] << endl;
        cout << "Average Marks: " << fixed << setprecision(1) << total[j]/3 << endl;
        cout << "Grade: ";
        display_grade(total[j]/3);
    }
}