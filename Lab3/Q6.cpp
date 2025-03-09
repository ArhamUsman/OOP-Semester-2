/*
Create a class called Smartphone with the following attributes:
- Company
- Model
- Display Resolution
- RAM
- ROM
- Storage

Create getter and setter methods for your attributes. A smartphone has some specific actions that it can perform.
For example:
1. Make a phone call
2. Send a message
3. Connect to the wifi
4. Browse the internet

Create different smartphone objects. Set their attributes using the setter functions and display their attributes after
using the getter functions to fetch the attributes.
*/

#include <iostream>
using namespace std;

class Smartphone{
    private: 
    string company, model, display;
    int ram, rom, storage;
    
    public:
    void setcompany(string c){
        company=c;
    }
    void setmodel(string m){
        model=m;
    }
    void setdisplay(string d){
        display=d;
    }
    void setram(int r){
        ram=r;
    }
    void setrom(int r){
        rom=r;
    }
    void setstorage(int s){
        storage=s;
    }
    string getcompany(){
        return company;
    }
    string getmodel(){
        return model;
    }
    string getdisplay(){
        return display;
    }
    int getram(){
        return ram;
    }
    int getrom(){
        return rom;
    }
    int getstorage(){
        return storage;
    }
    void call(){
        cout<<"Making a phone call\n";
    }
    void message(){
        cout<<"Sending a message\n";
    }
    void wifi(){
        cout<<"Connecting to wifi\n";
    }
    void browse(){
        cout<<"Browsing the internet\n";
    }
};

int main() {
    Smartphone phone1, phone2;

    phone1.setcompany("Apple");
    phone1.setmodel("iPhone 14 Pro");
    phone1.setdisplay("1179 x 2556 pixels");
    phone1.setram(6);
    phone1.setrom(128);
    phone1.setstorage(256);

    phone2.setcompany("Samsung");
    phone2.setmodel("Galaxy S23 Ultra");
    phone2.setdisplay("1440 x 3088 pixels");
    phone2.setram(12);
    phone2.setrom(256);
    phone2.setstorage(512);

    cout << "Smartphone 1 Details:\n";
    cout << "Company: " << phone1.getcompany() << endl;
    cout << "Model: " << phone1.getmodel() << endl;
    cout << "Display: " << phone1.getdisplay() << endl;
    cout << "RAM: " << phone1.getram() << "GB\n";
    cout << "ROM: " << phone1.getrom() << "GB\n";
    cout << "Storage: " << phone1.getstorage() << "GB\n";

    phone1.call();
    phone1.message();
    phone1.wifi();
    phone1.browse();

    cout << "\n-----------------------------\n";

    cout << "Smartphone 2 Details:\n";
    cout << "Company: " << phone2.getcompany() << endl;
    cout << "Model: " << phone2.getmodel() << endl;
    cout << "Display: " << phone2.getdisplay() << endl;
    cout << "RAM: " << phone2.getram() << "GB\n";
    cout << "ROM: " << phone2.getrom() << "GB\n";
    cout << "Storage: " << phone2.getstorage() << "GB\n";

    phone2.call();
    phone2.message();
    phone2.wifi();
    phone2.browse();
}