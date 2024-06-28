
#include <vector>

namespace Library {

enum Available {
    Yes,
    No
};

class Book {
    private:
        char*       title[100];
        char*       autor[100];
        int         year;
        Available   available;

        Book(char* title, char* autor, int year) : title{title}, autor{autor}, year{year} {};

    public:
        bool get_book() {
            bool is_available = false;
            if (available == Yes)
            {
                available = No;
                is_available = true;
            }
            return is_available;
        };
};

class Library {
    private:
        Book    Book_List[1000];
        int     book_list_index = 0;

        // Library (Book book_list[], int size_of_book_list) {
        //     for (int i=0 ; i < size_of_book_list; i++){
        //         Book_List[i] = book_list[i];
        //     }
        //     book_list_index = size_of_book_list - 1;
        // };

        Library() = default;

    public:
        bool add_book(Book book) {
            bool book_addind = false;
            if (book_list_index < 1000){
                book_list_index += 1;
                Book_List[book_list_index] = book;
                book_addind = true;
            }
            return book_addind;
        };
};

}


// Your First C++ Program

#include <iostream>

int main() {
    std::cout << "Hello World!";

    return 0;
}