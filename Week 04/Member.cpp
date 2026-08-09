#include "Member.h"
#include <iostream>
using namespace std;

Member::Member(string name, int member_id, int max_books) {
    this->name = name;
    this->member_id = member_id;
    this->max_books = max_books;
}

string Member::getName() { return name; }
int Member::getMemberId() { return member_id; }
int Member::getMaxBooks() { return max_books; }
vector<Book*> Member::getBorrowedBooks() { return borrowed_books; }

bool Member::borrowBook(Book* book) {
    if ((int)borrowed_books.size() >= max_books) {
        cout << name << " has reached the borrow limit (" << max_books << " books)." << endl;
        return false;
    }
    if (!book->isAvailable()) {
        cout << "\"" << book->getTitle() << "\" is not available right now." << endl;
        return false;
    }
    borrowed_books.push_back(book);
    book->setAvailable(false);
    return true;
}

bool Member::returnBook(string isbn) {
    for (int i = 0; i < (int)borrowed_books.size(); i++) {
        if (borrowed_books[i]->getIsbn() == isbn) {
            borrowed_books[i]->setAvailable(true);
            borrowed_books.erase(borrowed_books.begin() + i);
            return true;
        }
    }
    // isbn wasn't in this member's list
    return false;
}


// RegularMember
RegularMember::RegularMember(string name, int member_id) : Member(name, member_id, 3) {}
string RegularMember::getMemberType() { return "Regular"; }

// PremiumMember
PremiumMember::PremiumMember(string name, int member_id) : Member(name, member_id, 5) {}
string PremiumMember::getMemberType() { return "Premium"; }
