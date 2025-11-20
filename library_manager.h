#pragma once
#include <iostream>
#include <string>
#include <vector>

// Base Book class (Parent)
class Book {
protected:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;
    std::string dateAdded;

public:
    Book(const std::string& t, const std::string& a, const std::string& i,
         bool avail, const std::string& date);

    // Basic getters
    std::string getISBN() const;
    bool isAvailable() const;

    // Borrow and return methods
    void borrowBook();
    void returnBook();

    // virtual for polymorphic calls so child classes can override
    virtual void displayBook() const;
};

// Derived HardcopyBook Class - adds shelf number attribute
class HardcopyBook : public Book {
private:
    std::string shelfNumber;
public:
    HardcopyBook(const std::string& t, const std::string& a, const std::string& i,
                 bool avail, const std::string& date, const std::string& shelf);
    void displayBook() const; // overloaded
};

// Derived EBook Class - adds end-of-license date for digital books
class EBook : public Book {
private:
    std::string endOfLicenseDate;
public:
    EBook(const std::string& t, const std::string& a, const std::string& i,
          bool avail, const std::string& date, const std::string& endLicense);
    void displayBook() const; // overloaded
};

// Sorting algorithmns sorting by ISBN
void bubbleSort(std::vector<Book>& library);
void insertionSort(std::vector<Book>& library);
void selectionSort(std::vector<Book>& library);

// Function overloading for printing library
void printLibrary(const std::vector<Book>& library, const std::string& methodName); // with method name
void printLibrary(const std::vector<Book>& library); // without method name
