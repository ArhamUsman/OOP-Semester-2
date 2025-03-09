/*
Create a class called ValidateString. The purpose of this class will be check if the given characters in a
string are alphabet only. Numbers and symbols will mean that the string is invalid. By using a
parameterized constructor, create multiple objects for your class that accept different strings. Create a
constant function that checks whether the string variable is valid or not.
What happens if you do not make your function constant? Add a comment right above your function
explaining why we make a function constant.
*/

#include <iostream>
#include <string>
using namespace std;

class ValidateString{
    string sentence;

    public:
    //Constructor
    ValidateString(string sentence=""){
        this->sentence=sentence;
    }
    //Setter
    void setString(string String){
        sentence=String;
    }
    //Getter
    string getString(){
        return sentence;
    }
    //const make sure that the function don't change the original string
    const bool validate_string(){
        if (sentence==""){
            cout << "Set a string first"; return false;
        }
        for (int i=0; i<sentence.length(); i++){
            if ((sentence.at(i)>='a'&&sentence.at(i)<='z')||(sentence.at(i)>='A'&&sentence.at(i)<='Z')||(sentence.at(i)==' ')){}
            else{
                return false;
            }
        }
        return true;
    }
};

int main(){
    ValidateString *Strings=new ValidateString[3];
    Strings[0].setString("Hello World");
    Strings[1].setString("Hello 123");
    Strings[2].setString("Hello @!@");
    for (int i=0; i<3; i++){
        cout << "String "<< i+1<<": "<<Strings[i].getString()<<endl;
        if (Strings[i].validate_string()){
            cout<<"String is Valid.\n\n";
        }
        else{
            cout << "String is not Valid\n\n";
        }
    }
}