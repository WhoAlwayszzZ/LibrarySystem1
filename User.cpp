#include "User.h"



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



//Admin类的成员函数
//全参构造函数
Admin::Admin(string u, string p) : User(u, p) {}//调用基类构造函数初始化基类部分，这里的写法是？
//重写纯虚函数
void Admin::showMenu() {
    cout << "\n==== 管理员菜单 (" << userName << ") ====" << endl;
    cout << "1. 添加图书" << endl;
    cout << "2. 删除图书 (待开发)" << endl; 
    cout << "3. 修改图书 (待开发)" << endl;
    cout << "4. 用户管理 (待开发)" << endl; 
    cout << "5. 显示所有图书" << endl;
    cout << "0. 注销 (Logout)" << endl;
    cout << "==============================" << endl;
    cout << "请选择操作: ";
}

string Admin::getRole() {
	return "Admin";
}



//Reader类的成员函数

Reader::Reader(string u, string p) : User(u, p) {}//调用基类构造函数初始化基类部分，这里的写法是？

void Reader::showMenu() {
    cout << "\n==== 读者菜单 (" << userName << ") ====" << endl;
    cout << "1. 搜索图书 (ISBN)" << endl; 
    cout << "2. 搜索图书 (作者)" << endl; 
    cout << "3. 借阅图书" << endl;        
    cout << "4. 归还图书" << endl;        
    cout << "5. 查看我的借阅 (待开发)" << endl;
    cout << "0. 注销 (Logout)" << endl;
    cout << "============================" << endl;
    cout << "请选择操作: ";
}

string Reader::getRole() {
    return "Reader";
}