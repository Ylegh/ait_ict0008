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

    bool exitFlag = false;   // Loop control
    int choice;
    std::string inputISBN;

    while (!exitFlag) {
        // Display menu
        std::cout << "\nLibrary System\n";
        std::cout << "1. Borrow Book\n";
        std::cout << "2. Return Book\n";
        std::cout << "3. Exit\n";
        std::cout << "4. Display All Books\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 3) {
            exitFlag = true;
            std::cout << "Exiting program.\n";
            continue;
        }

        if (choice == 4) {
            std::cout << "\nLibrary Collection:\n";
            for (const Book &book : library) {
                book.displayBook();
            }
            continue;
        }

        // For borrow/return, ask for ISBN
        std::cout << "Enter the ISBN: ";
        std::cin >> inputISBN;

        bool found = false;
        for (Book &book : library) {
            if (book.getISBN() == inputISBN) {
                found = true;
                if (choice == 1) {
                    book.borrowBook();
                } else if (choice == 2) {
                    book.returnBook();
                } else {
                    std::cout << "Invalid choice.\n";
                }
                break; // Stop loop after handling the book
            }
        }

        if (!found) {
            std::cout << "Book not found in the library.\n";
        }
    }

    return 0;
}
