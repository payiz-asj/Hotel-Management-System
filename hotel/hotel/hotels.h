#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#ifndef BBBB
#define BBBB
//enum room_style { 0.自定义房间类型，1.单人间，2.双人间，3.三人间，4.大床房，
//5.标准间，6.豪华房，7.商务间，8.总统套房 ,9.雅致房，10.高级房，11.家庭式（带婴儿床）};

class Room
{
	string room_num;
	string room_price;
	//room_style style;       // 枚举类型的方案，后来被我取消了
	string style;

public:
	Room()
	{
		//room_num = "a";
	//	room_price = "a";
	//	style = "a";
	}
	void set_room_num(char c){ room_num.push_back(c); }
	void set_room_price(char c){ room_price.push_back(c); }
	void set_style(string cc);         // 函数实现在最下方

	void change_room_num(string c){ room_num = c; }
	void change_room_price(string c){ room_price = c; }

	//set 函数和 get函数 一定不要弄混!!!!

	string get_room_num(){ return room_num; }
	string get_room_price(){ return room_price; }
	string get_style(){ return style; }

	void print_oneroom_toscreen()
	{
		
		cout << room_num << "\t" <<" "<< room_price << "\t\t"<<" "<< style <<endl;
	}

};

class hotel
{

	string hotel_number;
	string hotel_name;
	int    hotel_level;
	string hotel_city;
	string hotel_location;
	vector <Room> allrooms;
	//enum room_style { 0.自定义房间类型，1.单人间，2.双人间，3.三人间，4.大床房，
	//5.标准间，6.豪华房，7.商务间，8.总统套房 ,9.雅致房，10.高级房，11.家庭式（带婴儿床）};
	vector<Room> sty0;
	vector<Room> sty1;
	vector<Room> sty2;
	vector<Room> sty3;
	vector<Room> sty4;
	vector<Room> sty5;
	vector<Room> sty6;
	vector<Room> sty7;
	vector<Room> sty8;
	vector<Room> sty9;
	vector<Room> sty10;
	vector<Room> sty11;
public:
	hotel()
	{
		// hotel_number="a";
		// hotel_name = "a";
		// hotel_level = 0;
		// hotel_city = "a";
		// hotel_location = "a";
	}
	void sethotel_number(char c){ hotel_number.push_back(c); }
	void sethotel_level(int n){ hotel_level = n; }
	void sethotel_name(char c){ hotel_name.push_back(c); }
	void sethotel_city(char c){ hotel_city.push_back(c); }
	void sethotel_location(char c){ hotel_location.push_back(c); }

	void change_hotel_number(string c){ hotel_number = c; }
	void change_hotel_level(int n){ hotel_level = n; }
	void change_hotel_name(string c){ hotel_name = c; }
	void change_hotel_city(string c){ hotel_city=c; }
	void change_hotel_location(string c){ hotel_location=c; }
//	void setallrooms(Room R){ allrooms.push_back(R); }
	void addrooms(string ch);
	void select_room_sty();
	
	//set 函数和 get函数 一定不要弄混!!!!


	string gethotel_number(){ return hotel_number; }
	int    gethotel_level(){ return hotel_level; }
	string gethotel_name(){ return hotel_name; }
	string gethotel_city(){ return hotel_city; }
	string gethotel_location(){ return hotel_location; }
	void print_onehotel_tofile(string c);
	Room  get_allrooms(int i){ return allrooms[i]; }
	int  get_sumof_rooms(){ return allrooms.size(); }


	void print_onehotel_toscreen()
	{
		
		cout << hotel_number << "\t" << hotel_level << "\t" << hotel_name;
		if (hotel_name.size()<19)
		cout<< "\t\t" << hotel_city << "\t" << hotel_location;
		else
			cout << "\t" << hotel_city << "\t" << hotel_location;
		cout << endl;
	}
	void find_room(hotel h );

	int  delete_hotel(string cc);

	int change_room();



};

#endif 




