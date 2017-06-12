//// Thi?t k? các ch? exit, chua có ch? exit
////Thi?t k? các get,set
#include"Assignment.h"


int main() {
	account *temp=new account();
	temp->setUsername("hahanhuy");
	account *thuthu=new account();
	thuthu->setUsername("thuthutest");
	//regist_user();
	//regist_account();
	send_announcement_to_individual(thuthu, "3");
	read_announcement(temp);
//add_book_to_store(thuthu);
	system("pause");
	return 0;
}
