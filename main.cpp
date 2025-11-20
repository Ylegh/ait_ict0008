#include "library_manager.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<Book> library;

    // Initialise library with 5 books
    library.push_back(Book("Sapiens", "Yuval Noah Harari", "9780099590088", true, "2023-12-01"));
    library.push_back(Book("Guns, Germs and Steel", "Jared Diamond", "9780393317558", true, "2023-12-02"));
    library.push_back(Book("The Silk Roads", "Peter Frankopan", "9781408839997", false, "2023-11-15"));
    library.push_back(Book("SPQR", "Mary Beard", "9781631492228", true, "2023-12-10"));
    library.push_back(Book("The Origins of Political Order", "Francis Fukuyama", "9780374533229", false, "2023-11-20"));

    bool exitFlag = false;
    int choice;
    std::string inputISBN;
    std::string lastSortMethod; // tracks last sorting method

    while (!exitFlag) {
        // Display menu
        std::cout << "\nLibrary System Menu:\n";
        std::cout << "1. Borrow Book\n";
        std::cout << "2. Return Book\n";
        std::cout << "3. Display All Books\n";
        std::cout << "4. Sort Library\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if(std::cin.fail()) { // invalid input
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: // Borrow book
                std::cout << "Enter ISBN to borrow (or 0 to exit): ";
                std::cin >> inputISBN;
                if (inputISBN == "0") { 
                    exitFlag = true;  // terminate the program
                    break; 
                }
                {
                    bool found = false;
                    for (Book &book : library) {
                        if (book.getISBN() == inputISBN) {
                            book.borrowBook();
                            found = true;
                            break;
                        }
                    }
                    if (!found) std::cout << "Book not found.\n";
                }
                break;

            case 2: // Return book
                std::cout << "Enter ISBN to return (or 0 to exit): ";
                std::cin >> inputISBN;
                if (inputISBN == "0") { 
                    exitFlag = true;  // terminate the program
                    break; 
                }
                {
                    bool found = false;
                    for (Book &book : library) {
                        if (book.getISBN() == inputISBN) {
                            book.returnBook();
                            found = true;
                            break;
                        }
                    }
                    if (!found) std::cout << "Book not found.\n";
                }
                break;

            case 3: // Display all books
                printLibrary(library, lastSortMethod);
                break;

            case 4: { // Sort library
                int sortChoice;
                std::cout << "Choose sorting method:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\nEnter choice: ";
                std::cin >> sortChoice;

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
                    std::cout << "Invalid choice.\n";
                    break;
                }

                printLibrary(library, lastSortMethod);
                std::cout << "Library sorted successfully.\n";
                break;
            }

            case 5: // Exit
                exitFlag = true;
                std::cout << "Exiting program.\n";
                break;

            default: // Invalid menu input
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
