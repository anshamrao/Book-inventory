#include <iostream>
#include <vector>
#include <algorithm>

class Book {
private:
    std::string title;
    std::string author;
    int year;
    std::string isbn;

public:
    // Constructors
    Book() : title(""), author(""), year(0), isbn("") {}
    Book(std::string title, std::string author, int year, std::string isbn)
        : title(title), author(author), year(year), isbn(isbn) {}

    // Getters
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return year; }
    std::string getISBN() const { return isbn; }

    // Setters
    void setTitle(std::string newTitle) { title = newTitle; }
    void setAuthor(std::string newAuthor) { author = newAuthor; }
    void setYear(int newYear) { year = newYear; }
    void setISBN(std::string newISBN) { isbn = newISBN; }

    // Display book details
    void display() const {
        std::cout << "Title: " << title << "\nAuthor: " << author
                  << "\nYear: " << year << "\nISBN: " << isbn << std::endl;
    }
};

class BookInventory {
private:
    std::vector<Book> books;

public:
    // CRUD operations

    // Create
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Read
    void displayAllBooks() const {
        for (const Book& book : books) {
            book.display();
            std::cout << "---------------------\n";
        }
    }

    // Update
    void updateBook(const std::string& isbn, const Book& newBook) {
        auto it = std::find_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getISBN() == isbn;
        });

        if (it != books.end()) {
            *it = newBook;
            std::cout << "Book with ISBN " << isbn << " updated successfully.\n";
        } else {
            std::cout << "Book with ISBN " << isbn << " not found.\n";
        }
    }

    // Delete
    void removeBook(const std::string& isbn) {
        auto it = std::remove_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getISBN() == isbn;
        });

        if (it != books.end()) {
            books.erase(it, books.end());
            std::cout << "Book with ISBN " << isbn << " removed successfully.\n";
        } else {
            std::cout << "Book with ISBN " << isbn << " not found.\n";
        }
    }
};

int main() {
    BookInventory inventory;

    // Adding books
    inventory.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925, "978-3-16-148410-0"));
    inventory.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960, "978-0-06-112008-4"));
    inventory.addBook(Book("1984", "George Orwell", 1949, "978-0-452-28423-4"));

    // Displaying all books
    std::cout << "All Books in Inventory:\n";
    inventory.displayAllBooks();

    // Updating a book
    inventory.updateBook("978-0-452-28423-4", Book("1984", "George Orwell", 1949, "978-0-452-28423-4"));

    // Displaying all books after update
    std::cout << "\nAll Books in Inventory after update:\n";
    inventory.displayAllBooks();

    // Removing a book
    inventory.removeBook("978-3-16-148410-0");

    // Displaying all books after removal
    std::cout << "\nAll Books in Inventory after removal:\n";
    inventory.displayAllBooks();

    return 0;
}
