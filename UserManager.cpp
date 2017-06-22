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
	 while (!outfile.eof()) {
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
	}
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
	while (!outfile.eof()) {
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
	} 
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
	while (!outfile.eof()) {
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
	} 
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
	while (!outfile.eof()) {
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
// TO DOOOOOOOOOO
void reset_password(account *usermanager) {
	string username;
	do {
		cout<<"Nhap username cua account can reset password: "<<endl;
		getline(cin,username);
		if(username=="") cout<<"Khong duoc de trong, hay nhap lai: "<<endl;
	} while(username=="");

}

////////////////////
void change_active_account(account *acc, string username, string newActive) {
	fstream outfile;
	outfile.open("account.txt", ios::in);
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	account *tempaccount=new account();
	int flag=0;

	while (!outfile.eof()) {
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
		if(username==tempaccount->getUsername()) {
			temp << tempaccount->getUsername() << '\n' << tempaccount->getPassword() << '\n' << tempaccount->getID() << '\n' << tempaccount->getRole() << '\n' << newActive << endl;
		}
	}
	temp.close();
	outfile.close();
	remove("account.txt");
	rename("temp.txt", "account.txt");
}

/////////////
user show_all_user_infomation_function(account *acc_manager, string ID){
	fstream outfile;
	outfile.open("user.txt", ios::in);
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
			outfile.close();
			return *temp;
		}

	}
	outfile.close();
}

string getrolestring(string role){
	string rolestring;
	if(role[0]=='1') rolestring=rolestring+"DOC GIA"+"-";
	if(role[1]=='1') rolestring=rolestring+"THU THU-";
	if(role[2]=='1') rolestring=rolestring+"QUAN LY NGUOI DUNG";
	if(role[0]=='0'&&role[1]=='0'&&role[2]=='0') rolestring="CHUA CO VAI TRO";
	return rolestring;
}

void find_all_account_with_user_id_function(user *newuser){
	fstream outfile;
	outfile.open("account.txt", ios::in);
	string datatemp;
	account *tempaccount=new account();
	while (!outfile.eof()) {
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

void printtiletleuser(){
	printline();
	cout << "|      ID       |                      Ho va ten                |        CMND         |                Email               |              Dien thoai            |\n";
	printline();
}
void printtiletleaccount(){
	printline();
	cout << "|                     Username                  |         ID         |                        Vai tro                     |              Trang thai            |\n";
	printline();
}
void printuserinfo(user *temp){
	cout<<"|"<<setw(15)<<left<<temp->getID()<<"|";
	if(temp->getName().length()<=47) cout<<setw(47)<<temp->getName()<<"|";
	if(temp->getName().length()>47){
		for (int i=0;i<44;i++) cout<<temp->getName()[i]; 
		cout<<"...|";
		}	
	cout<<setw(21)<<temp->getCMND()<<"|";
	if(temp->getEmail().length()<=36) cout<<setw(36)<<temp->getEmail()<<"|";
	if(temp->getEmail().length()>36){
		 for(int i=0;i<33;i++) cout<<temp->getEmail()[i];
		cout<<"...|";
		}
	cout<<setw(36)<<temp->getPhone()<<"|";
	cout<<endl;
}

void printaccountinfo(account *temp){
	if(temp->getUsername().length()<=47) cout<<"|"<<setw(47)<<left<<temp->getUsername()<<"|";
	else{
		cout<<"|";
		for (int i=0;i<44;i++) cout<<temp->getUsername()[i];
		cout<<"...|";
	}
	cout<<setw(20)<<temp->getID()<<"|"<<setw(52)<<getrolestring(temp->getRole())<<"|";
	if(temp->getActive()=="1") cout<<setw(36)<<"Dang hoat dong"<<"|";
	if(temp->getActive()=="0") cout<<setw(36)<<"Da bi khoa"<<"|";
	cout<<endl;
}
void search_user(account *acc, string userinfo, int searchchoice){
	fstream outfile;
	outfile.open("user.txt", ios::in);
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
}

void search_account(account *acc, string accountinfo, int searchchoice){
	fstream outfile;
	outfile.open("account.txt", ios::in);
	string datatemp;
	int count = 1;
	account *temp=new account();
	while (!outfile.eof()) {
		getline(outfile, datatemp);
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
		
		if (searchchoice == 3 && getrolestring(temp->getRole()).find(accountinfo,0)!=-1) {
			printaccountinfo(temp);
		}
	}
	outfile.close();
} 

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
//	if(choice=='4') //To Doooooooooooooooo
}

