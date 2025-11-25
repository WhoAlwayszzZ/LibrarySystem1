#ifndef BOOKRANKINGLIST_H
#define BOOKRANKINGLIST_H

#include "BookManager.h"

class BookRankingList {
private:
	BookManager bookmanager;
public:
	BookRankingList();
	BookRankingList(BookManager bookmanager0);
	//打印菜单
	void showRankingMenu() const;
	//菜单循环逻辑
	void run();
};
#endif

