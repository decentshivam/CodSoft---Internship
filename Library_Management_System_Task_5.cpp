#include <iostream>
#include <vector>
#include <string>

struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    bool isCheckedOut;
};

void addBook(std::vector<Book>& library) {
    std::string title, author, ISBN;
    std::cout << "Enter book title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter book author: ";
    std::getline(std::cin, author);
    std::cout << "Enter book ISBN: ";
    std::getline(std::cin, ISBN);
    library.push_back({title, author, ISBN, false});
    std::cout << "Book added to the library!" << std::endl;
}

void searchBook(const std::vector<Book>& library) {
    std::string searchTerm;
    std::cout << "Enter title, author, or ISBN to search: ";
    std::cin.ignore();
    std::getline(std::cin, searchTerm);

    for (const auto& book : library) {
        if (book.title == searchTerm || book.author == searchTerm || book.ISBN == searchTerm) {
            std::cout << "Book Found:\nTitle: " << book.title << "\nAuthor: " << book.author << "\nISBN: " << book.ISBN
                      << "\nStatus: " << (book.isCheckedOut ? "Checked Out" : "Available") << std::endl;
            return;
        }
    }
    std::cout << "Book not found." << std::endl;
}

void checkOutBook(std::vector<Book>& library) {
    std::string ISBN;
    std::cout << "Enter ISBN of the book to check out: ";
    std::cin.ignore();
    std::getline(std::cin, ISBN);

    for (auto& book : library) {
        if (book.ISBN == ISBN) {
            if (!book.isCheckedOut) {
                book.isCheckedOut = true;
                std::cout << "Book checked out successfully!" << std::endl;
            } else {
                std::cout << "Book is already checked out." << std::endl;
            }
            return;
        }
    }
    std::cout << "Book not found." << std::endl;
}

void returnBook(std::vector<Book>& library) {
    std::string ISBN;
    std::cout << "Enter ISBN of the book to return: ";
    std::cin.ignore();
    std::getline(std::cin, ISBN);

    for (auto& book : library) {
        if (book.ISBN == ISBN) {
            if (book.isCheckedOut) {
                book.isCheckedOut = false;
                std::cout << "Book returned successfully!" << std::endl;
            } else {
                std::cout << "Book was not checked out." << std::endl;
            }
            return;
        }
    }
    std::cout << "Book not found." << std::endl;
}

int main() {
    std::vector<Book> library;
    int choice;

    do {
        std::cout << "\n1. Add Book\n2. Search Book\n3. Check Out Book\n4. Return Book\n5. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch(choice) {
            case 1: addBook(library); break;
            case 2: searchBook(library); break;
            case 3: checkOutBook(library); break;
            case 4: returnBook(library); break;
            case 5: std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid option. Try again.\n"; break;
        }
    } while (choice != 5);

    return 0;
}
