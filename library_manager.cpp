#include "library_manager.h"

// Base Book Class 

// Constructor initialising book fields
Book::Book(const std::string& t,
           const std::string& a,
           const std::string& i,
           bool avail,
           const std::string& date)
    : title(t),
      author(a),
      isbn(i),
      available(avail),
      dateAdded(date) {}

// Function to allow for updating base book attributes
void Book::setBookDetails(const std::string& t,
        const std::string& a,
        const std::string& i,
        bool avail,
        const std::string& date) 
    {
        title = t;
        author = a;
        isbn = i;
        available = avail;
        dateAdded = date;
    }


std::string Book::getISBN() const {
    return isbn;
}

bool Book::isAvailable() const {
    return available;
}

// Marks the book as borrowed, only if currently available
void Book::borrowBook() {
    if (available) {
        available = false;
        std::cout << title << " has been borrowed.\n";
    } else {
        std::cout << title << " is currently unavailable.\n";
    }
}

// Marks the book as returned
void Book::returnBook() {
    if (!available) {
        available = true;
        std::cout << title << " has been returned.\n";
    } else {
        std::cout << title << " was not borrowed.\n";
    }
}

// Prints the base information of any book type (virtual for overrides)
void Book::displayBook() const {
    std::cout << "Title: " << title
              << " | Author: " << author
              << " | ISBN: " << isbn
              << " | Available: " << (available ? "Yes" : "No")
              << " | Date Added: " << dateAdded
              << "\n";
}

// Derived HardcopyBook Class

// Calls base constructor + stores shelf number
HardcopyBook::HardcopyBook(const std::string& t,
                           const std::string& a,
                           const std::string& i,
                           bool avail,
                           const std::string& date,
                           const std::string& shelf)
    : Book(t, a, i, avail, date),
      shelfNumber(shelf) {}

// Prints base book info, then adds hardcopy-only details
void HardcopyBook::displayBook() const {
    Book::displayBook();
    std::cout << "  Shelf Number: " << shelfNumber << "\n";
}

// Derived EBook Class

// Calls base constructor + stores license expiry date
EBook::EBook(const std::string& t,
             const std::string& a,
             const std::string& i,
             bool avail,
             const std::string& date,
             const std::string& endLicense)
    : Book(t, a, i, avail, date),
      endOfLicenseDate(endLicense) {}

// Prints base book info, then adds e-book-only details
void EBook::displayBook() const {
    Book::displayBook();
    std::cout << "  End-of-License Date: " << endOfLicenseDate << "\n";
}

// Sorting algorithms using ISBN for comparisons
void bubbleSort(std::vector<Book*>& library) {
    const std::size_t n = library.size();
    if (n < 2) return;

    for (std::size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;
        // Compare adjacent items and swap if needed
        for (std::size_t j = 0; j < n - 1 - i; ++j) {
            if (library[j]->getISBN() > library[j + 1]->getISBN()) {
                std::swap(library[j], library[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // already sorted
    }
}

void insertionSort(std::vector<Book*>& library) {
    const std::size_t n = library.size();
    for (std::size_t i = 1; i < n; ++i) {
        Book* key = library[i];
        int j = static_cast<int>(i) - 1;
        // Shift larger items to the right
        while (j >= 0 && library[j]->getISBN() > key->getISBN()) {
            library[j + 1] = library[j];
            --j;
        }
        library[j + 1] = key;
    }
}

void selectionSort(std::vector<Book*>& library) {
    const std::size_t n = library.size();
    for (std::size_t i = 0; i < n; ++i) {
        std::size_t minIdx = i;
         // Find minimum ISBN in the unsorted portion
        for (std::size_t j = i + 1; j < n; ++j) {
            if (library[j]->getISBN() < library[minIdx]->getISBN()) {
                minIdx = j;
            }
        }
        // Swap into correct position
        if (minIdx != i) {
            std::swap(library[i], library[minIdx]);
        }
    }
}

// Print Library Contents
void printLibrary(const std::vector<Book*>& library,
                  const std::string& methodName) {
    if (methodName.empty()) {
        std::cout << "\nLibrary Collection:\n";
    } else {
        std::cout << "\nLibrary sorted using " << methodName << ":\n";
    }

    for (const Book* book : library) {
        if (book) {
            book->displayBook(); // virtual dispatch so child attributes will show
        }
    }
}
