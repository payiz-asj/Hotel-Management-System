//#include<iostream>
//#include<fstream>
//#include<stdio.h>
//#include<cstring>
//#include<stdlib.h>
//#include<vector>
//#include"1.h"
//using namespace std;
//enum room_style {�Զ��巿�����ͣ����˼䣬˫�˼䣬�󴲷�����׼�䣬�����������񷿣���ͳ�׷� }style;
//class RoomType;
//class hotel;
//class order;
//
//class RoomType
//{
//	
//	string room_num;
//	string room_price;
//	room_style style;
//public:
//	RoomType()
//	{
//		room_num = '\0';
//		room_price = '\0';
//		room_style style = (enum room_style)0;
//	}
//	string set_room_num(string c){ 
//		room_num = c;
//		return room_num; }
//	string set_room_price(string c){
//		room_price = c;
//		return room_price; }
//	room_style set_style(string c){ 
//		if (c.compare("���˼�") == 0) style = (enum room_style)1;
//		else if (c.compare("˫�˼�") == 0) style = (enum room_style)2;
//		else if (c.compare("�󴲷�") == 0) style = (enum room_style)3;
//		else if (c.compare("��׼��") == 0) style = (enum room_style)4;
//		else if (c.compare("������") == 0) style = (enum room_style)5;
//		else if (c.compare("����") == 0) style = (enum room_style)6;
//		else style = (enum room_style)0;
//		return style; }
//	string get_room_num(string c){ return room_num; }
//	string get_room_price(string c){ return room_price; }
//	room_style get_style(string c){ return style; }
//
//
//
//};
//class hotel
//{
//	string hotel_number;
//	string hotel_name;
//	string region;
//	string location;
//	vector <RoomType*> rooms;
//
//public:
//	hotel()
//	{
//		hotel_number = '\0';
//		hotel_name = '\0';
//		region='\0';
//		location='\0';;
//		//rooms.clear();
//		//rooms.push_back('\0');
//		
//	}
//	string gethotel_number(){}
//	string gethotel_name(){}
//	string gethotel_region(){}
//	string gethotel_location(){}
//
//	int  create_hotel_and_room(const char *f);
//
//};
//
//class order
//{
//
//
//};