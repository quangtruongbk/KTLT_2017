#include "Assignment.h"
// Menu chinh 
void firstmenu() {
	system("cls");
	cout<<"Xin chao den voi thu vien"<<endl;
	printline();
	printline();
	cout<<"1. Dang nhap"<<endl;
	cout<<"2. Dang ky thong tin nguoi dung"<<endl;
	cout<<"3. Dang ky account"<<endl;
	cout<<"4. Sua thong tin nguoi dung"<<endl;
	cout<<"5. Yeu cau reset mat khau"<<endl;
	cout<<"6. Thoat"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6');
	if(choice=='1') login();
	if(choice=='2') regist_user();
	if(choice=='3') regist_account();
	if(choice=='4') change_user_infomation();
	if(choice=='5') reset_password();
	if(choice=='6') return;
}
//Menu Reader
void menu_reader(account *acc) {
	system("cls");
	cout << "MENU CHUC NANG CUA DOC GIA:" <<acc->getUsername()<<endl;
	cout << "1. Tim sach"<<endl;
	cout << "2. Xem danh sach muon muon sach va gui yeu cau muon sach"<<endl;;
	cout << "3. Danh sach cac sach dang muon"<<endl;
	cout << "4. Danh sach cac sach dang cho"<<endl;
	cout << "5. Xem thong tin"<<endl;
	cout << "6. Gui thong bao"<<endl;
	cout << "7. Tro ve"<<endl;
	cout << "Nhap lua chon: ";
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6'&&choice!='7') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6'&&choice!='7');
	if(choice=='1') return search_book(acc);
	if(choice=='2') return demand_book(acc);
	if(choice=='3') return already_have_book(acc);
	if(choice=='4') return waiting_book(acc);
	if(choice=='5') return read_infomation(acc);
	if(choice=='6') return send_announcement_reader(acc);
	if(choice=='7') return mainmenu(acc);
}
// Menu librarian
void menu_lib(account *acc) {
	system("cls");
	cout << "MENU CHUC NANG CUA THU THU:" << endl;
	cout << "1. Tim sach" << endl;
	cout << "2. Quan ly kho sach" << endl;
	cout << "3. Ghi nhan tra sach, xu ly that lac sach" << endl;
	cout << "4. Ghi nhan cho muon sach" << endl;
	cout << "5. Xu ly hang doi" << endl;
	cout << "6. Gui thong bao" << endl;
	cout << "7. Doc thong tin" << endl;
	cout << "8. Tro ve"<<endl;
	cout << "Nhap lua chon: "<<endl;
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6'&&choice!='7'&&choice!='8') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6'&&choice!='7'&&choice!='8');
	if(choice=='1') return search_book_lib(acc);
	if(choice=='2') return manage_book_store(acc);
	if(choice=='3') return pay_book(acc);
	if(choice=='4') return approve_book(acc);
	if(choice=='5') return approve_waiting(acc);
	if(choice=='6') return send_announcement(acc);
	if(choice=='7') return read_infomation(acc);
	if(choice=='8') return mainmenu(acc);
}
//Menu user manager
void menu_mgr(account *acc) {
	system("cls");
	cout << "MENU CHUC NANG CUA QUAN LY NGUOI DUNG:"<<endl;
	cout << "1. Tim kiem user"<<endl;
	cout<<"2. Tim kiem account"<<endl;
	cout << "3. Xac nhan thong tin nguoi dung"<<endl;
	cout << "4. Cap quyen"<<endl;
	cout << "5. Mo/khoa account"<<endl;
	cout << "6. Reset mat khau account"<<endl;
	cout<<"7. Doc thong tin"<<endl;
	cout << "8. Gui thong bao"<<endl;
	cout<<"9. Tro ve"<<endl;
	cout << "Nhap lua chon: "<<endl;
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6'&&choice!='7'&&choice!='8'&&choice!='9') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6'&&choice!='7'&&choice!='8'&&choice!='9');
	if(choice=='1') return  search_user_all(acc);
	if(choice=='2') return search_account_all(acc);
	if(choice=='3') return verify_user_full(acc);
	if(choice=='4') return thay_doi_role(acc);
	if(choice=='5') return khoa_tai_khoan_full(acc);
	if(choice == '6') return reset_password_full(acc);
	if(choice=='7') return read_infomation(acc);
	if(choice=='8') return send_announcement_user_manager(acc);
	if(choice=='9') return mainmenu(acc);
}
//Menu main
void mainmenu(account *acc) {
	system("cls");
	cout << "DANH SACH MENU THEO VAI TRO: " << endl;
	cout << "1. CHUC NANG DOC GIA" << endl;
	cout << "2. CHUC NANG CUA QUAN LY NGUOI DUNG" << endl;
	cout << "3. CHUC NANG CUA THU THU" << endl;
	cout << "4. DOI MAT KHAU ACCOUNT" << endl;
	cout << "5. DANG XUAT" << endl;
	cout << "Nhap lua chon: " << endl;
	char choice;
	do {
		fflush(stdin);
		choice = _getch();
		fflush(stdin);
		if (choice != '1'&&choice != '2'&&choice != '3'&&choice != '4'&&choice != '5') cout << "Hay bam lua chon dung" << endl;
	} while (choice != '1'&&choice != '2'&&choice != '3'&&choice != '4'&&choice != '5');
	if (choice == '1') {
		if (acc->getRole()[0] == '1') return  menu_reader(acc);
		if (acc->getRole()[0] == '0') {
			cout << "BAN KHONG CO CHUC NANG DOC GIA" << endl;
			cout << "Nhan bat ky de tro ve" << endl;
			fflush(stdin);
			char choice;
			choice = _getch();
			fflush(stdin);
			return mainmenu(acc);
		}
	}
	if (choice == '2') {
		if (acc->getRole()[1] == '1') return  menu_mgr(acc);
		if (acc->getRole()[1] == '0') {
			cout << "BAN KHONG CO CHUC NANG QUAN LY NGUOI DUNG" << endl;
			cout << "Nhan bat ky de tro ve" << endl;
			fflush(stdin);
			char choice;
			choice = _getch();
			fflush(stdin);
			return mainmenu(acc);
		}
	}
	if (choice == '3') {
		if (acc->getRole()[2] == '1') return  menu_lib(acc);
		if (acc->getRole()[2] == '0') {
			cout << "BAN KHONG CO CHUC NANG THU THU" << endl;
			cout << "Nhan bat ky de tro ve" << endl;
			fflush(stdin);
			char choice;
			choice = _getch();
			fflush(stdin);
			return mainmenu(acc);
		}
	}
	if (choice == '4') return change_password(acc);
	if (choice == '5') return log_out(acc);
}


////////////////////////////////////////////////////////////////////
//Dang nhap
void log_out(account *acc) {
	delete_entire_demand(acc);
	delete acc;
	acc=NULL;

	return firstmenu();
}

int login_function(string username, string password, account *&acc) {
	account *temp=new account();
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
		if (temp->getUsername() == username&&temp->getPassword() == password) {
			acc->setUsername(temp->getUsername());
			acc->setPassword(temp->getPassword());
			acc->setID(temp->getID());
			acc->setRole(temp->getRole());
			acc->setActive(temp->getActive());
			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
}

void login() {
	account *acc=new account();
	system("cls");
	string username,password;
	cout<<"Nhap username:"<<endl;
	getline(cin,username);
	cout<<"Nhap password:"<<endl;
	getline(cin,password);
	if(login_function(username,password,acc)==1) {
		if(acc->getActive()=="0") {
			cout<<"Tai khoan da bi khoa, nhan bat ky de tro ve."<<endl;
			fflush(stdin);
			char choice;
			choice=_getch();
			fflush(stdin);
			return firstmenu();
		} else {
			return mainmenu(acc);
		}
	} else {
		cout<<"Username hoac password khong ton tai"<<endl;
		cout<<"Nhan 1 de nhap username va password khac"<<endl;
		cout<<"Nhan 2 de tro ve"<<endl;
		char choice2;
		do {
			fflush(stdin);
			choice2=_getch();
			fflush(stdin);
			if(choice2!='1'&&choice2!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice2!='1'&&choice2!='2');
		if(choice2=='1') return login();
		else return firstmenu();
	}
}
/////////////////////////////////////////////////////////////////////////
// Doi mat khau account
void change_account_password_function(string account_username, string newPassword) {
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


//////////////////////////////////////////////////////
// Dang ky thong tin
void regist_account() {
	//thieu exit cho nhap ID
	system("cls");
	string username, password;
	string ID;
	cout << "Nhap ID da cho : " << endl;
	char key;
	while (1) {
		cin.clear();
		fflush(stdin);
		getline(cin, ID);
		if (check_ID_in_file(ID) == 1) { //TO DO
			cout << "ID hop le, ban duoc quyen dang ky tai khoan moi" << endl;
			break;
		} else {
			cout << "ID khong ton tai, ban khong duoc quyen dang ky tai khoan moi.Xin vui long nhap lai ID hop le."<<endl;
			cout<<"Trong truong hop chua co ID hop le, xin vui long dang ky thong tin ca nhan truoc."<<endl;
			cout<<"Nhan 1 de tiep tuc nhap ID khac"<<endl;
			cout<<"Nhan bat ky de tro ve."<<endl;
			fflush(stdin);
			key=_getch();
			fflush(stdin);
			if(key=='1') {
				return regist_account();
			} else return firstmenu();
		}
	}
	cout << "Nhap username (Khong ky tu dac biet, chi cho phep chu, so va 2 ky hieu _ -, do dai tu 8 toi 12): " << endl;
	account *temp=new account();
	while (1) {
		cin.clear();
		fflush(stdin);
		getline(cin, username);
		if (username.length()<8||username.length()>12||check_account_username(username,temp) == 1 || check_username_blank_space(username)==0 || check_username_legal(username)==0||check_not_blankspace(username)==0)  //TO DO
			cout << "Username da ton tai hoac khong hop le hoac de trong, vui long nhap lai username khac" << endl;
		else {
			break;
		}
	}
	cout << "Nhap password (tu 6 ky tu tro len): " << endl;
	do {
		cin.clear();
		fflush(stdin);
		getline(cin, password);
		if(password.length()<6)cout<<"Do dai mat khau qua ngan, yeu cau nhap lai"<<endl;
	} while(password.length()<6);
	string role="000";
	account *newAccount = new account(username, password, ID,role);
	newAccount->add_account_to_grant_permission();
	newAccount->add_account_to_list();
	system("cls");
	cout<<"Tai khoan da duoc tao, hay cho doi de quan ly nguoi dung cap quyen han cho ban."<<endl;
	cout<<"Bam phim bat ky de tro ve trang chu."<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return firstmenu();
}

//////////////////////////////////////////////////////////
//Dang ky account
void regist_user() {
	system("cls");
	string name, address, phone, CMND, password, email, job, birthday,active="000";
	cout << "Nhap ho va ten:" << endl;
	do {
		cin.clear();
		fflush(stdin);
		getline(cin,name);
		if (check_string(name)==0 || name.length()<1) cout << "Nhap lai ho va ten cho hop le : " << endl;
	} while (check_string(name)==0||name.length()<1);
	name=uppercase(name);
	cout << "Nhap CMND (khong khoang trang) (lon hon 9 chu so theo luat Viet Nam): " << endl;
	char choiceCMND='0';
	do {
		choiceCMND='0';
		cin.clear();
		fflush(stdin);
		getline(cin,CMND);
		if (check_number(CMND)==0||CMND.length()<9) cout << "Nhap lai CMND cho hop le: " << endl;
		if(check_CMND_in_file(CMND)==1||check_CMND_in_waiting(CMND)==1) {
			cout<<"CMND cua ban da duoc dung de dang ky. Xin vui long kiem tra lai."<<endl;
			cout<<"Nhan 1 neu ban muon nhap mot so CMND khac."<<endl;
			cout<<"Nhan 2 de tro ve trang chu."<<endl;
			do {
				fflush(stdin);
				choiceCMND=_getch();
				fflush(stdin);
				if(choiceCMND!='1'&&choiceCMND!='2') cout<<"Hay bam lua chon dung"<<endl;
			} while(choiceCMND!='1'&&choiceCMND!='2');
		}
		if(choiceCMND=='1') {
			cout<<"Moi nhap lai CMND: "<<endl;
		}
		if(choiceCMND=='2') return firstmenu(); /////////////////////////// TO DO
	} while ((check_number(CMND)==0||CMND.length()<9)||(choiceCMND=='1'));
	cout<<"Nhap Password xai cho thong tin ca nhan: "<<endl;
	cout<<"Goi y: Password cho thong tin nen khac voi password account"<<endl;
	do {
		cin.clear();
		fflush(stdin);
		getline(cin,password);
		if (password.length()<6) cout << "Mat khau qua ngan, hay nhap lai mat khau: " << endl;
	} while (password.length()<6);
	cout << "Nhap So dien thoai (khong khoang trang): " << endl;
	do {
		cin.clear();
		fflush(stdin);
		getline(cin,phone);
		if (check_number(phone)==0||phone.length()<5) cout << "Nhap lai so dien thoai cho hop le: " << endl;
	} while (check_number(phone)==0||phone.length()<5);
	fflush(stdin);
	cout << "Nhap dia chi: " << endl;
	do {
		cin.clear();
		fflush(stdin);
		getline(cin, address);
		address=uppercase(address);
		if(address=="") cout<<"Khong duoc de trong dia chi"<<endl;
	} while(address=="");
	fflush(stdin);
	birthday=input_date();
	fflush(stdin);
	cout << "Nhap email (khong khoang trang): " << endl;
	char choiceemail='0';
	do {
		choiceemail='0';
		cin.clear();
		fflush(stdin);
		getline(cin,email);
		if (email=="") cout << "Khong duoc bo trong email. Nhap lai email cho hop le: " << endl;
		if(check_email_in_file(email)==1||check_email_in_waiting(email)==1) {
			cout<<"Email cua ban da duoc dung de dang ky. Xin vui long kiem tra lai."<<endl;
			cout<<"Nhan 1 neu ban muon nhap mot so Email khac."<<endl;
			cout<<"Nhan 2 de tro ve trang chu."<<endl;
			do {
				fflush(stdin);
				choiceemail=_getch();
				fflush(stdin);
				if(choiceemail!='1'&&choiceemail!='2') cout<<"Hay bam lua chon dung"<<endl;
			} while(choiceemail!='1'&&choiceemail!='2');
		}
		if(choiceemail=='1') {
			cout<<"Moi nhap lai email: "<<endl;
		}
		if(choiceemail=='2') return firstmenu(); /////////////////////////// TO DO
	} while (email==""||(choiceemail=='1'));
	cout << "Nhap nghe nghiep: " << endl;
	do {
		cin.clear();
		fflush(stdin);
		getline(cin, job);
		if(job==""||check_string(job)==0) cout<<"Cong viec khong hop le, hay nhap dung."<<endl;
	} while(job==""||check_string(job)==0);
	job=uppercase(job);
	user *newUser = new user(name, CMND, password, phone, address,birthday,email,job,active);
	newUser->add_user_to_verify();
	system("cls");
	cout<<"Thong tin cua ban dang trong danh sach cho de duoc duyet"<<endl;
	cout<<"Bam phim bat ky de tro ve trang chu."<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return firstmenu();
}
//Doi mat khau
void change_password(account *acc) {
	string oldPassword;
	cout<<"Nhap password cu: "<<endl;
	getline(cin,oldPassword);
	string newPassword;
	if(acc->getPassword()==oldPassword) {
		cout << "Nhap password moi (tu 6 ky tu tro len): " << endl;
		do {
			cin.clear();
			fflush(stdin);
			getline(cin, newPassword);
			if(newPassword.length()<6)cout<<"Do dai mat khau qua ngan, yeu cau nhap lai"<<endl;
		} while(newPassword.length()<6);
		change_account_password_function(acc->getUsername(), newPassword);
		acc->setPassword(newPassword);
		cout<<"Mat khau da doi, bam bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return mainmenu(acc);
	} else {
		char choice2;
		cout<<"Password cu khong dung"<<endl;
		cout<<"Nhan 1 neu ban muon nhap password khac."<<endl;
		cout<<"Nhan 2 de tro ve trang chu."<<endl;
		do {
			fflush(stdin);
			choice2=_getch();
			fflush(stdin);
			if(choice2!='1'&&choice2!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice2!='1'&&choice2!='2');
		if(choice2=='1') return change_password(acc);
		else return mainmenu(acc);
	}
}
// Reset mat khau
void reset_password() {
	system("cls");
	string ID, password, username;
	cout << "Nhap ID da cho : " << endl;
	char key;
	while (1) {
		cin.clear();
		fflush(stdin);
		getline(cin, ID);
		if (check_ID_in_file(ID) == 1) { //TO DO
			cout << "ID hop le" << endl;
			break;
		} else {
			cout << "ID khong ton tai.Xin vui long nhap lai ID hop le."<<endl;
			cout<<"Trong truong hop chua co ID hop le, xin vui long dang ky thong tin ca nhan truoc."<<endl;
			cout<<"Nhan 1 de tiep tuc nhap ID khac"<<endl;
			cout<<"Nhan bat ky de tro ve."<<endl;
			fflush(stdin);
			key=_getch();
			fflush(stdin);
			if(key=='1') {
				return reset_password();
			} else return firstmenu();
		}
	}
	cout<<"Nhap password cua thong tin nguoi dung: "<<endl;
	while (1) {
		cin.clear();
		fflush(stdin);
		getline(cin, password);
		if (check_ID_password_in_file(password) == 1) { //TO DO
			cout << "Mat khau hop le" << endl;
			break;
		} else {
			cout << "Mat khau khong dung.Xin vui long nhap lai t u dau."<<endl;
			cout<<"Nhan 1 de tiep tuc nhap ID va mat khau khac."<<endl;
			cout<<"Nhan bat ky de tro ve."<<endl;
			fflush(stdin);
			key=_getch();
			fflush(stdin);
			if(key=='1') {
				return reset_password();
			} else return firstmenu();
		}
	}
	int check_account_username_and_ID(string username, string ID);
	char key3='1';
	while (key3='1') {
		cout<<"Nhap tai khoan ban muon reset mat khau: "<<endl;
		cin.clear();
		fflush(stdin);
		getline(cin, username);
		if (check_account_username_and_ID(username,ID) == 1) { //TO DO
			reset_password_function(username);
			cout << "Mat khau moi da duoc gui toi email cua ban. Kiem tra email de biet them chi tiet." << endl;
			fflush(stdin);
			char choice;
			choice=_getch();
			fflush(stdin);
			return firstmenu();
		} else {
			cout << "Khong ton tai tai khoan."<<endl;
			cout<<"Nhan 1 de tiep tuc nhap tai khoan khac."<<endl;
			cout<<"Nhan bat ky de tro ve."<<endl;
			fflush(stdin);
			key3=_getch();
			fflush(stdin);
			if(key3!='1') return firstmenu();
		}
	}
}
//Doi thong tin nguoi dung
void change_user_infomation_choice_function(string ID, string change, int choice) {
	fstream outfile;
	outfile.open("user.txt", ios::in);
	fstream temp1;
	temp1.open("temp.txt", ios::out);
	string datatemp;
	user *temp=new user();
	int flag=0;
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
		if (ID != temp->getID()&&(temp->getID() != "")) {
			temp1 << temp->getName() << '\n' << temp->getCMND() << '\n' << temp->getID() << '\n' << temp->getPassword() << '\n' << temp->getPhone()<<'\n'<< temp->getAddress()<<'\n'<< temp->getBirthday() << '\n'<<temp->getEmail()<<'\n'<< temp->getJob()<<'\n'<<temp->getActive()<< endl;
		}
		if(ID==temp->getID()&&choice==1) {
			temp1 << temp->getName() << '\n' << temp->getCMND() << '\n' << temp->getID() << '\n' << temp->getPassword() << '\n' << change<<'\n'<< temp->getAddress()<<'\n'<< temp->getBirthday() << '\n'<<temp->getEmail()<<'\n'<< temp->getJob()<<'\n'<<temp->getActive()<< endl;
		}
		if(ID==temp->getID()&&choice==2) {
			temp1 << temp->getName() << '\n' << temp->getCMND() << '\n' << temp->getID() << '\n' << temp->getPassword() << '\n' << temp->getPhone()<<'\n'<< change<<'\n'<< temp->getBirthday() << '\n'<<temp->getEmail()<<'\n'<< temp->getJob()<<'\n'<<temp->getActive()<< endl;
		}
		if(ID==temp->getID()&&choice==3) {
			temp1 << temp->getName() << '\n' << temp->getCMND() << '\n' << temp->getID() << '\n' << temp->getPassword() << '\n' << temp->getPhone()<<'\n'<< temp->getAddress()<<'\n'<< change << '\n'<<temp->getEmail()<<'\n'<< temp->getJob()<<'\n'<<temp->getActive()<< endl;
		}
		if(ID==temp->getID()&&choice==4) {
			temp1 << temp->getName() << '\n' << temp->getCMND() << '\n' << temp->getID() << '\n' << temp->getPassword() << '\n' << temp->getPhone()<<'\n'<< temp->getAddress()<<'\n'<< temp->getBirthday() << '\n'<<change<<'\n'<< temp->getJob()<<'\n'<<temp->getActive()<< endl;
		}
		if(ID==temp->getID()&&choice==5) {
			temp1 << temp->getName() << '\n' << temp->getCMND() << '\n' << temp->getID() << '\n' << temp->getPassword() << '\n' << temp->getPhone()<<'\n'<< temp->getAddress()<<'\n'<< temp->getBirthday() << '\n'<<temp->getEmail()<<'\n'<< change <<'\n'<<temp->getActive()<< endl;
		}
	}
	temp1.close();
	outfile.close();
	remove("user.txt");
	rename("temp.txt", "user.txt");
}

void change_phone_user(string ID) {
	string phone;
	cout << "Nhap So dien thoai (khong khoang trang): " << endl;
	do {
		cin.clear();
		fflush(stdin);
		getline(cin,phone);
		if (check_number(phone)==0||phone.length()<5) cout << "Nhap lai so dien thoai cho hop le: " << endl;
	} while (check_number(phone)==0||phone.length()<5);
	change_user_infomation_choice_function(ID,phone,1);
	return change_user_infomation_function(ID);
}

void change_address_user(string ID) {
	string address;
	fflush(stdin);
	cout << "Nhap dia chi: " << endl;
	do {
		cin.clear();
		fflush(stdin);
		getline(cin, address);
		address=uppercase(address);
		if(address=="") cout<<"Khong duoc de trong dia chi"<<endl;
	} while(address=="");

	change_user_infomation_choice_function(ID,address,2);
	return change_user_infomation_function(ID);

}

void change_birthday_user(string ID) {
	string birthday;
	fflush(stdin);
	birthday=input_date();
	fflush(stdin);
	change_user_infomation_choice_function(ID,birthday,3);
	return change_user_infomation_function(ID);

}

void change_email_user(string ID) {
	string email;
	cout << "Nhap email (khong khoang trang): " << endl;
	char choiceemail='0';
	do {
		choiceemail='0';
		cin.clear();
		fflush(stdin);
		getline(cin,email);
		if (email=="") cout << "Khong duoc bo trong email. Nhap lai email cho hop le: " << endl;
		if(check_email_in_file(email)==1||check_email_in_waiting(email)==1) {
			cout<<"Email cua ban da duoc dung de dang ky. Xin vui long kiem tra lai."<<endl;
			cout<<"Nhan 1 neu ban muon nhap mot so Email khac."<<endl;
			cout<<"Nhan 2 de tro ve."<<endl;
			do {
				fflush(stdin);
				choiceemail=_getch();
				fflush(stdin);
				if(choiceemail!='1'&&choiceemail!='2') cout<<"Hay bam lua chon dung"<<endl;
			} while(choiceemail!='1'&&choiceemail!='2');
		}
		if(choiceemail=='1') {
			cout<<"Moi nhap lai email: "<<endl;
		}
		if(choiceemail=='2') return change_user_infomation_function(ID); /////////////////////////// TO DO
	} while (email==""||(choiceemail=='1'));
	change_user_infomation_choice_function(ID,email,4);
	return change_user_infomation_function(ID);
}

void change_job_user(string ID) {
	string job;
	cout << "Nhap nghe nghiep: " << endl;
	do {
		cin.clear();
		fflush(stdin);
		getline(cin, job);
		if(job==""||check_string(job)==0) cout<<"Cong viec khong hop le, hay nhap dung."<<endl;
	} while(job==""||check_string(job)==0);
	job=uppercase(job);
	change_user_infomation_choice_function(ID,job,5);
	return change_user_infomation_function(ID);

}

user getinfouser(string ID) {
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
		if (temp->getID()==ID) {
			return *temp;
			outfile.close();
		}
	}
	outfile.close();
}
void change_user_infomation_function(string ID) {
	system("cls");
	user *newUser=new user();
	*newUser=getinfouser(ID);
	cout<<"Ho va ten: "<<newUser->getName()<<endl;
	cout<<"CMND: "<<newUser->getCMND()<<endl;
	cout<<"SDT: "<<newUser->getPhone()<<endl;
	cout<<"Dia chi: "<<newUser->getAddress()<<endl;
	cout<<"Ngay sinh: "<<getDay(newUser->getBirthday())<<endl;
	cout<<"Email: "<<newUser->getEmail()<<endl;
	cout<<"Nghe nghiep: "<<newUser->getJob()<<endl;
	find_all_account_with_user_id_function(newUser);
	printline();
	cout<<"1. Thay doi SDT"<<endl;
	cout<<"2. Thay doi dia chi"<<endl;
	cout<<"3. Thay doi ngay sinh"<<endl;
	cout<<"4. Thay doi email"<<endl;
	cout<<"5. Thay doi nghe nghiep"<<endl;
	cout<<"6. Tro ve"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6');
	if(choice=='1') change_phone_user(ID);
	if(choice=='2') change_address_user(ID);
	if(choice=='3') change_birthday_user(ID);
	if(choice=='4') change_email_user(ID);
	if(choice=='5') change_job_user(ID);
	if(choice=='6') return firstmenu();
}
void change_user_infomation() {
	system("cls");
	string ID, password;
	cout << "Nhap ID da cho : " << endl;
	char key;
	while (1) {
		cin.clear();
		fflush(stdin);
		getline(cin, ID);
		if (check_ID_in_file(ID) == 1) { //TO DO
			cout << "ID hop le" << endl;
			break;
		}
		else {
			cout << "ID khong ton tai.Xin vui long nhap lai ID hop le." << endl;
			cout << "Trong truong hop chua co ID hop le, xin vui long dang ky thong tin ca nhan truoc." << endl;
			cout << "Nhan 1 de tiep tuc nhap ID khac" << endl;
			cout << "Nhan bat ky de tro ve." << endl;
			fflush(stdin);
			key = _getch();
			fflush(stdin);
			if (key == '1') {
				return change_user_infomation();
			}
			else return firstmenu();
		}
	}
	cout << "Nhap password cua thong tin nguoi dung: " << endl;
	while (1) {
		cin.clear();
		fflush(stdin);
		getline(cin, password);
		if (check_ID_password_in_file(password) == 1) { //TO DO
			cout << "Mat khau hop le" << endl;
			break;
		}
		else {
			cout << "Mat khau khong dung.Xin vui long nhap lai t u dau." << endl;
			cout << "Nhan 1 de tiep tuc nhap ID va mat khau khac." << endl;
			cout << "Nhan bat ky de tro ve." << endl;
			fflush(stdin);
			key = _getch();
			fflush(stdin);
			if (key == '1') {
				return change_user_infomation();
			}
			else return firstmenu();
		}
	}

	change_user_infomation_function(ID);
}

