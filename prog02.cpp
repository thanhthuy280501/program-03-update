#include "Book.h"
#include "Member.h"
#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void updateBook(Book &book);
void convertTitleToUppercase(Book &book);
void convertTitleToLowercase(Book &book);
void convertAuthorToUppercase(Book &book);
void convertAuthorToLowercase(Book &book);

int main() {
    // Library dynamic array
    vector<Book> library;

    // Initialize with some books
    library.push_back(Book("Absolute C++", "Walter Savitch", "978-0-13-397078-4", "Pearson"));
    library.push_back(Book("Effective Java", "Joshua Bloch", "978-0-13-468599-1", "Addison-Wesley"));
    library.push_back(Book("Clean Code", "Robert C. Martin", "978-0-13-235088-4", "Prentice Hall"));
    library.push_back(Book("Design Patterns", "Erich Gamma", "978-0-201-63361-0", "Addison-Wesley"));

    // Create a Member object
    Member member("Xavier", "Charleston", "12345678");

    string command;
    while (true) {
        cout << "Enter command (borrow, return, account, newbook, updatebook, titleupper, titlelower, authorupper, authorlower, quit): ";
        cin >> command;

        if (command == "borrow") {
            string isbn;
            cout << "Enter ISBN to borrow: ";
            cin >> isbn;
            bool found = false;
            for (auto &book : library) {
                if (book.getISBN() == isbn) {
                    member.borrowBook(book);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found in the library." << endl;
            }

        } else if (command == "return") {
            string isbn;
            cout << "Enter ISBN to return: ";
            cin >> isbn;
            member.returnBook(isbn);

        } else if (command == "account") {
            cout << member << endl;

        } else if (command == "newbook") {
            string title, author, isbn, publisher;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            cin >> isbn;
            cout << "Enter publisher: ";
            cin.ignore();
            getline(cin, publisher);

            library.push_back(Book(title, author, isbn, publisher));
            cout << "New book added to the library." << endl;

        } else if (command == "updatebook") {
            string isbn;
            cout << "Enter ISBN of the book to update: ";
            cin >> isbn;

            bool found = false;
            for (auto &book : library) {
                if (book.getISBN() == isbn) {
                    updateBook(book);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found in the library." << endl;
            }

        } else if (command == "titleupper") {
            string isbn;
            cout << "Enter ISBN: ";
            cin >> isbn;

            bool found = false;
            for (auto &book : library) {
                if (book.getISBN() == isbn) {
                    convertTitleToUppercase(book);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found in the library." << endl;
            }

        } else if (command == "titlelower") {
            string isbn;
            cout << "Enter ISBN: ";
            cin >> isbn;

            bool found = false;
            for (auto &book : library) {
                if (book.getISBN() == isbn) {
                    convertTitleToLowercase(book);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found in the library." << endl;
            }

        } else if (command == "authorupper") {
            string isbn;
            cout << "Enter ISBN: ";
            cin >> isbn;

            bool found = false;
            for (auto &book : library) {
                if (book.getISBN() == isbn) {
                    convertAuthorToUppercase(book);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found in the library." << endl;
            }

        } else if (command == "authorlower") {
            string isbn;
            cout << "Enter ISBN: ";
            cin >> isbn;

            bool found = false;
            for (auto &book : library) {
                if (book.getISBN() == isbn) {
                    convertAuthorToLowercase(book);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found in the library." << endl;
            }

        } else if (command == "quit") {
            break;

        } else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}

// Update book details
void updateBook(Book &book) {
    string newTitle, newAuthor, newISBN, newPublisher;

    cout << "Current title: " << book.getTitle() << endl;
    cout << "Enter new title (leave blank to keep current): ";
    cin.ignore();
    getline(cin, newTitle);
    if (!newTitle.empty()) {
        book.setTitle(newTitle);
    }

    cout << "Current author: " << book.getAuthor() << endl;
    cout << "Enter new author (leave blank to keep current): ";
    getline(cin, newAuthor);
    if (!newAuthor.empty()) {
        book.setAuthor(newAuthor);
    }

    cout << "Current ISBN: " << book.getISBN() << endl;
    cout << "Enter new ISBN (leave blank to keep current): ";
    getline(cin, newISBN);
    if (!newISBN.empty()) {
        book.setISBN(newISBN);
    }

    cout << "Current publisher: " << book.getPublisher() << endl;
    cout << "Enter new publisher (leave blank to keep current): ";
    getline(cin, newPublisher);
    if (!newPublisher.empty()) {
        book.setPublisher(newPublisher);
    }
}

// Convert title to uppercase
void convertTitleToUppercase(Book &book) {
    book.convertTitleToUppercase();
    cout << "Updated title to uppercase: " << book.getTitle() << endl;
}

// Convert title to lowercase
void convertTitleToLowercase(Book &book) {
    book.convertTitleToLowercase();
    cout << "Updated title to lowercase: " << book.getTitle() << endl;
}

// Convert author to uppercase
void convertAuthorToUppercase(Book &book) {
    book.convertAuthorToUppercase();
    cout << "Updated author to uppercase: " << book.getAuthor() << endl;
}

// Convert author to lowercase
void convertAuthorToLowercase(Book &book) {
    book.convertAuthorToLowercase();
    cout << "Updated author to lowercase: " << book.getAuthor() << endl;
}

    return 0;
}
