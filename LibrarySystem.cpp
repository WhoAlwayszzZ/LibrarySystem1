#include "LibrarySystem.h"

LibrarySystem::LibrarySystem() {
	UserManager * usermanagerP = new UserManager;
	usermanager = *usermanagerP;
	BookManager* bookmanagerP = new BookManager;
	bookmanager = *bookmanagerP;
	usermanager.load();
	bookmanager.load();
	BookRankingList* bookrankinglistP = new BookRankingList(bookmanager);
	bookrankinglist = BookRankingList(bookmanager);
}


void LibrarySystem::showMainMenu() {
	system("cls"); // Windows 清屏
	cout << "\n=======================================" << endl;
	cout << "    H大学图书馆管理系统 (V2.0 Pro)    " << endl;
	cout << "=======================================" << endl;
	cout << "  1. 登录 (Login)" << endl;
	cout << "  2. 注册读者账号 (Register)" << endl;
	cout << "  0. 退出系统 (Exit)" << endl;
	cout << "=======================================" << endl;
	cout << "请输入选项: ";
}



void LibrarySystem::run() {
	int choice;
	User* currentUser = nullptr;
	while (true) {
		//if (currentUser != nullptr) break;
		showMainMenu();
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			cout << "请输入数字！" << endl;
			system("pause");
			continue;
		}
		switch (choice) {
		//登录
		case 1: {
			currentUser = handleLogin();
			if (currentUser != nullptr) currentUser->operate(bookmanager,usermanager,bookrankinglist);
			break;
		}
		case 2: {
			handleRegister();
			system("pause");
			break;
		}
		case 0: {
			bookmanager.save();
			usermanager.save();
			cout << "已退出系统" << endl;
			system("pause");
			return;
		}
		default: {
			cout << "请输入有效数字！（0~2）" << endl;
			system("pause");
			break;
		}
		}
	}
	//只有进行了1login后，才会继续进行到这里
	currentUser->operate(bookmanager,usermanager,bookrankinglist);
}

void LibrarySystem::handleRegister() {
	int i;
	string u, p;
	cout << "请输入要注册的用户类型（1.管理员2.读者）";
	cin >> i;
	while (true) {
	cout << "请输入用户名：";
	cin >> u;
	if (!usermanager.isUserExist(u)) break;
	else cout << "该名称已被使用！" << endl;
	system("pause");
	}

	cout << "请输入密码：";
	cin >> p;

	usermanager.registerUser(u, p, i);
	cout << "已经成功注册，欢迎您，" << u << "!" << endl;
	

}

User *  LibrarySystem::handleLogin() {
	User * user = usermanager.login();
	if (user == nullptr) {
		cout << "登录失败，请检查账号及密码是否输入正确" << endl;
	}
	else cout << "登录成功！" << endl;
	return user;
}