#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Base class Media
class Media {
protected:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool isCheckedOut;

public:
    // Constructor
    Media(string title, string publicationDate, string uniqueID, string publisher)
        : title(title), publicationDate(publicationDate), uniqueID(uniqueID), publisher(publisher), isCheckedOut(false) {}

    // Virtual function to display media info
    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    // Check out the item
    virtual void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    // Return the item
    virtual void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }

    // Function overloading: Search media by title
    virtual bool searchByTitle(const string& searchTitle) {
        return title == searchTitle;
    }

    // Function overloading: Search media by publisher
    virtual bool searchByPublisher(const string& searchPublisher) {
        return publisher == searchPublisher;
    }

    // Virtual destructor
    virtual ~Media() {}
};

// Derived class Book
class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;

public:
    // Constructor
    Book(string title, string publicationDate, string uniqueID, string publisher, string author, string ISBN, int numberOfPages)
        : Media(title, publicationDate, uniqueID, publisher), author(author), ISBN(ISBN), numberOfPages(numberOfPages) {}

    // Override displayInfo for books
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }

    // Function overloading: Search media by author
    bool searchByAuthor(const string& searchAuthor) {
        return author == searchAuthor;
    }

    // Destructor
    ~Book() {}
};

// Derived class DVD
class DVD : public Media {
private:
    string director;
    int duration; // in minutes
    string rating;

public:
    // Constructor
    DVD(string title, string publicationDate, string uniqueID, string publisher, string director, int duration, string rating)
        : Media(title, publicationDate, uniqueID, publisher), director(director), duration(duration), rating(rating) {}

    // Override displayInfo for DVDs
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }

    // Function overloading: Search media by director
    bool searchByDirector(const string& searchDirector) {
        return director == searchDirector;
    }

    // Destructor
    ~DVD() {}
};

// Derived class CD
class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    // Constructor
    CD(string title, string publicationDate, string uniqueID, string publisher, string artist, int numberOfTracks, string genre)
        : Media(title, publicationDate, uniqueID, publisher), artist(artist), numberOfTracks(numberOfTracks), genre(genre) {}

    // Override displayInfo for CDs
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }

    // Function overloading: Search media by artist
    bool searchByArtist(const string& searchArtist) {
        return artist == searchArtist;
    }

    // Destructor
    ~CD() {}
};

// Derived class Magazine
class Magazine : public Media {
private:
    string issueNumber;
    string editor;

public:
    // Constructor
    Magazine(string title, string publicationDate, string uniqueID, string publisher, string issueNumber, string editor)
        : Media(title, publicationDate, uniqueID, publisher), issueNumber(issueNumber), editor(editor) {}

    // Override displayInfo for magazines
    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Editor: " << editor << endl;
    }

    // Function overloading: Search media by issue number
    bool searchByIssueNumber(const string& searchIssueNumber) {
        return issueNumber == searchIssueNumber;
    }

    // Destructor
    ~Magazine() {}
};

// Function to search and display media items by title
void searchByTitle(vector<Media*>& mediaCollection, const string& title) {
    for (auto media : mediaCollection) {
        if (media->searchByTitle(title)) {
            media->displayInfo();
        }
    }
}

// Function to search and display media items by publisher
void searchByPublisher(vector<Media*>& mediaCollection, const string& publisher) {
    for (auto media : mediaCollection) {
        if (media->searchByPublisher(publisher)) {
            media->displayInfo();
        }
    }
}

int main() {
    // Dynamically create media items
    Book* book1 = new Book("The Great Gatsby", "1925-04-10", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD* dvd1 = new DVD("Inception", "2010-07-16", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD* cd1 = new CD("Abbey Road", "1969-09-26", "C001", "Apple Records", "The Beatles", 17, "Rock");
    Magazine* mag1 = new Magazine("National Geographic", "2023-03-01", "M001", "National Geographic Society", "0323", "Susan Goldberg");

    // Store all media in a collection
    vector<Media*> mediaCollection;
    mediaCollection.push_back(book1);
    mediaCollection.push_back(dvd1);
    mediaCollection.push_back(cd1);
    mediaCollection.push_back(mag1);

    // Display all media
    cout << "Displaying all media:\n";
    for (auto media : mediaCollection) {
        media->displayInfo();
        cout << endl;
    }

    // Search by title
    cout << "Search for media by title 'Inception':\n";
    searchByTitle(mediaCollection, "Inception");

    // Search by publisher
    cout << "Search for media by publisher 'Apple Records':\n";
    searchByPublisher(mediaCollection, "Apple Records");

    // Check out and return media
    cout << "\nChecking out and returning media:\n";
    dvd1->checkOut();
    dvd1->returnItem();
    dvd1->returnItem();  // Trying to return it again

    // Delete dynamically allocated media items
    delete book1;
    delete dvd1;
    delete cd1;
    delete mag1;

    return 0;
}
