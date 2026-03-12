/*
Problem: Library Management System
Demonstrate composition/aggregation.
A Library has Books. Book class encapsulates title, author, isbn.
Library class has an array/vector of Books and methods to addBook(), displayBooks().
*/

#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;

public:
    Book(std::string t, std::string a, std::string i) : title(t), author(a), ISBN(i) {}

    void displayBook() const {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "ISBN: " << ISBN << "\n" << std::endl;
    }
};

class Library {
private:
    std::string name;
    std::vector<Book> collection;

public:
    Library(std::string n) : name(n) {}

    void addBook(const Book& b) {
        collection.push_back(b);
        std::cout << "Book added to collection." << std::endl;
    }

    void displayAllBooks() const {
        std::cout << "--- " << name << " Collection ---" << std::endl;
        for (const auto& book : collection) {
            book.displayBook();
        }
    }
};

int main() {
    Book b1("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842");
    Book b2("Clean Code", "Robert C. Martin", "978-0132350884");

    Library myLib("Tech Hub Library");
    myLib.addBook(b1);
    myLib.addBook(b2);

    myLib.displayAllBooks();

    return 0;
}
