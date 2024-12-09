#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    string publisher;

public:
    // Constructors and Destructor
    Book();
    Book(string t, string a, string i, string p);
    ~Book();

    // Getters
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    string getPublisher() const;

    // Setters
    void setTitle(const string &t);
    void setAuthor(const string &a);
    void setISBN(const string &i);
    void setPublisher(const string &p);

    // String Manipulation
    void convertTitleToUppercase();
    void convertTitleToLowercase();
    void convertAuthorToUppercase();
    void convertAuthorToLowercase();

    // Overloaded Operators
    bool operator==(const Book &other) const;
    bool operator!=(const Book &other) const;
    friend ostream &operator<<(ostream &os, const Book &book);
};

#endif
