#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class resume{
    string name, email, summary;
    int yearsOfExperience;
    void write_a_resume(ofstream& file){
        cout<<"\nEnter your name: ";
        cin>>name;
        cout<<"Enter your email: ";
        cin>>email;
        cout<<"Enter your yearsOfExperience: ";
        cin>>yearsOfExperience;
        cout<<"Enter your summary: ";
        cin>>summary;
        file<<name<<endl;
        file<<email <<endl;
        file<<yearsOfExperience <<endl;        
        file<< summary<<endl;
        file.flush();
    }
public:
    void create_a_new_resume(string filename){
        ofstream file(filename);
        write_a_resume(file);
        file.close();
    }
    void update_a_resume(string filename){
        ofstream file(filename, ios::trunc);
        write_a_resume(file);
        file.close();
    }
    void read_resume(string filename){
        ifstream file(filename);
        string line;
        file>>line;
        name=line;
        cout<<"Name: "<<line<<endl;
        file>>line;
        email=line;
        cout<<"Email: "<<line<<endl;
        file>>line;
        stringstream(line)>>yearsOfExperience;
        cout<<"Years Of Experience: "<<line<<endl;
        file>>line;
        summary=line;
        cout<<"Summary: "<<line<<endl;
        file.close();
    }
};

int main(){
    resume r;
    r.create_a_new_resume("resume.txt");
    cout<<"\nOld resume:\n";
    r.read_resume("resume.txt");   
    r.update_a_resume("resume.txt");
    cout<<"\nUpdated resume:\n";
    r.read_resume("resume.txt");
}
