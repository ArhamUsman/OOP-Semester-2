/*
You are building a car rental system. Create a class `Car` to manage cars available for rent.
Requirements:
1. Attributes:
- `carID` (int)
- `model` (string)
- `year` (int)
- `isRented` (bool)
2. Define a default constructor that initializes `isRented` to `false`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:

- `rentCar()`: Marks the car as rented.
- `returnCar()`: Marks the car as available.
- `isVintage()`: Returns `true` if the car's year is before 2000.

5. Create a few `Car` objects and test the methods.
*/

#include <iostream>
using namespace std;

class Car {
private:
    int carID;
    string model;
    int year;
    bool isRented;

public:
    Car() {
        isRented = false;
    }

    Car(int car_id, string Model, int Year) {
        carID = car_id;
        model = Model;
        year = Year;
        isRented = false;
    }

    void rentCar() {
        if (isRented) {
            cout << "Error! Car with ID " << carID << " is already rented.\n"; 
        }
        else {
            isRented = true;
            cout << "Success! Car with ID " << carID << " is now rented.\n"; 
        } 
    }

    void returnCar() {
        if (isRented) {
            isRented = false;
            cout << "Success! Car with ID " << carID << " is now returned.\n"; } 
        else {
            cout << "Error! Car with ID " << carID << " is already available.\n"; }
    }

    bool isVintage() const {
        if (year < 2000) {
            return true; }
        else {
            return false; } 
    }

};

int main() {
    Car car1(1010, "Bugatti Chiron", 2010);
    Car car2(1011, "Porsche 911", 1985);
    Car car3(1012, "Benz s 6200", 2018);
    car1.rentCar();
    car1.returnCar();
    car1.rentCar();
    car2.rentCar();
    car2.returnCar();
    if (car3.isVintage()) {
        cout << "The car 3 is vintage" << endl; 
    } 
    else {
        cout << "The car 3 is not vintage" << endl; 
    }
    if (car2.isVintage()) {
        cout << "The car 2 is vintage" << endl; 
    } 
    else {
        cout << "The car 2 is not vintage" << endl; 
    }
}