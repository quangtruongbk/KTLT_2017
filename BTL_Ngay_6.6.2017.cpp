//// Thi?t k? c�c ch? exit, chua c� ch? exit
////Thi?t k? c�c get,set
#include"Assignment.h"


int main() {
	user *temp=new user();
		account *temp2=new account();
		account *temp3=new account();
	temp2->setUsername("tay14234");
	temp2->setID("T45964465");
	temp3->setUsername("tay1423");
	temp3->setID("T45964465");
	*temp=show_all_user_infomation_function(temp2, "L1513772766");
	cout<<"ID: "<<temp->getID()<<endl;
	cout<<"Name: "<<temp->getName()<<endl;
	cout<<"CMND: "<<temp->getCMND()<<endl;
	cout<<"Address: "<<temp->getAddress()<<endl;
	cout<<"Birthday: "<<temp->getBirthday()<<endl;
	cout<<"Email: "<<temp->getEmail()<<endl;
	cout<<"Job: "<<temp->getJob()<<endl;
	cout<<"Phone: "<<temp->getPhone()<<endl;
//	find_all_account_with_user_id_function(temp); 
	system("cls");
	Book *booktemp;
	cout<< count_number_of_waiting_of_each_person(temp3);

//	add_to_demand_borrow_function(temp3,"89349741454486565454654654");
//		add_to_demand_borrow_function(temp3,"akblK");
//	add_to_demand_borrow_function(temp3,"4533244563242");
//	add_to_demand_borrow_function(temp3,"9786049134418");
//	 send_demand_borrow_to_librarian_function(temp3) ;
//	 send_demand_to_waiting_line_function(temp2) ;
	// approve_waiting_function(temp2,temp3, "89349741454486565454654654")	; //	show_demand_function(temp); 
	 


//	read_announcement_with_ID_function(temp, "123");
	
//show_book_via_category(); 	return 0;
}
