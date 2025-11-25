#include "BookRankingList.h"


BookRankingList::BookRankingList() {}

BookRankingList::BookRankingList(BookManager bookmanager0) {
	bookmanager = bookmanager0;
}


void BookRankingList::showRankingMenu() const {
	cout << "\n==== 图书排行榜 ====" << endl;
	cout << "1.查看借阅次数排行榜（前十）" << endl;
	cout << "2.查看出版时间排行榜（前十）" << endl;
	cout << "0.返回" << endl;
	cout << "===================" << endl;
	return;
}

void BookRankingList::run() {
	while (true) {
		showRankingMenu();
		int choice;
		cin >> choice;
		if (cin.fail()) {
			cout << "请输入数字！" << endl;
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		switch (choice) {
		case 1: {
			bookmanager.top10ByBorrowedCount();
			bookmanager.displayTop10Books();
			break;
		}
		case 2: {
			bookmanager.top10ByPublishTime();
			bookmanager.displayTop10Books();
			break;
		}
		case 0: {
			return;
		}
		default: {
			cout << "请输入有效数字！（0~2）" << endl;
			break;
		}
		}
	}
	return;
}