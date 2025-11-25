#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "User.h"
#include <vector>
#include <fstream>

class UserManager {
private:
	vector<User*> Users;
	string filename;
public:
	UserManager();
	~UserManager();

	//查用户
	void displayAllUsers();
	User* searchByName(string u);
	//改用户
	void changeUserPassword(string u, string newP);
	//增删用户
	void addUser();
	bool deleteUser(string u, string p);


	User* login();//登录，返回值要给User指针
	void save();
	void load();
	bool isUserExist(string u);
	void registerUser(string u,string p,int role);

};





#endif
