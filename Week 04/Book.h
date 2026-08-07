#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool available;

public:
    Book(string title, string author, string isbn);

    // getters
    string getTitle();
    string getAuthor();
    string getIsbn();
    bool isAvailable();

    // setters
    void setTitle(string t);
    void setAuthor(string a);
    void setIsbn(string i);
    void setAvailable(bool a);
};

#endif
