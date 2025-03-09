/*
You are building an employee management system. Create a class `Employee` to manage employee
records.
Requirements:
1. Attributes:
- `employeeID` (int)
- `name` (string)
- `department` (string)
- `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
- `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
- `isManager()`: Returns `true` if the employee's department is "Management".
- `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods.
*/

#include <iostream>
using namespace std;

class Employee{
    int employeeID;
    string name, department;
    double salary;
    public:
    Employee(int Employee_ID=0, string Name="", string Department="", double Salary=0.0){
        employeeID=Employee_ID;
        name=Name;
        department=Department;
        salary=Salary;
    }
    void giveBonus(double amount){
        salary+=amount;
        cout<<"Bonus is successfully given.\n";
    }
    bool isManager(){
        if (department=="Management") return true;
        return false;
    }
    void displayDetails(){
        cout<<"Employee Id: "<<employeeID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Deparment: "<<department<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};

int main(){
    Employee *e=new Employee[5];
    e[0]=Employee(1010, "Ali", "Cleaning", 10000);
    e[1]=Employee(1011, "Ahmed", "Management", 100000);
    e[2]=Employee(1012, "Bilal", "Management", 100000);
    e[3]=Employee(1013, "Charlie", "Teaching", 50000);
    e[4]=Employee(1014, "Darwin", "Teaching", 50000);
    cout<<"Giving Bonus to Employee 1: \n";
    e[0].giveBonus(3000);
    cout<<"\nChecking if Employee 3 is a Manager:\n";
    if (e[2].isManager()) cout<<"Manager\n";
    else cout<<"Not Manager\n";
    cout<<"\nDisplaying Details:\n";
    for (int i=0; i<5; i++){
        cout<<"Employee "<<i+1<<" : \n";
        e[i].displayDetails();
        cout<<endl;
    }
    delete[] e;
}
