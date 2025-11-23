#include "LibrarySystem.h"

int main() {

    LibrarySystem app;

    app.run();

    return 0;
}












/*
int main() {
    //测试UserManager类，将其实例化
    UserManager usermanager;
    //测试addUser，login功能
    usermanager.load();
    usermanager.addUser();
    usermanager.save();
	//此时，多态发力了，login会通过检查数据集里刚刚save进去的用户第一条信息——Admin或Reader，来判断自己应该new哪个子类对象，
	//而User类指针可以接受这个子类对象，从而实现多态
    User * currentUser = usermanager.login();
	if(currentUser!=nullptr) currentUser->showMenu();
    
    return 0;
}
*/






/*
//第二次测试——多态：User，Admin，Reader类
int main() {
    // 1. 创建一个 BookManager (虽然这次测试暂时不用它，但放在这)
    BookManager bookMgr;
    bookMgr.load();

    // 2. 模拟登录：创建一个 User 指针
    // 核心点：父类指针指向子类对象
    User* currentUser = nullptr;

    int loginType;
    cout << "模拟登录：请输入身份 (1.管理员 2.读者): ";
    cin >> loginType;

    if (loginType == 1) {
        // new 一个管理员对象
        currentUser = new Admin("admin", "123456");
    }
    else {
        // new 一个读者对象
        currentUser = new Reader("student", "666666");
    }

    // 3. 见证奇迹的时刻：多态
    // 不管 currentUser 指向的是 Admin 还是 Reader，调用 showMenu 时
    // 程序会自动去调对应子类的那个函数！
    currentUser->showMenu();

    // 测试结束，清理内存
    delete currentUser;

    return 0;
}
*/

/*
* //第一次测试——Book，BookManager，main主循环菜单
int main() {
    BookManager manager;
    
    manager.load();
	bool isRunning = true;

    //处理输入，确定是否合法

    while (isRunning) {
        printMenu();


        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "请输入数字！" << endl;
            //清除错误标志
            cin.clear();
            //丢弃错误输入（回车键cin是不会读取的，然而必须输入回车，cin才会结束等待）
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            // === 录入新书 ===
            string t, a, p, isbn;
            double pr;
            int s;

            // 【关键点】这里要吃掉刚才输入choice时留下的回车
            cin.ignore();

            cout << "请输入书名: ";
            getline(cin, t); // 允许输入带空格的书名

            cout << "请输入作者: ";
            getline(cin, a);

            cout << "请输入出版社: ";
            getline(cin, p);

            cout << "请输入ISBN: ";
            cin >> isbn;

            cout << "请输入价格: ";
            cin >> pr;

            cout << "请输入库存: ";
            cin >> s;

            Book newBook(t, a, p, isbn, pr, s);
            manager.addBook(newBook);
            break;
        }

        case 2: {
            //ISBN搜索
            string is_bn;
            cout << "请输入ISBN: " << endl;
            cin >> is_bn;
            Book* result = manager.searchByISBN(is_bn);
            if (result != nullptr) {
                cout << "找到书籍：" << endl;
                result->displayBook();
            }
            else {
                cout << "没有找到" << endl;
            }
            break;
        }

        case 3: {
            //author搜索
            string author;
            cout << "请输入作者: " << endl;
            vector<Book*> results = manager.searchByAuthor(author);

            if (results.size() != 0) {
                cout << "共找到" << results.size() << "本书籍：" << endl;
                for (int i = 0; i < results.size(); i++) {
                    results[i]->displayBook();
                }
            }
            else {
                cout << "没有找到该作者的书籍" << endl;
            }
            break;
        }

        case 4: {
            //显示所有图书
            manager.displayAllBooks();
            break;
        }

        case 0: {
            cout << "正在保存数据..." << endl;
            manager.save();
            cout << "保存成功，程序退出。" << endl;
            isRunning = false;
            break;
        }

        default: {
            cout << "请输入有效数字（0~4）" << endl;
            break;
        }
      }
		system("pause"); 
    }
    return 0;
}


//void printMenu();

void printMenu(){
    system("cls");//可清屏（windows专用）
    cout << "\n===============================" << endl;
    cout << "    H大学图书馆管理系统 v1.0    " << endl;
    cout << "===============================" << endl;
    cout << "  1. 录入新书 (Add Book)" << endl;
    cout << "  2. ISBN搜索 (Search by ISBN)" << endl;
    cout << "  3. 作者搜索 (Search by Author)" << endl;
    cout << "  4. 显示所有图书 (Display All)" << endl; 
    cout << "  0. 保存并退出 (Save & Exit)" << endl;
    cout << "===============================" << endl;
    cout << "请输入选项: ";
}
*/




//int main() {
//
//
//    return 0;
//}