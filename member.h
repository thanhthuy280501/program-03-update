#ifndef MEMBER_H
#define MEMBER_H

#include "Book.h"

class Member {
private:
    string first_name;
    string last_name;
    string ID;
    Book **borrowedBooks;
    int borrowedCount;
    int borrowedCapacity;

    void resizeBorrowedBooks();

public:
    Member();
    Member(string fname, string lname, string id);
    ~Member();

    void borrowBook(const Book &book);
    void returnBook(const string &isbn);
    void listBorrowedBooks() const;

    void setFirstName(const string &fname);
    void setLastName(const string &lname);
};

#endif
