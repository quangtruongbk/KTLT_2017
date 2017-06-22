#include"Assignment.h"

//USER
user::user() {}
user::user(user *newUser) {
	name = newUser->getName();
	CMND = newUser->getCMND();
	ID=newUser->getID();
	password=newUser->getPassword();
	phone = newUser->getPhone();
	address = newUser->getAddress();
	active=newUser->getActive();
	birthday=newUser->getBirthday();
	email=newUser->getEmail();
	job=newUser->getJob();
}
user::user(string newName, string newCMND, string newPassword, string newPhone, string newAddress, string newBirthday, string newEmail, string newJob, string newActive) {
	name = newName;
	CMND = newCMND;
	create_id();
	password=newPassword;
	phone = newPhone;
	address = newAddress;
	active="1";
	birthday=newBirthday;
	email=newEmail;
	job=newJob;
}
void user::create_id() {
	do {
		srand (time(NULL));
		int secret_random_extended_id = rand() % 1000;
		stringstream ss2;
		ss2 << secret_random_extended_id;
		string secret_string = ss2.str();
		ID=name[0]+CMND+secret_string;
	} while(check_ID_in_file(ID)==1||check_ID_in_waiting( ID) ==1);
}
void user::setName(string newName) {
	this->name=newName;
}
string user::getName() {
	return this->name;
}
void user::setCMND(string newCMND) {
	this->CMND=newCMND;
}
string user::getCMND() {
	return this->CMND;
}
void user::setID(string newID) {
	this->ID=newID;
}

string user::getID() {
	return this->ID;
}

void user::setPassword(string newPassword) {
	this->password=newPassword;
}

string user::getPassword() {
	return this->password;
}

void user::setPhone(string newPhone) {
	this->phone=newPhone;
}

string user::getPhone() {
	return this->phone;
}

void user::setAddress(string newAddress) {
	this->address=newAddress;
}

string user::getAddress() {
	return this->address;
}

void user::setBirthday(string newBirthday) {
	this->birthday=newBirthday;
}

string user::getBirthday() {
	return this->birthday;
}

void user::setEmail(string newEmail) {
	this->email=newEmail;
}

string user::getEmail() {
	return this->email;
}

void user::setJob(string newJob) {
	this->job=newJob;
}

string user::getJob() {
	return this->job;
}

void user::setActive(string newActive) {
	this->active=newActive;
}

string user::getActive() {
	return this->active;
}

void user::add_user_to_verify() {
	//dua qua cho manager duyet xem co duoc khong bang cach gan vao file manageuser.txt
	//tao mot chuoi nhieu doi tuong, copy het du lieu vao doi tuong temp nao do, sau do neu ok
	// thi chay ham add
	fstream outfile;
	outfile.open("manageuser.txt", ios_base::app);
	outfile << name << "\n";
	outfile << CMND << "\n";
	outfile << ID << "\n";
	outfile << password << "\n";
	outfile << phone << "\n";
	outfile << address << "\n";
	outfile  << birthday<<"\n";
	outfile << email << "\n";
	outfile << job << "\n";
	outfile << active << "\n";
	outfile.close();
}
void user::add_user_to_list() {
	//neu ok thi gan vao danh sach chinh thuc
	fstream outfile;
	outfile.open("user.txt", ios_base::app);
	outfile << name << "\n";
	outfile << CMND << "\n";
	outfile << ID << "\n";
	outfile << password << "\n";
	outfile << phone << "\n";
	outfile << address << "\n";
	outfile  << birthday<<"\n";
	outfile << email << "\n";
	outfile << job << "\n";
	outfile << active << "\n";
	outfile.close();
}

user::~user(){}
/////////////////////////////////////////////////////////////
//ACCOUNT
account::account() {};
account::account(string newUsername, string newPass, string newID, string newRole) {
	username = newUsername;
	password = newPass;
	ID = newID;
	role=newRole;
	active="1";
}
void account::setUsername(string newUsername) {
	this->username=newUsername;
}
string account::getUsername() {
	return this->username;
}
void account::setPassword(string newPassword) {
	this->password=newPassword;
}
string account::getPassword() {
	return this->password;
}
void account::setID(string newID) {
	this->ID=newID;
}
string account::getID() {
	return this->ID;
}
void account::setRole(string newRole) {
	role=newRole;
}
string account::getRole() {
	return this->role;
}
void account::setActive(string newActive) {
	this->active=newActive;
}
string account::getActive() {
	return this->active;
}
void account::add_account_to_grant_permission() {
	fstream outfile;
	outfile.open("permissionaccount.txt", ios_base::app);
	outfile << username << "\n";
	outfile << password << "\n";
	outfile << ID <<"\n";
	outfile << role << "\n";
	outfile << active <<"\n";
	outfile.close();
}
void account::add_account_to_list() {
	fstream outfile;
	outfile.open("account.txt", ios_base::app);
	outfile << username << "\n";
	outfile << password << "\n";
	outfile << ID << "\n";
	outfile << role << "\n";
	outfile << active <<"\n";
	outfile.close();
}

account::~account(){
	}
////////////////////////////////////////////////////////////////
//Annoucement
announcement::announcement() {};
announcement::announcement(string newAnnouce, string newDate, string newSeen, string role_send, account *acc) {
	this->ID=create_ID();
	if(role_send=="3") newAnnouce="[THU THU: "+acc->getUsername()+"]"+newAnnouce;
	if(role_send=="2") newAnnouce="[HE THONG: "+acc->getUsername()+"]"+newAnnouce;
	if(role_send=="1") newAnnouce="[NGUOI DUNG: "+acc->getUsername()+ "]"+newAnnouce;
	this->announce=newAnnouce;
	this->date=newDate;
	this->seen=newSeen;
}

void announcement::setAnnounce(string newAnnounce) {
	this->announce=newAnnounce;
}
string announcement::getAnnounce() {
	return this->announce;
}
void announcement::setDate(string newDate) {
	this->date=newDate;
}
string announcement::getDate() {
	return this->date;
}
void announcement::setSeen(string newSeen) {
	this->seen=newSeen;
}
string announcement::getSeen() {
	return this->seen;
}
void announcement::setID(string newID) {
	this->ID=newID;
}
string announcement::getID() {
	return this->ID;
}
void announcement::send_to_user(string username) {
		fstream outfile;
	string filetemp="temp_"+username+".txt";
	outfile.open(filetemp.c_str(), ios_base::app);
	outfile << "1" << "\n";
	outfile << announce << "\n";
	outfile << date <<"\n";
	outfile << seen << "\n";
	outfile.close();
	fstream outfilereal;
	string filename="announcement_"+username+".txt";
	string datatemp;
	outfile.open(filetemp.c_str(), ios_base::app);
	outfilereal.open(filename.c_str(), ios_base::app| ios::in);
	if (!outfilereal) {
		outfilereal.clear();
		outfilereal.open(filename.c_str(),ios::out|ios::binary);
		outfilereal.close();
		outfilereal.open(filename.c_str(), ios_base::app | ios::in);
	}
	int count=1;
	int STT;
	while(getline(outfilereal,datatemp)) {
		if(count%4==1) {
			STT=atoi(datatemp.c_str());
			STT++;
			datatemp=from_int_to_string(STT);
		}
		outfile << datatemp << "\n";
		count++;
	}
	outfilereal.close();
	outfile.close();
	remove(filename.c_str());
	rename(filetemp.c_str(),filename.c_str());
}
string announcement::create_ID() {
	string newID;
	do {
		newID=randomstring();
	} while(check_ID_Announcement_in_archive(newID)==1);
	return newID;
}

