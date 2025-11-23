#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

class User {
protected:
	string userName;
	string password;
public:
	//全参构造函数
	User(string u, string p);
	//虚析构函数
	virtual ~User();//析构函数不能传入参数
	//get函数
	string getName() const;
	string getPassword() const;
	bool checkPassword() const;
	//纯虚函数——等待子类实现,父类不需要实现，不需要给出定义
	virtual string getRole()=0;
	virtual void showMenu()=0;
};



class Admin : public User {
public:
	//自己的全参构造函数
	Admin(string u, string p);
	//重写纯虚函数
	string getRole();
	void showMenu();
};



class Reader : public User {
public:
	//自己的全参构造函数
	Reader(string u, string p);
	//重写纯虚函数
	string getRole();
	void showMenu();
};

#endif