// BookManager.cpp
#include "BookManager.h"
#include <fstream>
#include <iostream>

using namespace std;

//BookManager::的前缀，就相当于把它们写在了class的大括号里面，为成员函数定义

// 构造函数：初始化文件名并加载数据
BookManager::BookManager() {
    filename = "books.txt";
    // 可以选择在构造时自动加载，也可以手动调用 load
    // load(); 
}

void BookManager::addBook(Book book) {
    Books.push_back(book);
}

Book* BookManager::searchByISBN(string isbn) {
    for (int i = 0; i < Books.size(); i++) {
        if (Books[i].getISBN() == isbn) {
            return &Books[i];
        }
    }
    return nullptr;
}

vector<Book*> BookManager::searchByAuthor(string author) {
    vector<Book*> BooksFound;
    for (int i = 0; i < Books.size(); i++) {
        if (Books[i].getAuthor() == author) {
            BooksFound.push_back(&Books[i]);
        }
    }
    return BooksFound;
}

void BookManager::save() {
	ofstream fout(filename.c_str(), ios::app);//这里ios::app是追加写入模式，防止覆盖原有数据
    if (!fout.is_open()) {
        cout << "保存失败：无法打开文件" << endl;
        return;
    }

    for (int i = 0; i < Books.size(); i++) {
        fout << Books[i].getTitle() << " " 
             << Books[i].getAuthor() << " " 
             << Books[i].getPublisher() << " " 
             << Books[i].getISBN() << " " 
             << Books[i].getPrice() << " " 
             << Books[i].getStock() << endl;
    }
    fout.close();
    cout << "保存成功" << endl;
}

void BookManager::load() {
	//如果不存在该文件，则创建该文件，若存在，则打开该文件进行读取
    ifstream fin(filename.c_str());//用来返回string类型中包含的指向c风格字符串的指针(char *)，以兼容只接受
	//char * 类型的一些函数 
    if (!fin.is_open()) {
		cout << "首次启动中，已创建数据文件。" << endl;
        return;
    }

	//此处不能直接Book.title等，因为title是私有属性；借用临时变量
    string t, a, p, is_bn;
    double pr;
    int s;

    //当能够读取成功时，循环继续，非常安全
    while (fin >> t >> a >> p >> is_bn >> pr >> s) {
        Book tempBook(t, a, p, is_bn, pr, s);
        Books.push_back(tempBook);
    }
    
    //关掉I/O流
    fin.close();
    cout << "加载成功，当前共有 " << Books.size() << " 本书。" << endl;
}


void BookManager::displayAllBooks() {
    for (int i = 0; i < Books.size(); i++) {
        Books[i].displayBook();
    }
}