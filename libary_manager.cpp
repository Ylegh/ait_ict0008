#include "library_manager.h"
#include <vector>
#include <iostream>

// Constructor with parameters
Book::Book(const std::string& title,
    const std::string& author,
    const std::string& ISBN,
    bool available,
    const std::string& dateAdded)
{
        this->title = title;
        this->author = author;
        this->ISBN = ISBN;
        this->available = available;
        this->date = dateAdded;
}

// Method to update book details 
void Book::setBookDetails(const std::string& title,
    const std::string& author,
    const std::string& ISBN,
    bool available,
    const std::string& dateAdded)
{
    this->title = title;         // assigns the parameter 'title' to the object's 'title' member
    this->author = author;       // assigns the parameter 'author' to the object's 'author' member
    this->ISBN = ISBN;           // assigns the parameter 'ISBN' to the object's 'ISBN' member
    this->available = available; // assigns the parameter 'available' to the object's 'available' member
    this->date = dateAdded;      // assigns the parameter 'dateAdded' to the object's 'date' member
}

// Method to display book details
void Book::displayBookDetails() const
{
    std::cout << "Book title: " << title << " | Author: " << author << " | ISBN: " << ISBN << " | Availability: " << available << std::endl;
}

// Method to borrow a book
void Book::borrowBook()
{
    if (available== true) {
        available = false; 
    }
    else {
        std::cout << title << " is unavailable.";
    };

}

// Method to return a book
void Book::returnBook()
{
    if (available == false) {
        available = true;
    }
    else {
        std::cout << title << " is already available";
    }
}

// Method to sort book data
void Book::sortBookData(std::vector<Book>& books)
{
    // To be implemented
}

std::string Book::getISBN() const {
    return ISBN;
}



// to be implemented into seperate cpp file

int main() {
    // Initialise library with 5 books
    std::vector<Book> library;

    // Populate the library
    library.push_back(Book("Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "9780062316097", true, "2018-02-10"));
    library.push_back(Book("Guns, Germs, and Steel", "Jared Diamond", "9780393354324", true, "1997-03-01"));
    library.push_back(Book("The Silk Roads: A New History of the World", "Peter Frankopan", "9781101912379", true, "2015-08-27"));
    library.push_back(Book("A People's History of the United States", "Howard Zinn", "9780062397348", true, "2015-01-15"));
    library.push_back(Book("The Wright Brothers", "David McCullough", "9781476728759", true, "2015-05-05"));


    int choice;
    std::string inputISBN;
    // Ask user for which functionality they want to use
    std::cout << "Library System\n";
    std::cout << "1. Borrow Book\n";
    std::cout << "2. Return Book\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cout << "Enter the ISBN: ";
    std::cin >> inputISBN;

    bool found = false;
    // Loop over the catalogue and see if the input ISBN is there
    for (Book &book : library) {
        if (book.getISBN() == inputISBN) {
            found = true;

            if (choice == 1) {
                book.borrowBook();
            }
            else if (choice == 2) {
                book.returnBook();
            }
            else {
                std::cout << "Invalid choice.\n";
            }
            break;
        }
    }

    if (!found) {
        std::cout << "Book not found in the library.\n";
    }

    return 0;
}