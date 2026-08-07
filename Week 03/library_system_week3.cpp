// Library Management System - Week 3 Skeleton
// C++ Mini Project

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


// ---- Book Class ----
// private attributes with getters and setters (encapsulation)

class Book {
private:
    string title;
    string author;
    string isbn;

public:
    Book(string title, string author, string isbn) {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
    }

    // getters
    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getIsbn() { return isbn; }

    // setters
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setIsbn(string i) { isbn = i; }
};


// ---- Member Class (base) ----
// RegularMember and PremiumMember will inherit from this

class Member {
protected:
    string name;
    int member_id;
    int max_books;
    vector<Book*> borrowed_books; // list of books the member currently has

public:
    Member(string name, int member_id, int max_books) {
        this->name = name;
        this->member_id = member_id;
        this->max_books = max_books;
    }

    virtual ~Member() {}

    // accessors
    string getName() { return name; }
    int getMemberId() { return member_id; }
    int getMaxBooks() { return max_books; }
    vector<Book*> getBorrowedBooks() { return borrowed_books; }

    // declaring these here - will implement the logic in week 4
    bool borrowBook(Book* book);
    bool returnBook(string isbn);

    // subclasses must implement this
    virtual string getMemberType() = 0;
};

// stubs for now
bool Member::borrowBook(Book* book) {
    // TODO: check availability and borrow limit, then add to borrowed_books
    return false;
}

bool Member::returnBook(string isbn) {
    // TODO: find the book, mark it available again, remove from list
    return false;
}


// ---- RegularMember - max 3 books ----
class RegularMember : public Member {
public:
    RegularMember(string name, int member_id) : Member(name, member_id, 3) {}

    string getMemberType() { return "Regular"; }
};


// ---- PremiumMember - max 5 books ----
class PremiumMember : public Member {
public:
    PremiumMember(string name, int member_id) : Member(name, member_id, 5) {}

    string getMemberType() { return "Premium"; }
};


// ---- BookRepository ----
// wraps a vector of books, MyLibrary will own one of these (composition)

class BookRepository {
private:
    vector<Book> books;

public:
    void addBook(Book book);        // TODO
    Book* findByIsbn(string isbn);  // TODO
    void listAll();                 // TODO
};

void BookRepository::addBook(Book book) {
    // TODO: check for duplicate isbn, then push to vector
}

Book* BookRepository::findByIsbn(string isbn) {
    // TODO: loop through and return matching book
    return nullptr;
}

void BookRepository::listAll() {
    // TODO: print all books with their status
}


// ---- AbstractLibrary ----
// general concept of a library - not a real/tangible one
// MyLibrary will inherit from this and implement the methods

class AbstractLibrary {
public:
    virtual ~AbstractLibrary() {}

    virtual void addBook(Book book) = 0;
    virtual bool borrowBook(Member& member, string isbn) = 0;
    virtual bool returnBook(Member& member, string isbn) = 0;
};


// ---- MyLibrary ----
// the actual tangible library, inherits from AbstractLibrary
//
// composition:  has a BookRepository (lives and dies with MyLibrary)
// association:  holds Member pointers but doesn't own them
//               (members come and go)

class MyLibrary : public AbstractLibrary {
private:
    string library_name;
    BookRepository repository;        // composition
    vector<Member*> members;          // association - not owned by library
    map<string, Member*> borrow_log;  // library-side record: isbn -> who has it

public:
    MyLibrary(string name) {
        this->library_name = name;
    }

    // member registration
    void registerMember(Member* member);   // TODO
    void unregisterMember(int member_id);  // TODO

    // AbstractLibrary methods
    void addBook(Book book);
    bool borrowBook(Member& member, string isbn);
    bool returnBook(Member& member, string isbn);

    // extra helpers
    void listBooks();
    void listMembers();
    void whoHas(string isbn); // check who has a book from the library side
};

void MyLibrary::registerMember(Member* member) {
    // TODO: check for duplicate id, then add to members
}

void MyLibrary::unregisterMember(int member_id) {
    // TODO: find by id and remove from members
}

void MyLibrary::addBook(Book book) {
    // TODO: pass to repository
}

bool MyLibrary::borrowBook(Member& member, string isbn) {
    // TODO: look up book, call member.borrowBook(), update borrow_log
    return false;
}

bool MyLibrary::returnBook(Member& member, string isbn) {
    // TODO: look up book, call member.returnBook(), erase from borrow_log
    return false;
}

void MyLibrary::listBooks() {
    // TODO: print all books
}

void MyLibrary::listMembers() {
    // TODO: print all registered members
}

void MyLibrary::whoHas(string isbn) {
    // TODO: look up isbn in borrow_log and print who has it
}


int main() {
    cout << "=== Library Management System - Week 3 ===" << endl;

    MyLibrary lib("City Central Library");

    // create some books to test
    Book b1("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842");
    Book b2("Clean Code", "Robert C. Martin", "978-0132350884");

    // showing the inheritance hierarchy works
    RegularMember alice("Alice", 101); // can borrow up to 3
    PremiumMember bob("Bob", 102);     // can borrow up to 5

    cout << "alice: " << alice.getMemberType() << endl;
    cout << "bob: " << bob.getMemberType() << endl;

    // these are stubs so nothing happens yet - full logic in week 4
    lib.registerMember(&alice);
    lib.registerMember(&bob);
    lib.addBook(b1);
    lib.addBook(b2);

    cout << "skeleton done - full logic coming in week 4" << endl;

    return 0;
}
