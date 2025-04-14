#include <iostream>
#include <string>
#include <map>
#include <iomanip> // For setting decimal precision
#include <stdexcept>

using namespace std;

// Base class for Currency
class Currency {
public:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; // exchange rate against a base currency

public:
    // Constructor for Currency class
    Currency(double amount = 0.0, string code = "", string symbol = "", double rate = 1.0)
        : amount(amount), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    // Convert the amount to a common base currency (e.g., USD)
    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    // Convert the amount from one currency to another
    double convertTo(Currency* targetCurrency) {
        double amountInBase = this->convertToBase(); // Convert current currency to base
        double targetExchangeRate = targetCurrency->exchangeRate;
        return amountInBase / targetExchangeRate;
    }

    // Display currency details (virtual for customization in derived classes)
    virtual void displayCurrency() {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ")\n";
        cout << "Amount: " << fixed << setprecision(2) << amount << "\n";
        cout << "Exchange Rate (to Base Currency): " << exchangeRate << "\n";
    }

    virtual ~Currency() {}
};

// Derived class for Dollar
class Dollar : public Currency {
public:
    // Constructor for Dollar class (USD as base currency)
    Dollar(double amount)
        : Currency(amount, "USD", "$", 1.0) {}

    // Override display function to format Dollar-specific details
    void displayCurrency() override {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ")\n";
        cout << "Amount: " << currencySymbol << fixed << setprecision(2) << amount << "\n";
        cout << "Exchange Rate (to Base Currency): " << exchangeRate << "\n";
    }
};

// Derived class for Euro
class Euro : public Currency {
public:
    // Constructor for Euro class
    Euro(double amount)
        : Currency(amount, "EUR", "€", 0.85) {}  // Assume 1 EUR = 0.85 USD

    // Override display function to format Euro-specific details
    void displayCurrency() override {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ")\n";
        cout << "Amount: " << currencySymbol << fixed << setprecision(2) << amount << "\n";
        cout << "Exchange Rate (to Base Currency): " << exchangeRate << "\n";
    }
};

// Derived class for Rupee
class Rupee : public Currency {
public:
    // Constructor for Rupee class
    Rupee(double amount)
        : Currency(amount, "INR", "₹", 75.0) {}  // Assume 1 INR = 75 USD

    // Override display function to format Rupee-specific details
    void displayCurrency() override {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ")\n";
        cout << "Amount: " << currencySymbol << fixed << setprecision(2) << amount << "\n";
        cout << "Exchange Rate (to Base Currency): " << exchangeRate << "\n";
    }
};

// Helper function to display conversion
void displayConversion(Currency* sourceCurrency, Currency* targetCurrency) {
    double convertedAmount = sourceCurrency->convertTo(targetCurrency);
    cout << "\nConverted Amount: " << fixed << setprecision(2) << convertedAmount << " " << targetCurrency->currencySymbol << endl;
}

int main() {
    // Create some currency objects
    Dollar usd(100);      // $100
    Euro eur(100);        // €100
    Rupee inr(1000);      // ₹1000

    // Display currency details
    cout << "Dollar Details:\n";
    usd.displayCurrency();
    cout << "\nEuro Details:\n";
    eur.displayCurrency();
    cout << "\nRupee Details:\n";
    inr.displayCurrency();

    // Perform conversions between currencies
    cout << "\nConversion from Dollar to Euro:\n";
    displayConversion(&usd, &eur);

    cout << "\nConversion from Euro to Rupee:\n";
    displayConversion(&eur, &inr);

    cout << "\nConversion from Rupee to Dollar:\n";
    displayConversion(&inr, &usd);

    return 0;
}
