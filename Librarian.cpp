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
	while (getline(outfile, datatemp)) {
		string role = "000";
	
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
	if(choice=='4') return mainmenu(acc);
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

void add_book_to_store(account *acc_librarian) {
	system("cls");
	cout<<"THEM SACH VAO KHO"<<endl;
	Book *newBook=new Book();
	char choiceISBN='1';
	cout << "Nhap ISBN cua sach: " << endl;
	do {
		fflush(stdin);
		getline(cin, newBook->ISBN);
		newBook->ISBN=uppercase(newBook->ISBN);
		fflush(stdin);
		if (newBook->ISBN == "") cout << "Khong duoc de trong, yeu cau nhap lai" << endl;
		if (check_ISBN_Book(newBook->ISBN) == 1) {
			cout << "Ma ISBN da ton tai trong thu vien. " << endl;
			cout << "Nhan 1 de nhap ma khac, nhan bat ky de tro ve" << endl;
			fflush(stdin);
			choiceISBN = _getch();
			fflush(stdin);
			if (choiceISBN != '1') return add_book(acc_librarian);
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
	add_book_to_store_function(acc_librarian,newBook);
	cout<<"Da them xong. ";
	char choice;
	cout<<"Nhan bat ky de tro ve."<<endl;
	fflush(stdin);
	choice=_getch();
	fflush(stdin);
	return manage_book_store(acc_librarian);
}

void add_book(account *acc) {
	cout << "Chwa hien thuc" << endl;
}

void showfullinfo_lib(Book& book) {
	cout << "ISBN: " << book.ISBN << endl;
	cout << "Ten sach: " << book.name << endl;
	cout << "The loai: " << getallcategoryname(book.category) << endl;
	cout << "Nha xuat ban: " << book.publisher << endl;
	cout << "Nam xuat ban: " << book.year << endl;
	cout << "Gia(VND/ngay): " << book.price << endl;
	cout<<"So luong con: "<<book.amount<<endl;
}

void read_book_info_lib(account *acc_librarian) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon tim hieu: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN=="") {
		char choice;
		cout<<"ISBN khong ton tai"<<endl;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return read_book_info_lib(acc_librarian);
		if(choice=='2') return search_book_lib(acc_librarian);
	} else {
		Book book;
		get_book_info(book,ISBN);
		//	cout<<"test "<<book.name<< book.ISBN<<endl;
		system("cls");
		showfullinfo_lib(book);
		char choice;
		cout<<"Nhan bat ky de tro ve."<<endl;
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		return search_book_lib(acc_librarian);
	}
}

void search_key_lib(string str) {
	fstream outfile;
	//fstream outfile2;
	string foundbookISBN = "";
	outfile.open("book.txt", ios::in);
	Book book;
	string info;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "| STT |     ISBN       |                      Ten sach               |        Tac gia        |        The loai       |         NXB         |  Nam |So luong|Gia thue|\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	string	get_category;
	int curline = 0;
	int count = 0;
	if (outfile.is_open()) {
		while (getbook(book, outfile, 0)) {
			stringstream ss;
			string year, price, amount;
			ss << book.year << book.price << book.amount;
			ss >> year >> price >> amount;
			get_category = getallcategoryname(book.category);
			if ((book.ISBN.find(str, 0) != -1) || (book.name.find(str, 0) != -1) || (book.author.find(str, 0) != -1) || (get_category.find(str, 0) != -1) || (book.publisher.find(str, 0) != -1) || (year.find(str, 0) != -1) || (price.find(str, 0) != -1)) {
				count++;
				foundbookISBN += book.ISBN + "\n";
				cout << "|" << setw(4) << count << " |" << right << setw(15) << book.ISBN << " | " << left << setw(44) << getnumofchar(book.name, 44) << "| " << setw(21) << getnumofchar(book.author, 21) << " | " << setw(21) << getnumofchar(get_category, 21) << " | " << setw(19) << getnumofchar(book.publisher, 19) << " | " << right << setw(4) << book.year << " |" << setw(7) << book.amount << " |" << setw(7) << book.price << " |\n";
			}
		}
	} else
		cout << "Khong co file";

	if (count == 0)
		cout << "Khong co ket qua phu hop voi tu khoa!\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	outfile.close();
}

void show_all_book_lib(account *acc_librarian) {
	system("cls");
	search_key_lib("");
	char choice;
	cout<<"Nhan 1 de tim hieu thong tin ve 1 cuon sach."<<endl;
	cout<<"Nhan 2 de tro ve."<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') return read_book_info_lib(acc_librarian);
	if(choice=='2') return search_book_lib(acc_librarian);
}

void show_all_book_libmanage(account *acc_librarian) {
	system("cls");
	search_key_lib("");
}

void search_tong_hop_lib(account *acc_librarian) {
	system("cls");
	string key;
	do {
		cout<<"Nhap tu khoa ban muon tim kiem: "<<endl;
		getline(cin,key);
		key=uppercase(key);
		if(key=="") cout<<"Khong duoc de trong, hay nhap lai "<<endl;
	} while(key=="");
	search_key_lib(key);
	char choice;
	cout<<"Nhan 1 de tim hieu thong tin ve 1 cuon sach."<<endl;
	cout<<"Nhan 2 de tro ve."<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') return read_book_info_lib(acc_librarian);
	if(choice=='2') return search_book_lib(acc_librarian);
}

void find_key_lib(string str, int selection) {
	Book book;
	fstream outfile;
	fstream outfile2;
	string line;
	string foundbookISBN = "";
	string	get_category;
	int curline = 0;
	int count = 0;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "| STT |     ISBN       |                      Ten sach               |        Tac gia        |        The loai       |         NXB         |  Nam |So luong|Gia thue|\n";
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	outfile.open("book.txt", ios::in);
	if (outfile.is_open()) {
		for (int i = 0; i < selection; i++) {
			getline(outfile, line);
			curline++;
		}

		while (getline(outfile, line)) {
			line=getallcategoryname(line);
			curline++;
			if (line.find(str, 0) != -1) {
				outfile2.open("book.txt", ios::in);
				getbook(book, outfile2, curline);
				count++;
				get_category = getallcategoryname(book.category);
				cout << "|" << setw(4) << count << " |" << right << setw(15) << book.ISBN << " | " << left << setw(44) << getnumofchar(book.name, 44) << "| " << setw(21) << getnumofchar(book.author, 21) << " | " << setw(21) << getnumofchar(get_category, 21) << " | " << setw(19) << getnumofchar(book.publisher, 19) << " | " << right << setw(4) << book.year << " |" << setw(7) << book.amount << " |" << setw(7) << book.price << " |\n";
				foundbookISBN += book.ISBN + "\n";
				outfile2.close();
			}
			for (int i = 0; i < 7; i++) {
				getline(outfile, line);
				curline++;
				if (outfile.eof())
					break;
			}
		}

	} else
		cout << "Khong co file";
	if (count == 0) {
		cout << "Khong co ket qua phu hop voi tu khoa!\n";

	}
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	outfile.close();
}

void show_book_via_category_lib(account *acc_librarian) {
	unsigned int choice = 0;
	do {
		fflush(stdin);
		cin.clear();
		cout << "Moi chon the loai can tim"<<endl;
		cout << "1.Van hoc \n2.Thieu nhi \n3.Ky nang, day nghe, nghe nghiep \n4.Kien thuc doi song \n5.Kinh te, tai chinh \n6.Giao khoa, tham khao, giao trinh. \n7.Tu dien \n8.Truyen tranh \n9.Tam ly\n10.Kien thuc tong hop\n11.Ngoai van\n12.The loai khac" << endl;
		fflush(stdin);
		cin >> choice;
	} while (cin.fail() || choice > 12 || choice < 0);
	stringstream ss;
	ss << choice;
	string str;
	ss >> str;
	str=getcategoryname(choice);
	find_key_lib(str, 3);
	char choice1;
	cout<<"Nhan 1 de tim hieu thong tin ve 1 cuon sach."<<endl;
	cout<<"Nhan 2 de tro ve."<<endl;
	do {
		fflush(stdin);
		choice1=_getch();
		fflush(stdin);
		if(choice1!='1'&&choice1!='2') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice1!='1'&&choice1!='2');
	if(choice1=='1') return read_book_info_lib(acc_librarian);
	if(choice1=='2') return search_book_lib(acc_librarian);
}

void search_book_lib(account *acc_librarian) {
	system("cls");
	cout<<"CHUC NANG TIM KIEM CUA THU THU: "<<acc_librarian->getUsername()<<endl;
	printline();
	printline();
	cout<<"1. Show toan bo danh sach sach"<<endl;
	cout<<"2. Show danh sach sach theo the loai"<<endl;
	cout<<"3. Tim kiem tong hop"<<endl;
	cout<<"4. Tim hieu thong tin day du cua sach"<<endl;
	cout<<"5. Tro ve"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5');
	if(choice=='1') return show_all_book_lib(acc_librarian);
	if(choice=='2') return show_book_via_category_lib(acc_librarian);
	if(choice=='3') return search_tong_hop_lib(acc_librarian);
	if(choice=='4') return read_book_info_lib(acc_librarian);
	if(choice=='5') return mainmenu(acc_librarian);
}

void delete_book_in_store_function(account *acc, string ISBN) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("tempbook2.txt",ios::out);
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
	remove("book.txt");
	rename("tempbook2.txt", "book.txt");
}

void delete_book_in_store(account *acc_librarian) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon xoa: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN==""||check_ISBN_exist_in_book_people_wanting_line(ISBN)==1||check_ISBN_exist_in_book_people_want_to_borrow(ISBN)==1||check_ISBN_exist_in_book_people_already_have(ISBN)) {
		cout<<"ISBN khong ton tai hoac sach dang duoc su dung, khong the xoa duoc"<<endl;
		char choice;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return delete_book_in_store(acc_librarian);
		if(choice=='2') return manage_book_store(acc_librarian);
	} else {
		delete_book_in_store_function(acc_librarian, ISBN);
		cout<<"Da xoa"<<endl;
		cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return manage_book_store(acc_librarian);
	}
}

void change_number_book_in_store_function(account *acc, string ISBN, int numberofchange) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("tempbook.txt",ios::out);
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
	remove("book.txt");
	rename("tempbook.txt", "book.txt");
}

void change_amount_book_store(account *acc_librarian) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon thay doi so luong: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN=="") {
		cout<<"ISBN khong ton tai"<<endl;
		char choice;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return change_amount_book_store(acc_librarian);
		if(choice=='2') return manage_book_store(acc_librarian);
	} else {
		int oldAmount=get_book_amount(ISBN);
		cout<<"So luong sach trong kho hien tai: "<<oldAmount<<endl;
		string temp;
		int newAmount;
		cout<<"Nhap su thay doi (dau + cho them sach, dau - cho viec giam bot so luong sach): "<<endl;
		do {
			cin.clear();
			fflush(stdin);
			cin>>newAmount;
			if(!cin.fail() && newAmount+oldAmount>0) break;
			fflush(stdin);
			if(cin.fail()||newAmount+oldAmount<0) cout<<"Khong hop le, yeu cau nhap lai"<<endl;
		} while(cin.fail()||newAmount+oldAmount<0);
		change_number_book_in_store_function(acc_librarian, ISBN,  newAmount);
		cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return manage_book_store(acc_librarian);
	}
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

void change_price_book_store(account *acc_librarian) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon thay doi gia: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN=="") {
		cout<<"ISBN khong ton tai"<<endl;
		char choice;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return change_price_book_store(acc_librarian);
		if(choice=='2') return manage_book_store(acc_librarian);
	} else {
		string temp;
		int newPrice;
		cout<<"Nhap gia thue trong 1 ngay: "<<endl;
		do {
			fflush(stdin);
			getline(cin,temp);
			if(temp!=""||check_number(temp)!=0) newPrice=atoi(temp.c_str());
			fflush(stdin);
			if(temp==""||check_number(temp)==0) cout<<"Khong hop le, yeu cau nhap lai"<<endl;
		} while(temp==""||check_number(temp)==0);
		change_price_book_in_store_function(acc_librarian, ISBN,  newPrice);
		cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return manage_book_store(acc_librarian);
	}
}

void change_name_book_in_store_function(account *acc, string ISBN, string name) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("tempbook.txt", ios::out);
	string datatemp;
	Book *temp = new Book();
	while (getline(outfile, temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile, temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->amount = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->price = atoi(datatemp.c_str());

		if (ISBN != temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n' << temp->category << '\n' << temp->publisher << '\n' << temp->year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
		if (ISBN == temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << name << '\n' << temp->author << '\n' << temp->category << '\n' << temp->publisher << '\n' << temp->year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
	}
	outfile2.close();
	outfile.close();
	remove("book.txt");
	rename("tempbook.txt", "book.txt");
}

void change_name_book_store(account *acc_librarian) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon thay doi ten: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN=="") {
		cout<<"ISBN khong ton tai"<<endl;
		char choice;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return change_name_book_store(acc_librarian);
		if(choice=='2') return manage_book_store(acc_librarian);
	} else {
		string name;

		cout<<"Nhap ten sach can thay doi ten: "<<endl;
		do {
			fflush(stdin);
			getline(cin,name);
			name=uppercase(name);
			fflush(stdin);
			if(name=="") cout<<"Khong duoc de trong, yeu cau nhap lai"<<endl;
		} while(name=="");
		change_name_book_in_store_function(acc_librarian, ISBN,  name);
		cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return manage_book_store(acc_librarian);
	}
}

void change_publisher_in_store_function(account *acc, string ISBN, string publisher) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("tempbook.txt", ios::out);
	string datatemp;
	Book *temp = new Book();
	while (getline(outfile, temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile, temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->amount = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->price = atoi(datatemp.c_str());

		if (ISBN != temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n' << temp->category << '\n' << temp->publisher << '\n' << temp->year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
		if (ISBN == temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n' << temp->category << '\n' << publisher << '\n' << temp->year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
	}
	outfile2.close();
	outfile.close();
	remove("book.txt");
	rename("tempbook.txt", "book.txt");
}

void change_publisher_book_store(account *acc_librarian) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon thay doi nha xuat ban: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN=="") {
		char choice;
		cout<<"ISBN khong ton tai"<<endl;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return change_publisher_book_store(acc_librarian);
		if(choice=='2') return manage_book_store(acc_librarian);
	} else {
		string publisher;

		cout<<"Nhap ten nha xuat ban moi: "<<endl;
		do {
			fflush(stdin);
			getline(cin,publisher);
			publisher=uppercase(publisher);
			fflush(stdin);
			if(publisher=="") cout<<"Khong duoc de trong, yeu cau nhap lai"<<endl;
		} while(publisher=="");
		change_publisher_in_store_function(acc_librarian, ISBN,  publisher);
		cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return manage_book_store(acc_librarian);
	}
}

void change_year_in_store_function(account *acc, string ISBN, int year) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("tempbook.txt", ios::out);
	string datatemp;
	Book *temp = new Book();
	while (getline(outfile, temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile, temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->amount = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->price = atoi(datatemp.c_str());
		if (ISBN != temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n' << temp->category << '\n' << temp->publisher << '\n' << temp->year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
		if (ISBN == temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n' << temp->category << '\n' << temp->publisher << '\n' << year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
	}
	outfile2.close();
	outfile.close();
	remove("book.txt");
	rename("tempbook.txt", "book.txt");
}

void change_year_book_store(account *acc_librarian) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon thay doi nam xuat ban: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN=="") {
		char choice;
		cout<<"ISBN khong ton tai"<<endl;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return change_year_book_store(acc_librarian);
		if(choice=='2') return manage_book_store(acc_librarian);
	} else {
		string temp;

		cout<<"Nhap nam xuat ban moi: "<<endl;
		int newYear;
		do {
			fflush(stdin);
			getline(cin,temp);
			if(temp!=""||check_number(temp)!=0) newYear=atoi(temp.c_str());
			fflush(stdin);
			if(temp==""||check_number(temp)==0) cout<<"Khong hop le, yeu cau nhap lai"<<endl;
		} while(temp==""||check_number(temp)==0);
		change_year_in_store_function(acc_librarian, ISBN,  newYear);
		cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return manage_book_store(acc_librarian);
	}
}

void change_book_author_in_store_function(account *acc, string ISBN, string author) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("tempbook.txt", ios::out);
	string datatemp;
	Book *temp = new Book();
	while (getline(outfile, temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile, temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->amount = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->price = atoi(datatemp.c_str());


		if (ISBN != temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n' << temp->category << '\n' << temp->publisher << '\n' << temp->year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
		if (ISBN == temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << author << '\n' << temp->category << '\n' << temp->publisher << '\n' << temp->year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
	}
	outfile2.close();
	outfile.close();
	remove("book.txt");
	rename("tempbook.txt", "book.txt");
}

void change_author_book_store(account *acc_librarian) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon thay doi tac gia: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN=="") {
		char choice;
		cout<<"ISBN khong ton tai"<<endl;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return change_author_book_store(acc_librarian);
		if(choice=='2') return manage_book_store(acc_librarian);
	} else {
		string author;
		cout<<"Nhap ten tac gia moi: "<<endl;
		do {
			fflush(stdin);
			getline(cin,author);
			author=uppercase(author);
			fflush(stdin);
			if(author=="") cout<<"Khong duoc de trong, yeu cau nhap lai"<<endl;
		} while(author=="");
		change_book_author_in_store_function(acc_librarian, ISBN,  author);
		cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return manage_book_store(acc_librarian);
	}
}

void change_book_category_in_store_function(account *acc, string ISBN, string category) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	fstream outfile2;
	outfile2.open("tempbook.txt", ios::out);
	string datatemp;
	Book *temp = new Book();
	while (getline(outfile, temp->ISBN)) {
		getline(outfile, temp->name);
		getline(outfile, temp->author);
		getline(outfile, temp->category);
		getline(outfile, temp->publisher);
		getline(outfile, datatemp);
		temp->year = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->amount = atoi(datatemp.c_str());
		getline(outfile, datatemp);
		temp->price = atoi(datatemp.c_str());


		if (ISBN != temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n' << temp->category << '\n' << temp->publisher << '\n' << temp->year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
		if (ISBN == temp->ISBN) {
			outfile2 << temp->ISBN << '\n' << temp->name << '\n' << temp->author << '\n' << category << '\n' << temp->publisher << '\n' << temp->year << '\n' << temp->amount << '\n' << temp->price << endl;
		}
	}
	outfile2.close();
	outfile.close();
	remove("book.txt");
	rename("tempbook.txt", "book.txt");
}

void change_category_book_store(account *acc_librarian) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon thay doi the loai: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN=="") {
		char choice;
		cout<<"ISBN khong ton tai"<<endl;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return change_category_book_store(acc_librarian);
		if(choice=='2') return manage_book_store(acc_librarian);
	} else {
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
		change_book_category_in_store_function(acc_librarian, ISBN,  category);
		cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return manage_book_store(acc_librarian);
	}
}

void manage_book_store(account *acc_librarian) {
	system("cls");
	cout<<"CHUC NANG QUAN LY KHO SACH CUA THU THU: "<<acc_librarian->getUsername()<<endl;
	printline();
	printline();
	show_all_book_libmanage(acc_librarian);
	cout<<"1. Them sach"<<endl;
	cout<<"2. Xoa sach"<<endl;
	cout<<"3. Thay doi ten sach"<<endl;
	cout<<"4. Thay doi tac gia sach"<<endl;
	cout<<"5. Thay doi nha xuat ban sach"<<endl;
	cout<<"6. Thay doi the loai sach"<<endl;
	cout<<"7. Thay doi so luong sach"<<endl;
	cout<<"8. Thay doi gia thue sach"<<endl;
	cout<<"9. Tro ve"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice = _getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6'&&choice!='7'&&choice!='8'&&choice!='9') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6'&&choice!='7'&&choice!='8'&&choice!='9');
	if(choice=='1') return add_book_to_store(acc_librarian);
	if(choice=='2') return delete_book_in_store(acc_librarian);
	if(choice=='3') return change_name_book_store(acc_librarian);
	if(choice=='4') return change_author_book_store(acc_librarian);
	if(choice=='5') return change_publisher_book_store(acc_librarian);
	if(choice=='6') return change_category_book_store(acc_librarian);
	if(choice=='7') return change_amount_book_store(acc_librarian);
	if(choice=='8') return change_price_book_store(acc_librarian);
	if(choice=='9') return mainmenu(acc_librarian);
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

		string filename4="history_"+readertemp->getUsername()+".txt";
		string history="Duoc chap nhan muon cuon sach: ISBN: "+newbook.ISBN+", ten: "+newbook.name+", ngay muon: "+getDay(dayborrow);
		add_to_history_file(readertemp, history);

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
	cout<<"Nhan bat ky de tro ve"<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return start_approve_book(acc_librarian);

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


void approve_waiting_function(account *acc_librarian, account *acc_reader, string ISBN, Book waitingline) {
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
	int count=0;
	Book newbook;
	getbookinfomation(newbook, waitingline.ISBN);
	string dayborrow=getCurrentDate();
	fstream outfile2;
	string filename="book_already_have_"+acc_reader->getUsername()+".txt";
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

	string filename4="history_"+acc_reader->getUsername()+".txt";
	string history="Duoc chap nhan muon cuon sach: ISBN: "+newbook.ISBN+", ten: "+newbook.name+", ngay muon: "+getDay(dayborrow);
	add_to_history_file(acc_reader, history);

	fstream outfile3;
	string filename3="book_already_people_have.txt";
	outfile3.open(filename3.c_str(), ios_base::app);
	outfile3<<acc_reader->getID()<<endl;
	outfile3<<acc_reader->getUsername()<<endl;
	outfile3<<newbook.ISBN<<endl;
	outfile3<<newbook.name<<endl;
	outfile3<<dayborrow<<endl;
	outfile3.close();
	change_number_book_in_store_function(acc_librarian, newbook.ISBN, -1);
	outfile.close();
	delete_after_waiting_process(acc_reader, ISBN);
	delete_single_book_in_waiting_of_each_person_function( acc_reader, ISBN);
	outfile.close();
}

void start_approve_waiting(account *acc_librarian) {
	int N = count_number_of_book_waiting_file(acc_librarian);
	account *acc_reader = new account[N];
	Book *book = new Book[N];
	get_all_book_waiting_infomation(acc_librarian, acc_reader, book);

	if (N > 0) {
		for (int i = 0; i<N; i++) {
			//system("cls");
			cout << "ID nguoi muon: " << acc_reader[i].getID() << endl;
			cout << "Account: " << acc_reader[i].getUsername() << endl;
			cout << "ISBN sach muon muon: " << book[i].ISBN << endl;
			cout << "Ten cua sach muon muon: " << book[i].name << endl;
			int amount = get_book_amount(book[i].ISBN);
			cout << "So luong sach con trong kho: " << amount << endl;
			if (amount>0) {
				cout << "1. Dong y cho muon" << endl;
				cout << "2. Tiep tuc doi" << endl;
				cout << "Nhap lua chon:" << endl;
				char choice;
				do {
					fflush(stdin);
					choice = _getch();
					fflush(stdin);
					if (choice != '1'&&choice != '2') cout << "Hay bam lua chon dung" << endl;
				} while (choice != '1'&&choice != '2');
				if (choice == '1'&&i < (N - 1)) approve_waiting_function(acc_librarian, acc_reader + i, book[i].ISBN, *book);
				if (choice == '1'&&i == (N - 1)) {
					approve_waiting_function(acc_librarian, acc_reader + i, book[i].ISBN, *book);
					cout << "Da den cuoi hang doi" << endl;
					cout << "Nhan bat ky de tro ve" << endl;
					cout << "Nhan bat ky de tro ve" << endl;
					fflush(stdin);
					char choice;
					choice = _getch();
					fflush(stdin);
					return approve_waiting(acc_librarian);
				}
				if (choice == '2'&&i < (N - 1)) system("cls");
				if (choice == '2' &&i == (N - 1)) {
					cout << "Da den cuoi hang doi" << endl;
					cout << "Nhan bat ky de tro ve" << endl;
					cout << "Nhan bat ky de tro ve" << endl;
					fflush(stdin);
					char choice;
					choice = _getch();
					fflush(stdin);
					return approve_waiting(acc_librarian);
				}
			}
			if (amount <= 0) {
				cout << "1. Tiep tuc doi" << endl;
				cout << "Nhap lua chon:" << endl;
				char choice;
				do {
					fflush(stdin);
					choice = _getch();
					fflush(stdin);
					if (choice != '1') cout << "Hay bam lua chon dung" << endl;
				} while (choice != '1');
				if (choice == '1'&&i < (N - 1))  system("cls");
				if (choice == '1'&&i == (N - 1)) {
					cout << "Da den cuoi hang doi" << endl;
					cout << "Nhan bat ky de tro ve" << endl;
					cout << "Nhan bat ky de tro ve" << endl;
					fflush(stdin);
					char choice;
					choice = _getch();
					fflush(stdin);
					return approve_waiting(acc_librarian);

				}
			}
		}
	}

	if (N == 0) {
		cout << "Hang doi rong" << endl;
		cout << "Nhan bat ky de tro ve" << endl;
		fflush(stdin);
		char choice;
		choice = _getch();
		fflush(stdin);
		return approve_waiting(acc_librarian);
	}
}

void approve_waiting(account *acc_librarian) {
	system("cls");
	show_book_waiting_line();
	cout<<"CHUC NANG XY LY HANG DOI CUA THU THU "<<acc_librarian->getUsername()<<endl;
	cout<<"1. Bat dau duyet hang doi"<<endl;
	cout<<"2. Tro ve"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') return start_approve_waiting(acc_librarian);
	if(choice=='2') return mainmenu(acc_librarian);

}
void disapprove_demand_function(account *acc_librarian) {
	delete_after_approve_process(acc_librarian);
	cout<<"Nhan bat ky de tro ve"<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return start_approve_book(acc_librarian);
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
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return start_approve_book(acc_librarian);
}

void send_announcement_because_late(account *acc_librarian, string username, string ISBN, string content) {
	string day;
	day=currentDateTime();
	announcement *newAnnounce=new announcement(content,day,"0","3",acc_librarian);

	newAnnounce->send_to_user(username);
	add_announcement_to_archive(newAnnounce,acc_librarian,username);

}
void show(string ID, string username, string ISBN, string bookname, string borrowdate) {
	cout << "| " << left << setw(20) << ID << " | " << setw(25) << username << " | " << setw(15) << ISBN << " | " << setw(33) << getnumofchar(bookname,33) << " | " << setw(10) << borrowdate << " |\n";
}
void printtile_show(){
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	cout << "|          ID          |         Username          |       ISBN      |             Ten sach              |  Ngay muon |\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}


void check_late_book_borrow(account *acc_librarian) {
	system("cls");
	fstream outfile;
	string datatemp;
	int count=0;
	outfile.open("book_already_people_have.txt", ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open("book_already_people_have.txt",ios::out|ios::binary);
		outfile.close();
		outfile.open("book_already_people_have.txt",ios::in );
	}
	account *temp=new account();
	Book book;
	string date;
	cout<<"DANH SACH NHUNG NGUOI MUON SACH QUA HAN"<<endl;
	printtile_show();
	while(getline(outfile,datatemp)) {
		temp->setID(datatemp);
		getline(outfile,datatemp);
		temp->setUsername(datatemp);
		getline(outfile,datatemp);
		book.ISBN=datatemp;
		getline(outfile,datatemp);
		book.name=datatemp;
		getline(outfile,datatemp);
		date=datatemp;
		if(distance_date(date)+1>14) {
			show(temp->getID(),temp->getUsername(),book.ISBN,book.name,date);
			string content="Ban da muon qua han cuon: "+book.name;
			send_announcement_because_late(acc_librarian,temp->getUsername(),book.ISBN,content);
		}
	}
	outfile.close();
	cout<<"Thong bao da canh cao qua han da duoc gui. Nhan bat ky de tro ve."<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	delete temp;
	return mainmenu(acc_librarian);
}


void send_announcement_because_pay_book(account *acc_reader, string ISBN, string content) {
	system("cls");
	string day;
	day=currentDateTime();
	announcement *newAnnounce=new announcement(content,day,"0","1",acc_reader);
	fstream outfile;
	string datatemp;
	account *temp=new account();
	outfile.open("account.txt", ios::in);
	string role="000";
	while (getline(outfile, datatemp)) {

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
		if (role[2] == '1') {
			newAnnounce->send_to_user(temp->getUsername());
		}
	}
	outfile.close();
	add_announcement_to_archive(newAnnounce,acc_reader,"all librarian");

}

int getPrice(account *acc,string ISBN) {
	fstream outfile;
	string filename="book_already_have_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(),ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	Book book;
	string datatemp;
	int totalprice=0;
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
		if(book.ISBN==ISBN &&book.amount==0) totalprice=totalprice+book.price*30;
		if(book.ISBN==ISBN &&book.amount==1) {
			if(distance_date(date)+1<=14) totalprice=totalprice+book.price*(distance_date(date)+1);
			else  totalprice=totalprice+book.price*14+book.price*2*(distance_date(date)+1-14);
		}
	}

	outfile.close();
	return totalprice;
}

void get_book_to_pay(account *acc_reader, string ISBN, Book &newbook, int &price) {
	fstream outfile;
	price=getPrice(acc_reader,ISBN);
	string filename="book_already_have_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(),ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	fstream temp;
	temp.open("temp.txt", ios::out);
	Book book;
	string datatemp;
	int count=0;
	string date;
	int flag=0;
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
		if(book.ISBN!=ISBN) {
			temp<<book.ISBN<<endl<<book.name<<endl<<book.author<<endl<<book.category<<endl<<book.publisher<<endl<<book.year<<endl<<book.amount<<endl<<book.price<<endl<<date<<endl;
		}
		if(book.ISBN==ISBN) {
			newbook.ISBN=book.ISBN;
			newbook.name=book.name;
			newbook.author=book.author;
			newbook.category=book.category;
			newbook.publisher=book.publisher;
			newbook.year=book.year;
			newbook.amount=book.amount;
			newbook.price=book.price;
		}
	}
	outfile.close();
	temp.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
}

void pay_a_single_book_function(account *acc_reader, string ISBN, int &price) {
	Book book;
	int newprice;
	get_book_to_pay(acc_reader,ISBN,book,newprice);
	price=newprice;
	//cout<<"book.isbn "<<book.ISBN<<" "<<book.name<<" "<<book.price<<endl;
	change_number_book_in_store_function(acc_reader, ISBN, +book.amount);
	string date=getDay(getCurrentDate());
	add_to_history_file(acc_reader, "Toi tra sach: ISBN "+book.ISBN+", ten: "+book.name+", vao ngay: "+date);
	delete_single_book_in_people_already_have(acc_reader,  book.ISBN);
	string content=acc_reader->getUsername()+" tra sach: ISBN: "+book.ISBN+", ten la: "+book.name;
	//send_announcement_because_pay_book(acc_reader, ISBN, content);

}

void pay_a_single_book(account *acc_librarian, account *acc_reader) {
	cout<<"Nhap ISBN cuon sach ma nguoi dung muon tra: "<<endl;
	string ISBN;
	getline(cin,ISBN);
	if(check_exist_book_already_have_of_each_person_function(acc_reader, ISBN)==0) {
		cout<<"Sach khong ton tai."<<endl;
		cout<<"Nhan 1 de nhap ISBN khac. "<<endl;
		cout<<"Nhan bat ky de tro ve. "<<endl;
		fflush(stdin);
		char choice;
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice=='1') return pay_a_single_book(acc_librarian, acc_reader);
		else return pay_book(acc_librarian);//TO DOOOOOOOO
	} else {
		int price, money;
		pay_a_single_book_function(acc_reader ,  ISBN,  price);
		cout<<"So tien ban phai thanh toan la: "<<price<<endl;
		cout<<"Nhan bat ky de tro ve"<<endl;
		char choice;
		choice=_getch();
		fflush(stdin);
		return mainmenu(acc_librarian);
	}
}

void pay_all_book(account *acc_librarian, account *acc_reader) {

	int N=get_number_of_book_already_have_of_each_person_function(acc_reader);
	Book *book=new Book[N];
	fstream outfile;
	int price;
	string filename="book_already_have_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(),ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string date;
	string datatemp;
	int i=0;
	while(getline(outfile,datatemp)) {
		book[i].ISBN=datatemp;
		getline(outfile,datatemp);
		book[i].name=datatemp;
		getline(outfile,datatemp);
		book[i].author=datatemp;
		getline(outfile,datatemp);
		book[i].category=datatemp;
		getline(outfile,datatemp);
		book[i].publisher=datatemp;
		getline(outfile,datatemp);
		book[i].year=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		book[i].amount=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		book[i].price=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		date=datatemp;
		i++;
	}
	outfile.close();
	int totalprice=0;
	for(int i=0; i<N; i++) {
		int price=0;
		pay_a_single_book_function(acc_reader, book[i].ISBN, price);
		totalprice=totalprice+price;
	}
	cout<<"So tien phai tra la: "<<totalprice<<endl;
	cout<<"Nhan bat ky de tro ve"<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return mainmenu(acc_librarian);
}

void pay_book(account *acc_librarian) {
	system("cls");
	cout<<"CHUC NANG QUAN LY TRA SACH, XU LY THAC LAC SACH CUA THU THU "<<acc_librarian->getUsername()<<endl;
	cout<<"Nhap username ban doc: "<<endl;
	string username;
	getline(cin,username);
	account *acc_reader=new account();
	if(get_account_username(username,acc_reader)==0||(get_account_username(username,acc_reader)==1&&acc_reader->getRole()[0]=='0')) {
		cout<<"Username khong dung hoac username khong phai la doc gia"<<endl;
		cout<<"Nhan 1 de nhap lai username khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		char choice;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return pay_book(acc_librarian);
		if(choice=='2') return mainmenu(acc_librarian);
	}
	if(get_account_username(username,acc_reader)==1&&acc_reader->getRole()[0]=='1') {
		show_all_book_already_have_of_each_person(acc_reader);
		cout<<"1. Tra tung cuon sach"<<endl;
		cout<<"2. Tra toan bo sach"<<endl;
		cout<<"3. Giai quyet lam mat sach"<<endl;
		cout<<"4. Tro ve"<<endl;
		char choice;
		cout<<"Nhap lua chon:"<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4');
		if(choice=='1') return pay_a_single_book(acc_librarian,acc_reader);
		if(choice=='2') return pay_all_book(acc_librarian, acc_reader);
		if(choice=='3') return announce_lost_book(acc_librarian, acc_reader);
		if(choice=='4') return mainmenu(acc_librarian);
	}
}

void show_all_book_already_have_of_each_person(account *acc_reader) {
	fstream outfile;
	string filename="book_already_have_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(),ios::in);
	cout << "|        ISBN        |             Ten sach                                    |        Ngay muon        |\n";
	cout << "__________________________________________________________________________________________________________"<<endl;
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
		cout<<"|"<<setw(20)<<book.ISBN<<"|";
		if(book.name.length()<=57) cout<<setw(57)<<book.name;
		else {
			for(int i=0; i<=54; i++) cout<<book.name[i];
		}
		cout<<"|"<<setw(25)<<date<<"|";
		cout<<endl;
	}
	cout << "__________________________________________________________________________________________________________"<<endl;
}

void send_announcement_because_lost_book(account *acc_reader, string ISBN) {
	system("cls");
	string content,day;
	Book book;
	getbookinfomation(book,ISBN);
	content= "Xin loi, nhung toi da lam mat cuon sach: ISBN: "+book.ISBN+", ten la: "+book.name+". Toi thanh that xin loi va xin chap hanh nhung an phat theo dung quy dinh cua thu vien";
	day=currentDateTime();
	announcement *newAnnounce=new announcement(content,day,"0","1",acc_reader);
	fstream outfile;
	string datatemp;
	account *temp=new account();
	outfile.open("account.txt", ios::in);
	string role="000";
	while (getline(outfile, datatemp)) {
		
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
		if (role[2] == '1') {
			newAnnounce->send_to_user(temp->getUsername());
		}
	}
	outfile.close();
	add_announcement_to_archive(newAnnounce,acc_reader,"all librarian");
}


void announce_lost_book_function(account *acc_reader, string ISBN) {
	fstream outfile;
	string filename="book_already_have_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(),ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	fstream temp;
	temp.open("temp.txt", ios::out);
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
		if(book.ISBN!=ISBN) {
			temp<<book.ISBN<<endl<<book.name<<endl<<book.author<<endl<<book.category<<endl<<book.publisher<<endl<<book.year<<endl<<book.amount<<endl<<book.price<<endl<<date<<endl;
		}
	}
	outfile.close();
	temp.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
	send_announcement_because_lost_book(acc_reader, ISBN);
	delete_single_book_in_people_already_have(acc_reader,  ISBN);
}


void announce_lost_book(account *acc_librarian, account *acc_reader) {
	cout<<"Nhap ISBN cuon sach ma nguoi doc lam mat: "<<endl;
	string ISBN;
	getline(cin,ISBN);
	if(check_exist_book_already_have_of_each_person_function(acc_reader, ISBN)==0) {
		cout<<"Sach khong ton tai."<<endl;
		cout<<"Nhan 1 de nhap ISBN khac. "<<endl;
		cout<<"Nhan bat ky de tro ve. "<<endl;
		fflush(stdin);
		char choice;
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice=='1') return announce_lost_book(acc_librarian, acc_reader);
		else return pay_book(acc_librarian);
	} else {
		Book newbook;
		getbookinfomation(newbook, ISBN);
		string date=getDay(getCurrentDate());
		add_to_history_file(acc_reader, "Toi lam mat sach: ISBN "+newbook.ISBN+", ten: "+newbook.name+", vao ngay: "+date);
		announce_lost_book_function(acc_reader, ISBN);
		system("cls");
		cout<<"So tien phai den bu: "<<newbook.price*30<<endl;
		cout<<"Nhan bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return pay_book(acc_librarian);
	}
}

void show_book_people_want_to_borrow() {
	fstream outfile;
	outfile.open("book_people_want_to_borrow.txt", ios::in);
	string ID, username, ISBN, bookname;
	cout << "----------------------------------------------------------------------------------------------------------\n";
	cout << "|          ID          |         Username          |       ISBN      |             Ten sach              |\n";
	cout << "----------------------------------------------------------------------------------------------------------\n";

	while (getline(outfile, ID)) {
		if (ID == "")
			break;
		getline(outfile, username);
		getline(outfile, ISBN);
		getline(outfile, bookname);
		cout << "| " << left << setw(20) << ID << " | " << setw(25) << username << " | " << setw(15) << ISBN << " | " << setw(33) << bookname << " |\n";
	}
	cout << "----------------------------------------------------------------------------------------------------------\n";
}

void show_book_waiting_line() {
	fstream outfile;
	outfile.open("book_waiting_line.txt", ios::in);
	string ID, username, ISBN, bookname;
	cout << "----------------------------------------------------------------------------------------------------------\n";
	cout << "|          ID          |         Username          |       ISBN      |             Ten sach              |\n";
	cout << "----------------------------------------------------------------------------------------------------------\n";

	while (getline(outfile, ID)) {
		if (ID == "")
			break;
		getline(outfile, username);
		getline(outfile, ISBN);
		getline(outfile, bookname);
		cout << "| " << left << setw(20) << ID << " | " << setw(25) << username << " | " << setw(15) << ISBN << " | " << setw(33) << bookname << " |\n";
	}
	cout << "----------------------------------------------------------------------------------------------------------\n";
}

void approve_book(account *acc_librarian) {
	system("cls");
	show_book_people_want_to_borrow();
	cout<<"1. Bat dau duyet don yeu cau muon"<<endl;
	cout<<"2. Tro ve"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') return start_approve_book(acc_librarian);
	if(choice=='2') return mainmenu(acc_librarian);
}

void start_approve_book(account *acc_librarian) {
	fstream outfile;
	system("cls");
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
		cout<<"ID nguoi muon: "<<readertemp->getID()<<endl;
		cout<<"Account: "<<readertemp->getUsername()<<endl;
		cout<<"ISBN sach muon muon: "<<book.ISBN<<endl;
		cout<<"Ten sach muon: "<<book.name<<endl;
	}
	outfile.close();
	if(count_number_of_book_approve(acc_librarian)!=0) {
		int amount=get_book_amount(book.ISBN);
		cout<<"So luong sach con trong kho: "<<amount<<endl;
		if(amount>0) {
			cout<<"1. Dong y cho muon"<<endl;
			cout<<"2. Khong dong y cho muon"<<endl;
			cout<<"3. Tro ve"<<endl;
			cout<<"Nhap lua chon:"<<endl;
			char choice;
			do {
				fflush(stdin);
				choice=_getch();
				fflush(stdin);
				if(choice!='1'&&choice!='2'&&choice!='3') cout<<"Hay bam lua chon dung"<<endl;
			} while(choice!='1'&&choice!='2'&&choice!='3');
			if(choice=='1') return approve_demand_function(acc_librarian);
			if(choice=='2') return disapprove_demand_function(acc_librarian);
			if(choice=='3') return approve_book(acc_librarian);
		}
		if(amount<=0) {
			cout<<"1. Cho vao hang doi"<<endl;
			cout<<"2. Khong dong y voi don yeu cau"<<endl;
			cout<<"3. Tro ve"<<endl;
			cout<<"Nhap lua chon:"<<endl;
			char choice;
			do {
				fflush(stdin);
				choice=_getch();
				fflush(stdin);
				if(choice!='1'&&choice!='2'&&choice!='3') cout<<"Hay bam lua chon dung"<<endl;
			} while(choice!='1'&&choice!='2'&&choice!='3');
			if(choice=='1') return send_demand_to_waiting_line_function(acc_librarian);
			if(choice=='2') return disapprove_demand_function(acc_librarian);
			if(choice=='3') return approve_book(acc_librarian);
		}
	} else {
		cout<<"Danh sach duyet rong"<<endl;
		cout<<"Nhan bat ky de tro ve"<<endl;
		char choice;
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		return approve_book(acc_librarian);
	}
}


