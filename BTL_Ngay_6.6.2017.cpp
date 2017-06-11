//// Thi?t k? các ch? exit, chua có ch? exit
////Thi?t k? các get,set
#include"Assignment.h"


int main() {
	account *temp=new account();
	temp->setUsername("tay142");
	account *thuthu=new account();
	thuthu->setUsername("thuthutest");

  	send_announcement_to_individual(thuthu,"3"); 
  	  	send_announcement_to_individual(thuthu,"3"); 
  	send_announcement_to_individual(thuthu,"3"); 
  	send_announcement_to_individual(thuthu,"3"); 

  	 	read_announcement(temp); 

	return 0;
}
