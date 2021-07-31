#include"hotels.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#ifndef UUUU
#define UUUU
struct date
{
	int year;
	int month;
	int day;
};

class order
{
	string or_user;
	string order_num;
	hotel ordered_hotel;
	Room  ordered_room;
	date  indate;
	date  outdate;
	string money;
public:
	order(){}
	void setorder_num_rand(string c){ order_num = c; }
	void setor_user(char c){ or_user.push_back(c); }
	void setorder_num(char c){ order_num.push_back(c); }
	void setordered_hotel(hotel h){ ordered_hotel = h; }
	void setordered_room(Room R){ ordered_room = R; }
	void setindate(date d){ indate = d; }
	void setoutdate(date d){ outdate = d; }
	void setmoney(char c){ money.push_back(c); }
	void setmoney_froom_user(string c){ money = c; }


	string getorder_num(){ return order_num; }
	string getordered_hotel_num()
	{
		string c = ordered_hotel.gethotel_number();
		return c;
	}
	string getordered_room_num()
	{
		string c = ordered_room.get_room_num();
		return c;
	}
	date get_indate(){ return indate; }
	date get_outdate(){ return outdate; }
	

	//set 函数和 get函数 一定不要弄混!!!!

	string getor_user(){ return or_user; }
	

	void print_oneorder_to_file(string c)
	{
		ofstream fp;
		if (c == "order.txt")
		{
			fp.open(c, ios::app);
			if (!fp)
			{
				cout << "文件 " << c << "打开失败！  无法写入";
				fp.open(c, ios::out);
				fp << or_user << "|" << order_num << "|" << ordered_hotel.gethotel_number() << "," << ordered_hotel.gethotel_level() << "," << ordered_hotel.gethotel_name() << ","\
					<< ordered_hotel.gethotel_city() << "," << ordered_hotel.gethotel_location() << "|" << indate.year << "/" << indate.month << "/" << indate.day << "-" << outdate.year \
					<< "/" << outdate.month << "/" << outdate.day << "|" << ordered_room.get_style() << "-" << ordered_room.get_room_num() << "|" << money << "|" << endl;
				fp.close();


			}
			else
			{
				fp << or_user << "|" << order_num << "|" << ordered_hotel.gethotel_number() << "," << ordered_hotel.gethotel_level() << "," << ordered_hotel.gethotel_name() << ","\
					<< ordered_hotel.gethotel_city() << "," << ordered_hotel.gethotel_location() << "|" << indate.year << "/" << indate.month << "/" << indate.day << "-" << outdate.year \
					<< "/" << outdate.month << "/" << outdate.day << "|" << ordered_room.get_style() << "-" << ordered_room.get_room_num() << "|" << money << "|" << endl;
				fp.close();
			}
		}
		
		else 
		 {
			 fp.open(c, ios::out);
			 if (!fp)
			 {
				 cout << "文件 " << c << "打开失败！ 无法写入";
				 //exit(-1);
			 }
			 else
			 {

				 fp << or_user << "|" << order_num << "|" << ordered_hotel.gethotel_number() << "," << ordered_hotel.gethotel_level() << "," << ordered_hotel.gethotel_name() << ","\
					 << ordered_hotel.gethotel_city() << "," << ordered_hotel.gethotel_location() << "|" << indate.year << "/" << indate.month << "/" << indate.day << "-" << outdate.year \
					 << "/" << outdate.month << "/" << outdate.day << "|" << ordered_room.get_style() << "-" << ordered_room.get_room_num() << "|" << money << "|" << endl;
				 fp.close();
			 }
		 }
		
	}

	void print_oneorder_to_screen()
	{
		
		cout << or_user << "\t" << order_num << "\t" << ordered_hotel.gethotel_number() << "\t\t" << ordered_hotel.gethotel_name()<<"|";
		if (ordered_hotel.gethotel_name().size() < 19){
			cout << "\t\t" << ordered_room.get_room_num() << "\t" << ordered_room.get_style() << "|";
			if (8<ordered_room.get_style().size() && ordered_room.get_style().size()< 16){
				cout << "\t\t" << indate.year << "." << indate.month << "." << \
					indate.day << "-" << outdate.year << "." << outdate.month << "." << outdate.day << "|" << "\t   " << money << endl;
			}
			 if (ordered_room.get_style().size() < 8)
				cout << "\t\t\t" << indate.year << "." << indate.month << "." << \
				indate.day << "-" << outdate.year << "." << outdate.month << "." << outdate.day << "|" << "\t   " << money << endl;
			else{
				cout << "\t" << indate.year << "." << indate.month << "." << \
					indate.day << "-" << outdate.year << "." << outdate.month << "." << outdate.day << "|" << "\t   " << money << endl;
			}
		}
		else{
			cout << "\t" << ordered_room.get_room_num() << "\t" << ordered_room.get_style() << "|";
			if (8<ordered_room.get_style().size() && ordered_room.get_style().size()< 16){
				cout << "\t\t" << indate.year << "." << indate.month << "." << \
					indate.day << "-" << outdate.year << "." << outdate.month << "." << outdate.day << "|" << "\t   " << money << endl;
			}
			if (ordered_room.get_style().size() < 8)
				cout << "\t\t\t" << indate.year << "." << indate.month << "." << \
				indate.day << "-" << outdate.year << "." << outdate.month << "." << outdate.day << "|" << "\t   " << money << endl;
			else{
				cout << "\t" << indate.year << "." << indate.month << "." << \
					indate.day << "-" << outdate.year << "." << outdate.month << "." << outdate.day << "|" << "\t   " << money << endl;
			}
		}
		//cout << endl;
			
	}

	void print_allorders()
	{
		ofstream fp;
			fp.open("order.txt", ios::app);
			if (!fp)
			{
				//cout<<"打开失败！";
			}
			else
			{
				fp << or_user << "|" << order_num << "|" << ordered_hotel.gethotel_number() << "," << ordered_hotel.gethotel_level() << "," << ordered_hotel.gethotel_name() << ","\
					<< ordered_hotel.gethotel_city() << "," << ordered_hotel.gethotel_location() << "|" << indate.year << "/" << indate.month << "/" << indate.day << "-" << outdate.year \
					<< "/" << outdate.month << "/" << outdate.day << "|" << ordered_room.get_style() << "-" << ordered_room.get_room_num() << "|" << money << "|" << endl;
				fp.close();
			}
	}



};



class user
{
	string user_id;
	string user_name;
	string user_sex;
	string user_phonenumber;
	string secret;
	vector<order > my_orders;
public:
	user(){}
	void setmy_orders(order rrr){ my_orders.push_back(rrr); }
	void setuser_id(char c){ user_id.push_back(c); }
	void setuer_name(char c){ user_name.push_back(c); }
	void setuser_sex(char c){ user_sex.push_back(c); }
	void setuser_phonenumber(char c){ user_phonenumber.push_back(c); }
	void setsecret(char c){ secret.push_back(c); }
	string getuser_id(){ return user_id; }
	int get_users_order_num(){ return my_orders.size(); }
	order getorder(int k){ return my_orders[k]; }
	string  getuser_secret(){ return secret; }
	string getuser_name(){ return user_name; }
	void print_myorders_to_screen()
	{
			vector <order> ::iterator it;
			for (it = my_orders.begin(); it != my_orders.end(); it++)
			{
				it->print_oneorder_to_screen();
			}
	}
	void print_myorders_to_file()
	{ 
		vector <order> ::iterator it;
		for (it = my_orders.begin(); it != my_orders.end(); it++)
		{
			it->print_allorders();
		}
	}
	void print_user_information_toscreen()
	{
		cout << user_id << "   " << user_name << "   " << user_sex << "   " << user_phonenumber << "  |  " << secret << "  |  " << endl;	
	}
	void print_user_information_tofile(string c)
	{
		ofstream fp;
		if (c == "user.txt")
		{
			fp.open(c, ios::app);
			if (!fp)
			{
				cout << "文件 " << c << "打开失败！ 为您新建了该文件";
				fp.open(c, ios::out);
				fp<< user_id << "," << user_name << "," << user_sex << "," << user_phonenumber << "|" << secret << "|" << endl;
				fp.close();


			}
			else
			{
				fp << user_id << "," << user_name << "," << user_sex << "," << user_phonenumber << "|" << secret << "|" << endl;
				fp.close();
			}
		}

		else
		{
			fp.open(c, ios::out);
			if (!fp)
			{
				cout << "文件 " << c << "打开失败！ 无法写入";
				//exit(-1);
			}
			else
			{
				fp << user_id << "," << user_name << "," << user_sex << "," << user_phonenumber << "|" << secret << "|" << endl;
				
				fp.close();
			}
		}
	}

	int  delete_order(string cc)
	{
		int flag = 0;
		vector <order>::iterator it;
		
		for (it = my_orders.begin(); it != my_orders.end(); it++)
		{

			if (it->getorder_num() == cc)
			{
				//删除成功
				flag = 1;
				my_orders.erase(it);
				return flag;
			}

		}
		return flag;
	}


};
#endif 

void usermain();