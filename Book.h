#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    string ISBN;
    double price;
    int stock;
    int borrowedCount;
    string publishTime;

public:
    // 构造函数声明
    //0参构造函数，可以在vector<Book> Books时发挥用处
    Book();
    //全参构造函数，使用初始化列表
    Book(string t, string a, string p, string i, double pr, int s, string pt);

    // Get函数
    string getTitle() const;
    string getAuthor() const;
    string getPublisher() const;
    string getISBN() const;
    double getPrice() const;
    int getStock() const;
    int getBorrowedCount() const;
	string getPublishTime() const;

    // Set函数
    void setStock(int newStock);
    void setBorrowedCount(int newBorrowedCount);
	void setPrice(double newPrice);

    // 
    bool borrowBook();
    void returnBook();
    void displayBook();

    //处理时间格式，用来排序
    int getIntTime() const;
};

#endif
