#include "library_manager.h"
#include <vector>
#include <iostream>
#include <string>

int main() {
    // Vector to store the library's books
    std::vector<Book> library;

    // Populate the library with 5 books
    library.push_back(Book("Sapiens", "Yuval Noah Harari", "9780099590088", true, "2023-12-01"));
    library.push_back(Book("Guns, Germs and Steel", "Jared Diamond", "9780393317558", true, "2023-12-02"));
    library.push_back(Book("The Silk Roads", "Peter Frankopan", "9781408839997", false, "2023-11-15"));
    library.push_back(Book("SPQR", "Mary Beard", "9781631492228", true, "2023-12-10"));
    library.push_back(Book("The Origins of Political Order", "Francis Fukuyama", "9780374533229", false, "2023-11-20"));

    int choice;
    std::string inputISBN;

    // Simple menu: ask user whether to borrow or return a book
    std::cout << "Library System\n";
    std::cout << "1. Borrow Book\n";
    std::cout << "2. Return Book\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Ask user for ISBN of the book
    std::cout << "Enter the ISBN: ";
    std::cin >> inputISBN;

    bool found = false;  // Flag to check if book exists in library

    // Loop through the library vector to find the book
    for (Book &book : library) {
        if (book.getISBN() == inputISBN) {
            found = true;

            if (choice == 1) {
                // Borrow the book
                book.borrowBook();
            }
            else if (choice == 2) {
                // Return the book
                book.returnBook();
            }
            else {
                std::cout << "Invalid choice.\n";
            }

            break;  // Stop loop after finding the book
        }
    }

    // If the book was not found
    if (!found) {
        std::cout << "Book not found in the library.\n";
    }

    return 0;
}
