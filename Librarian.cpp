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
void send_announcement_to_all(announcement *annouce);
void send_announcement_to_individual(account *acc,string role_send) {
	system("cls");
	account *temp=new account();
	string username_to_send;
	cout<<"Nhap username ma ban muon gui: "<<endl;
	getline(cin,username_to_send);
	if(check_account_username( username_to_send, temp)==0) {
		cout<<"Username khong dung"<<endl;
		cout<<"Nhan 1 de nhap lai username khac."<<endl;
		cout<<"Nhan 2 de tro ve."<<endl;
		char choice;
		do {
			fflush(stdin);
			choice=_getch();
			fflush(stdin);
			cout<<"test choice                    "<<choice<<endl;
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
		}while(content=="");
		day=currentDateTime();
		announcement *newAnnounce=new announcement(content,day,"0",role_send);
		newAnnounce->send_to_user(username_to_send);
		add_announcement_to_archive(newAnnounce,acc,username_to_send);
	}
}
void send_announcement(account *acc){
	system("cls");
	cout<<"CHUC NANG GUI THONG BAO CUA ACCOUNT: "<<acc->getUsername()<<endl;
	cout<<"Chua hien thuc "<<endl;
	
}
