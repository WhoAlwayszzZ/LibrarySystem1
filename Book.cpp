#include "Book.h" 

// 默认构造函数
Book::Book() {}

// 全参构造函数实现
Book::Book(string t, string a, string p, string i, double pr, int s, string pt)
    : title(t), author(a), publisher(p), ISBN(i), price(pr), stock(s), borrowedCount(0), publishTime(pt) {}

// Get函数实现
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getPublisher() const { return publisher; }
string Book::getISBN() const { return ISBN; }
double Book::getPrice() const { return price; }
int Book::getStock() const { return stock; }
int Book::getBorrowedCount() const { return borrowedCount; }
string Book::getPublishTime() const { return publishTime; }

// Set函数实现
void Book::setStock(int newStock) { stock = newStock; }
void Book::setBorrowedCount(int newBorrowedCount) { borrowedCount = newBorrowedCount; }
void Book::setPrice(double newPrice) { price = newPrice; }

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
    cout << "标题: " << title << " | 作者: " << author
         << " | 出版社: " << publisher << endl
        << " | ISBN: " << ISBN 
		<< " | 库存: " << stock << " | 借阅次数: " << borrowedCount << " | 出版时间: " << publishTime
		<< " | 价格: " << price << " 元" << endl;
}


int Book::getIntTime() const {
    int intTime = 0,year = 0,month =0,day=0,i = 0;
    while (publishTime[i] != '.') {
        year *= 10;
        year += publishTime[i] - '0';
        i++;
    }
    i++;
    while (publishTime[i] != '.') {
        month *= 10;
        month += publishTime[i] - '0';
        i++;
    }
    i++;
    while (publishTime[i] != '\0') {
        day *= 10;
        day += publishTime[i] - '0';
        i++;
    }
    intTime = year*10000 + month*100 + day;
    return intTime;
}