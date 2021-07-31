#include"hotels.h"
#include"manager.h"
#include"user.h"
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;
#ifndef AAAA
#define AAAA



class function
{
	vector <hotel> allhotels;
	vector <user> allusers;
	vector<manager>allmanagers;
	vector<hotel>finded_hotel;
	map<string, vector<hotel>> cities;
	//int file_error=0;   //为了输出文件读取失败的情况而设置的变量
public:
	function();

	hotel *searchhotel_by_location();
	hotel *searchhotel_by_name();
	//void set_file_error(int x){ file_error = x;}
	//int get_file_error(){ return file_error; }
	int get_managers_num(){ return allmanagers.size(); }
	int get_users_num(){ return allusers.size(); }
	int get_hotel_num(){ return allhotels.size(); }
	manager getmanagers(int i){return allmanagers[i];}
	user getuser(int i){ return allusers[i]; }
	hotel gethotel(int i){ return allhotels[i]; }
	int get_finded_hotel_num(){ return finded_hotel.size(); }
	hotel get_finded_hotel(int i){ return finded_hotel[i]; }
	void addhotels(string c);
	void addusers(string ch);
	void addmanager(string ch);
	void addorders(string ch);
	int  find_hotel(string cit);

	void print_allhotels_tofile()
	{
		vector<hotel>::iterator it;
		for (it = allhotels.begin(); it != allhotels.end(); it++)
		{
			it->print_onehotel_tofile("hotel.txt");
		}



	}

	//用户的功能，即输出找到的hotel
	void print_cities()
	{
		map<string, vector<hotel>>::iterator it;
		for (it = cities.begin(); it != cities.end(); it++)
		{
			cout<<endl << "为你找到以下酒店：" << endl;
			cout << "编号\t星级\t   名称\t\t\t城市\t  具体地点" << endl;
			int n = it->second.size();
			for (int i = 0; i < n; i++)
			{
				 it->second[i].print_onehotel_toscreen();
					 
			}
			
		}
	
	}
	int download_hotel_info(string c);


	static bool compare_hotel(hotel&h1, hotel&h2)
	{
		if (h1.gethotel_number ()!= h2.gethotel_number())
			return h1.gethotel_number() < h2.gethotel_number();
	}
	static bool compare_user(user&h1, user&h2)
	{
		if (h1.getuser_id ()!= h2.getuser_id())
			return h1.getuser_id() < h2.getuser_id();
	}
	static bool compar_manager(manager&h1, manager&h2)
	{
		if (h1.getmanager_id()!= h2.getmanager_id())
			return h1.getmanager_id()< h2.getmanager_id();
	}
	int delete_hotel(string cc);
	int change_hotel(string cc);
};

#endif 







