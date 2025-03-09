/*
Keeping in mind our previous car example, write a class that represents a car, and useaggregation and
composition to combine different components like engine, wheels, headlights and steering to create the
car object.

Hint: create the individual classes firstbeforeperforming the composition. Remember
thatfor aggregation, you will need pointers! You�ll be needing constructors and setters to
set these values in case of aggregation. Same hint applies to other questions.
*/

#include <iostream>
using namespace std;

class Engine
{
    int size;
    int horsepower;

public:
    Engine(int Size = 0, int HP = 0)
    {
        size = Size;
        horsepower = HP;
    }

    void displayEngineInfo()
    {
        cout << "Engine Size: " << size << "L, Horsepower: " << horsepower << " HP" << endl;
    }
};

class Wheel
{
    string type;

public:
    Wheel(string Type = "Alloy")
    {
        type = Type;
    }

    void displayWheelInfo()
    {
        cout << "Wheel Type: " << type << endl;
    }
};

class Headlight
{
    string type;

public:
    Headlight(string Type = "LED")
    {
        type = Type;
    }

    void displayHeadlightInfo()
    {
        cout << "Headlight Type: " << type << endl;
    }
};

class Steering
{
    string type;

public:
    Steering(string Type = "Power")
    {
        type = Type;
    }

    void displaySteeringInfo()
    {
        cout << "Steering Type: " << type << endl;
    }
};

class Car
{
    Engine engine;       // Composition
    Headlight headlight; // Composition
    Steering steering;   // Composition
    Wheel *wheels[4];    // Aggregation
    string name;

public:
    Car()
    {
        engine = Engine();
        headlight = Headlight();
        steering = Steering();
        name = "Car";
        for (int i = 0; i < 4; i++)
        {
            wheels[i] = nullptr;
        }
    }

    Car(string Name, Wheel *Wheels[4], Engine engine, Headlight headlight, Steering steering) : name(Name), engine(engine), headlight(headlight), steering(steering)
    {
        for (int i = 0; i < 4; i++)
        {
            this->wheels[i] = Wheels[i];
        }
    }

    void displayCarInfo()
    {
        cout << "Car Name: " << name << endl;
        engine.displayEngineInfo();
        headlight.displayHeadlightInfo();
        steering.displaySteeringInfo();
        for (int i = 0; i < 4; i++)
        {
            if (wheels[i] != nullptr)
            {
                wheels[i]->displayWheelInfo();
            }
            else
            {
                cout << "Wheels not set!" << endl;
            }
        }
    }
};

int main()
{
    Wheel bbs_1("Alloy");
    Wheel bbs_2("Alloy");
    Wheel bbs_3("Alloy");
    Wheel bbs_4("Alloy");

    Wheel *carWheels[] = {&bbs_1, &bbs_2, &bbs_3, &bbs_4};

    string carName = "Toyota";
    Car car1(carName, carWheels, Engine(3, 200), Headlight("Neon"), Steering("Power"));

    car1.displayCarInfo();

    return 0;
}
