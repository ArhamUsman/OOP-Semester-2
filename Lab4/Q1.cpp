/*
TASK # 01
You are building a student management system. Create a class `Student` to manage student records.
Requirements:
1. Attributes:
- `studentID` (int)
- `name` (string)
- `age` (int)
- `grade` (char)
2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
- `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
- `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
- `displayDetails()`: Displays the student's details.
5. Create a few `Student` objects and test the methods.
*/

#include <iostream>
using namespace std;

class Student{
    int studentID;
    string name;
    int age;
    char grade;
    
    public:
    Student(int studentID=0, string name="", int age=0, char grade='N'){
        this->studentID=studentID;
        this->name=name;
        this->age=age;
        this->grade=grade;
    }

    void setID(int student_id){
        studentID=student_id;
    }
    void setName(string Name){
        name=Name;
    }
    void setAge(int Age){
        age=Age;
    }
    void setGrade(char Grade){
        grade=Grade;
    }
    int getID(){
        return studentID;
    }
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    char getGrade(){
        return grade;
    }

    void promoteStudent(){
        if (grade>'A' && grade<='D'){
            grade-=1;
        }
        else if (grade=='F'){
            grade='D';
        }
    }

    bool isEligibleForScholarship(){
        if (grade=='A') return true;
        return false;
    }

    void displayDetails(){
        cout<<"\n-----Displaying Student Details-----\n";
        cout<<"Student ID: "<<studentID;
        cout<<"\nName: "<<name;
        cout<<"\nAge: "<<age;
        cout<<"\nGrade: "<<grade;
        cout<<"\n----------\n";
    }
};

int main(){
    int n, temp_i;
    string temp_s;
    char temp_c;

    //Getting no of student
    cout<<"Enter number of students: ";
    cin>>n;

    //using default constructor
    Student* class_1=new Student[n];
    for (int i=0; i<n; i++){
        cout<<"Enter Details for Student "<<i+1<<endl;
        cout<<"Enter Student ID: ";
        cin>>temp_i;
        class_1[i].setID(temp_i);
        cout<<"Enter Name: ";
        cin.ignore();
        getline(cin,temp_s);
        class_1[i].setName(temp_s);
        cout<<"Enter Age: ";
        cin>>temp_i;
        class_1[i].setAge(temp_i);
        cout<<"Enter Grade: ";
        cin.ignore();
        cin>>temp_c;
        cin.ignore();
        class_1[i].setGrade(temp_c);

    }

    //using parameterised constructor
    Student new_student(1016, "Bilal", 30, 'B');

    new_student.promoteStudent();
    cout<<"\nIs "<<new_student.getName()<<" Eligible for scholarship: "<<new_student.isEligibleForScholarship();

    new_student.displayDetails();
    for (int i=0; i<n; i++){
        class_1[i].displayDetails();
    }

    delete[] class_1;
}

