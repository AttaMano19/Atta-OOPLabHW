#include <iostream>
#include <vector>

using namespace std;

class Book {
public:
    string bookTitle;
    string bookAuthor;
    string bookIsbn;

    Book(string title, string author, string isbn) : bookTitle(title), bookAuthor(author), bookIsbn(isbn) {}
};

class Catalog {
private:
    vector<Book*> bookCollection;
public:
    void addBookToCatalog(Book* b) {
        bookCollection.push_back(b);
    }

    void removeBookFromCatalog(string isbn) {
        for (auto it = bookCollection.begin(); it != bookCollection.end(); ++it) {
            if ((*it)->bookIsbn == isbn) {
                bookCollection.erase(it);
                break;
            }
        }
    }

    void searchBookInCatalog(string isbn) {
        for (auto b : bookCollection) {
            if (b->bookIsbn == isbn) {
                cout << b->bookTitle << '\n';
                return;
            }
        }
        cout << "Book not found" << '\n';
    }
};

class Library {
private:
    Catalog libraryCatalog;
    vector<Book*> libraryBooks;
    string libraryName;
    string libraryAddress;

public:
    Library(string name, string address) : libraryName(name), libraryAddress(address) {}

    void addBookToLibrary(Book* b) {
        libraryBooks.push_back(b);
        libraryCatalog.addBookToCatalog(b);
    }

    void removeBookFromLibrary(string isbn) {
        for (auto it = libraryBooks.begin(); it != libraryBooks.end(); ++it) {
            if ((*it)->bookIsbn == isbn) {
                libraryBooks.erase(it);
                libraryCatalog.removeBookFromCatalog(isbn);
                break;
            }
        }
    }

    void searchBookInLibraryCatalog(string isbn) {
        libraryCatalog.searchBookInCatalog(isbn);
    }
};

int main() {
    Library localLibrary("City Central Library", "Main Street");

    Book book1("The Great Gatsby", "F. Scott Fitzgerald", "11111");
    Book book2("1984", "George Orwell", "22222");

    localLibrary.addBookToLibrary(&book1);
    localLibrary.addBookToLibrary(&book2);

    localLibrary.searchBookInLibraryCatalog("11111");
    localLibrary.searchBookInLibraryCatalog("22222");
    localLibrary.searchBookInLibraryCatalog("33333");

    return 0;
}
