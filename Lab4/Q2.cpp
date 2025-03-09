/*
A library system allows users to borrow and return books. The system should:
1. Add new books to the collection.
2. Borrow books (check availability).
3. Return books.
4. Display all available books.
Requirements:
- Implement a Book class with attributes: ID, title, author, availability.
- Implement a Library class with:
1. Method to add a book (with unique ID).
2. Method to borrow a book (updates availability).
3. Method to return a book (marks it available).
4. Method to display all available books.
- Store book records dynamically using pointers and DMA.
- Use constructor overloading to initialize books with or without availability status.
*/

#include <iostream>
using namespace std;

class Book{
    string ID, title, author, availability;
    public:
    Book(){
        this->author="";
        this->availability="";
        this->ID="";
        this->title="";
    }
    Book(string id, string Title, string Author, string Availability){
        this->author=Author;
        this->availability=Availability;
        this->ID=id;
        this->title=Title;
    }
    string get_ID(){
        return ID;
    }
    string get_title(){
        return title;
    }
    string get_author(){
        return author;
    }
    string get_availability(){
        return availability;
    }
    void set_ID(string ID){
        this->ID = ID;
    }
    void set_title(string title){
        this->title = title;
    }
    void set_author(string author){
        this->author = author;
    }
    void set_availability(string availability){
        this->availability = availability;
    }
    void displayDetails(){
        cout<<"Id: "<<ID;
        cout<<"\nTitle: "<<title;
        cout<<"\nAuthor: "<<author<<endl;
    }
};

class Library{
    Book *books;
    int noOfBooks;
    public:
        Library(Book* Books=nullptr, int NoOfBooks=0){
            noOfBooks=NoOfBooks;
            if (noOfBooks==0) books=nullptr;
            else{
                books=new Book[noOfBooks];
                for (int i=0; i<noOfBooks; i++){
                    books[i]=Books[i];
                }
            }
        }
        
        ~Library(){
            delete[] books;
        }
        
        void AddBook(Book book){
            Book *new_stock=new Book[++noOfBooks];
            int i, found=0;
            for (i=0; i<noOfBooks-1; i++){
                if (books[i].get_ID()==book.get_ID()){
                    found=1; break;
                }
                new_stock[i]=books[i];
            }
            if (found==0){
                new_stock[i]=book;
                delete[] books;
                books=new_stock;
                cout<<"\n-----Book added successfully-----\n";
            }
            else{
                delete[] new_stock;
                noOfBooks--;
                cout<<"\n-----Error! Book must have a unique ID-----\n";
            }
        }

        void BorrowBook(string id){
            for (int i=0; i<noOfBooks; i++){
                if (id==books[i].get_ID()){
                    if (books[i].get_availability()=="y"){
                        books[i].set_availability("n");
                        cout<<"\n-----Book issued successfully-----\n";
                    }
                    else{
                        cout<<"\n-----Book is not available-----\n";
                    }
                    return;
                }
            }
            cout<<"\n-----Book is not found-----\n";
        }
        
        void ReturnBook(string id){
            for (int i=0; i<noOfBooks; i++){
                if (id==books[i].get_ID()){
                    books[i].set_availability("y");
                    cout<<"\n-----Book returned sucessfully-----\n";
                    return;
                }
            }
            cout<<"\n-----Book is not found-----\n";
        }
        
        void DisplayAll(){
            cout<<"\n-----Displaying all books-----\n";
            for (int i=0; i<noOfBooks; i++){
                if (books[i].get_availability()=="y"){
                    cout<<"Book "<<i+1<<endl;
                    books[i].displayDetails();
                    cout<<endl;
                }
            }
            cout<<"----------\n";
        }
};

int main(){
    string choice, id, title, author;
    Library lib1;
    Book b1;
    while (1){
        cout<<"\n=====Main Menu=====\n";
        cout<<"Press 1 to add a new book\nPress 2 to borrow a book\nPress 3 to return a book\nPress 4 to display all available books\nPress any other key to exit :)\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        if (choice=="1"){
            cout<<"\n----------\n";
            cout<<"Enter id: ";
            cin>>id;
            cout<<"Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout<<"Enter author: ";
            getline(cin, author);
            lib1.AddBook(Book(id, title, author, "y"));
        }
        else if (choice=="2"){
            cout<<"\n----------\n";
            cout<<"Enter id: ";
            cin>>id;
            lib1.BorrowBook(id);
        }
        else if (choice=="3"){
            cout<<"\n----------\n";
            cout<<"Enter id: ";
            cin>>id;
            lib1.ReturnBook(id);
        }
        else if (choice=="4"){
            lib1.DisplayAll();
        }
        else{
            cout<<"\n=====Thank You for using our service=====";
            break;
        }
    }
}