#include "Assignment.h"
//////////////////////////////////////////////////////////////////////////////////
// Phan quyen cho account, nho chu y CLOSE va OPEN, phai check ky xem CO TON TAI TEMP hay khong.
//Xoa trong permission account
void delete_in_permissionaccount(string username) {
	fstream outfile;
	outfile.open("permissionaccount.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
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
		if (username != tempaccount->getUsername()&&(tempaccount->getUsername() != "")) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << tempaccount->getRole() << '\n' << tempaccount->getActive()<< endl;
		}
	}
	temp.close();
	outfile.close();
	remove("permissionaccount.txt");
	rename("temp.txt", "permissionaccount.txt");
}
//Doi vai tro account
void change_role_function(string username, string newRole) {
	fstream outfile;
	outfile.open("account.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
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
		if (username != tempaccount->getUsername()&&(tempaccount->getUsername() != "")) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << tempaccount->getRole() << '\n' << tempaccount->getActive()<< endl;
		}
		if (username == tempaccount->getUsername()) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << newRole << '\n' << tempaccount->getActive()<< endl;
		}
	}
	temp.close();
	outfile.close();
	remove("account.txt");
	rename("temp.txt", "account.txt");
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
	while (getline(outfile, datatemp)) {
		
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
	}
	temp.close();
	outfile.close();
	remove("manageuser.txt");
	rename("temp.txt", "manageuser.txt");

}
//Duyet thong tin user
void verify_user_function(string ID) {
	fstream outfile;
	outfile.open("manageuser.txt", ios::in);
	string datatemp;
	int count = 1;
	user *temp=new user();
	while (getline(outfile, datatemp)) {
		
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

//Duyet thong tin user
void verify_user(account *acc_usermanager) { //TO DO
	cout<<"Nhap ID cua nguoi duoc duyet: "<<endl;
	string ID;
	getline(cin,ID);
	if(check_ID_in_waiting(ID) ==0) {
		cout<<"Khong ton tai ID"<<endl<<"Nhan mot phim ngau nhien de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return verify_user_full(acc_usermanager);
	} else {
		verify_user_function(ID);
		cout<<"Nhan bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return verify_user_full(acc_usermanager);
	}
}
//Show info User dang xet duyet
void show_info_usermanager(account* acc_usermanager) {
	fstream outfile;
	outfile.open("manageuser.txt", ios::in);
	string name, CMND, ID;
	string datatemp;
	cout << "----------------------------------------------------------------------\n";
	cout << "|          ID          |           Ten             |       CMND      |\n";
	cout << "----------------------------------------------------------------------\n";
	while (getline(outfile, name)) {
		
		if (name == "")
			break;
		getline(outfile, CMND);
		getline(outfile, ID);
		getline(outfile, datatemp);
		getline(outfile, datatemp);
		getline(outfile, datatemp);
		getline(outfile, datatemp);
		getline(outfile, datatemp);
		getline(outfile, datatemp);
		getline(outfile, datatemp);
		cout << "| " << left << setw(20) << ID << " | " << setw(25) << name << " | " << setw(15) << CMND << " |\n";
	}
	cout << "----------------------------------------------------------------------\n";
	outfile.close();
}
//Duyet thong tin user
void verify_user_full(account *acc_manager) {
	show_info_usermanager(acc_manager);
	cout<<"1. Duyet thong tin."<<endl;
	cout<<"2. Tro ve."<<endl;
	fflush(stdin);
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') return verify_user(acc_manager);
	if(choice=='2') return mainmenu(acc_manager);
}
////////////////////////

//Reset password
void reset_password_function(string account_username) {
	account *temp1=new account();
	if(check_account_username( account_username, temp1)==0) cout<<"Khong tim thay "<<endl;
	fstream outfile;
	outfile.open("account.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	account *tempaccount=new account();
	int flag=0;
	string newPassword;
	srand(time(0));
	for(unsigned int i = 0; i < MAXRESETPASSWORD; ++i) {
		newPassword += genRandom();
	}
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
		if (account_username != tempaccount->getUsername()&&(tempaccount->getUsername() != "")) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << tempaccount->getRole() << '\n' << tempaccount->getActive()<< endl;
		}
		if(account_username==tempaccount->getUsername()) {
			temp << tempaccount->getUsername() << '\n' << newPassword << '\n' << tempaccount->getID() << '\n' << tempaccount->getRole() << '\n' << tempaccount->getActive()<< endl;
		}
	}
	temp.close();
	outfile.close();
	remove("account.txt");
	rename("temp.txt", "account.txt");
}
// reset password
void reset_password(account *usermanager) {
	cout << "Nhap username account reset mat khau: " << endl;
	string username;
	getline(cin, username);
	account *temp = new account();
	if (check_account_username(username, temp) == 0) {
		cout << "Khong ton tai username" << endl << "Nhan mot phim ngau nhien de tro ve." << endl;
		fflush(stdin);
		char choice;
		choice = _getch();
		fflush(stdin);
		return reset_password_full(usermanager);
	}
	else {
		reset_password_function(username);
		cout << "Nhan bat ky de tro ve" << endl;
		fflush(stdin);
		char choice;
		choice = _getch();
		fflush(stdin);
		return reset_password_full(usermanager);
	}

}
//Reset password toan bo
void reset_password_full(account *manager){
	system("cls");
	cout << "RESET MAT KHAU" << endl;
	cout << "1. Reset mat khau account." << endl;
	cout << "2. Tro ve." << endl;
	fflush(stdin);
	char choice;
	do {
		fflush(stdin);
		choice = _getch();
		fflush(stdin);
		if (choice != '1'&&choice != '2') cout << "Lua chon khong dung. Ban hay nhap lai:" << endl;
	} while (choice != '1'&&choice != '2');
	if (choice == '1') return reset_password(manager);
	if (choice == '2') return mainmenu(manager);
}

// Thay doi active disactive
void change_active_account(account *acc, string username, string newActive) {
	fstream outfile;
	outfile.open("account.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
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
		if (username != tempaccount->getUsername()&&(tempaccount->getUsername() != "")) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << tempaccount->getRole() << '\n' << tempaccount->getActive()<< endl;
		}
		if(username==tempaccount->getUsername()) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << tempaccount->getRole() << '\n' << newActive << endl;
		}
	}
	temp.close();
	outfile.close();
	remove("account.txt");
	rename("temp.txt", "account.txt");
}

// Show thong tin user
user show_all_user_infomation_function(account *acc_manager, string ID) {
	fstream outfile;
	outfile.open("user.txt", ios::in);
	string datatemp;
	int count = 1;
	user *temp=new user();
	while (getline(outfile, datatemp)) {
		
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
			outfile.close();
			return *temp;
		}

	}
	outfile.close();
}
//Lay vai tro nguoi dung
string getrolestring(string role) {
	string rolestring="";
	if(role[0]=='1') rolestring=rolestring+"DOC GIA"+"-";
	if(role[1]=='1') rolestring=rolestring+"THU THU-";
	if(role[2]=='1') rolestring=rolestring+"QUAN LY NGUOI DUNG";
	if(role[0]=='0'&&role[1]=='0'&&role[2]=='0') rolestring="CHUA CO VAI TRO";
	return rolestring;
}
//Tim account voi ID
void find_all_account_with_user_id_function(user *newuser) {
	fstream outfile;
	outfile.open("account.txt", ios::in);
	string datatemp;
	account *tempaccount=new account();
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

		if(newuser->getID()==tempaccount->getID()) {
			string newRole=getrolestring(tempaccount->getRole());
			cout<<"Username cua account: "<<tempaccount->getUsername()<<endl;
			cout<< newRole<<endl;
			if(tempaccount->getActive()=="1") cout<<"Dang hoat dong"<<endl;
			if(tempaccount->getActive()=="0") cout<<"Bi khoa"<<endl;
		}
	}
	outfile.close();
}

void printtiletleuser() {
	printline();
	cout << "|      ID       |                      Ho va ten                |        CMND         |                Email               |              Dien thoai            |\n";
	printline();
}
void printtiletleaccount() {
	printline();
	cout << "|                     Username                  |         ID         |                        Vai tro                     |              Trang thai            |\n";
	printline();
}
void printuserinfo(user *temp) {
	cout<<"|"<<setw(15)<<left<<temp->getID()<<"|";
	if(temp->getName().length()<=47) cout<<setw(47)<<temp->getName()<<"|";
	if(temp->getName().length()>47) {
		for (int i=0; i<44; i++) cout<<temp->getName()[i];
		cout<<"...|";
	}
	cout<<setw(21)<<temp->getCMND()<<"|";
	if(temp->getEmail().length()<=36) cout<<setw(36)<<temp->getEmail()<<"|";
	if(temp->getEmail().length()>36) {
		for(int i=0; i<33; i++) cout<<temp->getEmail()[i];
		cout<<"...|";
	}
	cout<<setw(36)<<temp->getPhone()<<"|";
	cout<<endl;
}

void printaccountinfo(account *temp) {
	if(temp->getUsername().length()<=47) cout<<"|"<<setw(47)<<left<<temp->getUsername()<<"|";
	else {
		cout<<"|";
		for (int i=0; i<44; i++) cout<<temp->getUsername()[i];
		cout<<"...|";
	}
	cout<<setw(20)<<temp->getID()<<"|"<<setw(52)<<getrolestring(temp->getRole())<<"|";
	if(temp->getActive()=="1") cout<<setw(36)<<"Dang hoat dong"<<"|";
	if(temp->getActive()=="0") cout<<setw(36)<<"Da bi khoa"<<"|";
	cout<<endl;
}
//Tim kiem nguoi dung
void search_user(account *acc, string userinfo, int searchchoice) {
	fstream outfile;
	outfile.open("user.txt", ios::in);
	string datatemp;
	int count = 1;
	user *temp=new user();
	while (getline(outfile, datatemp)) {
		
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
		if (searchchoice == 1 && temp->getID().find(userinfo,0)!=-1) {
			printuserinfo(temp);
		}
		if (searchchoice == 2 && temp->getName().find(userinfo,0)!=-1) {
			printuserinfo(temp);
		}
		if (searchchoice == 3 && temp->getCMND().find(userinfo,0)!=-1) {
			printuserinfo(temp);
		}
		if (searchchoice == 4 && temp->getEmail().find(userinfo,0)!=-1) {
			printuserinfo(temp);
		}
		if (searchchoice == 5 && temp->getPhone().find(userinfo,0)!=-1) {
			printuserinfo(temp);
		}
	}
	outfile.close();
	cout<<"Nhan bat ky de tro ve"<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return search_user_all(acc);
}

//Tim kiem account
void search_account(account *acc, string accountinfo, int searchchoice) {
	fstream outfile;
	outfile.open("account.txt", ios::in);
	string datatemp;
	int count = 1;
	account *temp=new account();
	while (getline(outfile, datatemp)) {
		
		temp->setUsername(datatemp);
		getline(outfile, datatemp);
		temp->setPassword(datatemp);
		getline(outfile, datatemp);
		temp->setID(datatemp);
		getline(outfile, datatemp);
		temp->setRole(datatemp);
		getline(outfile, datatemp);
		temp->setActive(datatemp);
		if (searchchoice == 1 && temp->getUsername().find(accountinfo,0)!=-1) {
			printaccountinfo(temp);
		}
		if (searchchoice == 2 && temp->getID().find(accountinfo,0)!=-1) {
			printaccountinfo(temp);
		}
	
	}
	outfile.close();
	cout<<"Nhan bat ky de tro ve"<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return search_account_all(acc);
}
//Tim kiem nguoi dung toan bo
void search_user_all(account *acc_manager) {
	system("cls");
	cout<<"CHUC NANG TIM KIEM THONG TIN NGUOI DUNG CUA QUAN LY NGUOI DUNG: "<<acc_manager->getUsername()<<endl;
	printline();
	printline();
	cout<<"1. Tim kiem theo ID"<<endl;
	cout<<"2. Tim kiem theo ten"<<endl;
	cout<<"3. Tim kiem theo CMND"<<endl;
	cout<<"4. Tim kiem email"<<endl;
	cout<<"5. Tim kiem theo phone"<<endl;
	cout<<"6. Tro ve"<<endl;
	char choice;
	cout << "Nhap lua chon tim kiem:" << endl;
	do {
		fflush(stdin);
		choice = _getch();
		fflush(stdin);
		if (choice != '1'&&choice != '2'&&choice != '3'&&choice != '4'&&choice != '5'&&choice != '6') cout << "Hay bam lua chon dung" << endl;
	} while (choice != '1'&&choice != '2'&&choice != '3'&&choice != '4'&&choice != '5'&&choice != '6');
	if (choice == '6') return mainmenu(acc_manager);

	cout<<"Xin vui long nhap tu khoa muon tim: "<<endl;
	string userinfo;
	do {
		fflush(stdin);
		getline(cin,userinfo);
		if(userinfo=="") cout<<"Khong duoc de trong tu khoa, xin vui long nhap lai"<<endl;
	} while(userinfo=="");
	string userinfo1 = uppercase(userinfo);
	if (choice == '1') return search_user(acc_manager, userinfo1, 1);
	if (choice == '2') return search_user(acc_manager, userinfo1, 2);
	if (choice == '3') return search_user(acc_manager, userinfo1, 3);
	if(choice=='4') return search_user(acc_manager, (userinfo), 4);
	if (choice == '5') return search_user(acc_manager, userinfo1, 5);
}
//Tim kiem account toan bo
void search_account_all(account *acc_manager) {
	system("cls");
	cout<<"CHUC NANG TIM KIEM ACCOUNT NGUOI DUNG CUA QUAN LY NGUOI DUNG: "<<acc_manager->getUsername()<<endl;
	printline();
	printline();
	cout<<"1. Tim kiem theo ID"<<endl;
	cout<<"2. Tim kiem theo username"<<endl;
	cout<<"3. Tro ve"<<endl;
	char choice;
	cout << "Nhap lua chon tim kiem:" << endl;
	do {
		fflush(stdin);
		choice = _getch();
		fflush(stdin);
		if (choice != '1'&&choice != '2'&&choice != '3') cout << "Hay bam lua chon dung" << endl;
	} while (choice != '1'&&choice != '2'&&choice != '3');
	if (choice == '3') return mainmenu(acc_manager);
	cout<<"Xin vui long nhap tu khoa muon tim: "<<endl;
	string userinfo;
	do {
		fflush(stdin);
		getline(cin,userinfo);
		if(userinfo=="") cout<<"Khong duoc de trong tu khoa, xin vui long nhap lai"<<endl;
	} while(userinfo=="");
	string userinfo1 = uppercase(userinfo);
	if (choice == '1') return search_account(acc_manager, userinfo1, 2);
	if(choice=='2') return search_account(acc_manager, userinfo, 1);
}

//	void show_all_infomation_accoutn
//Gui thong bao cua user manager
void send_announcement_user_manager(account *acc) {
	system("cls");
	cout<<"CHUC NANG GUI THONG BAO CUA ACCOUNT: "<<acc->getUsername()<<endl;
	cout<<"1. Gui thong bao cho toan bo doc gia."<<endl;
	cout<<"2. Gui thong bao cho mot ca nhan doc gia."<<endl;
	cout<<"3. Gui thong bao cho thu thu."<<endl;
	cout<<"4. Tro ve."<<endl;
	fflush(stdin);
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4');
	if(choice=='1') send_announcement_to_all(acc,0,"2");
	if(choice=='2') send_announcement_to_individual(acc,"2");
	if(choice=='3') send_announcement_to_all(acc,2,"2") ;
	if(choice=='4') return mainmenu(acc);
}
//Khoa tai khoan
void khoa_tai_khoan(account *acc_manager) {
	cout<<"Nhap username account can khoa: "<<endl;
	string username;
	getline(cin,username);
	account *temp=new account();
	if(check_account_username(username,temp) ==0) {
		cout<<"Khong ton tai username"<<endl<<"Nhan mot phim ngau nhien de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return khoa_tai_khoan_full(acc_manager);
	} else {
		change_active_account(acc_manager,username,"0");
		cout<<"Nhan bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return khoa_tai_khoan_full(acc_manager);
	}
}
//Mo tai khoan
void mo_tai_khoan(account *acc_manager) {
	cout<<"Nhap username account can mo khoa: "<<endl;
	string username;
	getline(cin,username);
	account *temp=new account();
	if(check_account_username(username,temp) ==0) {
		cout<<"Khong ton tai username"<<endl<<"Nhan mot phim ngau nhien de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return khoa_tai_khoan_full(acc_manager);
	} else {
		change_active_account(acc_manager,username,"1");
		cout<<"Nhan bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return khoa_tai_khoan_full(acc_manager);
	}
}
//Khoa mo tai khoan
void khoa_tai_khoan_full(account *acc_manager) {
	system("cls");
	cout<<"1. Khoa tai khoan"<<endl;
	cout<<"2. Mo tai khoan"<<endl;
	cout<<"3. Tro ve"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3');
	if(choice=='1') khoa_tai_khoan(acc_manager);
	if(choice=='2') mo_tai_khoan(acc_manager);
	if(choice=='3') return mainmenu(acc_manager);
}
//Show nhung account can duoc cap quyen
void show_permissionaccount(){
	fstream outfile;
	outfile.open("permissionaccount.txt", ios::in);
	string username, ID;
	string datatemp;
	cout << "----------------------------------------------------\n";
	cout << "|          ID          |         Username          |\n";
	cout << "----------------------------------------------------\n";
	while (getline(outfile, username)){
		
		if (username == "")
			break;
		getline(outfile, datatemp);
		getline(outfile, ID);
		getline(outfile, datatemp);
		getline(outfile, datatemp);
		cout << "| " << left << setw(20) << ID << " | " << setw(25) << username << " |\n";
	}
	cout << "----------------------------------------------------\n";
	outfile.close();
}
//Cap quyen moi
void grant_new_role(account *acc_manager) {
	system("cls");
	show_permissionaccount();
	cout<<"Nhap username account can cap quyen moi: "<<endl;
	string username;
	getline(cin,username);
	account *temp=new account();
	if(check_exist_username_in_permissionaccount(username) ==0) {
		cout<<"Khong ton tai username"<<endl<<"Nhan mot phim ngau nhien de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return thay_doi_role(acc_manager);
	} else {
		string newRole="000";
		cout<<"1. La doc gia."<<endl;
		cout<<"2. Khong la doc gia."<<endl;
		fflush(stdin);
		char choice;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') newRole[0]='1';
		if(choice=='2') newRole[0]='0';
		cout<<"1. La quan ly nguoi dung."<<endl;
		cout<<"2. Khong la quan ly nguoi dung."<<endl;
		fflush(stdin);
		char choice2;
		do {
			fflush(stdin);
			choice2=_getch();
			fflush(stdin);
			if(choice2!='1'&&choice2!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
		} while(choice2!='1'&&choice2!='2');
		if(choice2=='1') newRole[1]='1';
		if(choice2=='2') newRole[1]='0';
		cout<<"1. La thu thu."<<endl;
		cout<<"2. Khong la thu thu."<<endl;
		fflush(stdin);
		char choice3;
		do {
			fflush(stdin);
			choice3=_getch();
			fflush(stdin);
			if(choice3!='1'&&choice3!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
		} while(choice3!='1'&&choice3!='2');
		if(choice3=='1') newRole[2]='1';
		if(choice3=='2') newRole[2]='0';
		change_role_function(username, newRole);
		delete_in_permissionaccount(username);
		cout<<"Nhan bat ky de tro ve"<<endl;
		char choice5;
		fflush(stdin);
		choice5=_getch();
		fflush(stdin);
		return thay_doi_role(acc_manager);
	}
}
//Thay doi quyen cu
void change_role(account *acc_manager) {
	system("cls");
	cout<<"Nhap username account can cap quyen moi: "<<endl;
	string username;
	getline(cin,username);
	account *temp=new account();
	if(get_account_username(username,temp) ==0) {
		cout<<"Khong ton tai username"<<endl<<"Nhan mot phim ngau nhien de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return thay_doi_role(acc_manager);
	} else {
		string newRole="000";
		//
		cout<<"1. La doc gia."<<endl;
		cout<<"2. Khong la doc gia."<<endl;
		fflush(stdin);
		char choice;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') newRole[0]='1';
		if(choice=='2') newRole[0]='0';
		cout<<"1. La quan ly nguoi dung."<<endl;
		cout<<"2. Khong la quan ly nguoi dung."<<endl;
		fflush(stdin);
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') newRole[1]='1';
		if(choice=='2') newRole[1]='0';
		cout<<"1. La thu thu."<<endl;
		cout<<"2. Khong la thu thu."<<endl;
		fflush(stdin);
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') newRole[2]='1';
		if(choice=='2') newRole[2]='0';
		change_role_function(username, newRole);
		cout<<"Nhan bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice2;
		choice2=_getch();
		fflush(stdin);
		return thay_doi_role(acc_manager);
	}
}
//Thay doi role toan bo
void thay_doi_role(account *acc_manager) {
	system("cls");
	cout << "CHUC NANG THAY DOI VAI TRO" << endl;
	cout<<"1. Cap role cho tai khoan moi."<<endl;
	cout<<"2. Thay doi role tai khoan cu."<<endl;
	cout<<"3. Tro ve"<<endl;
	fflush(stdin);
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3');
	if(choice=='1') return grant_new_role(acc_manager);
	if(choice=='2') return change_role(acc_manager);
	if(choice=='3') return mainmenu(acc_manager);
}
