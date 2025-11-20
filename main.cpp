#include "library_manager.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<Book> library;

    // Initialize library with Hardcopy and EBooks
    library.push_back(HardcopyBook("Sapiens", "Yuval Noah Harari", "9780099590088", true, "2023-12-01", "909 HAR"));
    library.push_back(EBook("Guns, Germs and Steel", "Jared Diamond", "9780393317558", true, "2023-12-02", "2025-12-31"));
    library.push_back(HardcopyBook("The Silk Roads", "Peter Frankopan", "9781408839997", false, "2023-11-15", "909 FRA"));
    library.push_back(EBook("SPQR", "Mary Beard", "9781631492228", true, "2023-12-10", "2024-12-01"));
    library.push_back(HardcopyBook("The Origins of Political Order", "Francis Fukuyama", "9780374533229", false, "2023-11-20", "320.9 FUK"));

    bool exitFlag = false;
    int choice;
    std::string inputISBN;
    std::string lastSortMethod;

    // Main Menu Loop

    while (!exitFlag) {
        std::cout << "\nLibrary System Menu:\n";
        std::cout << "1. Borrow Book\n2. Return Book\n3. Display All Books\n4. Sort Library\n5. Exit\n";
        std::cout << "Enter your choice: ";

        // Prevent infinite loop on invalid input
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }

        switch (choice) {
            // Borrow Book 
            case 1:
                std::cout << "Enter ISBN to borrow (0 to exit): ";
                std::cin >> inputISBN;
                if (inputISBN == "0") { exitFlag = true; break; }
                {
                    bool found = false;
                    for (auto& book : library) {
                        if (book.getISBN() == inputISBN) { book.borrowBook(); found = true; break; }
                    }
                    if (!found) std::cout << "Book not found.\n";
                }
                break;
            // Return Book 
            case 2:
                std::cout << "Enter ISBN to return (0 to exit): ";
                std::cin >> inputISBN;
                if (inputISBN == "0") { exitFlag = true; break; }
                {
                    bool found = false;
                    for (auto& book : library) {
                        if (book.getISBN() == inputISBN) { book.returnBook(); found = true; break; }
                    }
                    if (!found) std::cout << "Book not found.\n";
                }
                break;
            // Display Library Collection
            case 3:
                printLibrary(library, lastSortMethod);
                break;
            // Sorting Menu
            case 4: {
                int sortChoice;
                std::cout << "Choose a method to sort the library by ISBN:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\nEnter choice: ";
                std::cin >> sortChoice;

                if (sortChoice == 1) { bubbleSort(library); lastSortMethod = "Bubble Sort"; }
                else if (sortChoice == 2) { insertionSort(library); lastSortMethod = "Insertion Sort"; }
                else if (sortChoice == 3) { selectionSort(library); lastSortMethod = "Selection Sort"; }
                else { std::cout << "Invalid choice.\n"; break; }

                std::cout << "Library sorted successfully.\n";
                printLibrary(library, lastSortMethod);
                break;
            }
            // Exit the program
            case 5:
                exitFlag = true;
                std::cout << "Exiting program.\n";
                break;
            // Invalid menu selection
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
