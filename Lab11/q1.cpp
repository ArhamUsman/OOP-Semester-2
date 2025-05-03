#include <iostream>
using namespace std;

class custom_exception: public exception{
    public:
    const char* what() const noexcept override{
        return "Error: InvalidValueException - Age cannot be negative or exceed 120.";
    }  
};

int main(){
    try{
        int age;
        cout<<"Enter age: ";
        cin>>age;
        if (age<0||age>120) throw custom_exception();
    }
    catch (custom_exception &e){
        cout<<e.what()<<endl;
    }
}