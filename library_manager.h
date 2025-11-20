#pragma once
#include <iostream>
#include <string>
#include <vector>

// Book class to represent individual books in the library
class Book {
private:
    std::string title;      // Book title
    std::string author;     // Book author
    std::string isbn;       // Unique ISBN identifier
    bool available;         // Availability flag
    std::string dueDate;    // Date the library added the book

public:
    // Constructor: initializes a book object with all attributes
    Book(const std::string& t, const std::string& a, const std::string& i, bool avail, const std::string& due);

    // Getter for ISBN (used to search books in the library)
    std::string getISBN() const;

    // Getter for availability
    bool isAvailable() const;

    // Borrow the book: sets availability to false if not already borrowed
    void borrowBook();

    // Return the book: sets availability to true if previously borrowed
    void returnBook();

    // Display book details to the console
    void displayBook() const;
};

// Sorting function declarations

void bubbleSort(std::vector<Book>& library);
void insertionSort(std::vector<Book>& library);
void selectionSort(std::vector<Book>& library);

// Print function
void printLibrary(const std::vector<Book>& library, const std::string& methodName = "");

