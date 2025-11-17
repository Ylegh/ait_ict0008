#pragma once
#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;
    std::string date;

public:
    Book(const std::string& title, const std::string& author,
        const std::string& ISBN, bool available, const std::string& dateAdded);

    // Member functions
    void setBookDetails(const std::string& title, const std::string& author,
        const std::string& ISBN, bool available, const std::string& dateAdded);
    void displayBookDetails() const;
    void borrowBook();
    void returnBook();
    

    static void sortBookData(std::vector<Book>& books);
    std::string getISBN() const;
};