#include "Assignment.h"
 ////////////////////////////////////////////////////////////TODO
void firstmenu(){
	system("cls");
	char choice;
	cout<<"Check thu 1 2 3 chu chua co lam function nay"<<endl;
	cout<<"Nhap 1 de vao menu, nhap 2 vao test: "<<endl;
	cin>>choice;
	if(choice==1)cout<<"1. Menu"<<endl;
	if(choice==2)cout<<"2. Menu test"<<endl;
}

////////////////////////////////////////////////////////////////////
//Dang nhap

int login(string username, string password, account *&acc) {
	account *temp=new account();
	fstream outfile;
	string datatemp;
	outfile.open("account.txt", ios::in);
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		temp->setUsername(datatemp);
		getline(outfile,datatemp);
		temp->setPassword(datatemp);
		getline(outfile,datatemp);
		getline(outfile,datatemp);
		getline(outfile,datatemp);
		if (temp->getUsername() == username&&temp->getPassword() == password) {
			outfile.close();
			return 1;
		}
	}
	outfile.close();
	return 0;
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
while (!outfile.eof()){
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
				regist_account();
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
	char choice;
	choice=_getch();
	return firstmenu();
}

//////////////////////////////////////////////////////////
//Dang ky account
void regist_user() {
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
			do{
				fflush(stdin);
				choiceCMND=_getch();
				fflush(stdin);
				if(choiceCMND!='1'&&choiceCMND!='2') cout<<"Hay bam lua chon dung"<<endl;
				}while(choiceCMND!='1'&&choiceCMND!='2');
		}
		if(choiceCMND=='1'){
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
	do{
		cin.clear();
		fflush(stdin);
		getline(cin, address);
		address=uppercase(address);
	if(address=="") cout<<"Khong duoc de trong dia chi"<<endl;
	}while(address=="");
	fflush(stdin);
	birthday=input_date();
	fflush(stdin);
	cout << "Nhap email (khong khoang trang) (lon hon 9 chu so theo luat Viet Nam): " << endl;
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
			do{
				fflush(stdin);
				choiceemail=_getch();
				fflush(stdin);
				if(choiceemail!='1'&&choiceemail!='2') cout<<"Hay bam lua chon dung"<<endl;
				}while(choiceemail!='1'&&choiceemail!='2');
		}
		if(choiceemail=='1'){
			cout<<"Moi nhap lai email: "<<endl;
		}
		if(choiceemail=='2') return firstmenu(); /////////////////////////// TO DO
	} while (email==""||(choiceemail=='1'));
	cout << "Nhap nghe nghiep: " << endl;
	do{
		cin.clear();
		fflush(stdin);
		getline(cin, job);
	if(job==""||check_string(job)==0) cout<<"Cong viec khong hop le, hay nhap dung."<<endl;
	}while(job==""||check_string(job)==0);
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

