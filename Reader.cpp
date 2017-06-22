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
			return "Van hoc";
		case 2:
			return "Thieu nhi";
		case 3:
			return "Ky nang, day nghe, nghe nghiep";
		case 4:
			return "Kien thuc doi song";
		case 5:
			return "Kinh te, tai chinh";
		case 6:
			return "Giao khoa, tham khao, giao trinh";
		case 7:
			return "Tu dien";
		case 8:
			return "Truyen tranh";
		case 9:
			return "Tam ly";
		case 10:
			return "Kien thuc tong hop";
		case 11:
			return "Ngoai van";
		case 12:
			return "The loai khac";
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

void showfullinfo(Book& book) {
	cout << "ISBN: " << book.ISBN << endl;
	cout << "Ten sach: " << book.name << endl;
	cout << "The loai: " << getallcategoryname(book.category) << endl;
	cout << "Nha xuat ban: " << book.publisher << endl;
	cout << "Nam xuat ban: " << book.year << endl;
	cout << "Gia(VND/ngay): " << book.price << endl;
}


//xuat thong tin cua toan bo sach co trong thu vien.
void show_all_book() {
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
}

void show_book_via_category() {
	unsigned int choice = 0;
	do {
		fflush(stdin);
		cin.clear();
		cout << "Moi chon the loai can tim";
		cout << "1.Van hoc \n2.Thieu nhi \n3.Ky nang, day nghe, nghe nghiep \n4.Kien thuc doi song \n5.Kinh te, tai chinh \n6.Giao khoa, tham khao, giao trinh. \n7.Tu dien \n8.Truyen tranh \n9.Tam ly\n10.Kien thuc tong hop\n11.Ngoai van\n12.The loai khac" << endl;
		fflush(stdin);
		cin >> choice;
	} while (cin.fail() || choice > 12 || choice == 0);
	stringstream ss;
	ss << choice;
	string str;
	ss >> str;
	find_key(str, 3);


}

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
		cout << "Khong co ket qua phu hop voi tu khoa!";

	}
	outfile.close();
}

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

void delete_in_cart();
////////////test

void show_cart(account *acc);//TO DOOOOOOOOOOOOOOOOOOOo
////////////test

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

// Demand book thi ko co date duoc muon, date la tinh tu luc no bat dau duoc cho muon nen file deman_borrow_txt ko co ngay bat dau muon. ngay bat dau muon chi co trong
// cart_txt ma thoi.
int count_number_of_book_demand(account *acc){
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
	while(getline(outfile,datatemp)){
		count++;
	}
	outfile.close();
	return count;
}

void delete_entire_demand(account *acc) {
	string filename="demand_book_"+acc->getUsername()+".txt";
	ofstream outfile;
	outfile.open(filename.c_str(), ofstream::out | ofstream::trunc);
	outfile.close();
}

void add_to_demand_borrow_function(account *acc,string ISBN) {
	fstream outfile;
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

void send_demand_borrow_to_librarian_function(account *acc_reader) {
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

}


void delete_single_book_in_demand_function(account *acc, int count) {
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
		if (counttemp!=count) {
			temp<<datatemp<<endl;
		}

	}
	temp.close();
	outfile.close();
	remove(filename.c_str());
	rename("temp.txt", filename.c_str());
}

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
		if(ISBN!=booktemp.ISBN){
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
}

void show_demand_function(account *acc){
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
	while(getline(outfile,datatemp)){
		count++;
		getbookinfomation(book, datatemp);
		showbookinfo(book,count);	
	}
	printline();
	outfile.close();
}


void add_to_cart();
//{
//	check role role ko thi return to reader();
//	getline book ISBn
//	check book exist
//	check active
//	add_to_cart_function
//	}
////////////test

void pay();
void cart();
/////////////////////////////////////////////////////////////////////////////
//Doc thong bao


/// chua xong
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
			for(int i=0; i<38; i++) cout<<left<<temp->getAnnounce()[i];
			cout<<"...";
		}
		cout<<"|"<<setw(20)<<temp->getDate()<<"|";
		if(temp->getSeen()=="0") cout<<setw(14)<<left<<"Chua doc"<<endl;
		else cout<<setw(14)<<left<<"Da doc"<<endl;
	}
	outfile.close();
}

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
		read_announcement(acc);
	}
	if(choice=='2') {
		read_announcement(acc);
	}
}

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
	cout<<"done "<<endl;
	read_announcement(acc);
}

void read_announcement_with_ID(account *acc) {
	string ID;
	cout<<"Nhap ma thong bao ban muon doc: "<<endl;
	fflush(stdin);
	getline(cin, ID);
	if(check_ID_Announcement_in_file(acc,ID)==1) read_announcement_with_ID_function(acc,ID);
	else {
		cout<<"Ma thong bao khong dung."<<endl;
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
	if(choice=='1') read_announcement_with_ID(acc);
	if(choice=='2') delete_entire_announcement(acc);
	if(choice=='3') delete_already_seen_announcement(acc);
	//	if(choice=='4')  //TO DOOOOOOOOO

}

void send_announcement_reader(account *acc) {
	system("cls");
	cout<<"CHUC NANG GUI THONG BAO CUA ACCOUNT: "<<acc->getUsername()<<endl;
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
//	if(choice=='3') //To Doooooooooooooooo
}

