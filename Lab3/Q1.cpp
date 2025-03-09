/*
Create a class called time that has separate int member data for hours, minutes, and seconds. One constructor
should initialize this data to 0, and another should initialize it to fixed values. Another member function should
display it, in 11:59:59 format. The final member function should add two objects of type time passed as
arguments.
A main() program should create two initialized time objects (should they be const?) and one that isn’t initialized.
Then it should add the two initialized values together, leaving the result in the third time variable. Finally it should
display the value of this third variable. Make appropriate member functions const.
*/
#include <iostream>
using namespace std;

class Time{
    private:
        int hour, minute, second;
    public:
        Time(int h, int m, int s){
            hour=h;
            minute=m;
            second=s;
        }
        Time(){
            hour=0;
            minute=0;
            second=0;
        }

        int getHour() const {
            return hour;
        }

        int getMinute() const {
            return minute;
        }

        int getSecond() const {
            return second;
        }

        void setHour(int h){
            hour=h;
        }

        void setMinute(int m){
            minute=m;
        }

        void setSecond(int s){
            second=s;
        }

        void display() const{
            cout<<hour<<":"<<minute<<":"<<second<<endl;
        }

        Time add(const Time& t) const {
            Time t2;
            t2.second=t.getSecond() +second;
            if (t2.second>=60){
                t2.second-=60;
                t2.minute+=1;
            }
            t2.minute+=t.getMinute() +minute;
            if (t2.minute>=60){
                t2.minute-=60;
                t2.hour+=1;
            }
            t2.hour+=t.getHour() +hour;
            return t2;
        }
};

int main(){
    Time t1;
    Time t2(11,59,59);
    Time t3=t2.add(t1);
    cout << "t3: ";
    t3.display();
    t1.setHour(2);
    t1.setMinute(34);
    t1.setSecond(48);
    cout<<"Updated t3: ";
    t3=t2.add(t1);
    t3.display();
}