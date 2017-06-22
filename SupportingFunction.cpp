#include"Assignment.h"

string uppercase(string name) {
	for(int i=0; i<name.length(); i++) {
		name[i]=toupper(name[i]);
	}
	return name;
}

string from_int_to_string(int N) {
	stringstream ss;
	ss << N;
	string str = ss.str();
	return str;
}

int check_valid_date(date date_struct) {
	int ny_days [13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int ly_days [13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (date_struct.month < 1 || date_struct.month > 12) return 0;
	if (date_struct.day < 1) return 0;
	if ((date_struct.year % 4 == 0 && date_struct.year%100!=0)||date_struct.year%400==0) {
		if (date_struct.day > ly_days[date_struct.month])
			return 0;
	} else {
		if (date_struct.day > ny_days[date_struct.month]) return 0;
	}
	if (date_struct.year < 1900 || date_struct.year>2017) return 0;
	return 1;
}

string input_date() {
	date input;
	do {
		cout<<"Nhap ngay thang nam sinh: "<<endl;
		cout<<"Chi nhap so, khong nhap ky tu nao khac"<<endl;
		cout<<"Nhap ngay sinh (VD ngay 14 thang 2 nam 1997 thi nhap 14):"<<endl;
		fflush(stdin);
		cin>>input.day;
		cout<<"Nhap thang sinh (VD ngay 14 thang 2 nam 1997 thi nhap 2):"<<endl;
		fflush(stdin);
		cin>>input.month;
		cout<<"Nhap nam sinh (VD ngay 14 thang 2 nam 1997 thi nhap 1997):"<<endl;
		fflush(stdin);
		cin>>input.year;
		if(check_valid_date(input)==0) cout<<"Ngay ban nhap khong hop le, vui long nhap lai"<<endl;
	} while(check_valid_date(input)==0);
	string day=from_int_to_string(input.day);
	string month=from_int_to_string(input.month);
	string year=from_int_to_string(input.year);
	string birthday=day+" "+month+" "+year;
	return birthday;
}

int check_number(string N) {
	for(int i=0; i<N.length(); i++) {
		if(isdigit(N[i])==0) return 0;
	}
	return 1;
}

int check_string(string N) {
	for(int i=0; i<N.length(); i++) {
		if(isalpha(N[i])==0 && N[i]!=' ') return 0;
	}
	return 1;
}

int check_not_blankspace(string N) {
	if(N=="") return 0;
	return 1;
}

int check_username_blank_space(string username) {
	//TO DO : check special character
	for(int i=0; i<username.length(); i++) {
		if(username[i]==' ') return 0;
	}
	return 1;
}

int check_username_legal(string username) {
	for(int i=0; i<username.length(); i++) {
		if(isalnum(username[i])==0) {
			if(username[i]!='_' && username[i]!='-') return 0;
		}
	}
	return 1;
}
int stringLength = sizeof(alphanum) - 1;

char genRandom() {
	return alphanum[rand() % stringLength];
}
string randomstring() {
	srand(time(0));
	std::string Str;
	for(unsigned int i = 0; i < MAXIDANNOUCEMENT; ++i) {
		Str += genRandom();
	}
	return Str;
}

string getCurrentDate(){
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    int year=now->tm_year + 1900;
    int month=now->tm_mon + 1;
    int day=now->tm_mday;
    string date=from_int_to_string(day)+" "+from_int_to_string(month)+" "+from_int_to_string(year);
    return date;
}

string getDay(string send_day) {
	string day, month,  year;
	stringstream ss;
	ss.str(send_day);
	ss>>day>>month>>year;
	return day+"/"+month+"/"+year;
}


string currentDateTime() {
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];
	time (&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,sizeof(buffer),"%d-%m-%Y %I:%M:%S",timeinfo);
	string str(buffer);
	return str;
}

string get_Category_Book_string(string choice) {
	if(choice=="1") return  "VAN HOC" ;
	if(choice=="2") return 	"THIEU NHI";
	if(choice=="3") return  "KY NANG/DAY NGHE/NGHE NGHIEP" ;
	if(choice=="4") return 	"KIEN THUC DOI SONG";
	if(choice=="5") return  "KINH TE/TAI CHINH" ;
	if(choice=="6") return 	"GIAO KHOA/THAM KHAO/GIAO TRINH";
	if(choice=="7") return  "TU DIEN" ;
	if(choice=="8") return 	"TRUYEN TRANH";
	if(choice=="9") return  "TAM LY" ;
	if(choice=="10") return "KIEN THUC TONG HOP";
	if(choice=="11") return  "SACH NUOC NGOAI" ;
	if(choice=="12") return  "THE LOAI KHAC" ;
}

int get_category_number(string category, int categoryarray[MAXCATEGORY]){
	stringstream ss;
	ss<<category;
	string data;
	int categoryint;
	for(int i=0; i<MAXCATEGORY;i++) categoryarray[i]=0;
	while(!ss.eof()){
		ss>>data;
		categoryint=atoi(data.c_str());
		categoryarray[categoryint-1]=1;
	//	cout<<"test category "<<categoryint<<endl;
	}
}

string print_category(string category){
	int categoryarray[MAXCATEGORY];
	get_category_number(category,categoryarray);
	string N;
	for(int i=0;i<MAXCATEGORY;i++){
		if(categoryarray[i]==1) N=N+","+get_Category_Book_string(from_int_to_string(i+1));
	}
	if(N[0]==',') N[0]=' ';
	return N;
}

int distance_date_function(int d, int m, int y) { 
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

int distance_date(string dateborrow){
	stringstream ss;
	ss<<dateborrow;
	string day1, month1,year1;
	ss>>day1>>month1>>year1;
	int day_int1,month_int1,year_int1;
	day_int1=atoi(day1.c_str());
	month_int1=atoi(month1.c_str());
	year_int1=atoi(year1.c_str());
	string datetoday=getCurrentDate();
	stringstream ss2;
	ss2<<datetoday;
	string day2, month2,year2;
	ss2>>day2>>month2>>year2;
	int day_int2,month_int2,year_int2;
	day_int2=atoi(day2.c_str());
	month_int2=atoi(month2.c_str());
	year_int2=atoi(year2.c_str());
	return distance_date_function(day_int2,month_int2,year_int2)- distance_date_function(day_int1,month_int1,year_int1);
}
