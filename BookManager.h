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
    void deleteBook(string is_bn);
	void changeBookInfo(string is_bn);

	// 搜索功能
    Book* searchByISBN(string isbn);
	Book* searchByTitle(string title);
    vector<Book*> searchByAuthor(string author);
    void save();
    void load();


    
	void displayAllBooks();
    void displayTop10Books();
	void top10ByBorrowedCount();
    void top10ByPublishTime();

    
};

#endif
