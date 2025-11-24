#include "library_manager.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    // Use pointers to preserve child attributes
    std::vector<Book*> library;

    // Mix of hardcopy and e-books for phase 2 requirements
    library.push_back(new HardcopyBook(
        "Sapiens", "Yuval Noah Harari", "9780099590088",
        true, "2023-12-01", "909 HAR"));
    library.push_back(new HardcopyBook(
        "Guns, Germs and Steel", "Jared Diamond", "9780393317558",
        true, "2023-12-02", "303.4 DIA"));
    library.push_back(new EBook(
        "The Silk Roads", "Peter Frankopan", "9781408839997",
        false, "2023-11-15", "2025-11-15"));
    library.push_back(new HardcopyBook(
        "SPQR", "Mary Beard", "9781631492228",
        true, "2023-12-10", "937 BEA"));
    library.push_back(new EBook(
        "The Origins of Political Order", "Francis Fukuyama", "9780374533229",
        false, "2023-11-20", "2025-12-01"));

    bool exitFlag = false;
    int choice;
    std::string inputISBN;
    std::string lastSortMethod; // empty = unsorted / original

    while (!exitFlag) {
        std::cout << "\nLibrary System Menu:\n";
        std::cout << "1. Borrow Book\n";
        std::cout << "2. Return Book\n";
        std::cout << "3. Display All Books\n";
        std::cout << "4. Sort Library\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            // Handle non-numeric input
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1: { // Borrow Book
            std::cout << "Enter ISBN to borrow (0 to exit): ";
            std::cin >> inputISBN;
            if (inputISBN == "0") {
                exitFlag = true;
                break;
            }

            bool found = false;
            for (Book* book : library) {
                if (book && book->getISBN() == inputISBN) {
                    book->borrowBook();
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Book not found.\n";
            }
            break;
        }

        case 2: { // Return Book
            std::cout << "Enter ISBN to return (0 to exit): ";
            std::cin >> inputISBN;
            if (inputISBN == "0") {
                exitFlag = true;
                break;
            }

            bool found = false;
            for (Book* book : library) {
                if (book && book->getISBN() == inputISBN) {
                    book->returnBook();
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Book not found.\n";
            }
            break;
        }

        case 3: // Display all books
            printLibrary(library, lastSortMethod);
            break;

        case 4: { // Sort library
            int sortChoice;
            std::cout << "Choose sorting method:\n";
            std::cout << "1. Bubble Sort\n";
            std::cout << "2. Insertion Sort\n";
            std::cout << "3. Selection Sort\n";
            std::cout << "Enter choice: ";
            if (!(std::cin >> sortChoice)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input.\n";
                break;
            }

            if (sortChoice == 1) {
                bubbleSort(library);
                lastSortMethod = "Bubble Sort";
            } else if (sortChoice == 2) {
                insertionSort(library);
                lastSortMethod = "Insertion Sort";
            } else if (sortChoice == 3) {
                selectionSort(library);
                lastSortMethod = "Selection Sort";
            } else {
                std::cout << "Invalid sorting choice.\n";
                break;
            }

            printLibrary(library, lastSortMethod);
            break;
        }

        case 5:
            exitFlag = true;
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid menu choice. Please try again.\n";
            break;
        }
    }

    // Clean up heap-allocated objects
    for (Book* book : library) {
        delete book;
    }

    return 0;
}
