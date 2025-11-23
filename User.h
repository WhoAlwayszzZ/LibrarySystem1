#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <limits>
#include "Book.h"
using namespace std;


class BookManager;//前置声明，用在.h文件中，这样能够使得User.h在不需要包含BookManager.h的前提下声明带有BookManager参数的函数
class UserManager;//接上一行——而BookManager.h的包含只需要在User.cpp中进行（※）

class User {
protected:
	string userName;
	string password;
public:
	//全参构造函数
	User(string u, string p);//用来帮助子类构造函数初始化基类部分
	//虚析构函数
	virtual ~User();//析构函数不能传入参数
	//get函数
	string getName() const;
	string getPassword() const;
	bool checkPassword() const;
	//纯虚函数——等待子类实现,父类不需要实现，不需要给出定义
	virtual string getRole()=0;
	virtual void operate(BookManager &bookmanager, UserManager &usermanager)=0;
};



class Admin : public User {
public:
	//自己的全参构造函数
	Admin(string u, string p);
	//重写纯虚函数
	string getRole();
	void operate(BookManager &bookmanager, UserManager &usermanager);
};



class Reader : public User {
public:
	//自己的全参构造函数
	Reader(string u, string p);
	//重写纯虚函数
	string getRole();
	void operate(BookManager &bookmanager, UserManager &usermanager);
};

#endif