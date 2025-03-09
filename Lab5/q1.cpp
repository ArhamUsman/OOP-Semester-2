/*
Task-01:
Create a class called Square with the following attributes:
• sideLength – float variable
• area – float variable
• allareas – static float variable
Create the following methods for your class:
• Constructors (default and parameterized (only takes sideLength as input))
• Function to calculate area, the calculated area should always be added to the allareas
variable each time an area is calculated. (assume it’s called only once for each object)
• Getters and Setters for all variables
In your main functions create 3 Squares with different sideLength. Call the area method for each of
those Square objects. After each time the area method is called, call that square’s getters for area and
allareas to display the updated values.
*/

#include <iostream>
#include <random>
using namespace std;

class Square{
    float sideLength, area;
    static float allAreas;

    public:
    //constructor
    Square(float sideLength=0){
        this->sideLength=sideLength;
        area=0;
        if (sideLength!=0){
            calculateArea();
        }
    }
    //destructor
    ~Square(){
        allAreas-=area;
    }
    //Setter
    void setSideLength(float Length){
        sideLength=Length;
        if (area==0){
            calculateArea();
        }
        else{
            allAreas-=area;
            area=0;
            calculateArea();
        }
    }
    void setArea(){
        calculateArea();
    }
    //Getter
    float getSideLength(){
        return sideLength;
    }
    float getArea(){
        return area;
    }
    float getAllAreas(){
        return allAreas;
    }
    //Method
    void calculateArea(){
        if (area==0){ //check if area is being calculated for the first time
            area = sideLength*sideLength;
            allAreas+=area;
        }
    }
};

float Square::allAreas=0;

int main(){
    Square squares[3];
    for (int i=0; i<3; i++){
        squares[i].setSideLength(rand()%10);
        squares[i].calculateArea();
        cout<<"Printing info for square"<<i+1<<endl;
        cout<<"Length: "<<squares[i].getSideLength()<<endl;
        cout<<"Area: "<<squares[i].getArea()<<endl;
        cout<<"Total Area: "<<squares[i].getAllAreas()<<endl;
        cout<<"----------\n";
    }
}