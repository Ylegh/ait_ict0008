#include "library_manager.h"

// Base Book Class
Book::Book(const std::string& t, const std::string& a, const std::string& i,
           bool avail, const std::string& date)
    : title(t), author(a), isbn(i), available(avail), dateAdded(date) {}

std::string Book::getISBN() const { return isbn; }
bool Book::isAvailable() const { return available; }

void Book::borrowBook() {
    if (available) {
        available = false;
        std::cout << title << " has been borrowed.\n";
    } else {
        std::cout << title << " is currently unavailable.\n";
    }
}

void Book::returnBook() {
    available = true;
    std::cout << title << " has been returned.\n";
}

void Book::displayBook() const {
    std::cout << "Title: " << title
              << " | Author: " << author
              << " | ISBN: " << isbn
              << " | Available: " << (available ? "Yes" : "No")
              << " | Date Added: " << dateAdded
              << "\n";
}

// HardcopyBook Child Class
HardcopyBook::HardcopyBook(const std::string& t, const std::string& a, const std::string& i,
                           bool avail, const std::string& date, const std::string& shelf)
    : Book(t, a, i, avail, date), shelfNumber(shelf) {}

void HardcopyBook::displayBook() const {
    Book::displayBook();
    std::cout << "  Shelf Number: " << shelfNumber << "\n";
}

// EBook Child Class
EBook::EBook(const std::string& t, const std::string& a, const std::string& i,
             bool avail, const std::string& date, const std::string& endLicense)
    : Book(t, a, i, avail, date), endOfLicenseDate(endLicense) {}

void EBook::displayBook() const {
    Book::displayBook();
    std::cout << "  End-of-License Date: " << endOfLicenseDate << "\n";
}

// Sorting Algorithmns (Bubble Sort, Insertion Sort, & Selection Sort)
void bubbleSort(std::vector<Book>& library) {
    for (size_t i = 0; i < library.size(); ++i) {
        for (size_t j = 0; j < library.size() - i - 1; ++j) {
            if (library[j].getISBN() > library[j + 1].getISBN())
                std::swap(library[j], library[j + 1]);
        }
    }
}

void insertionSort(std::vector<Book>& library) {
    for (size_t i = 1; i < library.size(); ++i) {
        Book key = library[i];
        int j = i - 1;
        while (j >= 0 && library[j].getISBN() > key.getISBN()) {
            library[j + 1] = library[j];
            --j;
        }
        library[j + 1] = key;
    }
}

void selectionSort(std::vector<Book>& library) {
    for (size_t i = 0; i < library.size(); ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < library.size(); ++j) {
            if (library[j].getISBN() < library[minIdx].getISBN())
                minIdx = j;
        }
        std::swap(library[i], library[minIdx]);
    }
}

// Print Library
void printLibrary(const std::vector<Book>& library, const std::string& methodName) {
    std::string displayName = methodName.empty() ? "Library Collection" : ("Library sorted using " + methodName);
    std::cout << "\n" << displayName << ":\n";
    for (const auto& book : library) {
        book.displayBook();
    }
}

void printLibrary(const std::vector<Book>& library) {
    printLibrary(library, ""); // calls overloaded version
}
