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
	void addUser();
	User* login();//登录，返回值要给User指针
	void save();
	void load();
};





#endif
