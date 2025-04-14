#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int id;
    string address;
    string phoneNumber;
    string email;

public:
    // Constructor
    Person(string name, int id, string address, string phoneNumber, string email)
        : name(name), id(id), address(address), phoneNumber(phoneNumber), email(email) {}

    // Display personal information
    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    // Update personal information
    void updateInfo(string newAddress, string newPhoneNumber, string newEmail) {
        address = newAddress;
        phoneNumber = newPhoneNumber;
        email = newEmail;
    }

    virtual ~Person() {}

    // Getter for id (added)
    int getId() const {
        return id;
    }

    // Getter for name (added)
    string getName() const {
        return name;
    }
};

// Derived class Student
class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    // Constructor
    Student(string name, int id, string address, string phoneNumber, string email, double GPA, int enrollmentYear)
        : Person(name, id, address, phoneNumber, email), GPA(GPA), enrollmentYear(enrollmentYear) {}

    // Enroll student in a course
    void enrollInCourse(const string& courseName) {
        coursesEnrolled.push_back(courseName);
    }

    // Display student-specific info
    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Enrolled: ";
        for (const string& course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }

    ~Student() {}
};

// Derived class Professor
class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    // Constructor
    Professor(string name, int id, string address, string phoneNumber, string email, string department, double salary)
        : Person(name, id, address, phoneNumber, email), department(department), salary(salary) {}

    // Add course taught by professor
    void addCourseTaught(const string& courseName) {
        coursesTaught.push_back(courseName);
    }

    // Display professor-specific info
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: ";
        for (const string& course : coursesTaught) {
            cout << course << " ";
        }
        cout << endl;
        cout << "Salary: " << salary << endl;
    }

    ~Professor() {}
};

// Derived class Staff
class Staff : public Person {
private:
    string department;
    string position;
    double salary;

public:
    // Constructor
    Staff(string name, int id, string address, string phoneNumber, string email, string department, string position, double salary)
        : Person(name, id, address, phoneNumber, email), department(department), position(position), salary(salary) {}

    // Display staff-specific info
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }

    ~Staff() {}
};

// Course Class
class Course {
private:
    int courseId;
    string courseName;
    int credits;
    Professor* instructor;
    string schedule;  // Course schedule (e.g., "MWF 9:00-10:30 AM")
    vector<Student*> studentsRegistered;

public:
    // Constructor
    Course(int courseId, string courseName, int credits, Professor* instructor, string schedule)
        : courseId(courseId), courseName(courseName), credits(credits), instructor(instructor), schedule(schedule) {}

    // Register a student for the course
    void registerStudent(Student* student) {
        studentsRegistered.push_back(student);
    }

    // Calculate grades for students (simplified for now)
    void calculateGrades() {
        cout << "Grades for course: " << courseName << endl;
        for (Student* student : studentsRegistered) {
            cout << "Student ID: " << student->getId() << " - Grade: A" << endl; // Placeholder grade
        }
    }

    // Display course details
    void displayCourseInfo() {
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor->getName() << endl;
        cout << "Schedule: " << schedule << endl;
    }

    int getCourseId() const { return courseId; }
    string getCourseName() const { return courseName; }

    ~Course() {}
};

int main() {
    // Create some people
    Professor prof("Dr. Smith", 101, "123 University Ave", "555-1234", "smith@university.edu", "Computer Science", 85000);
    Student student("John Doe", 201, "456 College Rd", "555-5678", "john.doe@student.edu", 3.8, 2021);
    Staff staff("Jane Doe", 301, "789 Admin St", "555-9876", "jane.doe@university.edu", "Administration", "Registrar", 60000);

    // Create a course
    Course cs101(101, "Introduction to Computer Science", 3, &prof, "MWF 9:00-10:30 AM");

    // Register the student in the course
    cs101.registerStudent(&student);

    // Display information
    cout << "\n--- Professor Info ---\n";
    prof.displayInfo();
    cout << "\n--- Student Info ---\n";
    student.displayInfo();
    cout << "\n--- Staff Info ---\n";
    staff.displayInfo();

    // Display Course Info
    cout << "\n--- Course Info ---\n";
    cs101.displayCourseInfo();

    // Calculate grades
    cout << "\n--- Course Grades ---\n";
    cs101.calculateGrades();

    return 0;
}
