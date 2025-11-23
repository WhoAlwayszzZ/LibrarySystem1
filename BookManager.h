// BookManager.h
#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H

#include "Book.h" // 因为要用到 Book 对象，所以必须包含它
#include <vector>
#include <string>

using namespace std;

class BookManager {
private:
    vector<Book> Books;
    string filename; // 把文件名变成变量，更灵活

public:
    BookManager(); 

    void addBook(Book book);
    Book* searchByISBN(string isbn);
    vector<Book*> searchByAuthor(string author);
    void save();
    void load();
	void displayAllBooks();
};

#endif
