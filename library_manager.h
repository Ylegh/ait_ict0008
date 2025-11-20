#pragma once
#include <iostream>
#include <string>
#include <vector>

// Base Book class
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

    std::string getISBN() const;
    bool isAvailable() const;

    void borrowBook();
    void returnBook();
    virtual void displayBook() const; // virtual for polymorphic calls if needed
};

// Derived HardcopyBook
class HardcopyBook : public Book {
private:
    std::string shelfNumber;
public:
    HardcopyBook(const std::string& t, const std::string& a, const std::string& i,
                 bool avail, const std::string& date, const std::string& shelf);
    void displayBook() const; // overloaded
};

// Derived EBook
class EBook : public Book {
private:
    std::string endOfLicenseDate;
public:
    EBook(const std::string& t, const std::string& a, const std::string& i,
          bool avail, const std::string& date, const std::string& endLicense);
    void displayBook() const; // overloaded
};

// Sorting function declarations
void bubbleSort(std::vector<Book>& library);
void insertionSort(std::vector<Book>& library);
void selectionSort(std::vector<Book>& library);

// Function overloading for printing library
void printLibrary(const std::vector<Book>& library, const std::string& methodName);
void printLibrary(const std::vector<Book>& library); // no method name
