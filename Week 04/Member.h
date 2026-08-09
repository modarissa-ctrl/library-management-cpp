#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Book.h"
using namespace std;

// base class - RegularMember and PremiumMember inherit from this
class Member {
protected:
    string name;
    int member_id;
    int max_books;
    vector<Book*> borrowed_books;

public:
    Member(string name, int member_id, int max_books);
    virtual ~Member() {}

    string getName();
    int getMemberId();
    int getMaxBooks();
    vector<Book*> getBorrowedBooks();

    bool borrowBook(Book* book);
    bool returnBook(string isbn);

    // subclasses must define this
    virtual string getMemberType() = 0;
};


// ---- RegularMember - max 3 books ----
class RegularMember : public Member {
public:
    RegularMember(string name, int member_id);
    string getMemberType();
};


// ---- PremiumMember - max 5 books ----
class PremiumMember : public Member {
public:
    PremiumMember(string name, int member_id);
    string getMemberType();
};

#endif
