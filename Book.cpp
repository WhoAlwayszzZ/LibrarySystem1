#include "Book.h" 

// 默认构造函数
Book::Book() {}

// 全参构造函数实现
Book::Book(string t, string a, string p, string i, double pr, int s)
    : title(t), author(a), publisher(p), ISBN(i), price(pr), stock(s), borrowedCount(0) {}

// Get函数实现
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getPublisher() const { return publisher; }
string Book::getISBN() const { return ISBN; }
double Book::getPrice() const { return price; }
int Book::getStock() const { return stock; }
int Book::getBorrowedCount() const { return borrowedCount; }

// Set函数实现
void Book::setStock(int newStock) { stock = newStock; }
void Book::setBorrowedCount(int newBorrowedCount) { borrowedCount = newBorrowedCount; }

// 业务功能实现
bool Book::borrowBook() {
    if (stock > 0) {
        stock--;
        borrowedCount++;
        return true;
    }
    else return false;
}

void Book::returnBook() {
    stock++;
}

void Book::displayBook() {
    cout << "Title: " << title << " | Author: " << author
         << " | Publisher: " << publisher << " | ISBN: " << ISBN 
         << " | Stock: " << stock << endl;
}
