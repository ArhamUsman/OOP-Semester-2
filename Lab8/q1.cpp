#include <iostream>
#include <string>
using namespace std;

class Device{

    protected:
    string DeviceID,DeviceType,DeviceName;
    double PowerRating;
    bool Status;

    public:
    //Device():DeviceID("Default"),PowerRating(0.0),Status(false){}

    virtual void turnOn(){
        Status=true;
    }

    virtual void turnOff(){
        Status=false;
    }

    virtual double calculatePowerUsage(int hours){
        return PowerRating*hours;
    }
};

class Light: public Device{

    public:
    Light(string id, string name, double power) {
        DeviceType="Light";
        DeviceID=id;
        DeviceName=name;
        PowerRating=power;
    }

    void turnOn()override{
        Status=true;
    }

    void turnOff()override{
        Status=false;
    }

    double calculatePowerUsage(int hours)override{
        
        return PowerRating*hours;
    }
};

class Fan: public Device{

    double SpeedFactor;
    public:
    Fan(string id, string name, double power, double sf) {
        DeviceType="Fan";
        DeviceID=id;
        DeviceName=name;
        PowerRating=power;
        SpeedFactor=sf;
    }

    void turnOn()override{
        Status=true;
    }

    void turnOff()override{
        Status=false;
    }

    double calculatePowerUsage(int hours)override{
        
        return PowerRating*hours*SpeedFactor;
    }
};

class AC: public Device{

    double DesiredTemp,CurrentTemp;
    public:
    AC(string id, string name, double power,double dt,double ct) {
        DeviceType="Fan";
        DeviceID=id;
        DeviceName=name;
        PowerRating=power;
        DesiredTemp=dt;
        CurrentTemp=ct;
    }

    void turnOn()override{
        Status=true;
    }

    void turnOff()override{
        Status=false;
    }

    double calculatePowerUsage(int hours)override{
        
        return PowerRating*hours*(1-(CurrentTemp-DesiredTemp)/100);
    }


};
