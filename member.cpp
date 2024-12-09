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


void loadMembersFromFile(const string &filename, vector<Member> &members) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Could not open the member file." << endl;
        return;
    }

    string fname, lname, id;
    int count;
    while (getline(infile, fname) && getline(infile, lname) && getline(infile, id) && infile >> count) {
        infile.ignore();
        Member member(fname, lname, id);
        for (int i = 0; i < count; i++) {
            string title, author, isbn, publisher;
            getline(infile, title);
            getline(infile, author);
            getline(infile, isbn);
            getline(infile, publisher);
            member.borrowBook(Book(title, author, isbn, publisher));
        }
        members.push_back(member);
    }
    infile.close();
}

void saveMembersToFile(const string &filename, const vector<Member> &members) {
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cerr << "Error: Could not open the member file for writing." << endl;
        return;
    }

    for (const auto &member : members) {
        outfile << member.getFirstName() << endl;
        outfile << member.getLastName() << endl;
        outfile << member.getID() << endl;
        outfile << member.getBorrowedCount() << endl;

        member.listBorrowedBooks([&outfile](const Book &book) {
            outfile << book.getTitle() << endl;
            outfile << book.getAuthor() << endl;
            outfile << book.getISBN() << endl;
            outfile << book.getPublisher() << endl;
        });
    }
    outfile.close();
}
void sortMembers(vector<Member> &members) {
    sort(members.begin(), members.end(), [](const Member &a, const Member &b) {
        return a.getLastName() < b.getLastName();
    });
}
void switchMember(vector<Member> &members, Member *&currentMember) {
    string memberID;
    cout << "Enter Member ID: ";
    cin >> memberID;

    for (auto &member : members) {
        if (member.getID() == memberID) {
            currentMember = &member;
            cout << "Switched to member: " << member.getFirstName() << " " << member.getLastName() << endl;
            return;
        }
    }
    cout << "Member ID not found." << endl;
}



