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
    Book(const std::string& t,
         const std::string& a,
         const std::string& i,
         bool avail,
         const std::string& date);

    std::string getISBN() const;
    bool isAvailable() const;

    void borrowBook();
    void returnBook();

    // Virtual so derived classes can extend the output
    virtual void displayBook() const;

    virtual ~Book() = default;
    void setBookDetails(const std::string& t,
        const std::string& a,
        const std::string& i,
        bool avail,
        const std::string& date);
};

// HardcopyBook: physical book with shelf number
class HardcopyBook : public Book {
private:
    std::string shelfNumber;   // e.g. "909 HAR"

public:
    HardcopyBook(const std::string& t,
                 const std::string& a,
                 const std::string& i,
                 bool avail,
                 const std::string& date,
                 const std::string& shelf);

    void displayBook() const override;
};

// EBook: digital book with end-of-license date
class EBook : public Book {
private:
    std::string endOfLicenseDate; // e.g. "2026-12-01"

public:
    EBook(const std::string& t,
          const std::string& a,
          const std::string& i,
          bool avail,
          const std::string& date,
          const std::string& endLicense);

    void displayBook() const override;
};

// Sorting functions (work on vector of pointers)
void bubbleSort(std::vector<Book*>& library);
void insertionSort(std::vector<Book*>& library);
void selectionSort(std::vector<Book*>& library);

// Print library. If methodName is empty, just prints "Library Collection".
void printLibrary(const std::vector<Book*>& library,
                  const std::string& methodName = "");
