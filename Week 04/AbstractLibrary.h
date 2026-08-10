#ifndef ABSTRACTLIBRARY_H
#define ABSTRACTLIBRARY_H

#include "Book.h"
#include "Member.h"

// general concept of a library - not a real/tangible one
// MyLibrary inherits from this and provides the actual implementation
class AbstractLibrary {
public:
    virtual ~AbstractLibrary() {}

    virtual void addBook(Book book) = 0;
    virtual bool borrowBook(Member& member, string isbn) = 0;
    virtual bool returnBook(Member& member, string isbn) = 0;
};

#endif
