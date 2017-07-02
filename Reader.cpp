#include"Assignment.h"

////////////////////////////////////////////Tim sach

int getbook(Book& book,fstream& outfile, int row) {
	if (!outfile.eof()) {
		row = row - row % 8; // row co nghia la hang bat dau getline
		//ham for dung de bo nhung hang dau tien de getline hang can lay thong tin
		for (int i = 0; i < row; i++) {
			string line;
			getline(outfile, line);
		}
		string ISBN;
		getline(outfile,book.ISBN);
		if (book.ISBN == "")
			return 0;
		else {
			getline(outfile, book.name);
			getline(outfile, book.author);
			getline(outfile, book.category);
			getline(outfile, book.publisher);
			string temp;
			getline(outfile, temp);
			stringstream ss1(temp);
			ss1 >> book.year;
			getline(outfile, temp);
			stringstream ss2(temp);
			ss2 >> book.amount;
			getline(outfile, temp);
			stringstream ss3(temp);
			ss3 >> book.price;
			return 1;
		}

	} else
		return 0;
}

void printline() {
	for (int i = 0; i < 156; i++)
		cout << "-";
	cout << endl;
}

void printlinealreadyhave() {
	for (int i = 0; i < 162; i++)
		cout << "-";
	cout << endl;
}

void printtitle() {
	printline();
	cout << "| STT |     ISBN       |                      Ten sach               |        Tac gia        |        The loai       |         NXB         |  Nam |Gia thue|\n";
	printline();
}


//lay so ky tu nam trong khoang space tuy y, ket thuc tra ve 1 chuoi co ky tu "..." o cuoi neu chuoi co do dai lon hon khoang space.
string getnumofchar(string str,int space) {
	if (str.length() <= space)
		return str;
	else {
		string temp = "";
		for (int i = 0; i < (space - 4); i++)
			temp += str[i];
		temp += " ...";
		return temp;
	}
}

//tra ve mot string la ten cua the loai tuy thuoc vao ma the loai.
string getcategoryname(int categoryNo) {
	switch (categoryNo) {
		case 1:
			return "VAN HOC";
		case 2:
			return "THIEU NHI";
		case 3:
			return "KY NANG, DAY NGHE, NGHE NGHIEP";
		case 4:
			return "KIEN THUC DOI SONG";
		case 5:
			return "KINH TE, TAI CHINH";
		case 6:
			return "GIAO KHOA, THAM KHAO, GIAO TRINH";
		case 7:
			return "TU DIEN";
		case 8:
			return "TRUYEN TRANH";
		case 9:
			return "TAM LY";
		case 10:
			return "KIEN THUC TONG HOP";
		case 11:
			return "NGOAI VAN";
		case 12:
			return "THE LOAI KHAC";
	}
}


//tra ve 1 chuoi danh sach ten cac the loai
string getallcategoryname(string categorylist) {
	stringstream ss(categorylist);
	int categoryNo;
	string temp = "";
	while (!ss.eof()) {
		ss >> categoryNo;
		temp += getcategoryname(categoryNo) + " - ";
	}
	if(temp[temp.length()-2]=='-') temp[temp.length()-2]=' ';
	return temp;
}

//xuat ra man hinh thong tin cua sach theo 1 hang.
void showbookinfo(Book& book,int count) {
	string category = getallcategoryname(book.category);
	cout << "|" << setw(4) << count << " |" << right << setw(15) << book.ISBN << " | " << left << setw(44) << getnumofchar(book.name, 44) << "| " << setw(21) << getnumofchar(book.author, 21) << " | " << setw(21) << getnumofchar(category, 21) << " | " << setw(19) << getnumofchar(book.publisher,19) << " | " << right << setw(4) << book.year << " |" << setw(7) << book.price << " |\n";
}


void printtitlealreadyhave() {
	printlinealreadyhave();
	cout << "| STT |     ISBN       |                      Ten sach               |        Tac gia        |     The loai    |       NXB       |  Nam | Gia   |    Ngay thue   |\n";
	printlinealreadyhave();
}
void showalreadyhavebookinfo(Book& book,int count, string date) {
	string category = getallcategoryname(book.category);
	date=getDay(date);
	cout << "|" << setw(4) << count << " |" << right << setw(15) << book.ISBN << " | " << left << setw(44) << getnumofchar(book.name, 44) << "| " << setw(21) << getnumofchar(book.author, 21) << " | " << setw(15) << getnumofchar(category, 15) << " | " << setw(15) << getnumofchar(book.publisher,15) << " | " << right << setw(4) << book.year << " |" << setw(7) << book.price << "|"<<setw(15)<<date<<" |\n";
}

void showfullinfo(Book& book) {
	cout << "ISBN: " << book.ISBN << endl;
	cout << "Ten sach: " << book.name << endl;
	cout << "The loai: " << getallcategoryname(book.category) << endl;
	cout << "Nha xuat ban: " << book.publisher << endl;
	cout << "Nam xuat ban: " << book.year << endl;
	cout << "Gia(VND/ngay): " << book.price << endl;
}

void read_book_info(account *acc_reader) {
	string ISBN;
	cout<<"Nhap ISBN sach ban muon tim hieu: "<<endl;
	getline(cin,ISBN);
	if(check_ISBN_Book(ISBN)==0||ISBN=="") {
		char choice;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return read_book_info(acc_reader);
		if(choice=='2') return search_book(acc_reader);
	} else {
		Book book;
		get_book_info(book,ISBN);
		//	cout<<"test "<<book.name<< book.ISBN<<endl;
		system("cls");
		showfullinfo(book);
		char choice;
		cout<<"Nhan 1 muon dua vao gio hang."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') add_to_demand_borrow_searching_function(acc_reader,ISBN);
		if(choice=='2') return search_book(acc_reader);
	}
}

//xuat thong tin cua toan bo sach co trong thu vien.
void show_all_book(account *acc_reader) {
	system("cls");
	fstream outfile;
	outfile.open("book.txt", ios::in);
	Book book;
	int count = 0;
	printtitle();
	while (1) {
		if (getbook(book,outfile,0) == 1) {
			count++;
			showbookinfo(book, count);
		} else {
			break;
		}
	}
	printline();
	outfile.close();
	char choice;
	cout<<"Nhan 1 de tim hieu thong tin ve 1 cuon sach."<<endl;
	cout<<"Nhan 2 de tro ve."<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') return read_book_info(acc_reader);
	if(choice=='2') return search_book(acc_reader);
}


//Show book thong qua the loai
void show_book_via_category(account *acc_reader) {
	system("cls");
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
	printtitle();
	str=getcategoryname(choice);
	find_the_loai(str, 3);
	char choice1;
	cout<<"Nhan 1 de tim hieu thong tin ve 1 cuon sach."<<endl;
	cout<<"Nhan 2 de tro ve."<<endl;
	do {
		fflush(stdin);
		choice1=_getch();
		fflush(stdin);
		if(choice1!='1'&&choice1!='2') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice1!='1'&&choice1!='2');
	if(choice1=='1') return read_book_info(acc_reader);
	if(choice1=='2') return search_book(acc_reader);
}
//Lay thong tin sach thong qua ISBN
void get_book_via_ISBN(Book& book, string ISBN) {
	fstream outfile;
	fstream outfile2;
	string line;
	int curline = 0;
	outfile.open("book.txt", ios::in);
	if (outfile.is_open()) {
		while (getline(outfile, line)) {
			if (line.find(ISBN, 0) != -1) {
				outfile2.open("book.txt", ios::in);
				getbook(book, outfile2, curline);
				outfile2.close();
				break;
			}
			curline++;
		}
	} else
		cout << "Khong co file";
	outfile.close();

}
//Chon book
void choosebook(Book& book, string foundbookISBN,int selection) {
	stringstream ss(foundbookISBN);
	string ISBN;
	for (int i = 0; i < selection; i++) {
		getline(ss, ISBN);
	}
	get_book_via_ISBN(book, ISBN);
}



//Tim kiem theo tung loai:
//0-ISBN
//1-Ten sach
//2-Tac gia
//3-NXB
//4-Nam XB
void find_key(string str, int selection) {
	Book book;
	fstream outfile;
	fstream outfile2;
	string line;
	string foundbookISBN = "";
	int curline = 0;
	int count = 0;

	outfile.open("book.txt", ios::in);
	if (outfile.is_open()) {
		for (int i = 0; i < selection; i++) {
			getline(outfile, line);
			curline++;
		}

		while (getline(outfile, line)) {
			curline++;
			if (line.find(str, 0) != -1) {
				outfile2.open("book.txt", ios::in);
				getbook(book, outfile2, curline);
				count++;
				showbookinfo(book, count);
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
		printline();
	} else
		cout << "Khong co file";
	if (count == 0) {
		cout << "Khong co ket qua phu hop voi tu khoa!"<<endl;

	}
	outfile.close();
}

void find_the_loai(string str, int selection) {
	Book book;
	fstream outfile;
	fstream outfile2;
	string line;
	string foundbookISBN = "";
	int curline = 0;
	int count = 0;

	outfile.open("book.txt", ios::in);
	if (outfile.is_open()) {
		for (int i = 0; i < selection; i++) {
			getline(outfile, line);
			curline++;
		}

		while (getline(outfile, line)) {
			curline++;
			line=getallcategoryname(line);
			if (line.find(str, 0) != -1) {
				outfile2.open("book.txt", ios::in);
				getbook(book, outfile2, curline);
				count++;
				showbookinfo(book, count);
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
		printline();
	} else
		cout << "Khong co file";
	if (count == 0) {
		cout << "Khong co ket qua phu hop voi tu khoa!"<<endl;

	}
	outfile.close();
}
//Search tuy chon
void search_key(string str) {
	fstream outfile;
	//fstream outfile2;
	string foundbookISBN = "";
	outfile.open("book.txt", ios::in);
	Book book;
	string info;
	printtitle();
	string	get_category;
	int curline = 0;
	int count = 0;
	if (outfile.is_open()) {
		while (getbook(book,outfile,0)) {
			stringstream ss;
			string year, price;
			ss << book.year << book.price;
			ss >> year >> price;
			get_category=getallcategoryname(book.category);
			if ((book.ISBN.find(str, 0) != -1) || (book.name.find(str, 0) != -1) || (book.author.find(str, 0) != -1) || (get_category.find(str, 0) != -1) || (book.publisher.find(str, 0) != -1) || (year.find(str, 0) != -1) || (price.find(str, 0) != -1)) {
				count++;
				foundbookISBN += book.ISBN + "\n";
				showbookinfo(book, count);
			}
		}
	} else
		cout << "Khong co file";

	if (count == 0)
		cout << "Khong co ket qua phu hop voi tu khoa!\n";

	printline();
	outfile.close();
}
//Search tong hop
void search_tong_hop(account *acc_reader) {
	system("cls");
	string key;
	do {
		cout<<"Nhap tu khoa ban muon tim kiem: "<<endl;
		getline(cin,key);
		key=uppercase(key);
		if(key=="") cout<<"Khong duoc de trong, hay nhap lai "<<endl;
	} while(key=="");
	search_key(key);
	char choice;
	cout<<"Nhan 1 de tim hieu thong tin ve 1 cuon sach."<<endl;
	cout<<"Nhan 2 de tro ve."<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') return read_book_info(acc_reader);
	if(choice=='2') return search_book(acc_reader);
}
void search_tuy_chon(account *acc_reader) {
	system("cls");
	cout<<"Tim kiem theo: "<<endl;
	cout<<"1-ISBN"<<endl;
	cout<<"2-Ten sach"<<endl;
	cout<<"3-Tac gia"<<endl;
	cout<<"4-Nha xuat ban"<<endl;
	cout<<"5-Nam xuat ban"<<endl;
	int choice;
	do {
		cin.clear();
		fflush(stdin);
		cin>>choice;
		fflush(stdin);
		if(cin.fail()||choice>5||choice<1) cout<<"Hay bam lua chon dung"<<endl;
	} while(cin.fail()||choice>5||choice<1);
	string key;
	do {
		cout<<"Nhap tu khoa ban muon tim kiem: "<<endl;
		getline(cin,key);
		key=uppercase(key);
		if(key=="") cout<<"Khong duoc de trong, hay nhap lai "<<endl;
	} while(key=="");
	system("cls");
	printtitle();
	if(choice==1) find_key(key,choice-1);
	if(choice==2) find_key(key,choice-1);
	if(choice==3) find_key(key,choice-1);
	if(choice==4) find_key(key,choice);
	if(choice==5) find_key(key,choice);
	char choice1;
	cout<<"Nhan 1 de tim hieu thong tin ve 1 cuon sach."<<endl;
	cout<<"Nhan 2 de tro ve."<<endl;
	do {
		fflush(stdin);
		choice1=_getch();
		fflush(stdin);
		if(choice1!='1'&&choice1!='2') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice1!='1'&&choice1!='2');
	if(choice1=='1') return read_book_info(acc_reader);
	if(choice1=='2') return search_book(acc_reader);

}
//Tim kiem chung
void search_book(account *acc_reader) {
	system("cls");
	cout<<"CHUC NANG TIM KIEM CUA DOC GIA: "<<acc_reader->getUsername()<<endl;
	printline();
	printline();
	cout<<"1. Show toan bo danh sach sach"<<endl;
	cout<<"2. Show danh sach sach theo the loai"<<endl;
	cout<<"3. Tim kiem tong hop"<<endl;
	cout<<"4. Tim kiem tuy chon"<<endl;
	cout<<"5. Tim hieu thong tin day du cua sach"<<endl;
	cout<<"6. Tro ve"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6');
	if(choice=='1') return show_all_book(acc_reader);
	if(choice=='2') return show_book_via_category(acc_reader);
	if(choice=='3') return search_tong_hop(acc_reader);
	if(choice=='4') return search_tuy_chon(acc_reader);
	if(choice=='5') return read_book_info(acc_reader);
	if(choice=='6') return mainmenu(acc_reader);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//Cart

void delete_entire_cart(account *acc) {
	string filename="cart_"+acc->getUsername()+".txt";
	ofstream outfile;
	outfile.open(filename.c_str(), ofstream::out | ofstream::trunc);
	outfile.close();
}

void delete_single_book_cart_function(account *acc, string ISBN) {
	fstream outfile;
	string filename="cart_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	Book *tempbook=new Book();
	string date, numberofdate;
	int flag=0;
	while (getline(outfile, datatemp)) {
		tempbook->ISBN=datatemp;
		getline(outfile, datatemp);
		tempbook->name=datatemp;
		getline(outfile, datatemp);
		tempbook->author=datatemp;
		getline(outfile, datatemp);
		tempbook->category=datatemp;
		getline(outfile, datatemp);
		tempbook->publisher=datatemp;
		getline(outfile, datatemp);
		tempbook->year=atoi(datatemp.c_str());
		getline(outfile, datatemp);
		tempbook->price=atoi(datatemp.c_str());
		getline(outfile, datatemp);
		date=datatemp;
		getline(outfile, datatemp);
		numberofdate=datatemp;

		if (ISBN != tempbook->ISBN) {
			temp << tempbook->ISBN << '\n' << tempbook->name << '\n' << tempbook->author << '\n' << tempbook->publisher << '\n' << tempbook->year <<'\n' << tempbook->price <<'\n'<<date <<'\n' << numberofdate << endl;
		}

	}
	temp.close();
	outfile.close();
	delete[]tempbook;
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
}

//Lay thong tin gia
int get_price(account *acc) {
	fstream outfile;
	string filename="cart_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string datatemp;
	Book *tempbook=new Book();
	string date, numberofdate;
	int dateint,numberofdateint;
	int totalprice=0;
	while (getline(outfile, datatemp)) {
		tempbook->ISBN=datatemp;
		getline(outfile, datatemp);
		tempbook->name=datatemp;
		getline(outfile, datatemp);
		tempbook->author=datatemp;
		getline(outfile, datatemp);
		tempbook->category=datatemp;
		getline(outfile, datatemp);
		tempbook->publisher=datatemp;
		getline(outfile, datatemp);
		tempbook->year=atoi(datatemp.c_str());
		getline(outfile, datatemp);
		tempbook->price=atoi(datatemp.c_str());
		getline(outfile, datatemp);
		date=datatemp;
		getline(outfile, datatemp);
		numberofdate=datatemp;
		numberofdateint=atoi(datatemp.c_str());
		totalprice=totalprice+numberofdateint*tempbook->price;
	}
	outfile.close();
	return totalprice;
}

//Lay thong tin sach thong qua ISBN
int getbookinfomation(Book& book, string ISBN) {
	fstream outfile;
	outfile.open("book.txt", ios::in);
	string datatemp;
	Book temp;
	while (getline(outfile,  temp.ISBN)) {
		getline(outfile, temp.name);
		getline(outfile,  temp.author);
		getline(outfile, temp.category);
		getline(outfile, temp.publisher);
		getline(outfile, datatemp);
		temp.year=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp.amount=atoi(datatemp.c_str());
		getline(outfile,  datatemp);
		temp.price=atoi(datatemp.c_str());
		if(ISBN==temp.ISBN) {
			book.ISBN=temp.ISBN;
			book.name=temp.name;
			book.author=temp.author;
			book.category=temp.category;
			book.publisher=temp.publisher;
			book.year=temp.year;
			book.amount=temp.amount;
			book.price=temp.price;
			outfile.close();
			return 1;
		}

	}
	outfile.close();
	return 0;
}

//Dem book dang yeu cau muon
int count_number_of_book_demand(account *acc) {
	fstream outfile;
	string datatemp;
	int count=0;
	string filename="demand_book_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(),ios::in );
	}
	while(getline(outfile,datatemp)) {
		count++;
	}
	outfile.close();
	return count;
}
//Xoa toan bo yeu cau muon
void delete_entire_demand(account *acc) {
	string filename="demand_book_"+acc->getUsername()+".txt";
	ofstream outfile;
	outfile.open(filename.c_str(), ofstream::out | ofstream::trunc);
	outfile.close();
}
//Them sach voa yeu cau muon
void add_to_demand_borrow_function(account *acc,string ISBN) {
	fstream outfile;
	if(check_exist_book_in_store(ISBN)==0||check_exist_ISBN_in_demand_file(acc, ISBN)==1||(count_number_of_waiting_of_each_person(acc)+count_in_demand_file(acc))>=4||check_exist_book_in_book_people_wanting_line(acc,  ISBN)==1) {
		if(check_exist_ISBN_in_demand_file(acc,ISBN)==1||check_exist_book_in_book_people_wanting_line(acc,  ISBN)==1) cout<<"Khong the them duoc do sach da ton tai trong don hang hoac ban dang trong danh sach cho cuon sach nay."<<endl;
		if((count_number_of_waiting_of_each_person(acc)+ count_in_demand_file(acc))>4) cout<<"Khong the them duoc do so luong sach trong hang doi va trong don vuot qua 4"<<endl;
		if(check_exist_book_in_store(ISBN)==0) cout<<"Khong ton tai sach trong kho"<<endl;
		return;
	} else {
		string filename="demand_book_"+acc->getUsername()+".txt";
		outfile.open(filename.c_str(), ios_base::app);
		if (!outfile) {
			outfile.clear();
			outfile.open(filename.c_str(),ios::out|ios::binary);
			outfile.close();
			outfile.open(filename.c_str(), ios_base::app);
		}
		outfile<<ISBN<<'\n';
		outfile.close();

	}
}
//Them sach khi dang tim kiem vao yeu cau muon
void add_to_demand_borrow_searching_function(account *acc,string ISBN) {
	fstream outfile;
	if(check_exist_book_in_store(ISBN)==0||check_exist_ISBN_in_demand_file(acc, ISBN)==1||(count_number_of_waiting_of_each_person(acc)+count_in_demand_file(acc))>=4||check_exist_book_in_book_people_wanting_line(acc,  ISBN)==1) {
		if(check_exist_ISBN_in_demand_file(acc,ISBN)==1||check_exist_book_in_book_people_wanting_line(acc,  ISBN)==1) cout<<"Khong the them duoc do sach da ton tai trong don hang hoac ban dang trong danh sach cho cuon sach nay."<<endl;
		if((count_number_of_waiting_of_each_person(acc)+ count_in_demand_file(acc))>=4) cout<<"Khong the them duoc do so luong sach trong hang doi va trong don vuot qua 4"<<endl;
		if(check_exist_book_in_store(ISBN)==0) cout<<"Khong ton tai sach trong kho"<<endl;
		char choice;
		cout<<"Nhan bat ky de tro ve."<<endl;

		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		return search_book(acc);
	} else {
		Book book;
		getbookinfomation(book, ISBN);
		cout<<"Da them vao cuon: ISBN:"<<book.ISBN<<", ten: "<<book.name<<", tac gia: "<<book.author<<endl;
		string filename="demand_book_"+acc->getUsername()+".txt";
		outfile.open(filename.c_str(), ios_base::app);
		if (!outfile) {
			outfile.clear();
			outfile.open(filename.c_str(),ios::out|ios::binary);
			outfile.close();
			outfile.open(filename.c_str(), ios_base::app);
		}
		outfile<<ISBN<<'\n';
		outfile.close();
		cout<<"Nhan bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return search_book(acc);
	}
}

//Them sach voa yeu cau muon 
void add_to_demand_borrow_in_don_hang_function(account *acc,string ISBN) {
	fstream outfile;
	if(check_exist_book_in_store(ISBN)==0||check_exist_ISBN_in_demand_file(acc, ISBN)==1||(count_number_of_waiting_of_each_person(acc)+count_in_demand_file(acc))>=4||check_exist_book_in_book_people_wanting_line(acc,  ISBN)==1) {
		if(check_exist_ISBN_in_demand_file(acc,ISBN)==1||check_exist_book_in_book_people_wanting_line(acc,  ISBN)==1) cout<<"Khong the them duoc do sach da ton tai trong don hang hoac ban dang trong danh sach cho cuon sach nay."<<endl;
		if((count_number_of_waiting_of_each_person(acc)+ count_in_demand_file(acc))>=4) cout<<"Khong the them duoc do so luong sach trong hang doi va trong don vuot qua 4"<<endl;
		if(check_exist_book_in_store(ISBN)==0) cout<<"Khong ton tai sach trong kho"<<endl;
		char choice;
		cout<<"Nhan 1 neu ban muon nhap mot ISBN khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			if(choice!='1'&&choice!='2') cout<<"Hay bam lua chon dung"<<endl;
		} while(choice!='1'&&choice!='2');
		if(choice=='1') return add_to_demand_borrow(acc);
		if(choice=='2') return demand_book(acc);
	} else {
		Book book;
		getbookinfomation(book, ISBN);
		cout<<"Da them vao cuon: ISBN:"<<book.ISBN<<", ten: "<<book.name<<", tac gia: "<<book.author<<endl;
		string filename="demand_book_"+acc->getUsername()+".txt";
		outfile.open(filename.c_str(), ios_base::app);
		if (!outfile) {
			outfile.clear();
			outfile.open(filename.c_str(),ios::out|ios::binary);
			outfile.close();
			outfile.open(filename.c_str(), ios_base::app);
		}
		outfile<<ISBN<<'\n';
		outfile.close();
		cout<<"Nhan bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return demand_book(acc);
	}
}
//Them sach muon thong qua ISBN
void add_to_demand_borrow(account *acc) {
	system("cls");
	cout<<"Nhap ISBN sach muon muon: "<<endl;
	string ISBN;
	getline(cin,ISBN);
	add_to_demand_borrow_in_don_hang_function(acc, ISBN);


}
//Gui yeu cau cho thu thu
void send_demand_borrow_to_librarian_function(account *acc_reader) {
	system("cls");
	if(check_exist_in_book_people_want_to_borrow_file(acc_reader)==1||check_exist_book_in_already_one_person_have(acc_reader)==1) {
		cout<<"Khong the gui don hang do ban doc chua tra het sach hoac co don hang cua ban dang doi duyet."<<endl;
		cout<<"Nhan bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return demand_book(acc_reader);
	} else {
		fstream outfile;
		string filename="demand_book_"+acc_reader->getUsername()+".txt";
		outfile.open(filename.c_str(),ios::in);
		if (!outfile) {
			outfile.clear();
			outfile.open(filename.c_str(),ios::out);
			outfile.close();
			outfile.open(filename.c_str(), ios::in);
		}
		fstream outfile2;
		outfile2.open("book_people_want_to_borrow.txt", ios_base::app);
		string datatemp;
		Book book;
		while(getline(outfile,datatemp)) {
			getbookinfomation(book,datatemp);
			outfile2<<acc_reader->getID()<<'\n';
			outfile2<<acc_reader->getUsername()<<'\n';
			outfile2<<book.ISBN<<'\n';
			outfile2<<book.name<<'\n';
		}
		delete_entire_demand(acc_reader);
		outfile.close();
		outfile2.close();
		cout<<"Da gui don yeu cau muon sach toi thu thu"<<endl;
		cout<<"Nhan bat ky de tro ve"<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return demand_book(acc_reader);
	}
}

//Xoa 1 cuon trong yeu cau muon
void delete_single_book_in_demand_function(account *acc, string ISBN) {
	fstream outfile;
	string filename="demand_book_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	int counttemp=0;
	while (getline(outfile, datatemp)) {
		counttemp++;
		if (datatemp!=ISBN) {
			temp<<datatemp<<endl;
		}

	}
	temp.close();
	outfile.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
}


//Xoa 1 cuon trong hang doi cua tung nguoi
void delete_single_book_in_waiting_of_each_person_function(account *acc, string ISBN) {
	fstream outfile;
	string filename="book_waiting_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	int counttemp=0;
	Book booktemp;
	while (getline(outfile, datatemp)) {
		booktemp.ISBN=datatemp;
		getline(outfile,datatemp);
		booktemp.name=datatemp;
		getline(outfile,datatemp);
		booktemp.author=datatemp;
		getline(outfile,datatemp);
		booktemp.category=datatemp;
		getline(outfile,datatemp);
		booktemp.publisher=datatemp;
		getline(outfile,datatemp);
		booktemp.year=atoi(datatemp.c_str());
		if(ISBN!=booktemp.ISBN) {
			temp<<booktemp.ISBN<<endl;
			temp<<booktemp.name<<endl;
			temp<<booktemp.author<<endl;
			temp<<booktemp.category<<endl;
			temp<<booktemp.publisher<<endl;
			temp<<booktemp.year<<endl;
		}
	}
	temp.close();
	outfile.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
	delete_after_waiting_process(acc, ISBN);
}
//Xoa 1 cuon trong hang doi cua tung nguoi
void delete_single_book_in_waiting_of_each_person(account *acc) {
	cout<<"Nhap ISBN cua sach can xoa: "<<endl;
	string ISBN;
	getline(cin,ISBN);
	if(check_exist_ISBN_of_waiting_of_each_person(acc,ISBN) ==0) {
		cout<<"Khong ton tai cuon sach"<<endl<<"Nhan mot phim ngau nhien de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return waiting_book(acc);
	} else {
		delete_single_book_in_waiting_of_each_person_function(acc, ISBN);
		system("cls");
		cout<<"Da xoa. Nhan mot phim ngau nhien de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return waiting_book(acc);
	}
}
//Xoa sach yeu cau
void delete_a_book_in_demand(account *acc) {
	cout<<"Nhap ISBN cua sach can xoa: "<<endl;
	string ISBN;
	getline(cin,ISBN);
	if(check_exist_ISBN_in_demand_file(acc, ISBN)==0) {
		cout<<"Khong ton tai cuon sach"<<endl<<"Nhan mot phim ngau nhien de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return demand_book(acc);
	} else {
		delete_single_book_in_demand_function(acc,  ISBN);
		cout<<"Da xoa. Nhan mot phim ngau nhien de tro ve."<<endl;
		fflush(stdin);
		char choice;
		choice=_getch();
		fflush(stdin);
		return demand_book(acc);
	}

}
//Xoa sach dang co
void delete_single_book_in_people_already_have(account *acc, string ISBN) {
	fstream outfile;
	string filename="book_already_people_have.txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	int counttemp=0;
	Book booktemp;
	account *tempacc=new account();
	string date;
	while (getline(outfile, datatemp)) {
		tempacc->setID(datatemp);
		getline(outfile,datatemp);
		tempacc->setUsername(datatemp);
		getline(outfile,datatemp);
		booktemp.ISBN=datatemp;
		getline(outfile,datatemp);
		booktemp.name=datatemp;
		getline(outfile,datatemp);
		date=datatemp;
		if(ISBN!=booktemp.ISBN||tempacc->getUsername()!=acc->getUsername()) {
			temp<<tempacc->getID()<<endl;
			temp<<tempacc->getUsername()<<endl;
			temp<<booktemp.ISBN<<endl;
			temp<<booktemp.name<<endl;
			temp<<date<<endl;
		}
	}
	temp.close();
	outfile.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());

}
//Xoa sasch tung nguoi dang co
void delete_single_book_in_already_have_of_each_person_function(account *acc, string ISBN) {
	fstream outfile;
	string filename="book_alread_have_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	fstream temp;
	temp.open("temp.txt", ios::out);
	string datatemp;
	int counttemp=0;
	Book booktemp;
	string date;
	while (getline(outfile, datatemp)) {
		booktemp.ISBN=datatemp;
		getline(outfile,datatemp);
		booktemp.name=datatemp;
		getline(outfile,datatemp);
		booktemp.author=datatemp;
		getline(outfile,datatemp);
		booktemp.category=datatemp;
		getline(outfile,datatemp);
		booktemp.publisher=datatemp;
		getline(outfile,datatemp);
		booktemp.year=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		booktemp.amount=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		booktemp.price=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		date=datatemp;
		if(ISBN!=booktemp.ISBN) {
			temp<<booktemp.ISBN<<endl;
			temp<<booktemp.name<<endl;
			temp<<booktemp.author<<endl;
			temp<<booktemp.category<<endl;
			temp<<booktemp.publisher<<endl;
			temp<<booktemp.year<<endl;
			temp<<booktemp.amount<<endl;
			temp<<booktemp.price<<endl;
			temp<<date<<endl;

		}
	}
	temp.close();
	outfile.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
	delete_single_book_in_people_already_have(acc,ISBN);
}
//Show toan bo yeu cau
void show_demand_function(account *acc) {
	system("cls");
	fstream outfile;
	string filename="demand_book_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	printtitle();
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string datatemp;
	Book book;
	int count=0;
	while(getline(outfile,datatemp)) {
		count++;
		getbookinfomation(book, datatemp);
		showbookinfo(book,count);
	}
	printline();
	outfile.close();
}
//Yeu cau muon sach
void demand_book(account *acc) {
	show_demand_function(acc);
	printline();
	cout<<"1. Dat them sach"<<endl;
	cout<<"2. Xoa bo mot cuon trong don muon sach"<<endl;
	cout<<"3. Gui cho thu thu"<<endl;
	cout<<"4. Tro ve"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4');
	if(choice=='1') return add_to_demand_borrow(acc);
	if(choice=='2') return delete_a_book_in_demand(acc);
	if(choice=='3') return send_demand_borrow_to_librarian_function(acc);
	if(choice=='4') return mainmenu(acc);
}
//Hang doi tung nguoi
void show_waiting_function(account *acc) {
	system("cls");
	fstream outfile;
	string filename="book_waiting_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	printtitle();
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string datatemp;
	Book booktemp;
	int count=0;
	while(getline(outfile,datatemp)) {
		booktemp.ISBN=datatemp;
		getline(outfile,datatemp);
		booktemp.name=datatemp;
		getline(outfile,datatemp);
		booktemp.author=datatemp;
		getline(outfile,datatemp);
		booktemp.category=datatemp;
		getline(outfile,datatemp);
		booktemp.publisher=datatemp;
		getline(outfile,datatemp);
		count++;
		booktemp.year=atoi(datatemp.c_str());
		getbookinfomation(booktemp, datatemp);
		showbookinfo(booktemp,count);
	}
	printline();
	outfile.close();
}
//Show dang co
void show_already_have_function(account *acc) {
	system("cls");
	fstream outfile;
	string filename="book_already_have_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	printtitlealreadyhave();
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string datatemp;
	Book booktemp;
	string date;
	int count=0;
	while(getline(outfile,datatemp)) {
		booktemp.ISBN=datatemp;
		getline(outfile,datatemp);
		booktemp.name=datatemp;
		getline(outfile,datatemp);
		booktemp.author=datatemp;
		getline(outfile,datatemp);
		booktemp.category=datatemp;
		getline(outfile,datatemp);
		booktemp.publisher=datatemp;
		getline(outfile,datatemp);
		booktemp.year=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		booktemp.amount=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		booktemp.price=atoi(datatemp.c_str());
		getline(outfile,datatemp);
		date=datatemp;
		count++;
		getbookinfomation(booktemp, booktemp.ISBN);
		showalreadyhavebookinfo(booktemp,count,date);
	}
	printline();
	outfile.close();
}
//Show sach chua duoc duyet
void show_book_not_already_approve(account *acc_reader) {
	system("cls");
	fstream outfile;
	string filename="book_people_want_to_borrow.txt";
	outfile.open(filename.c_str(), ios::in);
	printtitle();
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string datatemp;
	Book tempbook;
	string date;
	int count=0;
	account *readertemp=new account();
	while (getline(outfile, datatemp)) {
		readertemp->setID(datatemp);
		getline(outfile,datatemp);
		readertemp->setUsername(datatemp);
		getline(outfile,datatemp);
		tempbook.ISBN=datatemp;
		getline(outfile,datatemp);
		tempbook.name=datatemp;
		if(readertemp->getUsername()==acc_reader->getUsername()) {
			count++;
			getbookinfomation(tempbook, tempbook.ISBN);
			showbookinfo(tempbook,count);
		}
	}
	printline();
	cout<<"Nhan phim bat ky de tro ve"<<endl;
	outfile.close();
	char choice;
	fflush(stdin);
	choice=_getch();
	fflush(stdin);
	return waiting_book(acc_reader);
}
//Sach dang doi
void waiting_book(account *acc) {
	system("cls");
	show_waiting_function(acc);
	cout<<"Nhap lua chon:"<<endl;
	cout<<"1. Xoa mot cuon sach ra khoi danh sach doi"<<endl;
	cout<<"2. Kiem tra nhung sach chua duoc thu thu xet den"<<endl;
	cout<<"3. Tro ve"<<endl;
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3');
	if(choice=='1') return delete_single_book_in_waiting_of_each_person(acc);
	if(choice=='2') return show_book_not_already_approve(acc);
	if(choice=='3') return mainmenu(acc);
}



/// show toan bo thong bao
void show_all_announcement(account *acc) {
	fstream outfile;
	string filename="announcement_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(),ios::in);
	}
	string datatemp;
//	cout << " __________________________________________________________________________________________"<<endl;
	cout << "| ID thong bao |             Thong bao                 |        Ngay        |   Da doc ?   |\n";
	cout << " __________________________________________________________________________________________"<<endl;
	cout<<endl;
	announcement *temp = new announcement();
	while (getline(outfile,datatemp)) {
		temp->setID(datatemp);
		getline(outfile, datatemp);
		temp->setAnnounce(datatemp);
		getline(outfile, datatemp);
		temp->setDate(datatemp);
		getline(outfile, datatemp);
		temp->setSeen(datatemp);
		cout<<"|"<<setw(14)<<left<<temp->getID()<<"|";
		if(temp->getAnnounce().length()<40) cout<<setw(39)<<left<<temp->getAnnounce();
		else {
			for(int i=0; i<36; i++) cout<<left<<temp->getAnnounce()[i];
			cout<<"...";
		}
		cout<<"|"<<setw(20)<<temp->getDate()<<"|";
		if(temp->getSeen()=="0") cout<<setw(14)<<left<<"Chua doc"<<endl;
		else cout<<setw(14)<<left<<"Da doc"<<endl;
	}
	outfile.close();
}
//Delete toan bo thong bao
void delete_entire_announcement(account *acc) {
	system("cls");
	cout<<"Ban co chac muon xoa toan bo thong bao hay khong? "<<endl;
	cout<<"1. Co"<<endl<<"2. Khong"<<endl;
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') {
		string filename="announcement_"+acc->getUsername()+".txt";
		ofstream outfile;
		outfile.open(filename.c_str(), ofstream::out | ofstream::trunc);
		outfile.close();
		cout<<"Da xoa."<<endl;
		cout<<"Nhan bat ky de tro ve. "<<endl;
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		return read_announcement(acc);
	}
	if(choice=='2') {
		return read_announcement(acc);
	}
}
//Delete nhung thong bao da seen
void delete_already_seen_announcement(account *acc) {
	system("cls");
	cout<<"Ban co chac muon xoa thong bao chua doc hay khong? "<<endl;
	cout<<"1. Co"<<endl<<"2. Khong"<<endl;
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') {
		fstream outfile;
		string filename="announcement_"+acc->getUsername()+".txt";
		outfile.open(filename.c_str(), ios::in);
		if (!outfile) {
			outfile.clear();
			outfile.open(filename.c_str(),ios::out|ios::binary);
			outfile.close();
			outfile.open(filename.c_str(),ios::in);
		}
		fstream temp1;
		temp1.open("temp.txt", ios::out);
		string datatemp;
		announcement *temp=new announcement();
		string date, numberofdate;
		int flag=0;
		while (getline(outfile, datatemp)) {
			temp->setID(datatemp);
			getline(outfile, datatemp);
			temp->setAnnounce(datatemp);
			getline(outfile, datatemp);
			temp->setDate(datatemp);
			getline(outfile, datatemp);
			temp->setSeen(datatemp);
			if (temp->getSeen()=="0") {
				temp1 << temp->getID() << '\n' << temp->getAnnounce() << '\n' << temp->getDate() << '\n' << temp->getSeen() <<endl;
			}
		}
		temp1.close();
		outfile.close();
		remove(filename.c_str());
		rename("temp.txt", filename.c_str());
		cout<<"Da xoa."<<endl;
		cout<<"Nhan bat ky de tro ve. "<<endl;
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		read_announcement(acc);
	}
	if(choice=='2') read_announcement(acc);
}
//Chuyen thong bao thanh da doc
void set_announcement_already_seen(string ID, account *acc) {
	fstream outfile;
	string filename="announcement_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	fstream temp1;
	temp1.open("temp.txt", ios::out);
	string datatemp;
	announcement *temp=new announcement();
	while (getline(outfile,datatemp)) {
		temp->setID(datatemp);
		getline(outfile, datatemp);
		temp->setAnnounce(datatemp);
		getline(outfile, datatemp);
		temp->setDate(datatemp);
		getline(outfile, datatemp);
		temp->setSeen(datatemp);
		if (ID != temp->getID()) {
			temp1 << temp->getID() << '\n' << temp->getAnnounce() << '\n' << temp->getDate() << '\n' << temp->getSeen() <<endl;
		}
		if (ID == temp->getID()) {
			temp->setSeen("1");
			temp1 << temp->getID() << '\n' << temp->getAnnounce() << '\n' << temp->getDate() << '\n' <<  "1" <<endl;
		}
	}
	outfile.close();
	temp1.close();
	remove(filename.c_str());
	rename("temp.txt",filename.c_str());
}
//Doc thong bao voi ID
void read_announcement_with_ID_function(account *acc, string ID) {
	system("cls");
	fstream outfile;
	string filename="announcement_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string datatemp;
	announcement *temp=new announcement();
	while (getline(outfile, datatemp)) {
		temp->setID(datatemp);
		getline(outfile, datatemp);
		temp->setAnnounce(datatemp);
		getline(outfile, datatemp);
		temp->setDate(datatemp);
		getline(outfile, datatemp);
		temp->setSeen(datatemp);
		if(ID==temp->getID()) {
			cout<<"Ngay gui: "<<temp->getDate()<<endl; //Check lai ngay gui
			cout<<"Noi dung thong bao:"<<endl;
			cout<<temp->getAnnounce();
		}
	}
	outfile.close();
	set_announcement_already_seen(ID, acc);
	cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return read_announcement(acc);
}
//Doc thong bao voi ID
void read_announcement_with_ID(account *acc) {
	string ID;
	cout<<"Nhap ma thong bao ban muon doc: "<<endl;
	fflush(stdin);
	getline(cin, ID);
	if(check_ID_Announcement_in_file(acc,ID)==1) return read_announcement_with_ID_function(acc,ID);
	else {
		cout<<"Ma thong bao khong dung."<<endl;
		cout<<"Nhan 1 de nhap ma khac."<<endl;
		cout<<"Nhan bat ky (khac so 1) de tro ve."<<endl;
		char choice;
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice=='1') return read_announcement_with_ID(acc);
		else return read_announcement(acc);
	}
}
//Doc thong bao
void read_announcement(account *acc) {
	system("cls");
	cout<<"BANG THONG BAO CUA USER "<<acc->getUsername()<<endl<<endl;
	show_all_announcement(acc);
	cout<<endl<<endl;
	cout<<"1. Doc thong bao theo ma so."<<endl;
	cout<<"2. Xoa toan bo thong bao."<<endl;
	cout<<"3. Xoa thong bao da doc."<<endl;
	cout<<"4. Tro ve."<<endl;
	fflush(stdin);
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4');
	if(choice=='1') return read_announcement_with_ID(acc);
	if(choice=='2') return delete_entire_announcement(acc);
	if(choice=='3') return delete_already_seen_announcement(acc);
	if(choice=='4')  return read_infomation(acc);

}
//Gui thong bao
void send_announcement_reader(account *acc) {
	system("cls");
	cout<<"CHUC NANG GUI THONG BAO CUA DOC GIA ACCOUNT: "<<acc->getUsername()<<endl;
	cout<<"1. Gui thong bao cho quan ly nguoi dung."<<endl;
	cout<<"2. Gui thong bao cho thu thu."<<endl;
	cout<<"3. Tro ve."<<endl;
	fflush(stdin);
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4');
	if(choice=='1') send_announcement_to_all(acc,1,"1");
	if(choice=='2') send_announcement_to_all(acc,2,"1");
	if(choice=='3') return mainmenu(acc);
}

//Add thong tin vao lich su
void add_to_history_file(account *acc_reader, string history) {
	fstream outfile;
	string filetemp="temp_"+acc_reader->getUsername()+".txt";
	outfile.open(filetemp.c_str(), ios_base::app);
	outfile << "1" << "\n";
	outfile << history << "\n";
	outfile << currentDateTime() <<"\n";
	outfile.close();
	fstream outfilereal;
	string filename="history_"+acc_reader->getUsername()+".txt";
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
		if(count%3==1) {
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
//Doc thong tin account
void read_account_infomation(account *acc_reader) {
	system("cls");
	user *newUser=new user();
	*newUser=getinfouser(acc_reader->getID());
	cout<<"Ho va ten: "<<newUser->getName()<<endl;
	cout<<"CMND: "<<newUser->getCMND()<<endl;
	cout<<"SDT: "<<newUser->getPhone()<<endl;
	cout<<"Dia chi: "<<newUser->getAddress()<<endl;
	cout<<"Ngay sinh: "<<getDay(newUser->getBirthday())<<endl;
	cout<<"Email: "<<newUser->getEmail()<<endl;
	cout<<"Nghe nghiep: "<<newUser->getJob()<<endl;
	cout<<"Ten username account: "<<acc_reader->getUsername()<<endl;
	cout<<"Vai tro: "<<endl;
	string N=acc_reader->getRole();
	if(N[0]=='1') cout<<"-Doc gia"<<endl;
	if(N[1]=='1') cout<<"-Quan ly nguoi dung"<<endl;
	if(N[2]=='1') cout<<"-Thu thu"<<endl;
	cout<<"Nhan bat ky de tro ve."<<endl;
	char choice;
	fflush(stdin);
	choice=_getch();
	fflush(stdin);
	return read_infomation(acc_reader);

}
//Show lich su
void show_history(account *acc_reader) {
	fstream outfile;
	string filename="history_"+acc_reader->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(),ios::in);
	}
	string datatemp;
	string STT, history, date;
//	cout << " __________________________________________________________________________________________"<<endl;
	cout << "|  STT  |             Lich su                                     |        Ngay        |\n";
	cout << "__________________________________________________________________________________________"<<endl;
	cout<<endl;
	while (getline(outfile,STT)) {
		getline(outfile,history);
		getline(outfile,date);
		cout<<"|"<<setw(7)<<left<<STT<<"|";
		if(history.length()<=57) cout<<setw(57)<<left<<history;
		else {
			for(int i=0; i<54; i++) cout<<left<<history[i];
			cout<<"...";
		}
		cout<<"|"<<setw(20)<<date<<"|";
		cout<<endl;
	}
	outfile.close();
}
//Doc lich su voi ID
void read_history_with_ID_function(account *acc, string ID) {
	system("cls");
	fstream outfile;
	string filename="history_"+acc->getUsername()+".txt";
	outfile.open(filename.c_str(), ios::in);
	if (!outfile) {
		outfile.clear();
		outfile.open(filename.c_str(),ios::out|ios::binary);
		outfile.close();
		outfile.open(filename.c_str(), ios::in);
	}
	string STT,history,date;
	while (getline(outfile, STT)) {
		getline(outfile, history);
		getline(outfile, date);
		if(ID==STT) {
			cout<<"Thoi diem: "<<date<<endl; //Check lai ngay gui
			cout<<"Noi dung:"<<endl;
			cout<<history<<endl;
		}
	}
	outfile.close();
	cout<<endl<<"Nhap bat ky de tro ve:"<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return read_history(acc);
}
//Doc lich su voi ID
void read_history_with_ID(account *acc) {
	string ID;
	cout<<"Nhap stt lich su ban muon doc: "<<endl;
	fflush(stdin);
	getline(cin, ID);
	if(check_ID_history_in_file(acc,ID)==1) return read_history_with_ID_function(acc,ID);
	else {
		cout<<"Ma lich su khong dung."<<endl;
		cout<<"Nhan 1 de nhap ma khac."<<endl;
		cout<<"Nhan bat ky (khac so 1) de tro ve."<<endl;
		char choice;
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice=='1') read_announcement_with_ID(acc);
		else read_announcement(acc);
	}
}
//Doc lich su
void read_history(account *acc) {
	system("cls");
	cout<<"LICH SU CUA USER "<<acc->getUsername()<<endl<<endl;
	show_history(acc);
	cout<<endl<<endl;
	cout<<"1. Doc thong bao theo ma so."<<endl;
	cout<<"2. Tro ve."<<endl;
	fflush(stdin);
	char choice;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2') cout<<"Lua chon khong dung. Ban hay nhap lai:"<<endl;
	} while(choice!='1'&&choice!='2');
	if(choice=='1') return read_history_with_ID(acc);
	if(choice=='2') return read_infomation(acc);

}
//Doc thong tin
void read_infomation(account *acc) {
	system("cls");
	cout<<"DOC THONG TIN CUA ACCOUNT:"<<acc->getUsername()<<endl;
	printline();
	printline();
	cout<<"1. Doc thong bao"<<endl;
	cout<<"2. Doc lich su"<<endl;
	cout<<"3. Doc thong tin account"<<endl;
	cout<<"4. Tro ve"<<endl;
	char choice;
	cout<<"Nhap lua chon:"<<endl;
	do {
		fflush(stdin);
		choice=_getch();
		fflush(stdin);
		if(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4') cout<<"Hay bam lua chon dung"<<endl;
	} while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4');
	if(choice=='1') return read_announcement(acc);
	if(choice=='2') return read_history(acc);
	if(choice=='3') return read_account_infomation(acc);
	if(choice=='4') return mainmenu(acc);

}

//Nhung sach da co
void already_have_book(account *acc_reader) {
	show_already_have_function(acc_reader);
	cout<<"Nhan bat ky de tro ve"<<endl;
	fflush(stdin);
	char choice;
	choice=_getch();
	fflush(stdin);
	return mainmenu(acc_reader);
}

