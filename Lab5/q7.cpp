/*
Implement a restaurant ordering system that holds information about the restaurant’s menus, menu
items, orders, and payments. Identify the relationship between the five entities mentioned. Keep in
mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functions to add and
remove items, or display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. Theorder class
consists of one or more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay.This is
generated when the order is placed.
*/

#include <iostream>
#include <string>

using namespace std;

class MenuItem {
    string name;
    int price;
public:
    MenuItem(string name = "", int price = 0) {
        this->name = name;
        this->price = price;
    }

    string get_name() const {
        return name;
    }

    int get_price() const {
        return price;
    }

    void update_price(int price) {
        this->price = price;
    }
};

class Menu {
    MenuItem* items;
    int noOfitems;
    int maxitems;
public:
    Menu() {
        items = new MenuItem[50];
        maxitems = 50;
        noOfitems = 0;
    }
    ~Menu() {
        delete[] items;
    }
    MenuItem get_item(int index) const {
        if (index < 1 || index > noOfitems) {
            return MenuItem();
        }
        return items[index - 1];
    }
    void addItem(const MenuItem& item) {
        if (noOfitems == maxitems) {
            maxitems *= 2;
            MenuItem* temp = new MenuItem[maxitems];
            for (int i = 0; i < noOfitems; i++) {
                temp[i] = items[i];
            }
            delete[] items;
            items = temp;
        }
        items[noOfitems] = item;
        noOfitems++;
    }
    void removeItem(const string& name) {
        bool found = false;
        for (int i = 0; i < noOfitems; i++) {
            if (items[i].get_name() == name) {
                found = true;
            }
            if (found && i < noOfitems - 1) {
                items[i] = items[i + 1];
            }
        }
        if (found) {
            noOfitems--;
            cout << "Item removed successfully\n";
        } else {
            cout << "Error! Item not found\n";
        }
    }
    void displayMenu() const {
        cout << "\nDisplaying Menu:\n";
        for (int i = 0; i < noOfitems; i++) {
            cout << "Item " << i + 1 << ": Name: " << items[i].get_name() << "  || Price: " << items[i].get_price() << endl;
        }
        cout << "----------\n";
    }
    int get_noOfitems() const {
        return noOfitems;
    }
};

class Payment {
    mutable int bill;  // Declare bill as mutable so it can be modified in const functions
public:
    Payment() : bill(0) {}

    int generate_bill(MenuItem* items, int noOfitems) const {
        bill = 0;  // Now this is allowed because bill is mutable
        cout << "\n\n=====Bill=====\n";
        for (int i = 0; i < noOfitems; i++) {
            cout << "Item " << i + 1 << ": Name: " << items[i].get_name() << "  || Price: " << items[i].get_price() << endl;
            bill += items[i].get_price();
        }
        cout << "\nTotal Amount Payable: " << bill << endl;
        cout << "==========\n";
        return bill;
    }
};

class Order {
    Menu* menu;
    MenuItem* items;
    int noOfitems;
    Payment p;

    void addItem(const MenuItem& item) {
        MenuItem* temp = new MenuItem[noOfitems + 1];
        for (int i = 0; i < noOfitems; i++) {
            temp[i] = items[i];
        }
        temp[noOfitems++] = item;
        delete[] items;
        items = temp;
    }

    void placeOrder() const {
        p.generate_bill(items, noOfitems);
    }

public:
    Order() {
        items = nullptr;
        noOfitems = 0;
    }

    ~Order() {
        delete[] items;
    }

    void OrderFood() {
        int itemIndex;
        menu->displayMenu();
        cout << "Enter the item number to order (or 0 to finish): ";
        while (true) {
            cin >> itemIndex;
            if (itemIndex == 0) break;
            if (itemIndex > 0 && itemIndex <= menu->get_noOfitems()) {
                addItem(menu->get_item(itemIndex));
                cout << "Item added to order.\n";
            } 
            else {
                cout << "Invalid item number.\n";
            }
            cout << "Enter another item number or 0 to finish: ";
        }
        placeOrder();
    }

    void setMenu(Menu* menu) {
        this->menu = menu;
    }
};

class Restaurant {
    Menu menu;
    Order order;

public:
    void addMenuItem(const MenuItem& item) {
        menu.addItem(item);
    }

    void removeMenuItem(const string& name) {
        menu.removeItem(name);
    }

    void displayMenu() {
        menu.displayMenu();
    }

    void OrderFood() {
        order.setMenu(&menu);
        order.OrderFood();
    }
};

int main() {
    Restaurant restaurant;
    restaurant.addMenuItem(MenuItem("Pizza", 2500));
    restaurant.addMenuItem(MenuItem("Burger", 1500));
    restaurant.addMenuItem(MenuItem("Pasta", 800));
    restaurant.OrderFood();
}
