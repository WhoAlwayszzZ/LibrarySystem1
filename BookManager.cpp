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

void BookManager::deleteBook(string is_bn) {
    for (int i = 0; i < Books.size(); i++) {
        if (Books[i].getISBN() == is_bn) {
            Books.erase(Books.begin() + i);
            break;
        }
    }
}

void BookManager::changeBookInfo(string is_bn) {
	Book* book = searchByISBN(is_bn);
    if (book == nullptr) {
        cout << "没有找到该书籍" << endl;
        return;
    }
    else {
        char choice;
		cout << "要修改价格吗？（y/n）" << "   原价格为：" << book->getPrice();
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
			cout << "请输入新的价格：";
            double price;
            cin >> price;
			book->setPrice(price);
        }
		else cout << "价格保持不变。" << endl;
        cout << "要修改库存吗？（y/n）" << "   原库存为：" << book->getStock();
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
			cout << "请输入新的库存：";
            int stock;
			cin >> stock;
			book->setStock(stock);
        }
    }
}

   


Book* BookManager::searchByISBN(string isbn) {
    for (int i = 0; i < Books.size(); i++) {
        if (Books[i].getISBN() == isbn) {
            return &Books[i];
        }
    }
    return nullptr;
}

Book* BookManager::searchByTitle(string title) {
    for(int i=0; i < Books.size(); i++) {
        if (Books[i].getTitle() == title) {
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
	ofstream fout(filename.c_str());
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
            << Books[i].getStock() << ""
            << Books[i].getPublishTime() << endl;
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
    string t, a, p, is_bn,pt;
    double pr;
    int s;

    ////当能够读取成功时，循环继续
    //while (fin >> t >> a >> p >> is_bn >> pr >> s >> pt) {
    //    Book tempBook(t, a, p, is_bn, pr, s, pt);
    //    Books.push_back(tempBook);
    //}

    while (getline(fin, t, '|')) {
		fin >> a >> p >> is_bn >> pr >> s >> pt;
		Books.push_back(Book(t, a, p, is_bn, pr, s, pt));
    }
    
    //关掉通道
    fin.close();
    cout << "加载成功，当前共有 " << Books.size() << " 本书。" << endl;
}






void BookManager::displayAllBooks() {
    for (int i = 0; i < Books.size(); i++) {
        Books[i].displayBook();
    }
}

void BookManager::displayTop10Books() {
    for (int i = 0; i < 10 && i < Books.size(); i++) {
        cout << i+1 << ": ";
        Books[i].displayBook();
    }
}



//利用选择排序直接修改Books数组来实现，O(n)
void BookManager::top10ByBorrowedCount() {
    for (int i = 0; i < 10&&i<Books.size(); i++) {//忘了写i<Books.size()了
        int max = Books[i].getBorrowedCount();
        int maxIndex = i;
        for (int j = i + 1; j < Books.size(); j++) {
            if (Books[j].getBorrowedCount() > max) {
                max = Books[j].getBorrowedCount();
                maxIndex = j;
            }
        }
        swap(Books[i], Books[maxIndex]);
    }
}

//利用选择排序，结合getIntTime的时间格式化处理进行排序
void BookManager::top10ByPublishTime() {
    for (int i = 0; i < 10&&i<Books.size(); i++) {
        int latestTime = Books[i].getIntTime();
        int maxIndex = i;
        for (int j = i + 1; j < Books.size(); j++) {
            if (Books[j].getIntTime() > latestTime) {
                latestTime = Books[j].getIntTime();
                maxIndex = j;
            }
        }
        swap(Books[i], Books[maxIndex]);
    }
}