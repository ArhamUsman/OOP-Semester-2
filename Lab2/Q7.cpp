/*
You are tasked with building a simple product management system for an online store.
1. Create a function that allows the addition of a new product to the system. The function should
take parameters such as product name, price, quantity, and any other relevant details.
2. Implement a function that takes a product ID as input and displays detailed information about the
product, including its name, price, quantity in stock, and any other relevant details.
3. Design a function that enables the update of product information. It should take a product ID as
well as the new details (e.g., updated price, quantity, etc.) and modify the existing product&#39;s
information accordingly.
4. Create a function that removes a product from the system based on its product ID. Ensure that
the inventory is updated after the removal.
*/

#include <iostream>
using namespace std;

typedef struct{
    int id;
    string name;
    float price;
    int quantity;
}product;

void increase_size(product *&arr, int &size){
    product *updated= new product[++size];
    for (int i=0; i<size-1; i++){
        updated[i]=arr[i];
    }
    delete[] arr;
    arr=updated;
}

void add_product(product *&arr, int id, string name, float price, int quantity){
    arr[id].id=id;
    arr[id].name=name;
    arr[id].price=price;
    arr[id].quantity=quantity;
}

void display(product *&arr, int id){
    cout << "\n-----PRODUCT ID "<<arr[id].id<<"-----\n";
    cout<<"Name: "<<arr[id].name<<endl;
    cout<<"Price: "<<arr[id].price<<endl;
    cout<<"Quantity: "<<arr[id].quantity<<endl;
    cout<<endl;
} 

void update(product *&arr, int id, string name, float price, int quantity){
    arr[id].name=name;
    arr[id].price=price;
    arr[id].quantity=quantity;
}

void remove(product *&arr, int id, int &size){
    size--;
    for (int i=id; i<size; i++){
        arr[i].name=arr[i+1].name;
        arr[i].price=arr[i+1].price;
        arr[i].quantity=arr[i+1].quantity;
    }
    product *arr2=new product[size];
    for (int i=0; i<size; i++){
        arr2[i]=arr[i];
    }
    delete[] arr;
    arr=arr2;
}

void display_all(product *&arr, int size){
    for (int i=0; i<size; i++){
        if (arr[i].id!=-1){
            display(arr, i);
        }
    }
}

void menu(product *&arr, int &num){
    int choice;
    int id;
    string name;
    float price;
    int quantity;
    while (true){
        cout<<"\nMenu:\nPress 1 to add a product\nPress 2 to view a product\n";
        cout<<"Press 3 to update a product\nPress 4 to remove a product\n";
        cout<<"Press 5 to view all inventory\nPress any other key to exit";
        cout<<"\nEnter your choice: ";
        fflush(stdout);
        cin>>choice;
        switch (choice){
            case 1:
                increase_size(arr, num);
                cout<<"Product ID: "<<num-1<<endl;
                cout<<"Enter Name: ";
                fflush(stdout);
                cin>>name;
                cout<<"Enter price: ";
                fflush(stdout);
                cin>>price;
                cout<<"Enter quantity: ";
                fflush(stdout);
                cin>>quantity;
                add_product(arr, num-1, name, price, quantity);
                break;
            case 2:
                cout<<"Enter Product ID: ";
                fflush(stdout);
                cin>>id;
                if (id>=num||id<0){
                    cout<<"Invalid ID!\n";
                }
                else{
                    display(arr, id);
                }
                break;
            case 3:
                cout<<"Enter Product ID: ";
                fflush(stdout);
                cin>>id;
                if (id>=num||id<0){
                    cout<<"Invalid ID!\n";
                }
                else{
                    cout<<"Enter Name: ";
                    fflush(stdout);
                    cin>>name;
                    cout<<"Enter price: ";
                    fflush(stdout);
                    cin>>price;
                    cout<<"Enter quantity: ";
                    fflush(stdout);
                    cin>>quantity;
                    update(arr, id, name, price, quantity);
                }
                break;
            case 4:
                cout<<"Enter Product ID: ";
                fflush(stdout);
                cin>>id;
                if (id>=num||id<0){
                    cout<<"Invalid ID!\n";
                }
                else{
                    remove(arr, id, num);
                }
                break;
            case 5:
                display_all(arr, num);
                break;
            default:
                return;
        }
    }
}

int main(){
    product *online_store = new product[1];
    int number_of_products=0;
    cout<<"\n===PRODUCT MANAGEMENT SYSTEM===\n";
    menu(online_store, number_of_products);
    delete[] online_store;
}