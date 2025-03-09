/*
Keeping in mind our previous car example, write a class that represents a car, and useaggregation and
composition to combine different components like engine, wheels, headlights and steering to create the
car object.

Hint: create the individual classes firstbeforeperforming the composition. Remember
thatfor aggregation, you will need pointers! You’ll be needing constructors and setters to
set these values in case of aggregation. Same hint applies to other questions.
*/
#include <iostream>
using namespace std;

class GraphicsRenderingEngine{
    string resolution;
    public:
    GraphicsRenderingEngine(string resolution=""){
        this->resolution=resolution;
        cout<<"Graphics Rendering Engine created\n";
    }
    ~GraphicsRenderingEngine(){
        cout<<"Graphics Rendering Engine destroyed\n";
    }
};

class InputHandler{
    string eventManager;
    public:
    InputHandler(string EventManager=""){
        eventManager=EventManager;
        cout<<"Input Handler created\n";
    }
    ~InputHandler(){
        cout<<"InputHandler destroyed\n";
    }
};

class PhysicsEngine{
    float gravity;
    public:
    PhysicsEngine(float Gravity=0){
        gravity=Gravity;
        cout<<"Physics Engine created\n";
    }
    ~PhysicsEngine(){
        cout<<"Physics Engine destroyed\n";
    }
};

class GameEngine{
    GraphicsRenderingEngine gre;
    PhysicsEngine pe;
    InputHandler ih;
    public:
    GameEngine(string resolution="", string eventManager="", float gravity=0){
        gre=GraphicsRenderingEngine(resolution);
        pe=PhysicsEngine(gravity);
        ih=InputHandler(eventManager);
        cout<<"Game Engine created\n";
    }
    ~GameEngine(){
        cout<<"Game Engine destroyed\n";
    }
};

int main(){
    GameEngine ge("1024x2048", "startGame", 9.812);
}