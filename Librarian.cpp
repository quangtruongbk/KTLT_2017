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

void send_announcement_to_all_reader(account *acc) {
	system("cls");
	string content,day;
	cout<<"GUI THONG BAO CHO TOAN BO DOC GIA" <<endl;
	cout<<"Nhap noi dung thong bao: "<<endl;
	do {
		fflush(stdin);
		getline(cin,content);
		if(content=="") cout<<"Khong duoc de thong bao trong, hay nhap lai."<<endl;
	} while(content=="");
	day=currentDateTime();
	announcement *newAnnounce=new announcement(content,day,"0","3");
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
		if (role[0] == '1') {
			newAnnounce->send_to_user(temp->getUsername());
		}
	}
	outfile.close();
	add_announcement_to_archive(newAnnounce,acc,"all reader");
	cout<<"Thong bao da duoc gui. Nhan bat ky de tro ve."<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	send_announcement(acc);
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
		if(choice=='1') send_announcement_to_individual(acc,role_send);
		if(choice=='2') send_announcement(acc);
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
		announcement *newAnnounce=new announcement(content,day,"0",role_send);
		newAnnounce->send_to_user(username_to_send);
		add_announcement_to_archive(newAnnounce,acc,username_to_send);
		cout<<"Thong bao da duoc gui. Nhan bat ky de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		send_announcement(acc);
	}
}
void send_announcement(account *acc) {
	system("cls");
	cout<<"CHUC NANG GUI THONG BAO CUA ACCOUNT: "<<acc->getUsername()<<endl;
	cout<<"1. Gui thong bao cho toan bo doc gia."<<endl;
	cout<<"2. Gui thong bao cho mot ca nhan doc gia."<<endl;
	cout<<"3. Tro ve."<<endl;
	fflush(stdin);
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3');
	if(choice=='1') send_announcement_to_all_reader(acc);
	if(choice=='2') send_announcement_to_individual(acc,"3") ;
//	if(choice=='3') ; //TO DOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
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
		if (check_ISBN_Book(newBook->ISBN) == 1){
			cout << "Ma ISBN da ton tai trong thu vien. " << endl;
			cout << "Nhan 1 de nhap ma khac, nhan bat ky de tro ve" << endl;
			fflush(stdin);
			choiceISBN = _getch();
			fflush(stdin);
			if (choiceISBN != '1') add_book(acc);
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

void add_book(account *acc){
	cout << "Chwa hien thuc" << endl;
}
