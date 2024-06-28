#include <iostream>
#include <vector>

namespace Lib
{
    class Book {
        private:
            std::string title;
            std::string author;
            int publicationYear;
            bool status;

        public:
            Book(std::string t, std::string a, int year, int st) : title(t), author(a), publicationYear(year), status(st) { }

            std::string getTitle() const { return title; }
            std::string getAuthor() const { return author; }
            int getPublicationYear() const { return publicationYear; }
            bool getStatus() const { return status; }

            void borrow() {
                if (status) {
                    status = false;
                } else {
                    throw std::runtime_error("Le livre n'est pas disponible a l'emprunt.");
                }
            }

            void returnBook() {
                if (!status) {
                    status = true;
                } else {
                    throw std::runtime_error("Le livre est toujours disponible a l'emprunt.");
                }
            }

    };

    class Library {
        private:
            std::vector<Book> books;
            std::string name;

        public:
            Library(const std::string & n) : name(n) { }

            void addBook(const Book& book) {
                books.push_back(book);
            }

            void displayBooks() {
                std::cout << "Livres disponibles dans la bibliotheque : " << std::endl;
                for (const auto& book: books) {
                    std::cout << book.getTitle() << " par " << book.getAuthor() << std::endl;
                }
            }

            void borrowBook(const std::string& title) {
                bool bookFound = false;
                for (auto& book: books) {
                    if (book.getTitle() == title) {
                        book.borrow();
                        bookFound = true;
                        break;
                    }
                }
                if (!bookFound) {
                    throw std::runtime_error("Le livre n'a pas ete trouve.");
                }
            }

            void returnBook(const std::string& title) {
                bool bookFound = false;
                for (auto& book: books) {
                    if (book.getTitle() == title) {
                        book.returnBook();
                        bookFound = true;
                        break;
                    }
                }
                if (!bookFound) {
                    throw std::runtime_error("Le livre n'a pas ete trouve.");
                }
            }

            int getTotalNumberBooks() const {
                return books.size();
            }

            int getNumberBooksAvailable()  const {
                int i = 0;
                for (const auto& book: books) {
                    if (book.getStatus()) 
                        i++;   
                }
                return i;
            }
    };

}; // namespace Library


int main() {
    using namespace Lib;

    Book b1("Ving mille lieux sous les mers", "Jules Vernes", 1970, true);
    Book b2("Le Hobbit", "JRRR Tolkien", 1925, true);
    Book b3("L'Encyclopedie", "Diderot et d'Alembert", 1600, true);

    Library library("Bibliotheque de village");

    try {
        library.addBook(b1);
        library.addBook(b2);
        library.addBook(b3);

        library.borrowBook("Ving mille lieux sous les mers");
        library.borrowBook("Le Hobbit");
        library.returnBook("Le Hobbit");

        std::cout << "Total : " << library.getTotalNumberBooks() << " - dispo : " << library.getNumberBooksAvailable() << std::endl;

    } catch (const std::runtime_error& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}