#include <iostream>
using namespace std;

class StackOverflowException: public exception{
    public:
    const char* what() const noexcept override{
        return "StackOverflowException - Stack is full!";
    }
};


class StackUnderflowException: public exception{
    public:
    const char* what() const noexcept override{
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack{
    T *stack = new T[10];
    int top=0;
    public:
    Stack(T *arr, int top){
        if (top>10) top=10;
        for (int i=0; i<top; i++){
            stack[i]=arr[i];
        }
        this->top=top;
    }
    ~Stack(){
        delete stack;
    }
    bool push(T t){
        try{
            if (top>=10){
                throw(StackOverflowException());
            }
            stack[top++]=t;
            cout<<t<<" pushed successfully\n";
            return true;
        }
        catch (StackOverflowException &e){
            cout<<e.what()<<endl;
            return false;
        }
    }
    void pop(){
        try{
            T t;
            if (top<=10){
                throw(StackUnderflowException());
            }
            t=stack[--top];
            cout<<t<<" popped successfully\n";
        }
        catch (StackUnderflowException &e){
            cout<<e.what()<<endl;
        }
    }
};

int main(){
    int* full=new int[10];
    for (int i=0; i<10; i++) full[i]=10;
    float* empty= new float[10];
    Stack s_full(full, 10);
    Stack s_empty(empty, 0);
    cout<<"Pushing to a full stack: ";
    s_full.push(15);
    cout<<"Popping from an empty stack: ";
    s_empty.pop();
}