#include "library_manager.h"
#include <iostream>
#include <vector>

void printVector(const std::string& title, const std::vector<Book*>& vec) {
    std::cout << "\n==================== " << title << " ====================\n";
    for (auto* book : vec) {
        book->displayBook();
        std::cout << "-----------------------------------------------------------\n";
    }
}

int main() {

    std::cout << "\n===========================================================\n";
    std::cout << "        APPLICATION TESTING    \n";
    std::cout << "===========================================================\n";

    // 1. Correct Initialisation 

    Book* b1 = new Book(
        "Guns, Germs & Steel",
        "Jared Diamond",
        "9780099302780",          
        true,
        "2024-01-10"
    );

    Book* b2 = new Book(
        "The Silk Roads: A New History of the World",
        "Peter Frankopan",
        "9781408839997",          
        true,
        "2023-12-02"
    );

    Book* b3 = new Book(
        "The Origins of Political Order",
        "Francis Fukuyama",
        "9781846682575",          
        false,
        "2023-11-20"
    );

    std::cout << "\n******** Correct Book Initialisation ********\n";
    b1->displayBook();
    b2->displayBook();
    b3->displayBook();

    // 2. Incorrect Initialisation 
  
    Book* i1 = new Book(
        "A World History??",       
        "Anon.",                   
        "9780-999-XYZ12",          
        true,
        "2024-14-01"               
    );

    Book* i2 = new Book(
        "",                        
        "M",                      
        "00123",                   
        false,
        " "                        
    );

    Book* i3 = new Book(
        "Empires of Earth (Draft)", 
        "44219",                   
        "-9780140440550",          
        true,
        "unk-date"                 
    );

    std::cout << "\n******** Incorrect Book Initialisation ********\n";
    i1->displayBook();
    i2->displayBook();
    i3->displayBook();

    // 3. Vectors for Sorting Tests

    std::vector<Book*> ascendingOrder  = { b1, b2, b3 };
    std::vector<Book*> descendingOrder = { b3, b2, b1 };
    std::vector<Book*> mixedOrder      = { b2, b3, b1 };

    // 4. BEFORE Sorting
    printVector("Ascending Vector (ALREADY Sorted)", ascendingOrder);
    printVector("Descending Vector (BEFORE Sort)", descendingOrder);
    printVector("Mixed Vector     (BEFORE Sort)", mixedOrder);


    // 5. Apply Sorting
    bubbleSort(ascendingOrder);
    bubbleSort(descendingOrder);
    bubbleSort(mixedOrder);

    // 6. AFTER Sorting
    printVector("Ascending Vector (AFTER Sort)", ascendingOrder);
    printVector("Descending Vector (AFTER Sort)", descendingOrder);
    printVector("Mixed Vector     (AFTER Sort)", mixedOrder);

    // 7. Clean Up
    delete b1; delete b2; delete b3;
    delete i1; delete i2; delete i3;

    std::cout << "\n==================== TESTING COMPLETE ====================\n";

    return 0;
}
