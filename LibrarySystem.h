#include "UserManager.h"
#include "BookManager.h"
#include "BookRankingList.h"


class LibrarySystem {
private:
	UserManager usermanager;
	BookManager bookmanager;
	BookRankingList bookrankinglist;
public:
	LibrarySystem();
	void run();
	void handleRegister();
	User *  handleLogin();
	void showMainMenu();
};
