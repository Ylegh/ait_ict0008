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
    // Constructor
    Book(const std::string& t, const std::string& a, const std::string& i, bool avail, const std::string& due);

    // Getter for ISBN
    std::string getISBN() const;

    // Getter for availability
    bool isAvailable() const;

    // Borrow the book
    void borrowBook();

    // Return the book
    void returnBook();

    // Display book details
    void displayBook() const;
};

// Sorting function declarations
void bubbleSort(std::vector<Book>& library);
void insertionSort(std::vector<Book>& library);
void selectionSort(std::vector<Book>& library);

// Function to print library
void printLibrary(const std::vector<Book>& library, const std::string& methodName = "");
