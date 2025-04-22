#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
using namespace std;

void create_random_file(string filename){
    ofstream file(filename);
    srand(time(0));
    int r;
    for (int i=1; i<=20; i++){
        file<<i<<":"<<rand()%100<<endl;
    }
    file.close();
}

void display(string filename){
    ifstream file(filename);
    string line;
    while (getline(file, line)){
        cout<<line<<endl;
    }
    file.close();
}

int main(){
    create_random_file("chapter1.txt");
    system("pause");
    create_random_file("chapter2.txt");
    ifstream file1("chapter1.txt");
    ifstream file2("chapter2.txt");
    ofstream file3("book.txt", ios::app);
    string line;
    while (!file1.eof()){
        file1>>line;
        if (!file1.eof()){
            file3<<line<<endl;
        }
    }
    while (!file2.eof()){
        file2>>line;
        if (!file2.eof()){
            file3<<line<<endl;
        }
    }
    file1.close();
    file2.close();
    file3.close();
    display("book.txt");
}
