#include "library_manager.h"
#include <vector>
#include <iostream>
#include <string>

int main() {
    std::vector<Book> library;

    // Populate library with 5 books
    library.push_back(Book("Sapiens", "Yuval Noah Harari", "9780099590088", true, "2023-12-01"));
    library.push_back(Book("Guns, Germs and Steel", "Jared Diamond", "9780393317558", true, "2023-12-02"));
    library.push_back(Book("The Silk Roads", "Peter Frankopan", "9781408839997", false, "2023-11-15"));
    library.push_back(Book("SPQR", "Mary Beard", "9781631492228", true, "2023-12-10"));
    library.push_back(Book("The Origins of Political Order", "Francis Fukuyama", "9780374533229", false, "2023-11-20"));

    bool exitFlag = false;
    int choice;
    std::string inputISBN;
    std::string methodName = "Unsorted"; // default

    while (!exitFlag) {
        std::cout << "\nLibrary System Menu:\n";
        std::cout << "1. Borrow Book\n";
        std::cout << "2. Return Book\n";
        std::cout << "3. Display All Books\n";
        std::cout << "4. Sort Library\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::cout << "Enter ISBN to borrow: ";
                std::cin >> inputISBN;
                bool found = false;
                for (Book &book : library) {
                    if (book.getISBN() == inputISBN) {
                        book.borrowBook();
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Book not found.\n";
                break;
            }

            case 2: {
                std::cout << "Enter ISBN to return: ";
                std::cin >> inputISBN;
                bool found = false;
                for (Book &book : library) {
                    if (book.getISBN() == inputISBN) {
                        book.returnBook();
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Book not found.\n";
                break;
            }

            case 3:
                printLibrary(library, methodName);
                break;

            case 4: {
                int sortChoice;
                std::cout << "\nChoose sorting method:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\nEnter choice: ";
                std::cin >> sortChoice;

                if (sortChoice == 1) {
                    bubbleSort(library);
                    methodName = "Bubble Sort";
                } else if (sortChoice == 2) {
                    insertionSort(library);
                    methodName = "Insertion Sort";
                } else if (sortChoice == 3) {
                    selectionSort(library);
                    methodName = "Selection Sort";
                } else {
                    std::cout << "Invalid choice.\n";
                    break;
                }

                // Show sorted library after sorting
                printLibrary(library, methodName);
                break;
            }

            case 5:
                exitFlag = true;
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }

    return 0;
}
