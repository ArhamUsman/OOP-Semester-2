/*
You are tasked with implementing a simple Student Registration System in C++. Define two structures,
Register and Student, where Register contains attributes courseId and courseName, and Student inherits
from Register while having additional attributes such as studentId, firstName, lastName, cellNo, and
email. Your goal is to create an array of Student structures to store information for five students. Write a
C++ program that accomplishes the following tasks:
- Implement the Register and Student structures.
- Inherit the Register structure in the Student structure.
- Create an array of Student structures to store information for 5 students.
- Take input for each student, including their courseId, courseName, studentId, firstName,
lastName, cellNo, and email.
- Display the information for all 5 students.
*/

#include <iostream>
using namespace std;

typedef struct{
    string courseID;
    string courseName;
}Register;

typedef struct{
    Register rgt;
    string studentId;
    string firstName;
    string LastName;
    string cellNo;
    string email;
}Student;

void input(Student &students){
    cout<<"Enter Course ID: ";
    fflush(stdout);
    cin>> students.rgt.courseID;
    cout<<"Enter Course Name: ";
    fflush(stdout);
    cin>> students.rgt.courseName;
    cout<<"Enter Student ID: ";
    fflush(stdout);
    cin>> students.studentId;
    cout<<"Enter First Name: ";
    fflush(stdout);
    cin>> students.firstName;
    cout<<"Enter Last Name: ";
    fflush(stdout);
    cin>> students.LastName;
    cout<<"Enter cell no: ";
    fflush(stdout);
    cin>> students.cellNo;
    cout<<"Enter email: ";
    fflush(stdout);
    cin>> students.email;
}

void display(Student &students){
    cout<<"Course ID: "<<students.rgt.courseID;
    cout<<"\nCourse Name: "<<students.rgt.courseName;
    cout<<"\nStudent ID: "<<students.studentId;
    cout<<"\nFirst Name: "<<students.firstName;
    cout<<"\nLast Name: "<<students.LastName;
    cout<<"\ncell no: "<<students.cellNo;
    cout<<"\nemail: "<<students.email<<endl;
}

int main(){
    int size=5;
    Student *students=new Student[size];
    for (int i=0; i<size; i++){
        cout<<"Student "<<i+1<<" :\n";
        input(students[i]);
    }
    cout<<"\nDisplaying all Details:\n";
    for (int i=0; i<size; i++){
        cout<<"Student "<<i+1<<" :\n";
        display(students[i]);
    }
}