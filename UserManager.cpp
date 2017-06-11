#include "Assignment.h"
//////////////////////////////////////////////////////////////////////////////////
// Phan quyen cho account, nho chu y CLOSE va OPEN, phai check ky xem CO TON TAI TEMP hay khong.

void delete_in_permissionaccount(string username) {
	fstream outfile;
	outfile.open("permissionaccount.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	account *tempaccount=new account();
	int flag=0;
	do {
		getline(outfile, datatemp);
		tempaccount->setUsername(datatemp);
		getline(outfile, datatemp);
		tempaccount->setPassword(datatemp);
		getline(outfile, datatemp);
		tempaccount->setID(datatemp);
		getline(outfile, datatemp);
		tempaccount->setRole(datatemp);
		getline(outfile, datatemp);
		tempaccount->setActive(datatemp);
		if (username != tempaccount->getUsername()&&(tempaccount->getUsername() != "")) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << tempaccount->getRole() << '\n' << tempaccount->getActive()<< endl;
		}
	} while (!outfile.eof());
	temp.close();
	outfile.close();
	remove("permissionaccount.txt");
	rename("temp.txt", "permissionaccount.txt");
}

void change_role_function(string username, string newRole) {
	fstream outfile;
	outfile.open("account.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	account *tempaccount=new account();
	int flag=0;
	do {
		getline(outfile, datatemp);
		tempaccount->setUsername(datatemp);
		getline(outfile, datatemp);
		tempaccount->setPassword(datatemp);
		getline(outfile, datatemp);
		tempaccount->setID(datatemp);
		getline(outfile, datatemp);
		tempaccount->setRole(datatemp);
		getline(outfile, datatemp);
		tempaccount->setActive(datatemp);
		if (username != tempaccount->getUsername()&&(tempaccount->getUsername() != "")) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << tempaccount->getRole() << '\n' << tempaccount->getActive()<< endl;
		}
		if (username == tempaccount->getUsername()) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << newRole << '\n' << tempaccount->getActive()<< endl;
		}
	} while (!outfile.eof());
	temp.close();
	outfile.close();
	remove("account.txt");
	rename("temp.txt", "account.txt");
}

void grant_new_role() {
	//show thong tin cac account
	// check xem username co khong
	//neu co thi tien hanh grant moi role
	//xoa ben permissionaccount

}
//////////////////////////////////////////////////////////////////////////
//Xet duyet thong tin User
void delete_user_in_manage_user(string ID) {
	fstream outfile;
	outfile.open("manageuser.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	user *tempuser=new user();
	int flag=0;
	do {
		getline(outfile,datatemp);
		tempuser->setName(datatemp);
		getline(outfile,datatemp);
		tempuser->setCMND(datatemp);
		getline(outfile,datatemp);
		tempuser->setID(datatemp);
		getline(outfile,datatemp);
		tempuser->setPassword(datatemp);
		getline(outfile,datatemp);
		tempuser->setPhone(datatemp);
		getline(outfile,datatemp);
		tempuser->setAddress(datatemp);
		getline(outfile,datatemp);
		tempuser->setBirthday(datatemp);
		getline(outfile,datatemp);
		tempuser->setEmail(datatemp);
		getline(outfile,datatemp);
		tempuser->setJob(datatemp);
		getline(outfile,datatemp);
		tempuser->setActive(datatemp);
		if (ID != tempuser->getID()&&(tempuser->getID() != "")) {
			temp << tempuser->getName() << '\n' << tempuser->getCMND() << '\n' << tempuser->getID() << '\n' << tempuser->getPassword() << '\n' << tempuser->getPhone()
			     <<'\n'<<tempuser->getAddress()<< '\n'<<tempuser->getBirthday()<< '\n'<<tempuser->getEmail()<< '\n'<<tempuser->getJob()<<'\n'<<tempuser->getActive()<<endl;
		}
	} while (!outfile.eof());
	temp.close();
	outfile.close();
	remove("manageuser.txt");
	rename("temp.txt", "manageuser.txt");

}

void verify_user_function(string ID) {
	fstream outfile;
	outfile.open("manageuser.txt", ios::in);
	string datatemp;
	int count = 1;
	user *temp=new user();
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		temp->setName(datatemp);
		getline(outfile,datatemp);
		temp->setCMND(datatemp);
		getline(outfile,datatemp);
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setPassword(datatemp);
		getline(outfile,datatemp);
		temp->setPhone(datatemp);
		getline(outfile,datatemp);
		temp->setAddress(datatemp);
		getline(outfile,datatemp);
		temp->setBirthday(datatemp);
		getline(outfile,datatemp);
		temp->setEmail(datatemp);
		getline(outfile,datatemp);
		temp->setJob(datatemp);
		getline(outfile,datatemp);
		temp->setActive(datatemp);
		if (temp->getID() == ID) {
			user *newUser=new user(temp); //ghi vao list
			newUser->add_user_to_list();
		}

	}
	outfile.close();
	delete_user_in_manage_user(ID);
}



void verify_user() { //TO DO
}

////////////////////////
