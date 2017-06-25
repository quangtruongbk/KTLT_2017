#include "Assignment.h"
int check_ID_in_file(string ID) {
	fstream outfile;
	outfile.open("user.txt", ios::in);
	string datatemp;
	int count = 1;
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		if (count%10 == 3) {
			if (ID == datatemp) {
				outfile.close();
				return 1;
			}
		}
		count++;
	}
	outfile.close();
	return 0;
}

int check_ID_password_in_file(string IDpass) {
	fstream outfile;
	outfile.open("user.txt", ios::in);
	string datatemp;
	int count = 1;
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		if (count%10 == 4) {
			if (IDpass == datatemp) {
				outfile.close();
				return 1;
			}
		}
		count++;
	}
	outfile.close();
	return 0;
}

int check_CMND_in_file(string CMND) {
	fstream outfile;
	outfile.open("user.txt", ios::in);
	string datatemp;
	int count = 1;
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		if (count%10 == 2) {
			if (CMND == datatemp) {
				outfile.close();
				return 1;
			}
		}
		count++;
	}
	outfile.close();
	return 0;
}

int check_CMND_in_waiting(string CMND) {
	fstream outfile;
	outfile.open("manageuser.txt", ios::in);
	string datatemp;
	int count = 1;
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		if (count%10 == 2) {
			if (CMND == datatemp) {
				outfile.close();
				return 1;
			}
		}
		count++;
	}
	outfile.close();
	return 0;
}

int check_CMND_exist(string CMND) {
	if(check_CMND_in_file(CMND)==1||check_CMND_in_waiting(CMND)==1) return 1;
	return 0;
}

int check_email_in_file(string email) {
	fstream outfile;
	outfile.open("user.txt", ios::in);
	string datatemp;
	int count = 1;
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		if (count%10 == 8) {
			if (email == datatemp) {
				outfile.close();
				return 1;
			}
		}
		count++;
	}
	outfile.close();
	return 0;
}

int check_email_in_waiting(string email) {
	fstream outfile;
	outfile.open("manageuser.txt", ios::in);
	string datatemp;
	int count = 1;
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		if (count%10 == 8) {
			if (email == datatemp) {
				outfile.close();
				return 1;
			}
		}
		count++;
	}
	outfile.close();
	return 0;
}

int check_email_exist(string email) {
	if(check_email_in_file(email)==1||check_email_in_waiting(email)==1) return 1;
	return 0;
}

int check_ID_in_waiting(string ID) {
	fstream outfile;
	outfile.open("manageuser.txt", ios::in);
	string datatemp;
	int count = 1;
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		if (count%10 == 3) {
			if (ID == datatemp) {
				outfile.close();
				return 1;
			}
		}
		count++;
	}
	outfile.close();
	return 0;
}

int check_exist_username_in_permissionaccount(string username) {
	fstream outfile;
	outfile.open("permissionaccount.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_already_people_have.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_already_people_have.txt",ios::in );
	}
	string datatemp;
	account *tempaccount=new account();
	int flag=0;
	while (getline(outfile, datatemp)) {
		
		tempaccount->setUsername(datatemp);
		getline(outfile, datatemp);
		tempaccount->setPassword(datatemp);
		getline(outfile, datatemp);
		tempaccount->setID(datatemp);
		getline(outfile, datatemp);
		tempaccount->setRole(datatemp);
		getline(outfile, datatemp);
		tempaccount->setActive(datatemp);
		if (username == tempaccount->getUsername()) {
			return 1;
			outfile.close();
		}
	}
	outfile.close();
	return 0;
}

int check_account_username(string username, account*&temp) {
	fstream outfile;
	string datatemp;
	outfile.open("account.txt", ios::in);
	while (getline(outfile, datatemp)) {
		
		temp->setUsername(datatemp);
		getline(outfile,datatemp);
		temp->setPassword(datatemp);
		getline(outfile,datatemp);
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setRole(datatemp);
		getline(outfile,datatemp);
		temp->setActive(datatemp);
		if (temp->getUsername() == username) {
			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
}

int check_account_username_and_ID(string username, string ID) {
	fstream outfile;
	string datatemp;
	outfile.open("account.txt", ios::in);
	account *temp=new account();
	while (getline(outfile, datatemp)) {
		
		temp->setUsername(datatemp);
		getline(outfile,datatemp);
		temp->setPassword(datatemp);
		getline(outfile,datatemp);
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setRole(datatemp);
		getline(outfile,datatemp);
		temp->setActive(datatemp);
		if (temp->getUsername() == username&&temp->getID()==ID) {
			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
}

int get_account_username(string username, account *&acc) {
	fstream outfile;
	string datatemp;
	outfile.open("account.txt", ios::in);
	account *temp=new account();
	while (getline(outfile, datatemp)) {
		
		temp->setUsername(datatemp);
		getline(outfile,datatemp);
		temp->setPassword(datatemp);
		getline(outfile,datatemp);
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setRole(datatemp);
		getline(outfile,datatemp);
		temp->setActive(datatemp);
		if (temp->getUsername() == username) {
			acc->setUsername(temp->getUsername());
			acc->setID(temp->getID());
			acc->setPassword(temp->getPassword());
			acc->setRole(temp->getRole());
			acc->setActive(temp->getActive());
			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
}

int check_ID_Announcement_in_file(account *acc, string ID) {
	fstream outfile;
	string filename="announcement_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string datatemp;
	announcement *temp=new announcement();
	while (getline(outfile, datatemp)) {
		temp->setID(datatemp);
		getline(outfile, datatemp);
		temp->setAnnounce(datatemp);
		getline(outfile, datatemp);
		temp->setDate(datatemp);
		getline(outfile, datatemp);
		temp->setSeen(datatemp);
		if(ID==temp->getID()) return 1;
	}
	return 0;
	outfile.close();
}

int check_ID_history_in_file(account *acc, string ID) {
	fstream outfile;
	string filename="history_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string STT,history,date;
	while (getline(outfile, STT)) {
		getline(outfile, history);
		getline(outfile, date);
		if(ID==STT) return 1;
	}
	return 0;
	outfile.close();
}

int check_ISBN_Book(string ID) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	string datatemp;
	Book *temp=new Book();
	while (getline(outfile,  temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile,  temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->amount=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->price=atoi(datatemp.c_str());
		if(ID==temp->ISBN) {
			outfile.close();
			return 1;
		}
	}
	return 0;
	outfile.close();
}

int check_ID_Announcement_in_archive(string ID) {
	fstream outfile;
	string filename="archive_announcement_database.txt";
	string datatemp;
	announcement *temp=new announcement();
	while (getline(outfile, datatemp)) {
		temp->setID(datatemp);
		getline(outfile, datatemp);
		temp->setAnnounce(datatemp);
		getline(outfile, datatemp);
		temp->setDate(datatemp);
		getline(outfile, datatemp);
		if(ID==temp->getID()) return 1;
	}
	return 0;
	outfile.close();
}

//Truoc luc add
int check_exist_ISBN_in_demand_file(account *acc_reader, string ISBN) {
	fstream outfile;
	string datatemp;
	int count=0;
	string filename="demand_book_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(),ios::in );
	}
	while(getline(outfile,datatemp)) {
		if(datatemp==ISBN) {
			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
}

int count_in_demand_file(account *acc_reader) {
	fstream outfile;
	string datatemp;
	int count=0;
	string filename="demand_book_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(),ios::in );
	}

	while(getline(outfile,datatemp)) {
		count++;
	}
	outfile.close();
	return count;
}

int count_number_of_waiting_of_each_person(account *acc) {
	fstream outfile;
	string filename="book_waiting_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}

	string datatemp;
	int counttemp=0;
	Book booktemp;
	while (getline(outfile, datatemp)) {
		booktemp.ISBN=datatemp;
		getline(outfile,datatemp);
		booktemp.name=datatemp;
		getline(outfile,datatemp);
		booktemp.author=datatemp;
		getline(outfile,datatemp);
		booktemp.category=datatemp;
		getline(outfile,datatemp);
		booktemp.publisher=datatemp;
		getline(outfile,datatemp);
		booktemp.year=atoi(datatemp.c_str());
		counttemp++;
	}
	outfile.close();
	return counttemp;
}

int check_exist_ISBN_of_waiting_of_each_person(account *acc,string ISBN) {
	fstream outfile;
	string filename="book_waiting_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}

	string datatemp;
	int counttemp=0;
	Book booktemp;
	while (getline(outfile, datatemp)) {
		booktemp.ISBN=datatemp;
		getline(outfile,datatemp);
		booktemp.name=datatemp;
		getline(outfile,datatemp);
		booktemp.author=datatemp;
		getline(outfile,datatemp);
		booktemp.category=datatemp;
		getline(outfile,datatemp);
		booktemp.publisher=datatemp;
		getline(outfile,datatemp);
		booktemp.year=atoi(datatemp.c_str());
		if(ISBN==booktemp.ISBN) {
			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
}

int check_exist_book_in_book_people_wanting_line(account *acc_reader, string ISBN) {
	fstream outfile;
	string datatemp;
	int count=0;

	outfile.open("book_waiting_line.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_waiting_line.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_waiting_line.txt",ios::in );
	}
	account *temp=new account();
	while(getline(outfile,datatemp)) {
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setUsername(datatemp);

		getline(outfile,datatemp);
		if(acc_reader->getID()==temp->getID()&&datatemp==ISBN) {
			outfile.close();
			return 1;
		}
		getline(outfile,datatemp);

	}
	outfile.close();
	delete temp;
	return 0;
}



//Truoc luc send
int check_exist_in_book_people_want_to_borrow_file(account *acc_reader) {
	fstream outfile;
	string datatemp;
	int count=0;

	outfile.open("book_people_want_to_borrow.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_people_want_to_borrow.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_people_want_to_borrow.txt",ios::in );
	}
	account *temp=new account();
	while(getline(outfile,datatemp)) {
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setUsername(datatemp);
		if(acc_reader->getID()==temp->getID()) {
			outfile.close();
			return 1;
		}
		getline(outfile,datatemp);
		getline(outfile,datatemp);

	}
	outfile.close();
	delete temp;
	return 0;
}



int check_exist_in_book_people_already_have(account *acc_reader) {
	fstream outfile;
	string datatemp;
	int count=0;

	outfile.open("book_already_people_have.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_already_people_have.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_already_people_have.txt",ios::in );
	}
	account *temp=new account();
	while(getline(outfile,datatemp)) {
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setUsername(datatemp);
		if(acc_reader->getID()==temp->getID()) {
			outfile.close();
			return 1;
		}
		getline(outfile,datatemp);
		getline(outfile,datatemp);
		getline(outfile,datatemp);
	}
	outfile.close();
	delete temp;
	return 0;
}

int check_ISBN_exist_in_book_people_already_have(string ISBN) {
	fstream outfile;
	string datatemp;
	int count=0;

	outfile.open("book_already_people_have.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_already_people_have.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_already_people_have.txt",ios::in );
	}
	account *temp=new account();
	while(getline(outfile,datatemp)) {
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setUsername(datatemp);

		getline(outfile,datatemp);
		if(ISBN==datatemp) {
			outfile.close();
			return 1;
		}
		getline(outfile,datatemp);
		getline(outfile,datatemp);

	}
	outfile.close();
	delete temp;
	return 0;
}

int check_ISBN_exist_in_book_people_want_to_borrow(string ISBN) {
	fstream outfile;
	string datatemp;
	int count=0;

	outfile.open("book_people_want_to_borrow.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_people_want_to_borrow.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_people_want_to_borrow.txt",ios::in );
	}
	account *temp=new account();
	while(getline(outfile,datatemp)) {
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setUsername(datatemp);

		getline(outfile,datatemp);
		if(ISBN==datatemp) {
			outfile.close();
			return 1;
		}
		getline(outfile,datatemp);

	}
	outfile.close();
	delete temp;
	return 0;
}

int check_ISBN_exist_in_book_people_wanting_line(string ISBN) {
	fstream outfile;
	string datatemp;
	int count=0;

	outfile.open("book_waiting_line.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_waiting_line.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_waiting_line.txt",ios::in );
	}
	account *temp=new account();
	while(getline(outfile,datatemp)) {
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setUsername(datatemp);

		getline(outfile,datatemp);
		if(datatemp==ISBN) {
			outfile.close();
			return 1;
		}
		getline(outfile,datatemp);

	}
	outfile.close();
	delete temp;
	return 0;
}


int check_exist_book_in_already_one_person_have(account *acc_reader) {
	if(get_number_of_book_already_have_of_each_person_function(acc_reader)!=0) return 1;
	return 0;
}


int count_number_of_book_approve(account *acc) {
	fstream outfile;
	string datatemp;
	int count=0;

	outfile.open("book_people_want_to_borrow.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_people_want_to_borrow.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_people_want_to_borrow.txt",ios::in );
	}
	while(getline(outfile,datatemp)) {
		getline(outfile,datatemp);
		getline(outfile,datatemp);
		getline(outfile,datatemp);
		count++;
	}
	outfile.close();
	return count;
}

int count_number_of_book_waiting_file(account *acc) {
	fstream outfile;
	string datatemp;
	int count=0;

	outfile.open("book_waiting_line.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_waiting_line.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_waiting_line.txt",ios::in );
	}
	while(getline(outfile,datatemp)) {
		getline(outfile,datatemp);
		getline(outfile,datatemp);
		getline(outfile,datatemp);
		count++;
	}
	outfile.close();
	return count;
}

int get_number_of_waiting_of_each_person_function(account *acc_reader) {
	fstream outfile;
	string filename="book_waiting_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(),ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	Book book;
	string datatemp;
	int count=0;
	while(getline(outfile,datatemp)) {
		book.ISBN=datatemp;
		getline(outfile,datatemp);
		book.name=datatemp;
		getline(outfile,datatemp);
		book.author=datatemp;
		getline(outfile,datatemp);
		book.category=datatemp;
		getline(outfile,datatemp);
		book.publisher=datatemp;
		getline(outfile,datatemp);
		book.year=atoi(datatemp.c_str());

		count++;
	}
	outfile.close();
	return count;
}

int get_number_of_book_already_have_of_each_person_function(account *acc_reader) {
	fstream outfile;
	string filename="book_already_have_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(),ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	Book book;
	string datatemp;
	int count=0;
	string date;
	while(getline(outfile,datatemp)) {
		book.ISBN=datatemp;
		getline(outfile,datatemp);
		book.name=datatemp;
		getline(outfile,datatemp);
		book.author=datatemp;
		getline(outfile,datatemp);
		book.category=datatemp;
		getline(outfile,datatemp);
		book.publisher=datatemp;
		getline(outfile,datatemp);
		book.year=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		book.amount=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		book.price=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		date=datatemp;
		count++;
	}
	outfile.close();
	return count;
}

int check_book_if_exist(account *librarian, string ISBN) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	string datatemp;
	Book *temp=new Book();
	while (getline(outfile,  temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile,  temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->amount=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->price=atoi(datatemp.c_str());
		if(temp->ISBN==ISBN) {
			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
}

int check_exist_book_already_have_of_each_person_function(account *acc_reader, string ISBN) {
	fstream outfile;
	string filename="book_already_have_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(),ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	Book book;
	string datatemp;
	int count=0;
	string date;
	while(getline(outfile,datatemp)) {
		book.ISBN=datatemp;
		getline(outfile,datatemp);
		book.name=datatemp;
		getline(outfile,datatemp);
		book.author=datatemp;
		getline(outfile,datatemp);
		book.category=datatemp;
		getline(outfile,datatemp);
		book.publisher=datatemp;
		getline(outfile,datatemp);
		book.year=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		book.amount=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		book.price=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		date=datatemp;
		if(book.ISBN==ISBN) {
			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
}

int get_book_number_in_store(account *librarian, string ISBN) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	string datatemp;
	Book *temp=new Book();
	while (getline(outfile,  temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile,  temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->amount=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->price=atoi(datatemp.c_str());
		if(temp->ISBN==ISBN) {

			outfile.close();
			return temp->amount;
		}
	}
	outfile.close();
	return -1;
}

int check_exist_book_in_store(string ISBN) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	string datatemp;
	Book *temp=new Book();
	while (getline(outfile,  temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile,  temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->amount=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->price=atoi(datatemp.c_str());
		if(temp->ISBN==ISBN) {

			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
}

void get_book_info(Book &book,string ISBN) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	string datatemp;
	Book *temp=new Book();
	while (getline(outfile,  temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile,  temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->amount=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->price=atoi(datatemp.c_str());
		if(temp->ISBN==ISBN) {
			book.ISBN=temp->ISBN;
			book.name=temp->name;
			book.category=temp->category;
			book.publisher=temp->publisher;
			book.year=temp->year;
			book.amount=temp->amount;
			book.price=temp->price;
			outfile.close();
			return;
		}
	}
	outfile.close();
	return;
}

int get_book_amount(string ISBN) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	string datatemp;
	Book *temp=new Book();
	while (getline(outfile,  temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile,  temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->amount=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp->price=atoi(datatemp.c_str());
		if(temp->ISBN==ISBN) {
			outfile.close();
			return temp->amount;
		}
	}
	outfile.close();
	return -1;
}

