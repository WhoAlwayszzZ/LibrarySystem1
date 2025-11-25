#include "User.h"
#include "BookManager.h"
#include "UserManager.h"
#include "BookRankingList.h"

User::User(string u, string p) {
	userName = u;
	password = p;
}

User::~User() {}

//User类的成员函数
string User::getName() const {
	return userName;
}

string User::getPassword() const {
    return password;
}

bool User::checkPassword() const {
	return 1;//password==input_password;
}

void User::printInfo () const {
    //此处不能使用纯虚函数getRole()——显然，因为父类是没有纯虚函数定义的
    cout << "身份" << "用户名: " << userName << ", 密码: " << password << endl;
}

void User::setPassword(string newP) {
	password = newP;
}



//Admin类的成员函数
//全参构造函数
Admin::Admin(string u, string p) : User(u, p) {}//调用基类构造函数初始化基类部分，这里的写法是？
//重写纯虚函数
void Admin::operate(BookManager& bookmanager, UserManager& usermanager, BookRankingList &bookrankinglist) {

    while (true) {

        //1.展示菜单
        cout << "\n==== 管理员菜单 (" << userName << ") ====" << endl;
        cout << "1. 添加图书" << endl;
        cout << "2. 删除图书" << endl;
        cout << "3. 修改图书 (待开发)" << endl;
        cout << "4. 删除用户" << endl;
        cout << "5. 显示所有图书" << endl;
		cout << "6. 查看图书排行榜" << endl;
        cout << "0. 注销 (Logout)" << endl;
        cout << "==============================" << endl;
        cout << "请选择操作: ";


        int choice;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "请输入数字！" << endl;
            continue;
        }

        if (choice == 0) break;

        switch (choice) {
        //添加图书
        case 1: {
            string t, a, p, is_bn, pt;
            double pr;
            int s;
            cout << "请输入图书的名称： ";
			cin >> t;
			cout << "请输入图书的作者： ";
			cin >> a;
			cout << "请输入图书的出版社： ";
			cin >> p;
			cout << "请输入图书的ISBN： ";
			cin >> is_bn;
			cout << "请输入图书的价格： ";
            cin >> pr;
			cout << "请输入图书的库存： ";
            cin >> s;
            cout << "请输入图书的出版时间： ";
            cin >> pt;
            Book book(t, a, p, is_bn, pr, s, pt);
			bookmanager.addBook(book);
			cout << "添加成功！" << endl;
            break;
        }
        //删除图书（待）
        case 2: {
            string is_bn;
            cout << "请输入要删除的图书的ISBN：";
            cin >> is_bn;
            bookmanager.deleteBook(is_bn);
            cout << "已删除该书！" << endl;
            break;
        }
        //修改图书
        case 3: {

            break;
        }
        //删除用户
        case 4: {
            string u, p;
            cout << "请输入要删除的用户的用户名：";
            cin >> u;
            cout << "请输入要删除的用户的密码：";
            cin >> p;
            if (usermanager.deleteUser(u, p)) cout << "已删除该用户！" << endl;
            else cout << "删除失败，该用户不存在！" << endl;;
            break;
        }
        //显示所有图书
        case 5: {
            cout << "图书馆现有图书如下： " << endl;
            bookmanager.displayAllBooks();
            break;
        }
        case 6: {
			bookrankinglist.run();
            break;
        }
        default: {
            cout << "请输入有效数字（0~5）！" << endl;
            break;
        }
        }
    }
}

string Admin::getRole() {
	return "Admin";
}



//Reader类的成员函数

Reader::Reader(string u, string p) : User(u, p) {}//调用基类构造函数初始化基类部分，这里的写法是？

void Reader::operate(BookManager& bookmanager, UserManager& usermanager, BookRankingList& bookrankinglist) {
    int choice;
    while (true) {

        //打印菜单
        cout << "\n==== 读者菜单 (" << userName << ") ====" << endl;
        cout << "1. 搜索图书 (ISBN)" << endl;
        cout << "2. 搜索图书 (作者)" << endl;
        cout << "3. 借阅图书" << endl;
        cout << "4. 归还图书" << endl;
        cout << "5. 查看我的借阅 (待开发)" << endl;
		cout << "6. 进入图书排行榜" << endl;
        cout << "0. 注销 (Logout)" << endl;
        cout << "============================" << endl;
        cout << "请选择操作: ";

        
        cin >> choice;
        if (choice == 0) break;

        switch (choice) {
        //搜索图书（ISBN）
        case 1: {
            string is_bn;
            cout << "请输入图书的ISBN：";
            cin >> is_bn;
            Book* BookFound = bookmanager.searchByISBN(is_bn);
            if (BookFound == nullptr) cout << "抱歉，没有找到该书" << endl;
            else {
                cout << "已找到：";
                BookFound->displayBook();
            }
            break;
        }
        //搜索图书（作者）
        case 2: {
            string author;
            cout << "请输入作者姓名：";
            cin >> author;
            vector<Book*> BooksFound = bookmanager.searchByAuthor(author);
            if (!BooksFound.empty()) {
                cout << "已找到" << BooksFound.size() << "本书籍：" << endl;
                for (int i = 0; i < BooksFound.size(); i++) {
                    BooksFound[i]->displayBook();
                }
            }
            else cout << "抱歉，暂无该作者书籍" << endl;
            break;
        }
        //借阅图书
        case 3: {
            string is_bn;
            cout << "请输入要借阅的图书的ISBN：";
            cin >> is_bn;
            Book* BookFound = bookmanager.searchByISBN(is_bn);
            if (BookFound == nullptr) cout << "抱歉，没有找到该书，请检查ISBN输入" << endl;
            else {
                if (BookFound->borrowBook()) {
                    cout << "已经成功借阅：" << endl;
                    BookFound->displayBook();
                }
                else cout << "借阅失败，该书库存为0" << endl;
            }
            break;
        }
        //归还图书
        case 4: {
            string is_bn;
            cout << "请输入要归还的图书的ISBN：";
            cin >> is_bn;
            Book* BookFound = bookmanager.searchByISBN(is_bn);
            if (BookFound == nullptr) cout << "抱歉，没有找到该书，请检查ISBN输入是否正确" << endl;
            else {
                BookFound->returnBook();
            }
            break;
        }
        //查看我的借阅（待开发）
        case 5: {
            cout << "该功能正在开发中，敬请期待！" << endl;
			break;
        }

        case 6: {
            bookrankinglist.run();
            break;
        }
    } 
}
}

string Reader::getRole() {
    return "Reader";
}