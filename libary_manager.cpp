#include "library_manager.h"
#include <vector>
#include <iostream>

// Constructor with parameters
Book::Book(const std::string& title,
    const std::string& author,
    const std::string& ISBN,
    bool available,
    const std::string& dateAdded)
{
    // To be implemented
}

// Method to set book details
void Book::setBookDetails(const std::string& title,
    const std::string& author,
    const std::string& ISBN,
    bool available,
    const std::string& dateAdded)
{
    // To be implemented
}

// Method to display book details
void Book::displayBookDetails() const
{
    // To be implemented
}

// Method to borrow a book
void Book::borrowBook()
{
    // To be implemented
}

// Method to return a book
void Book::returnBook()
{
    // To be implemented
}

// Method to sort book data
void Book::sortBookData(std::vector<Book>& books)
{
    // To be implemented
}

// to be implemented into seperate cpp file

int main() {
    // Initialise library with 5 books
    std::vector<Book> library;

    // To be implemented: populate the library

    std::string inputISBN;

    while (true) {
        std::cout << "Enter ISBN to borrow a book (or 0 to exit): ";
        std::cin >> inputISBN;

        if (inputISBN == "0") {
            std::cout << "Exiting program.\n";
            break;
        }

        // To be implemented: search for book by ISBN and handle borrowing
    }

    return 0;
}
