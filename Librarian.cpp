#include "Assignment.h"
// viet class Librarian
void librarian(account *acc);

void add_announcement_to_archive(announcement *newAnnouce,account *acc_librarian ,string usernamethatsend) {
	fstream outfile;
	string filename="archive_announcement_database.txt";
	outfile.open(filename.c_str(), ios_base::app);
	outfile << newAnnouce->getID() << "\n";
	outfile << newAnnouce->getAnnounce() << "\n";
	outfile << newAnnouce->getDate() <<"\n";
	outfile << acc_librarian->getUsername()<< "\n";
	outfile << usernamethatsend <<"\n";
	outfile.close();
}


//dung method trong class send_to_user

void send_announcement_to_all(account *acc, int sendto, string rolesend) {
	system("cls");
	string content,day;
	if(rolesend=="3") {
		if(sendto==0)cout<<"GUI THONG BAO CHO TOAN BO DOC GIA" <<endl;
		if(sendto==1)cout<<"GUI THONG BAO CHO QUAN LY NGUOI DUNG" <<endl;
	}
	if(rolesend=="2") {
		if(sendto==0)cout<<"GUI THONG BAO CHO TOAN BO DOC GIA" <<endl;
		if(sendto==2)cout<<"GUI THONG BAO CHO THU THU" <<endl;
	}
	if(rolesend=="1") {
		if(sendto==1)cout<<"GUI THONG BAO CHO QUAN LY NGUOI DUNG" <<endl;
		if(sendto==2)cout<<"GUI THONG BAO CHO THU THU" <<endl;
	}
	cout<<"Nhap noi dung thong bao: "<<endl;
	do {
		fflush(stdin);
		getline(cin,content);
		if(content=="") cout<<"Khong duoc de thong bao trong, hay nhap lai."<<endl;
	} while(content=="");
	day=currentDateTime();
	announcement *newAnnounce=new announcement(content,day,"0",rolesend,acc);
	fstream outfile;
	string datatemp;
	account *temp=new account();
	outfile.open("account.txt", ios::in);
	string role;
	while (!outfile.eof()) {
		getline(outfile,datatemp);
		temp->setUsername(datatemp);
		getline(outfile,datatemp);
		temp->setPassword(datatemp);
		getline(outfile,datatemp);
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setRole(datatemp);
		role=temp->getRole();
		getline(outfile,datatemp);
		temp->setActive(datatemp);
		if (role[sendto] == '1') {
			newAnnounce->send_to_user(temp->getUsername());
		}
	}
	outfile.close();
	if(sendto==0)	add_announcement_to_archive(newAnnounce,acc,"all reader");
	if(sendto==1)	add_announcement_to_archive(newAnnounce,acc,"all user manager");
	if(sendto==2) 	add_announcement_to_archive(newAnnounce,acc,"all librarian");
	cout<<"Thong bao da duoc gui. Nhan bat ky de tro ve."<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	if(rolesend=="3")	return send_announcement(acc);
	if(rolesend=="2") 	return send_announcement_user_manager(acc);
	if(rolesend=="1")	return send_announcement_reader(acc);
}


void send_announcement_to_individual(account *acc,string role_send) {
	system("cls");

	cout<<"GUI THONG BAO CHO CA NHAN DOC GIA" <<endl;
	account *temp=new account();
	string username_to_send;
	cout<<"Nhap username ma ban muon gui: "<<endl;
	getline(cin,username_to_send);
	if(check_account_username(username_to_send, temp)==0) {
		cout<<"Username khong dung"<<endl;
		cout<<"Nhan 1 de nhap lai username khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		char choice;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1' &&role_send=="3") return send_announcement_to_individual(acc,role_send);
		if(choice=='2' &&role_send=="3") return send_announcement(acc);
		if(choice=='2' &&role_send=="2") return send_announcement_user_manager(acc);

	}
	if(check_account_username(username_to_send, temp)==1) {
		string content,day;
		cout<<"Nhap noi dung thong bao: "<<endl;
		do {
			fflush(stdin);
			getline(cin,content);
			if(content=="") cout<<"Khong duoc de thong bao trong, hay nhap lai."<<endl;
		} while(content=="");
		day=currentDateTime();
		announcement *newAnnounce=new announcement(content,day,"0",role_send,acc);
		newAnnounce->send_to_user(username_to_send);
		add_announcement_to_archive(newAnnounce,acc,username_to_send);
		cout<<"Thong bao da duoc gui. Nhan bat ky de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		if(role_send=="3")return send_announcement(acc);
		if(role_send=="2") return send_announcement_user_manager(acc);
	}
}
void send_announcement(account *acc) {
	system("cls");
	cout<<"CHUC NANG GUI THONG BAO CUA ACCOUNT: "<<acc->getUsername()<<endl;
	cout<<"1. Gui thong bao cho toan bo doc gia."<<endl;
	cout<<"2. Gui thong bao cho mot ca nhan doc gia."<<endl;
	cout<<"3. Gui thong bao cho quan ly nguoi dung."<<endl;
	cout<<"4. Tro ve."<<endl;
	fflush(stdin);
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4');
	if(choice=='1') send_announcement_to_all(acc,0,"3");
	if(choice=='2') send_announcement_to_individual(acc,"3");
	if(choice=='3') send_announcement_to_all(acc,1,"3") ;
//	if(choice=='4') //To Doooooooooooooooo
}

//////////////
//Them sach vao store
void add_book_to_store_function(account *acc, Book *newBook) {
	fstream outfile;
	outfile.open("temp.txt", ios_base::app);
	outfile << newBook->ISBN << "\n";
	outfile << newBook->name << "\n";
	outfile << newBook->author <<"\n";
	outfile << newBook->category <<"\n";
	outfile << newBook->publisher << "\n";
	outfile << newBook->year << "\n";
	outfile << newBook->amount << "\n";
	outfile << newBook->price << "\n";
	outfile.close();
	fstream outfilereal;
	string datatemp;
	outfile.open("temp.txt", ios_base::app);
	outfilereal.open("book.txt", ios_base::app| ios::in);
	while(getline(outfilereal,datatemp)) {
		outfile << datatemp << "\n";
	}
	outfilereal.close();
	outfile.close();
	remove("book.txt");
	rename("temp.txt","book.txt");
}

void add_book_to_store(account *acc) {
	system("cls");
	cout<<"THEM SACH VAO KHO"<<endl;
	Book *newBook=new Book();
	char choiceISBN='1';
	cout << "Nhap ISBN cua sach: " << endl;
	do {
		fflush(stdin);
		getline(cin, newBook->ISBN);
		fflush(stdin);
		if (newBook->ISBN == "") cout << "Khong duoc de trong, yeu cau nhap lai" << endl;
		if (check_ISBN_Book(newBook->ISBN) == 1) {
			cout << "Ma ISBN da ton tai trong thu vien. " << endl;
			cout << "Nhan 1 de nhap ma khac, nhan bat ky de tro ve" << endl;
			fflush(stdin);
			choiceISBN = _getch();
			fflush(stdin);
			if (choiceISBN != '1') return add_book(acc);
		}
	} while ((newBook->ISBN == ""||check_ISBN_Book(newBook->ISBN)==1)&&choiceISBN=='1');
	cout<<"Nhap ten sach can them vao: "<<endl;
	do {
		fflush(stdin);
		getline(cin,newBook->name);
		newBook->name=uppercase(newBook->name);
		fflush(stdin);
		if(newBook->name=="") cout<<"Khong duoc de trong, yeu cau nhap lai"<<endl;
	} while(newBook->name=="");
	cout<<"Nhap ten tac gia: "<<endl;
	do {
		fflush(stdin);
		getline(cin,newBook->author);
		newBook->author=uppercase(newBook->author);
		fflush(stdin);
		if(newBook->author=="") cout<<"Khong duoc de trong, yeu cau nhap lai"<<endl;
	} while(newBook->author=="");
	cout<<"Chon the loai cho book"<<endl;
	cout<<"1.Van hoc \n2.Thieu nhi \n3.Ky nang, day nghe, nghe nghiep \n4.Kien thuc doi song \n5.Kinh te, tai chinh \n6.Giao khoa, tham khao, giao trinh. \n7.Tu dien \n8.Truyen tranh \n9.Tam ly\n10.Kien thuc tong hop\n11.Ngoai van\n12.The loai khac"<<endl;
	char continuechar='1';
	string category;
	string choicecategory;
	while(continuechar=='1') {
		do {
			cout<<"Hay chi chon lan luot 1 (khong khoang trang) lua chon va enter."<<endl;
			fflush(stdin);
			getline(cin,choicecategory);
			fflush(stdin);
			if(choicecategory==""||(choicecategory!="1"&&choicecategory!="2"&&choicecategory!="3"&&choicecategory!="4"&&choicecategory!="5"&&choicecategory!="6"&&choicecategory!="7"&&choicecategory!="8"&&choicecategory!="9"&&choicecategory!="10"&&choicecategory!="11"&&choicecategory!="12")) cout<<"Khong hop le, yeu cau nhap lai"<<endl;
		} while(choicecategory==""||(choicecategory!="1"&&choicecategory!="2"&&choicecategory!="3"&&choicecategory!="4"&&choicecategory!="5"&&choicecategory!="6"&&choicecategory!="7"&&choicecategory!="8"&&choicecategory!="9"&&choicecategory!="10"&&choicecategory!="11"&&choicecategory!="12"));
		category=category+" "+choicecategory;
		cout<<"Ban muon them the loai khac khong? "<<endl;
		cout<<"1.Co"<<endl<<"2.Khong"<<endl;
		fflush(stdin);
		continuechar=_getch();
		fflush(stdin);
	}
	newBook->category=category;
	cout<<"Nhap ten nha xuat ban can them vao: "<<endl;
	do {
		fflush(stdin);
		getline(cin,newBook->publisher);
		newBook->publisher=uppercase(newBook->publisher);
		fflush(stdin);
		if(newBook->publisher=="") cout<<"Khong duoc de trong, yeu cau nhap lai"<<endl;
	} while(newBook->publisher=="");
	cout<<"Nhap nam xuat ban: "<<endl;
	string temp;
	do {
		fflush(stdin);
		getline(cin,temp);
		if(temp!=""||check_number(temp)!=0)	newBook->year=atoi(temp.c_str());
		fflush(stdin);
		if(temp==""||check_number(temp)==0) cout<<"Khong hop le, yeu cau nhap lai"<<endl;
	} while(temp==""||check_number(temp)==0);
	cout<<"Nhap so luong trong kho"<<endl;
	do {
		fflush(stdin);
		getline(cin,temp);
		if(temp!=""||check_number(temp)!=0)	newBook->amount=atoi(temp.c_str());
		fflush(stdin);
		if(temp==""||check_number(temp)==0) cout<<"Khong hop le, yeu cau nhap lai"<<endl;
	} while(temp==""||check_number(temp)==0);
	cout<<"Nhap gia thue trong 1 ngay: "<<endl;
	do {
		fflush(stdin);
		getline(cin,temp);
		if(temp!=""||check_number(temp)!=0)	newBook->price=atoi(temp.c_str());
		fflush(stdin);
		if(temp==""||check_number(temp)==0) cout<<"Khong hop le, yeu cau nhap lai"<<endl;
	} while(temp==""||check_number(temp)==0);
	add_book_to_store_function(acc,newBook);
	cout<<"Da them xong. ";
}

void add_book(account *acc) {
	cout << "Chwa hien thuc" << endl;
}

void delete_book_in_store_function(account *acc, string ISBN) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("temp.txt",ios::out);
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
		if(ISBN!=temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n'<<temp->category<<'\n' << temp->publisher << '\n' << temp->year <<'\n' << temp->amount <<'\n'<<temp->price<< endl;
		}
	}
	outfile2.close();
	outfile.close();
	delete temp;
	remove("book.txt");
	rename("temp.txt", "book.txt");
}

void change_number_book_in_store_function(account *acc, string ISBN, int numberofchange) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("temp.txt",ios::out);
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

		if(ISBN!=temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n'<<temp->category<<'\n' << temp->publisher << '\n' << temp->year <<'\n' << temp->amount <<'\n'<<temp->price<< endl;
		}
		if(ISBN==temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n'<<temp->category<<'\n' << temp->publisher << '\n' << temp->year <<'\n' << temp->amount + numberofchange<<'\n'<<temp->price<< endl;
		}
	}
	outfile2.close();
	outfile.close();
	delete temp;
	remove("book.txt");
	rename("temp.txt", "book.txt");
}

void change_price_book_in_store_function(account *acc, string ISBN, int newPrice) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("temp.txt",ios::out);
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
		if(ISBN!=temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n'<<temp->category<<'\n' << temp->publisher << '\n' << temp->year <<'\n' << temp->amount <<'\n'<<temp->price<< endl;
		}
		if(ISBN==temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n'<<temp->category<<'\n' << temp->publisher << '\n' << temp->year <<'\n' << temp->amount <<'\n'<<newPrice<< endl;
		}
	}
	outfile2.close();
	outfile.close();
	delete temp;
	remove("book.txt");
	rename("temp.txt", "book.txt");
}



int count_number_of_waiting_book(account *acc) {
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


void delete_after_approve_process(account *acc_librarian) {
	fstream outfile;
	outfile.open("book_people_want_to_borrow.txt", ios_base::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_people_want_to_borrow.txt",ios::out);
		outfile.close();
		outfile.open("book_people_want_to_borrow.txt", ios::in);
	}
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	int counttemp=0;
	account *readertemp=new account();
	Book tempbook;
	while (getline(outfile, datatemp)) {
		readertemp->setID(datatemp);
		getline(outfile,datatemp);
		readertemp->setUsername(datatemp);
		getline(outfile,datatemp);
		tempbook.ISBN=datatemp;
		getline(outfile,datatemp);
		tempbook.name=datatemp;
		counttemp++;
		if (counttemp!=1) {
			temp<<readertemp->getID()<<endl<<readertemp->getUsername()<<endl<<tempbook.ISBN<<endl<<tempbook.name<<endl;
		}

	}
	temp.close();
	outfile.close();
	remove("book_people_want_to_borrow.txt");
	rename("temp.txt","book_people_want_to_borrow.txt");
}

void delete_after_waiting_process(account *acc_reader, string ISBN) {
	fstream outfile;
	outfile.open("book_waiting_line.txt", ios_base::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_waiting_line.txt",ios::out);
		outfile.close();
		outfile.open("book_waiting_line.txt", ios::in);
	}
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	int counttemp=0;
	account *readertemp=new account();
	Book tempbook;
	while (getline(outfile, datatemp)) {
		readertemp->setID(datatemp);
		getline(outfile,datatemp);
		readertemp->setUsername(datatemp);
		getline(outfile,datatemp);
		tempbook.ISBN=datatemp;
		getline(outfile,datatemp);
		tempbook.name=datatemp;
		counttemp++;
		if (readertemp->getID()!=acc_reader->getID()||readertemp->getUsername()!=acc_reader->getUsername()||tempbook.ISBN!=ISBN) {
			temp<<readertemp->getID()<<endl<<readertemp->getUsername()<<endl<<tempbook.ISBN<<endl<<tempbook.name<<endl;
		}

	}
	temp.close();
	outfile.close();
	remove("book_waiting_line.txt");
	rename("temp.txt","book_waiting_line.txt");
}



void approve_demand_function(account *acc_librarian) {
	fstream outfile;
	outfile.open("book_people_want_to_borrow.txt",ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_people_want_to_borrow.txt",ios::out);
		outfile.close();
		outfile.open("book_people_want_to_borrow.txt", ios::in);
	}
	string datatemp;
	Book book;
	account *readertemp=new account();
	if(count_number_of_book_approve(acc_librarian)!=0) {
		getline(outfile,datatemp);
		readertemp->setID(datatemp);
		getline(outfile,datatemp);
		readertemp->setUsername(datatemp);
		getline(outfile,datatemp);
		book.ISBN=datatemp;
		getline(outfile,datatemp);
		book.name=datatemp;
		Book newbook;
		getbookinfomation(newbook, book.ISBN);
		string dayborrow=getCurrentDate();
		fstream outfile2;
		string filename="book_already_have_"+readertemp->getUsername()+".txt";
		outfile2.open(filename.c_str(), ios_base::app);
		outfile2<<newbook.ISBN<<endl;
		outfile2<<newbook.name<<endl;
		outfile2<<newbook.author<<endl;
		outfile2<<newbook.category<<endl;
		outfile2<<newbook.publisher<<endl;
		outfile2<<newbook.year<<endl;
		outfile2<<"1"<<endl;
		outfile2<<newbook.price<<endl;
		outfile2<<dayborrow<<endl;
		outfile2.close();

		fstream outfile4;
		string filename4="history_"+readertemp->getUsername()+".txt";
		outfile4.open(filename4.c_str(), ios_base::app);
		outfile4<<"Duoc chap nhan muon cuon sach:"<<endl;
		outfile4<<newbook.ISBN<<endl;
		outfile4<<newbook.name<<endl;
		outfile4<<dayborrow<<endl;
		outfile4.close();

		fstream outfile3;
		string filename3="book_already_people_have.txt";
		outfile3.open(filename3.c_str(), ios_base::app);
		outfile3<<readertemp->getID()<<endl;
		outfile3<<readertemp->getUsername()<<endl;
		outfile3<<newbook.ISBN<<endl;
		outfile3<<newbook.name<<endl;
		outfile3<<dayborrow<<endl;
		outfile3.close();
		change_number_book_in_store_function(acc_librarian, newbook.ISBN, -1);
	}
	outfile.close();
	delete_after_approve_process(acc_librarian);
}
/////////////////////Su dung cho approve waiting line
void get_all_book_waiting_infomation(account *acc_librarian, account *&acc_reader, Book *&booktemp) {
	int N=count_number_of_book_waiting_file(acc_librarian);
	acc_reader=new account[N];
	booktemp=new Book[N];
	fstream outfile;
	outfile.open("book_waiting_line.txt",ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_waiting_line.txt",ios::out);
		outfile.close();
		outfile.open("book_waiting_line.txt", ios::in);
	}
	account *readertemp=new account();
	Book book;
	string datatemp;
	int i=0;
	while(getline(outfile,datatemp)) {
		acc_reader[i].setID(datatemp);
		getline(outfile,datatemp);
		acc_reader[i].setUsername(datatemp);
		getline(outfile,datatemp);
		booktemp[i].ISBN=datatemp;
		getline(outfile,datatemp);
		booktemp[i].name=datatemp;
		i++;
	}
	outfile.close();
}

void approve_waiting_function(account *acc_librarian, account *acc_reader, string ISBN) {
	fstream outfile;
	outfile.open("book_waiting_line.txt",ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_waiting_line.txt",ios::out);
		outfile.close();
		outfile.open("book_waiting_line.txt", ios::in);
	}
	string datatemp;
	Book book;
	account *readertemp=new account();
	int count=0;
	while(getline(outfile,datatemp)) {
		readertemp->setID(datatemp);
		getline(outfile,datatemp);
		readertemp->setUsername(datatemp);
		getline(outfile,datatemp);
		book.ISBN=datatemp;
		getline(outfile,datatemp);
		book.name=datatemp;
		if(readertemp->getID()==acc_reader->getID()&&readertemp->getUsername()==acc_reader->getUsername()&&book.ISBN==ISBN) {
			Book newbook;
			getbookinfomation(newbook, book.ISBN);
			string dayborrow=getCurrentDate();
			fstream outfile2;
			string filename="book_already_have_"+readertemp->getUsername()+".txt";
			outfile2.open(filename.c_str(), ios_base::app);
			outfile2<<newbook.ISBN<<endl;
			outfile2<<newbook.name<<endl;
			outfile2<<newbook.author<<endl;
			outfile2<<newbook.category<<endl;
			outfile2<<newbook.publisher<<endl;
			outfile2<<newbook.year<<endl;
			outfile2<<"1"<<endl;
			outfile2<<newbook.price<<endl;
			outfile2<<dayborrow<<endl;
			outfile2.close();

			fstream outfile4;
			string filename4="history_"+readertemp->getUsername()+".txt";
			outfile4.open(filename4.c_str(), ios_base::app);
			outfile4<<"Duoc chap nhan muon cuon sach:"<<endl;
			outfile4<<newbook.ISBN<<endl;
			outfile4<<newbook.name<<endl;
			outfile4<<dayborrow<<endl;
			outfile4.close();

			fstream outfile3;
			string filename3="book_already_people_have.txt";
			outfile3.open(filename3.c_str(), ios_base::app);
			outfile3<<readertemp->getID()<<endl;
			outfile3<<readertemp->getUsername()<<endl;
			outfile3<<newbook.ISBN<<endl;
			outfile3<<newbook.name<<endl;
			outfile3<<dayborrow<<endl;
			outfile3.close();
			change_number_book_in_store_function(acc_librarian, newbook.ISBN, -1);
			outfile.close();
			delete_after_waiting_process(acc_reader, ISBN);
			delete_single_book_in_waiting_of_each_person_function( acc_reader, ISBN);
		}

	}
	outfile.close();
}

void disapprove_demand_function(account *acc_librarian) {
	delete_after_approve_process(acc_librarian);
}

void send_demand_to_waiting_line_function(account *acc_librarian) {
	fstream outfile;
	outfile.open("book_people_want_to_borrow.txt",ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_people_want_to_borrow.txt",ios::out);
		outfile.close();
		outfile.open("book_people_want_to_borrow.txt", ios::in);
	}
	string datatemp;
	Book book;
	account *readertemp=new account();
	if(count_number_of_book_approve(acc_librarian)!=0) {
		getline(outfile,datatemp);
		readertemp->setID(datatemp);
		getline(outfile,datatemp);
		readertemp->setUsername(datatemp);
		getline(outfile,datatemp);
		book.ISBN=datatemp;
		getline(outfile,datatemp);
		book.name=datatemp;
		Book newbook;
		getbookinfomation(newbook, book.ISBN);
		string dayborrow=getCurrentDate();
		fstream outfile2;
		string filename="book_waiting_"+readertemp->getUsername()+".txt";
		outfile2.open(filename.c_str(), ios_base::app);
		outfile2<<newbook.ISBN<<endl;
		outfile2<<newbook.name<<endl;
		outfile2<<newbook.author<<endl;
		outfile2<<newbook.category<<endl;
		outfile2<<newbook.publisher<<endl;
		outfile2<<newbook.year<<endl;
		outfile2.close();
		fstream outfile3;
		outfile3.open("book_waiting_line.txt", ios_base::app);
		outfile3<<readertemp->getID()<<endl;
		outfile3<<readertemp->getUsername()<<endl;
		outfile3<<newbook.ISBN<<endl;
		outfile3<<newbook.name<<endl;
		outfile3.close();

	}
	outfile.close();
	delete_after_approve_process(acc_librarian);
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


