#include "UserManager.h"


UserManager::UserManager() {
	//初始化文件名
	filename = "users.txt";
}

UserManager::~UserManager() {
	//释放内存
	for (int i = 0; i < Users.size(); i++) {
		delete Users[i];//前面还要加[]吗
	}
	Users.clear();
}

void UserManager::addUser(){
	//添加用户
	int roleType;
	string u, p;
	cout << "请输入用户类型： (1.管理员 2.读者): ";
	cin >> roleType;
	cout << "请输入用户名： ";
	cin >> u;
	cout << "请输入密码： ";
	cin >> p;
	User* newUser = nullptr;
	if(roleType==1) newUser = new Admin (u, p);
	else newUser = new Reader(u, p);
	Users.push_back(newUser);
}

User* UserManager::login() {
	string u, p;
	cout << "请输入用户名： ";
	cin >> u;
	cout << "请输入密码： ";
	cin >> p;
	for (int i = 0; i < Users.size(); i++) {
		if(u==Users[i]->getName() && p == Users[i]->getPassword()) {
			return Users[i];
		}
	}
	return nullptr;
}

void UserManager::save() {
	ofstream fout(filename.c_str(),ios::app);
	if (!fout.is_open()) {
		return;
	}
	for (int i = 0; i < Users.size(); i++) {
		fout << Users[i]->getRole() << ' ' << Users[i]->getName() << ' ' << Users[i]->getPassword() << endl;
	}
	fout.close();
	cout << "用户数据保存成功！" << endl;
}

//不知道为什么自己把逻辑写成没有cout用户提示的addUser了
//逻辑：读取数据集中的数据，并根据读取到的数据决定创建什么对象
void UserManager::load() {
	ifstream fin(filename.c_str());
	if (!fin.is_open()) {
		return;
	}
	string role, u, p;
	while (fin >> role >> u >> p) {
		if (role == "Admin") {
			User* newUser = new Admin(u, p);
			Users.push_back(newUser);
		}
		else if (role == "Reader") {
			User* newUser = new Reader(u, p);
			Users.push_back(newUser);
		}
	}
	fin.close();
	cout << "用户数据加载成功！共有" << Users.size() << "个用户。" << endl;
}