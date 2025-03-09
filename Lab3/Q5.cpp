/*
Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that
stores information about the current year. The user is allowed to store their tasks to do against each day. Assume
only one entry is needed per day.
Create the following methods for your class:
- Add a task. Thisfunction accepts three parameters: task details, date and month. It should add
- a task on the day specified.
- Remove a task. Accepts the date and month as a parameter to remove the task from.
- Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how
you’ll remove a task, and display the updated task list.
*/

#include <iostream>
using namespace std;

class calender{
    private:
    string **cal=new string* [12];
    void check(int &m, int &d){
        while (m<=0 || m>12){
            cout<<"Enter a valid month number(1-12): ";
            cin>>m;
        }
        int max_days;
        if (m == 2)
            max_days = 28;
        else if (m == 4 || m == 6 || m == 9 || m == 11) 
            max_days = 30;
        else
            max_days = 31;
        while (d <= 0 || d > max_days) {
            cout << "Enter a valid day number: ";
            cin >> d;
        }
    }
    public:
    calender(){
        for (int i=0; i<12; i++){
            cal[i]=new string[31];
            for (int j=0; j<31; j++){
                cal[i][j]=" ";
            }
        }
    }
    void addTask(string t, int d, int m){
        check(m, d);
        cal[m-1][d-1]=t;
    }
    void removeTask(int d, int m){
        check(m, d);
        cal[m-1][d-1]=" ";
    }
    void showTasks(){
        for (int i=0; i<12; i++){
            for (int j=0; j<31; j++){
                if (cal[i][j]!=" "){
                    cout<<"Day: "<<j<<" Month: "<<i+1<<" Task: "<<cal[i][j]<<endl; 
                }
            }
        }
    }
};

int main(){
    calender c;
    c.addTask("Do Task 1", 1, 1);
    c.addTask("Do Task 2", 2, 2);
    c.addTask("Do Task 3", 3, 3);
    c.addTask("Do Task 4", 4, 4);
    c.addTask("Do Task 5", 5, 5);
    c.addTask("Do Task 6", 6, 6);
    cout<<"Before Removing:\n";
    c.showTasks();
    c.removeTask(3,3);
    cout<<"After Removing:\n";
    c.showTasks();
}