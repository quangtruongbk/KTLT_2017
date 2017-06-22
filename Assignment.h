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
#define MAXRESETPASSWORD 8
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
		~user();
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
		~account();
};

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
		announcement(string newAnnouce, string newDate, string newSeenstring,string role_send,account *acc);
		void setAnnounce(string newAnnouce);
		string getAnnounce();
		void setDate(string newDate);
		string getDate();
		void setSeen(string newSeen);
		string getSeen();
		void setID(string newID);
		string getID();
		void send_to_user(string username);
		~announcement();
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
string getCurrentDate();
int distance_date(string dateborrow);

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
int check_email_in_file(string email);
int check_email_in_waiting(string email);
int check_exist_in_book_people_want_to_borrow_file(account *acc_reader);
int count_number_of_book_approve(account *acc);
int count_number_of_book_waiting_file(account *acc);
int count_number_of_waiting_of_each_person(account *acc);
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
void reset_password_function(string account_username);
void change_active_account(account *acc, string username, string newActive);
user show_all_user_infomation_function(account *acc_manager, string ID);
string getrolestring(string role);
void find_all_account_with_user_id_function(user *newuser);
void search_user(account *acc, string userinfo, int searchchoice);
void search_account(account *acc, string accountinfo, int searchchoice);
void send_announcement_user_manager(account *acc);
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
	void read_announcement_with_ID_function(account *acc, string ID);
void read_announcement_with_ID(account *acc);
void read_announcement(account *acc);
void delete_already_seen_announcement(account *acc);
void delete_entire_announcement(account *acc);
void show_book_via_category();
void add_to_demand_borrow_function(account *acc,string ISBN);
void send_demand_borrow_to_librarian_function(account *acc_reader);
int getbookinfomation(Book& book, string ISBN);
int count_number_of_book_demand(account *acc);
void delete_single_book_in_demand_function(account *acc, int count);
void show_demand_function(account *acc);
void send_announcement_reader(account *acc);
void delete_single_book_in_waiting_of_each_person_function(account *acc, string ISBN);
//Function for Librarian
void add_new_book(); //2
void delete_book(); //3
void fine_reader_lost_book(); //4 //phat mat sach
void fine_reader_late_pay_book(); //5 //phat tre sach
void add_announcement_to_archive(announcement *newAnnouce,account *acc_librarian ,string usernamethatsend);
void send_announcement_to_all(account *acc, int sendto, string rolesend);
void send_announcement_to_individual(account *acc_librarian,string role_send);
void send_announcement(account *acc);
void add_book_to_store_function(account *acc, Book *newBook);
void add_book_to_store(account *acc);
void add_book(account *acc);
void change_price_book_in_store_function(account *acc, string ISBN, int newPrice);
void change_number_book_in_store_function(account *acc, string ISBN, int numberofchange);
void delete_after_approve_process(account *acc_librarian);
void approve_demand_function(account *acc_librarian);
void send_demand_to_waiting_line_function(account *acc_librarian) ;
int get_number_of_waiting_of_each_person_function(account *acc_reader);
void approve_waiting_function(account *acc_librarian, account *acc_reader, string ISBN);
int get_number_of_book_already_have_of_each_person_function(account *acc_reader);
void delete_after_waiting_process(account *acc_reader, string ISBN);
void get_all_book_waiting_infomation(account *acc_librarian, account *&acc_reader, Book *&booktemp);
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
