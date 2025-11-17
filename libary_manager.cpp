#include "library_manager.h"

// Constructor: initializes all member variables using initializer list
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
        available = false;  // Mark the book as borrowed
        std::cout << "You have borrowed: " << title << std::endl;
    } else {
        std::cout << "This book is currently not available." << std::endl;
    }
}

// Return the book
void Book::returnBook() {
    if (!available) {
        available = true;  // Mark the book as available again
        std::cout << "You have returned: " << title << std::endl;
    } else {
        std::cout << "This book was not borrowed." << std::endl;
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

// Placeholder for future sorting method
void Book::sortBookData(std::vector<Book>& books) {
    // Sorting logic will be implemented here (Bubble/Insertion/Selection sort)
}
