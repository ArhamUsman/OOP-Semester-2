#include <iostream>
#include <exception>
#include <string>
using namespace std;

// Base exception
class FileException : public exception {
protected:
    string message;
public:
    FileException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// Derived: File not found
class FileNotFoundException : public FileException {
public:
    FileNotFoundException() : FileException("FileNotFoundException - File not found!") {}
};

// Derived: Permission denied
class PermissionDeniedException : public FileException {
public:
    PermissionDeniedException() : FileException("PermissionDeniedException - Access denied!") {}
};

// Simulated file reader
void readFile(const string& filename) {
    cout << "Reading '" << filename << "': ";
    if (filename == "missing.txt") {
        throw FileNotFoundException();
    } else if (filename == "secret.txt") {
        throw PermissionDeniedException();
    } else {
        cout << "File read successfully." << endl;
    }
}

int main() {
    try {
        readFile("secret.txt");
    } catch (const FileNotFoundException& e) {
        cout << e.what() << endl;
    } catch (const PermissionDeniedException& e) {
        cout << e.what() << endl;
    } catch (const FileException& e) {
        cout << "Other FileException: " << e.what() << endl;
    }

    return 0;
}
