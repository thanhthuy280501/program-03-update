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

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <library_file> <member_file>" << endl;
        return 1;
    }

    string libraryFile = argv[1];
    string memberFile = argv[2];

    vector<Book> library;
    vector<Member> members;
    Member *currentMember = nullptr;

    loadBooksFromFile(libraryFile, library);
    loadMembersFromFile(memberFile, members);

    string command;
    while (true) {
        cout << "Enter command (borrow, return, account, newbook, updatebook, titleupper, titlelower, authorupper, authorlower, search, library, memberlist, sortlibrary, sortmembers, switch, quit): ";
        cin >> command;

        if (command == "borrow" && currentMember) {
            string isbn;
            cout << "Enter ISBN to borrow: ";
            cin >> isbn;
            Book *book = searchBookByISBN(library, isbn);
            if (book) {
                currentMember->borrowBook(*book);
            } else {
                cout << "Book not found in the library." << endl;
            }
        } else if (command == "return" && currentMember) {
            string isbn;
            cout << "Enter ISBN to return: ";
            cin >> isbn;
            currentMember->returnBook(isbn);
        } else if (command == "switch") {
            switchMember(members, currentMember);
        } else if (command == "sortlibrary") {
            sortLibrary(library);
        } else if (command == "sortmembers") {
            sortMembers(members);
        } else if (command == "search") {
            string isbn;
            cout << "Enter ISBN to search: ";
            cin >> isbn;
            Book *book = searchBookByISBN(library, isbn);
            if (book) {
                cout << "Book found: " << *book << endl;
            } else {
                cout << "Book not found." << endl;
            }
        } else if (command == "library") {
            for (const auto &book : library) {
                cout << book << endl;
            }
        } else if (command == "memberlist") {
            for (const auto &member : members) {
                cout << member << endl;
            }
        } else if (command == "quit") {
            saveBooksToFile(libraryFile, library);
            saveMembersToFile(memberFile, members);
            break;
        } else {
            cout << "Invalid command or no member selected." << endl;
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
void loadBooksFromFile(const string &filename, vector<Book> &library) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Could not open the book file." << endl;
        return;
    }

    string title, author, isbn, publisher;
    while (getline(infile, title) && getline(infile, author) && getline(infile, isbn) && getline(infile, publisher)) {
        library.emplace_back(title, author, isbn, publisher);
    }
    infile.close();
}

void saveBooksToFile(const string &filename, const vector<Book> &library) {
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cerr << "Error: Could not open the book file for writing." << endl;
        return;
    }

    for (const auto &book : library) {
        outfile << book.getTitle() << endl;
        outfile << book.getAuthor() << endl;
        outfile << book.getISBN() << endl;
        outfile << book.getPublisher() << endl;
    }
    outfile.close();
}
Book *searchBookByISBN(vector<Book> &library, const string &isbn, int index = 0) {
    if (index >= library.size()) return nullptr;
    if (library[index].getISBN() == isbn) return &library[index];
    return searchBookByISBN(library, isbn, index + 1);
}


    return 0;
}
