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

int check_CMND_exist(string CMND){
	if(check_CMND_in_file(CMND)==1||check_CMND_in_waiting(CMND)==1) return 1;
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

int check_account_username(string username, account*&temp) {
	fstream outfile;
	string datatemp;
	outfile.open("account.txt", ios::in);
	while (!outfile.eof()) {
		getline(outfile,datatemp);
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

int check_ID_Announcement_in_file(account *acc, string ID) {
fstream outfile;
	string filename="announcement_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	string datatemp;
	announcement *temp=new announcement();
	while (getline(outfile, datatemp)){
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

int check_ISBN_Book(string ID) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	string datatemp;
	Book *temp=new Book();
	while (getline(outfile,  temp->ISBN)){
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
		if(ID==temp->ISBN){
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

