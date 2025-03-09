/*
Create a class for a stationary shop. The stationary shop maintains a list for all the items that it sells (hint: array of
strings), and another list with the prices of the items (hint: array of prices).
Create a menu-driven program to:
1. Allow the shop owner to add the items and their prices.
2. Fetch the list of items
3. Edit the prices of the items
4. View all the items and their prices
Create a receipt that the shopkeeper can share with their customers. The receipt can only be created after the
shopkeeper inputs the items and their amounts bought by the customer.
*/

#include <iostream>
using namespace std;

class StationaryShop{
    private:
    string *item;
    int *price;
    int count;
    public:
    StationaryShop(){
        count=0;
        item=nullptr;
        price=nullptr;
    }
    ~StationaryShop() {
        delete[] item;
        delete[] price;
    }
    void add(string it, int p){
        string *arr1=new string[count+1];
        int *arr2=new int[count+1];
        for (int i=0; i<count; i++){
            arr1[i]=item[i];
            arr2[i]=price[i];
        }
        arr1[count]=it;
        arr2[count]=p;
        count++;
        delete[] item;
        delete[] price;
        item=arr1;
        price=arr2;
    }
    string* fetchItem(){
        return item;
    }
    void editPrice(string name, int p){
        for (int i=0; i<count; i++){
            if (name==item[i]){
                price[i]=p;
                return;
            }
        }
        cout<<"Item not found\n";
    }
    void display(){
        if (count==0){
            cout<<"Inventory is empty\n";
            return;
        }
        cout<<"\nShop Items:\n";
        for (int i=0; i<count; i++){
            cout<<"Item: "<<item[i]<<" | Price: "<<price[i]<<endl; 
        }
    }
    int getIndex(string name){
        for (int i=0; i<count; i++){
            if (name==item[i]){
                return i;
            }
        }
        cout<<"Item not found\n";
        return -1;
    }
    void generate_reciept(){
        int* quantity=new int[count];
        for (int i=0; i<count; i++){
            quantity[i]=0;
        }
        string s;
        int index, q, total=0;
        while (1){
            cout<<"Enter item(exit to exit): ";
            cin>>s;
            if (s=="exit") break;
            index=getIndex(s);
            if (index>=0) {
                cout<<"Enter quantity: ";
                cin>>q;
                if (q>0) quantity[index]=q;
                else cout<<"Error\n";
            }
        }
        cout<<"\n------Reciept------\n";
        for (int i=0; i<count; i++){
            if (quantity[i]!=0){
                cout<<"Item: "<<item[i]<<" Quantity: "<<quantity[i]<<" Price (per piece): "<<price[i]<<endl;
                total+=quantity[i]*price[i];
            }
        }
        cout<<"\nTotal bill: "<<total<<endl;
        cout<<"-------------------\n";
        delete[] quantity;
    }
    int getCount(){
        return count;
    }
};

int main() {
    StationaryShop shop;
    int choice;

    do {
        cout << "\n--- Stationary Shop Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. Fetch List of Items\n";
        cout << "3. Edit Price\n";
        cout << "4. View All Items and Prices\n";
        cout << "5. Generate Receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string item;
                int price;
                cout << "Enter item name: ";
                cin >> item;
                cout << "Enter price: ";
                cin >> price;
                shop.add(item, price);
                break;
            }
            case 2: {
                string* items = shop.fetchItem();
                cout << "\nList of Items:\n";
                int count=shop.getCount();
                for (int i = 0; i < count; i++) {
                    cout << items[i] << endl;
                }
                break;
            }
            case 3: {
                string item;
                int newPrice;
                cout << "Enter item name to edit price: ";
                cin >> item;
                cout << "Enter new price: ";
                cin >> newPrice;
                shop.editPrice(item, newPrice);
                break;
            }
            case 4: {
                shop.display();
                break;
            }
            case 5: {
                shop.generate_reciept();
                break;
            }
            case 6: {
                cout << "Exiting program...\n";
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

}