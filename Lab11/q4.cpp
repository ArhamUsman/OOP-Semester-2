#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

// Custom exception for negative numbers
class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "NegativeNumberException - Input must be non-negative!";
    }
};

// Custom exception for invalid types
class InvalidTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "InvalidTypeException - Non-numeric type detected!";
    }
};

// Primary template: non-numeric (will throw InvalidTypeException)
template <typename T>
double custom_sqrt(T) {
    throw InvalidTypeException();
}

// Specialization for int
template <>
double custom_sqrt<int>(int num) {
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(static_cast<double>(num));
}

// Specialization for double
template <>
double custom_sqrt<double>(double num) {
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(num);
}

// Specialization for float
template <>
double custom_sqrt<float>(float num) {
    if (num < 0)
        throw NegativeNumberException();
    return sqrt(static_cast<double>(num));
}

int main() {
    try {
        cout << "sqrt(-4): ";
        cout << custom_sqrt(-4) << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "sqrt(\"hello\"): ";
        cout << custom_sqrt("hello") << endl; // This now works: throws InvalidTypeException
    } catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
