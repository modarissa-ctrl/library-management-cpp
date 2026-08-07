#include "Book.h"

Book::Book(string title, string author, string isbn) {
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->available = true;
}

string Book::getTitle() { return title; }
string Book::getAuthor() { return author; }
string Book::getIsbn() { return isbn; }
bool Book::isAvailable() { return available; }

void Book::setTitle(string t) { title = t; }
void Book::setAuthor(string a) { author = a; }
void Book::setIsbn(string i) { isbn = i; }
void Book::setAvailable(bool a) { available = a; }
