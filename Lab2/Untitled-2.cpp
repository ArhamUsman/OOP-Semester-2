#include <iostream>
#include <string>
using namespace std;
int vowels(char *c){
    int v=0;
    for (int i=0; c[i]!='\0'; i++){
        if (c[i]=='A'||c[i]=='E'||c[i]=='I'||c[i]=='O'||c[i]=='U'||c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'){
            v++;
        }
    }
    return v;
}
int main(){
    char c[10]="Murtaza";
    cout<<vowels(c);
}