#include "Book.h"
#include <algorithm>

Book::Book() : title(""), author(""), ISBN(""), publisher("") {}

Book::Book(string t, string a, string i, string p)
    : title(t), author(a), ISBN(i), publisher(p) {}

Book::~Book() {}

// Getters
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getISBN() const { return ISBN; }
string Book::getPublisher() const { return publisher; }

// Setters
void Book::setTitle(const string &t) { title = t; }
void Book::setAuthor(const string &a) { author = a; }
void Book::setISBN(const string &i) { ISBN = i; }
void Book::setPublisher(const string &p) { publisher = p; }

// String Manipulation
void Book::convertTitleToUppercase() {
    transform(title.begin(), title.end(), title.begin(), ::toupper);
}

void Book::convertTitleToLowercase() {
    transform(title.begin(), title.end(), title.begin(), ::tolower);
}

void Book::convertAuthorToUppercase() {
    transform(author.begin(), author.end(), author.begin(), ::toupper);
}

void Book::convertAuthorToLowercase() {
    transform(author.begin(), author.end(), author.begin(), ::tolower);
}

// Overloaded Operators
bool Book::operator==(const Book &other) const { return ISBN == other.ISBN; }
bool Book::operator!=(const Book &other) const { return ISBN != other.ISBN; }
ostream &operator<<(ostream &os, const Book &book) {
    os << book.title << " by " << book.author << ", ISBN: " << book.ISBN
       << ", Publisher: " << book.publisher;
    return os;
}
