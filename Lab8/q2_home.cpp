#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

// Base class Product
class Product {
protected:
    string productID;
    double price;

public:
    // Constructor
    Product(string productID, double price) : productID(productID), price(price) {}

    // Virtual function to calculate price (with tax)
    virtual double calculatePrice() const {
        return price;  // Base price
    }

    // Virtual function to apply discount
    virtual void applyDiscount(double discount) {
        price -= discount;  // Apply fixed discount
    }

    // Virtual function to get product ID (added to fix issue)
    string getProductID() const {
        return productID;
    }

    // Virtual destructor
    virtual ~Product() {}
};

// Derived class Electronics
class Electronics : public Product {
public:
    // Constructor
    Electronics(string productID, double price) : Product(productID, price) {}

    // Override calculatePrice to apply tax of 15%
    double calculatePrice() const override {
        return price * 1.15;  // 15% tax
    }

    // Apply percentage discount
    void applyDiscount(double discount) override {
        if (discount > 0 && discount <= 100) {
            price -= (price * discount / 100);  // Apply percentage discount
        }
        else {
            throw invalid_argument("Invalid percentage discount");
        }
    }

    // Destructor
    ~Electronics() {}
};

// Derived class Clothing
class Clothing : public Product {
public:
    // Constructor
    Clothing(string productID, double price) : Product(productID, price) {}

    // Override calculatePrice to apply tax of 5%
    double calculatePrice() const override {
        return price * 1.05;  // 5% tax
    }

    // Apply fixed discount
    void applyDiscount(double discount) override {
        if (discount >= 0) {
            price -= discount;  // Apply fixed discount
        } else {
            throw invalid_argument("Invalid fixed discount");
        }
    }

    // Destructor
    ~Clothing() {}
};

// ShoppingCart Class
class ShoppingCart {
private:
    vector<Product*> products;

public:
    // Add product to cart
    void addProduct(Product* product) {
        products.push_back(product);
    }

    // Calculate total price of the cart
    double calculateTotalPrice() const {
        double total = 0;
        for (auto product : products) {
            total += product->calculatePrice();
        }
        return total;
    }

    // Remove product from cart
    void removeProduct(const string& productID) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if ((*it)->getProductID() == productID) {
                products.erase(it);
                return;
            }
        }
        cout << "Product not found in the cart!" << endl;
    }

    // Operator overloading for + (merge two carts)
    ShoppingCart operator+(const ShoppingCart& other) {
        ShoppingCart mergedCart = *this;
        for (auto product : other.products) {
            mergedCart.addProduct(product);
        }
        return mergedCart;
    }

    // Operator overloading for - (remove product from cart by ID)
    ShoppingCart& operator-(const string& productID) {
        removeProduct(productID);
        return *this;
    }

    // Operator overloading for * (apply bulk discount)
    ShoppingCart& operator*(double discount) {
        for (auto product : products) {
            product->applyDiscount(discount);
        }
        return *this;
    }

    // Operator overloading for / (split cart total among users)
    double operator/(int users) {
        if (users <= 0) {
            cout << "Invalid number of users!" << endl;
            return 0;
        }
        return calculateTotalPrice() / users;
    }

    // Display cart contents
    void displayCart() const {
        cout << "Shopping Cart Contents:" << endl;
        for (auto product : products) {
            cout << "Product ID: " << product->getProductID() << ", Price: $" << product->calculatePrice() << endl;
        }
    }

    // Destructor
    ~ShoppingCart() {
        // No need to delete product objects because they are not dynamically allocated
        products.clear();
    }
};

int main() {
    // Create product objects
    Electronics laptop("E001", 1000.0);
    Electronics phone("E002", 500.0);
    Clothing tShirt("C001", 50.0);
    Clothing jeans("C002", 80.0);

    // Create shopping cart
    ShoppingCart cart1;
    cart1.addProduct(&laptop);
    cart1.addProduct(&phone);
    cart1.addProduct(&tShirt);

    // Create another shopping cart
    ShoppingCart cart2;
    cart2.addProduct(&jeans);

    // Display cart contents
    cart1.displayCart();
    cart2.displayCart();

    // Calculate total price for cart1
    cout << "Total price of cart1: $" << cart1.calculateTotalPrice() << endl;

    // Merge carts
    ShoppingCart mergedCart = cart1 + cart2;
    mergedCart.displayCart();
    cout << "Total price after merging: $" << mergedCart.calculateTotalPrice() << endl;

    // Apply bulk discount to cart1
    cart1 * 10; // 10% discount
    cart1.displayCart();
    cout << "Total price after bulk discount: $" << cart1.calculateTotalPrice() << endl;

    // Split cart total among 3 users
    double splitPrice = cart1 / 3;
    cout << "Each user pays: $" << splitPrice << endl;

    // Remove an item from cart
    cart1 - "E002"; // Remove phone from cart
    cart1.displayCart();
    cout << "Total price after removing item: $" << cart1.calculateTotalPrice() << endl;

    return 0;
}
