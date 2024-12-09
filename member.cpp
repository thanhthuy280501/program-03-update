#include "Member.h"
#include <iostream>

Member::Member() : first_name(""), last_name(""), ID(""), borrowedCount(0), borrowedCapacity(2) {
    borrowedBooks = new Book*[borrowedCapacity];
}

Member::Member(string fname, string lname, string id)
    : first_name(fname), last_name(lname), ID(id), borrowedCount(0), borrowedCapacity(2) {
    borrowedBooks = new Book*[borrowedCapacity];
}

Member::~Member() {
    for (int i = 0; i < borrowedCount; i++) {
        delete borrowedBooks[i];
    }
    delete[] borrowedBooks;
}

void Member::resizeBorrowedBooks() {
    borrowedCapacity *= 2;
    Book **newArray = new Book*[borrowedCapacity];
    for (int i = 0; i < borrowedCount; i++) {
        newArray[i] = borrowedBooks[i];
    }
    delete[] borrowedBooks;
    borrowedBooks = newArray;
}

void Member::borrowBook(const Book &book) {
    if (borrowedCount == borrowedCapacity) {
        resizeBorrowedBooks();
    }
    borrowedBooks[borrowedCount++] = new Book(book);
}

void Member::returnBook(const string &isbn) {
    for (int i = 0; i < borrowedCount; i++) {
        if (borrowedBooks[i]->getISBN() == isbn) {
            delete borrowedBooks[i];
            for (int j = i; j < borrowedCount - 1; j++) {
                borrowedBooks[j] = borrowedBooks[j + 1];
            }
            borrowedCount--;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Member::listBorrowedBooks() const {
    if (borrowedCount == 0) {
        cout << "No books borrowed." << endl;
    } else {
        for (int i = 0; i < borrowedCount; i++) {
            cout << *(borrowedBooks[i]) << endl;
        }
    }
}

void Member::setFirstName(const string &fname) { first_name = fname; }
void Member::setLastName(const string &lname) { last_name = lname; }
