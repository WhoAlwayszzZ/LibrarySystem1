#include "UserManager.h"
#include "BookManager.h"

class LibrarySystem {
private:
	UserManager usermanager;
	BookManager bookmanager;
public:
	LibrarySystem();
	void run();
	void handleRegister();
	User *  handleLogin();
	void showMainMenu();
};
