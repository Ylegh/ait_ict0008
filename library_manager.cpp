#include "library_manager.h"
#include <algorithm>

// Constructor
Book::Book(const std::string& t, const std::string& a, const std::string& i, bool avail, const std::string& due)
    : title(t), author(a), isbn(i), available(avail), dueDate(due) {}

// Getter for ISBN
std::string Book::getISBN() const { 
    return isbn; 
}

// Getter for availability
bool Book::isAvailable() const { 
    return available; 
}

// Borrow the book
void Book::borrowBook() {
    if (available) {
        available = false;
        std::cout << "You have borrowed: " << title << std::endl;
    } else {
        std::cout << "This book is currently not available.\n";
    }
}

// Return the book
void Book::returnBook() {
    if (!available) {
        available = true;
        std::cout << "You have returned: " << title << std::endl;
    } else {
        std::cout << "This book was not borrowed.\n";
    }
}

// Display book details
void Book::displayBook() const {
    std::cout << "Title: " << title
              << " | Author: " << author
              << " | ISBN: " << isbn
              << " | Available: " << (available ? "Yes" : "No")
              << " | Added Date: " << dueDate << std::endl;
}

// Bubble Sort
void bubbleSort(std::vector<Book>& library) {
    int n = library.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (library[j].getISBN() > library[j + 1].getISBN()) {
                std::swap(library[j], library[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Insertion Sort
void insertionSort(std::vector<Book>& library) {
    int n = library.size();
    for (int i = 1; i < n; i++) {
        Book key = library[i];
        int j = i - 1;
        while (j >= 0 && library[j].getISBN() > key.getISBN()) {
            library[j + 1] = library[j];
            j--;
        }
        library[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(std::vector<Book>& library) {
    int n = library.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (library[j].getISBN() < library[minIndex].getISBN()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(library[i], library[minIndex]);
        }
    }
}

// Print library
void printLibrary(const std::vector<Book>& library, const std::string& methodName) {
    if (methodName.empty())
        std::cout << "\nLibrary Collection:\n";
    else
        std::cout << "\nLibrary sorted using " << methodName << ":\n";

    for (const Book &book : library) {
        book.displayBook();
    }
}