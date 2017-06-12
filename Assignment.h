#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<time.h>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#define MAXROLE 3
#define MAXIDANNOUCEMENT 5
#define MAXIDBOOK 5
#define MAXCATEGORY 12
#pragma warning(disable:4996)
using namespace std;

// Class va struct
struct date {
	int day;
	int month;
	int year;
};

struct Book {
	string ISBN;
	string name;
	string author;
	string category;
	string publisher;
	int year;
	int amount;
	int price;
};

static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";


char genRandom();
string randomstring();
class announcement {
	private:
		string ID;
		string announce;
		string date;
		string seen;
		string role_send;
	public:
		string create_ID();
		announcement();
		announcement(string newAnnouce, string newDate, string newSeenstring,string role_send);
		void setAnnounce(string newAnnouce);
		string getAnnounce();
		void setDate(string newDate);
		string getDate();
		void setSeen(string newSeen);
		string getSeen();
		void setID(string newID);
		string getID();
		void send_to_user(string username);

};

class user {
	private:
		string CMND;
		string name;
		string phone;
		string address;
		string ID;
		string active;
		string email;
		string job;
		string birthday;
		string password;
	public:
		void create_id();
		user();
		user(string newName, string newCMND, string newPassword, string newPhone, string newAddress, string newBirthday, string newEmail, string newJob, string newActive);
		user(user *newUser);
		void setName(string newName);
		string getName();
		void setCMND(string newCMND);
		string getCMND();
		void setID(string newID);
		string getID();
		void setPassword(string newPassword);
		string getPassword();
		void setPhone(string newPhone);
		string getPhone();
		void setAddress(string newAddress);
		string getAddress();
		void setBirthday(string newBirthday);
		string getBirthday();
		void setEmail(string newEmail);
		string getEmail();
		void setJob(string newJob);
		string getJob();
		void setActive(string newActive);
		string getActive();
		void add_user_to_verify();
		void add_user_to_list();
};

class account {
	private:
		string username;
		string password;
		string role;
		string ID;
		string active;
	public:
		account();
		account(string newUsername, string newPass, string newID, string newRole);
		void setUsername(string newUsername);
		string getUsername();
		void setPassword(string newPassword);
		string getPassword();
		void setID(string newID);

		string getID();
		void setRole(string newRole);
		string getRole();
		void setActive(string newActive);
		string getActive();
		void add_account_to_grant_permission();
		void add_account_to_list();
};

//Supporting Function
string uppercase(string name); //Viet hoa toan bo chu
string from_int_to_string(int N);
int check_valid_date(date date_struct);
string input_date();
int check_number(string N);
int check_string(string N); //Viet lai ham nay cho day du
int check_username_blank_space(string username);
int check_username_legal(string username);
int check_not_blankspace(string N);
string getDay(string send_day);
string currentDateTime();
string randomstring();
string getCategoryBook(string choice);
int get_category_number(string category, int categoryarray[MAXCATEGORY]);
string print_category(string category);
//Function to check exist of ID and username and CMND
int check_ID_in_file(string ID); //check su ton tai cua ID trong user.txt
int check_ID_in_waiting(string ID);//Check su ton tai cua ID trong manageuser.txt
int check_account_username(string username, account*&temp); //check su ton tai cua Username trong account.txt
int check_CMND_in_waiting(string CMND);
int check_CMND_in_file(string CMND);
int check_CMND_exist(string CMND);
int check_ID_Announcement_in_file(account *acc, string ID);
int check_ID_Announcement_in_archive(string ID);
int check_ISBN_Book(string ID);
//Function that use for all user
void firstmenu(); ////////////////////////////////////////////////////////////TODO
int login(string username, string password, account *&acc);
void regist_account();
void regist_user();
void change_account_password_function(string account_username, string newPassword); //doi mat khau cua minh
void change_account_password(); //To do
void show_all_user_infomation();//To do
void change_user_password();
int get_price(account *acc);
void show_cart(account *acc);
void delete_single_book_cart_function(account *acc, string ISBN);
void delete_entire_cart(account *acc);
string get_date_now();
string getDay(string send_day);
string currentDateTime();
//Function for User Manager
void delete_in_permissionaccount(string username);
void change_role_function(string username, string newRole);
void grant_new_role(); //TO DO
void change_role();//TO DO

void delete_user_in_manage_user(string ID);
void verify_user_function(string ID);
void verify_user(); //To do

//Function for Reader
void search_book_all();//To do
void search_book_by_name();//TO do
void search_book_by_author();//To do
void search_book(); //To do 1

void borrow_book();//3
void cart(); //Gio hang TO DO //4
void paid(); //To do //5
void list_of_book_not_repay();
void lost_book();
void list_of_fee();
void delete_cart(account *acc);
void show_announcement(account *acc);
void set_announcement_already_seen(string ISBN, account *acc);
void show_all_announcement(account *acc);
void set_announcement_already_seen(string ISBN);
void read_announcement_with_ID(account *acc);
void read_announcement(account *acc);
void delete_already_seen_announcement(account *acc);
void delete_entire_announcement(account *acc);


//Function for Librarian
void add_new_book(); //2
void delete_book(); //3
void fine_reader_lost_book(); //4 //phat mat sach
void fine_reader_late_pay_book(); //5 //phat tre sach
void add_announcement_to_archive(announcement *newAnnouce,account *acc_librarian ,string usernamethatsend);
void send_announcement_to_all_reader(account *acc);
void send_announcement_to_individual(account *acc_librarian,string role_send);
void send_announcement(account *acc);
void add_book_to_store_function(account *acc, Book *newBook);
void add_book_to_store(account *acc);
void add_book(account *acc);
//Function for book
int getbook(Book& book,fstream& outfile, int row);
void printline();
void printtitle();
void showbookinfo(Book& book,int count);
void show_all_book();
void putinfo(Book& book,string& info);
void setbookinfo(string& info, Book book,int key);
void find_key(string str, int selection);
void search_key(string str);
void search_name(string str);
string create_ID_book();


#endif
