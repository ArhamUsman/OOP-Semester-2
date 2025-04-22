#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

typedef struct{
    int id;
    string name;
    float gpa;
}Student;

int main(){
    Student students[5];
    for (int i=0; i<5; i++){
        cout<<"Enter student name: ";
        cin>>students[i].name;
        cout<<"Enter student id (in int): ";
        cin>>students[i].id;
        cout<<"Enter student gpa (in float): ";
        cin>>students[i].gpa;
    }
    ofstream file("students.txt", ios::out);
    for (int i=0; i<5; i++){
        file<<students[i].name<<endl;
        file<<students[i].id<<endl;
        file<<students[i].gpa<<endl;
    }
    file.close();
    Student extra;
    cout<<"Enter student name: ";
    cin>>extra.name;
    cout<<"Enter student id (in int): ";
    cin>>extra.id;
    cout<<"Enter student gpa (in float): ";
    cin>>extra.gpa;
    ofstream file2("students.txt", ios::app);
    if (file2.is_open()&&!(file2.bad())){
        file2<<extra.name<<endl;
        file2<<extra.id<<endl;
        file2<<extra.gpa<<endl;
    }
    else{
        cout<<"Error!\n";
    }
    file2.close();
    ifstream file3("students.txt");
    vector <Student> read_data;
    string line;
    Student temp;
    if (file3.is_open()&&!(file3.bad())){
        while (!(file3.eof())){
            // file3>>temp.name;
            file3>>line;
            // stringstream(line)>>temp.id;
            // file3>>line;
            // stringstream(line)>>temp.gpa;
            // read_data.push_back(temp);
            if (!file3.eof()){
                cout<<"Name: "<<line<<endl;
                file3>>line;
                cout<<"ID: "<<line<<endl;
                file3>>line;
                cout<<"GPA: "<<line<<endl;
            }
        }
    }
    file3.close();
}
