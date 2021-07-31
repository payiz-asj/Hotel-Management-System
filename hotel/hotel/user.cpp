#include"user.h"
#include"functions.h"
#include"hotels.h"
#include"window.h"
#include<map>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<cstdlib>
#include<string>
#include<conio.h>
#include<ctime>
using namespace std;

//**************  函数声明区   *************

//关于日期的一些函数声明
date input_date_information(int year, int mon, int day);
bool isleapyear(int y);
int sum(int y, int m, int d);
int Count(int y1, int m1, int d1, int y2, int m2, int d2);

//关于查询的一些函数声明
void user_find_hotel_offline();
int  user_find_hotel_online(user A);
void user_find_room_offline(function asj_user2);
// int  countday(int beginyear, int beginmonth, int beginday, int endyear, int  endmonth, int  endday);   //这个被淘汰了


//登陆函数声明
int user_login(user &BB);
//不同身份，运行不同功能：
void  youke();
void  zhengshi();
void user_func(user f);


//**************  函数实现区   *************

//=========用户主函数=================

void usermain()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t >>> 欢迎来到用户登录页面！<<< \t" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   1.正式登录\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   2.游客登录\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   3.帮助\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   4.返回上一级\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   5.退出系统\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;
	switch (_getch())
	{
	case '1':{
				 zhengshi();
				 // break; 
	}
	case '2':{
				 youke();
				 //break;
	}
	case'3':{
				system("cls");
				cout << "\t\t\t\t\t管理员说明书:" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "正式登陆:指凭用户账号、密码登录，输入错误次数超过有三次即自动进入游客模式。" << endl;
				cout << "可见游客模式指的是不需要帐号、密码直接登录" << endl << endl;
				cout << "然而，正式登录为线上服务，游客登录为线下服务。二者能使用本系统的权限不同！" << endl << endl;
				cout << "即：正式登陆成功方可进行预定、查看订单、查看个人信息等功能，" << endl;
				cout << "而游客只能使用查询功能，也就是随便逛逛  ^o^  " << endl;
				cout << endl;
				_getch();
				system("cls");
				usermain();
				//break;
	}
	case '4':{
				 system("cls");
				 enter();
				 // break;
	}
	case '5':{
				 system("cls");
				 exit_all();
				 // break;
	}

	default:{
				system("cls");
				flase_input();
				system("cls");
				usermain();
				//		break; 
	}

	}
}




//关于日期的一些函数
bool isleapyear(int y){
	return (y % 4 == 0 && y % 100 || y % 400 == 0);
}
int sum(int y, int m, int d){
	int md[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int cnt = y * 365;
	cnt += (y - 1) / 4 + 1;
	cnt -= (y - 1) / 100 + 1;
	cnt += (y - 1) / 400 + 1;
	for (int i = 1; i < m; ++i) cnt += md[i];
	if (m > 2 && isleapyear(y)) ++cnt;
	cnt += d;
	return cnt;
}
int Count(int y1, int m1, int d1, int y2, int m2, int d2){
	return sum(y2, m2, d2) - sum(y1, m1, d1);
}
date input_date_information(int year, int mon, int day)
{
	cout << "年分：";
	cin >> year;
	cout << endl;
	while (year<2017 || year>2027)
	{
		cout << endl;
		cout << "\t\t★---------------------------------------------★" << endl;
		cout << "\t\t\t该年份不在服务区！请输入2017-2027年之间的年份：" << endl << endl;
		cout << "\t\t★---------------------------------------------★" << endl << endl;
		cout << "年分：";
		cin >> year;
		cout << endl;
	}
	cout << "月份：";
	cin >> mon;
	cout << endl;
	while (mon<1 || mon>12)
	{
		cout << endl;
		cout << "\t\t★---------------------------------------------★" << endl;
		cout << "\t\t\t该月份不在服务区！请输入1月-12月之间的月份：" << endl << endl;
		cout << "\t\t★---------------------------------------------★" << endl << endl;
		cout << "月分：";
		cin >> mon;
		cout << endl;
	}
	cout << "具体的日期：";
	cin >> day;
	cout << endl;
	int flag = 0;
	while (flag != 1)
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		{
			if (mon == 2)
			{
				if (day > 29 || day < 1)
				{
					cout << endl;
					cout << "\t\t★---------------------------------------------★" << endl;
					cout << "\t\t\t       该月份最多只有1日到29日！" << endl << endl;
					cout << "\t\t★---------------------------------------------★" << endl << endl;
					cout << "重新输入：";
				}
				else {
					flag = 1; break;
				}
			}
			else if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
			{
				if (day > 31 || day < 1)
				{
					cout << endl;
					cout << "\t\t★---------------------------------------------★" << endl;
					cout << "\t\t\t       该月份最多只有1日到31日！" << endl << endl;
					cout << "\t\t★---------------------------------------------★" << endl << endl;
					
					cout << "重新输入：";
				}
				else { flag = 1; break; }
			}
			else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
			{
				if (day > 31 || day < 1)
				{
					cout << endl;
					cout << "\t\t★---------------------------------------------★" << endl;
					cout << "\t\t\t       该月份最多只有1日到30日！" << endl << endl;
					cout << "\t\t★---------------------------------------------★" << endl << endl;
					
					cout << "重新输入：";
				}
				else {
					flag = 1; break;
				}
			}
		}
		else
		{
			if (mon == 2)
			{
				if (day > 28 || day < 1)
				{
					cout << endl;
					cout << "\t\t★---------------------------------------------★" << endl;
					cout << "\t\t\t       该月份最多只有1日到28日！" << endl << endl;
					cout << "\t\t★---------------------------------------------★" << endl << endl;
					cout << "重新输入：";
				}
				else {
					flag = 1; break;
				}
			}
			else if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
			{
				if (day > 31 || day < 1)
				{
					cout << endl;
					cout << "\t\t★---------------------------------------------★" << endl;
					cout << "\t\t\t       该月份最多只有1日到31日！" << endl << endl;
					cout << "\t\t★---------------------------------------------★" << endl << endl;
					cout << "重新输入：";
				}
				else { flag = 1; break; }
			}
			else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
			{
				if (day > 31 || day < 1)
				{
					cout << endl;
					cout << "\t\t★---------------------------------------------★" << endl;
					cout << "\t\t\t       该月份最多只有1日到30日！" << endl << endl;
					cout << "\t\t★---------------------------------------------★" << endl << endl;
					cout << "重新输入：";
				}
				else {
					flag = 1; break;
				}
			}
		}
		
		cout << "请重新输入具体日期：";
		cin >> day;
		cout << endl;
		


	}
	/*string c;
	c.push_back(year);
	c.push_back('/');
	c.push_back(mon);
	c.push_back('/');
	c.push_back(day);
	*/
	date XXX;
	XXX.year = year;
	XXX.month = mon;
	XXX.day = day;

	return XXX;
}
 
//被淘汰的方案：

//int  countday(int beginyear, int beginmonth, int beginday, int endyear, int  endmonth, int  endday)
//{
//	//int beginday, beginmonth, beginyear, sum, leap, endday, endmonth, endyear, i, y = 0;
//	int sum = 0, leap = 0, i = 0, y = 0;
//
//	for (i = beginyear; i<endyear; i++)
//	{
//		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))y = y + 1;
//	}
//
//	//计算某月以前月份的天数
//	switch (endmonth){
//	case 1:sum = 0; break;
//	case 2:sum = 31; break;
//	case 3:sum = 59; break;
//	case 4:sum = 90; break;
//	case 5:sum = 120; break;
//	case 6:sum = 151; break;
//	case 7:sum = 181; break;
//	case 8:sum = 212; break;
//	case 9:sum = 243; break;
//	case 10:sum = 273; break;
//	case 11:sum = 304; break;
//	case 12:sum = 334; break;
//	default:cout << "data error!" << endl; break;
//	}
//
//	//月份天数加上这个月的日数
//	sum = sum + endday;
//	sum = 365 * (endyear - beginyear) + y + sum;
//
//
//	if (endyear % 400 == 0 || (endyear % 4 == 0 && endyear % 100 != 0)) //判断是否闰年
//		leap = 1;
//	else
//		leap = 0;
//
//	if (leap == 1 && endmonth>2)sum = sum + 1;
//	return sum;
//}        //    
  



//关于查询的一些函数

void user_find_hotel_offline()
{
	function  asj_user;


loop1:
	cout << endl << endl << endl;
	int flag = 0;
	string input_cityname;
	cout << "输入你要查找的城市：";


	cin >> input_cityname;
	flag = asj_user.find_hotel(input_cityname);
	if (flag == 1)
	{
		cout << endl;
		cout << "\t\t★---------------------------------------------★" << endl;
		cout << "\t\t\t    没有找到该城市! " << endl << endl;
		cout << "\t\t\t    重新输入请按 \"9\"    |     退出请按 \"0\" " << endl << endl;
		cout << "\t\t★---------------------------------------------★" << endl << endl;
		
	loop2:
		char c = _getch();
		switch (c)
		{
		case '9':{goto loop1; }

		case '0':{goto loop3; break; }
		default:{cout << "\t\t输入错误！ 重新输入！" << endl; goto loop2; break; }
		}
	}
	else
	{
		
		asj_user.print_cities();
	}

	user_find_room_offline(asj_user);

loop3:
	char c = '0';
}

void user_find_room_offline(function asj_user2)
{
loop1:
	cout << endl<<endl;
	cout << "  选择你想查询的酒店：";
	string input_hotelnum;

	
	cin >> input_hotelnum;

	vector<hotel> using_finded_hotel;
	int num_of_finded_hotel = asj_user2.get_finded_hotel_num();
	for (int i = 0; i < num_of_finded_hotel; i++)
		using_finded_hotel.push_back(asj_user2.get_finded_hotel(i));

	hotel ho;
	vector<hotel>::iterator it;
	for (it = using_finded_hotel.begin(); it != using_finded_hotel.end(); it++)
	{
		if (it->gethotel_number() == input_hotelnum)
			ho = *it;
	}
	string c = ho.gethotel_number();
	if (c.empty())
	{
		cout << endl;
		cout << "\t\t★---------------------------------------------★" << endl;
		cout << "\t\t\t    没有找到该酒店! " << endl << endl;
		cout << "\t\t\t    重新输入请按 \"9\"    |     退出请按 \"0\" " << endl << endl;
		cout << "\t\t★---------------------------------------------★" << endl << endl;
	
	loop2:
		char c = _getch();
		switch (c)
		{
		case '9':{goto loop1; break; }

		case '0':{goto loop3; break; }
		default:{cout << "\t\t输入错误！ 重新输入！" << endl; goto loop2; break; }
		}
	}
	else
	{
		cout << "房间号\t房间价格\t房间类型" << endl;
		ho.find_room(ho);
	}

loop3:

	cout << endl << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	//cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
	cout << "\t\t|\t 线下服务到此结束，谢谢使用!!! \t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t★---------------------------------------------★" << endl;

	_getch();



}


int  user_find_hotel_online(user A)
{

	function  asj_user_book;
loop1:
	int flag = 0;
	string input_cityname;
	cout << endl << endl;
	cout << "      输入你要查找的城市名称：";

	cin >> input_cityname;
	flag = asj_user_book.find_hotel(input_cityname);
	if (flag == 1)
	{
		cout << endl;
		cout << "\t\t★---------------------------------------------★" << endl;
		cout << "\t\t\t    没有找到该城市! " << endl << endl;
		cout << "\t\t\t    重新输入  请按  \" 9 \"  " << endl << endl;
		cout << "\t\t★---------------------------------------------★" << endl << endl;
		

loop2:
		char c = _getch();
		switch (c)
		{
		case '9':{goto loop1;  }
		default:{cout << "\t\t输入错误！ 重新输入！" << endl; goto loop2;  }
		}
		
	}
	else
	{
	
		asj_user_book.print_cities();  //打印酒店信息
	}

loop4 :
	cout << "选择你想查询的酒店编号：";
	  string input_hotelnum;


	  cin >> input_hotelnum;

	  vector<hotel> using_finded_hotel;
	  int num_of_finded_hotel = asj_user_book.get_finded_hotel_num();
	  for (int i = 0; i < num_of_finded_hotel; i++)
		  using_finded_hotel.push_back(asj_user_book.get_finded_hotel(i));

	  hotel ho;
	  vector<hotel>::iterator it;
	  for (it = using_finded_hotel.begin(); it != using_finded_hotel.end(); it++)
	  {
		  if (it->gethotel_number() == input_hotelnum)
			  ho = *it;
	  }
	  string c = ho.gethotel_number();
	  if (c.empty())
	  {
		  cout << endl;
		  cout << "\t\t★---------------------------------------------★" << endl;
		  cout << "\t\t\t    没有找到该酒店! " << endl << endl;
		  cout << "\t\t\t    重新输入  请按  \" 9 \"  " << endl << endl;
		  cout << "\t\t★---------------------------------------------★" << endl << endl;
loop5:
		  char c = _getch();
		  switch (c)
		  {
		  case '9':{goto loop4;  }
		  default:{cout << "\t\t输入错误！ 重新输入！" << endl; goto loop5; }
		  }
	  }
	  else
	  {
		  cout << "房间号\t房间价格\t房间类型" << endl;
		  ho.find_room(ho);//打印房间信息
	  }

  loop11:
	  cout << "选择你想预定的房间的房间号：";
	  string input_room_num;


	  cin >> input_room_num;


	  string cost_of_eachroom;
	  vector<Room> source_rooms;      //该酒店的所有房间，建立订单时用
	  int sum_of_rooms = ho.get_sumof_rooms();
	  for (int i = 0; i < sum_of_rooms; i++)
	  {
		  source_rooms.push_back(ho.get_allrooms(i));
	  }
	  int yy = 0;
	  vector<Room>::iterator tt;
	  for (tt = source_rooms.begin(); tt != source_rooms.end(); tt++)
	  {
		  if (tt->get_room_num() == input_room_num)
		  {
			  yy = 1;
			  break;
		  }

	  }
	  if (yy == 0)
	  {
		  cout << endl;
		  cout << "\t\t★---------------------------------------------★" << endl;
		  cout << "\t\t\t    没有找到该房间! " << endl << endl;
		  cout << "\t\t\t    重新输入  请按  \" 9 \"  " << endl << endl;
		  cout << "\t\t★---------------------------------------------★" << endl << endl;
		 
	  loop22:
		  char c = _getch();
		  switch (c)
		  {
		  case '9':{goto loop11; break; }

		  default:{cout << "\t\t输入错误！ 重新输入！" << endl; goto loop22; break; }
		  }
	  }
	  else{
		  order booked;     //一个order对象，用来建立本次订单



		  date   comdate, godate;
		  int year1 = 0, year2 = 0, mon1 = 0, mon2 = 0, day1 = 0, day2 = 0;

 loop44:
		  cout << "输入订房时间" << endl;
		  comdate = input_date_information(year1, mon1, day1);
		  godate = input_date_information(year2, mon2, day2);
		  //int sum = countday(comdate.year, comdate.month,comdate.day,godate.year, godate.month, godate.day);
		  int sum = Count(comdate.year, comdate.month, comdate.day, godate.year, godate.month, godate.day);
		  if (sum < 0)
		  {
			  cout << endl;
			  cout << "\t\t★---------------------------------------------★" << endl;
			  cout << "\t\t\t    退房日期应在入住日期之后！ " << endl << endl;
			  cout << "\t\t★---------------------------------------------★" << endl << endl;
			 
			  goto loop44;
		  }

		  vector<user> alluser2;     //新建所有用户
		  int num_of_alluser = asj_user_book.get_users_num();
		  for (int j = 0; j < num_of_alluser; j++)
			  alluser2.push_back(asj_user_book.getuser(j));


		  /////////////////////////////////////////////////////////////////////预览所有订单，判断可否预定
		  vector<order> allorder2;     //新建所有订单
		  vector <user> ::iterator point;
		  for (point = alluser2.begin(); point != alluser2.end(); point++)
		  {
			  int num_of_oneusers_order = point->get_users_order_num();
			  for (int j = 0; j < num_of_oneusers_order; j++)
				  allorder2.push_back(point->getorder(j));
		  }
		  vector <order> target_hotel_orders;  //  缩小比较范围
		  vector <order> ::iterator point2;
		  for (point2 = allorder2.begin(); point2 != allorder2.end(); point2++)
		  {
			  if (point2->getordered_hotel_num() == input_hotelnum)
			  {
				  target_hotel_orders.push_back(*point2);
			  }
		  }
		  vector<order>target_room_orders;  // 继续 缩小比较范围
		  for (point2 = target_hotel_orders.begin(); point2 != target_hotel_orders.end(); point2++)
		  {
			  if (point2->getordered_room_num() == input_room_num)
			  {
				  target_room_orders.push_back(*point2);
			  }
		  }
		  //判断并导入房间，最关键的地方！！！
		  int flag2 = 0;
		  if (target_room_orders.size() == 0)
		  {
			  //可以预订
			  flag2 = 1;
			  vector<Room>::iterator point3;
			  for (point3 = source_rooms.begin(); point3 != source_rooms.end(); point3++)
			  {
				  if (point3->get_room_num() == input_room_num)
				  {

					  booked.setordered_room(*point3);
					  cost_of_eachroom = point3->get_room_price();
					  break;
				  }

			  }
		  }
		  else
		  {
			  for (point2 = target_room_orders.begin(); point2 != target_room_orders.end(); point2++)
			  {
				  if (comdate.year >= point2->get_outdate().year&&comdate.month >= point2->get_outdate().month&&comdate.day >= point2->get_outdate().day)
				  {
					  //可以预订
					  flag2 = 1;

					  vector<Room>::iterator point3;
					  for (point3 = source_rooms.begin(); point3 != source_rooms.end(); point3++)
					  {
						  if (point3->get_room_num() == input_room_num)
						  {
							  booked.setordered_room(*point3);
							  cost_of_eachroom = point3->get_room_price();
							  break;
						  }

					  }


				  }
				  else if (godate.year <= point2->get_indate().year&&godate.month <= point2->get_indate().month&&godate.day <= point2->get_indate().day)
				  {
					  //可以预订
					  flag2 = 1;
					  vector<Room>::iterator point3;
					  for (point3 = source_rooms.begin(); point3 != source_rooms.end(); point3++)
					  {
						  if (point3->get_room_num() == input_room_num)
						  {
							  booked.setordered_room(*point3);
							  cost_of_eachroom = point3->get_room_price();
							  break;
						  }
					  }

				  }
				  else
				  {
					  //不可预订，该房间，该时间段已经被预订！！!
					  break;
				  }
			  }
		  }
		  int haha = 0;
		  if (flag2 == 0)
		  {
			  //cout << "很抱歉 先生\\女士，该房间 该时间段已经被预定！" << endl<<endl;
			  haha = 0;
		  }
		  else if (flag2 == 1)
		  {
			  srand((unsigned)time(0));
			  int b = rand() % (99999 - 10000) + 10000;

			  booked.setorder_num_rand(to_string(b));

			  string vv = A.getuser_id();
			  int g = vv.size();
			  for (int j = 0; j < g; j++)
				  booked.setor_user(vv[j]);

			  booked.setordered_hotel(ho);

			  booked.setindate(comdate);
			  booked.setoutdate(godate);

			  int  ss = atoi(cost_of_eachroom.c_str());
			  int allmoney = ss*sum;
			  booked.setmoney_froom_user(to_string(allmoney));

			  A.setmy_orders(booked);
			  string c = "order.txt";
			  booked.print_oneorder_to_file(c);
			  haha = 1;
		  }

		  return haha;
	  }


}

//登陆函数
int user_login(user &BB)
{

	int n = 3;
	string user_id_number;
	string user_password;
	int kk = 0;
	//_getch();
	system("cls");
	for (;;)
	{
		cout << endl;
		cout << "预设用户帐号: 666" << endl;
		cout << "密码: 666";
		cout << endl;
		cout << endl;
		cout << endl;
		printf("请输入用户帐号：");
		//scanf_s("%10s", number);
		cin >> user_id_number;
		printf("请输入密码：");
		//scanf_s("%6s", passward);
		cin >>user_password;


		function *SS = new function;
	
		vector<user> alluser2;   //输出所有用户，用户登录时用
		int num_of_alluser = SS->get_users_num();
		for (int j = 0; j < num_of_alluser; j++)
			alluser2.push_back(SS->getuser(j));

		delete SS;
		user uuus;
		vector<user> ::iterator it;
		for (it = alluser2.begin(); it != alluser2.end(); it++)
		{
			if (it->getuser_id() == user_id_number)
			{
				uuus = *it;
				break;
			}
		}
		if (uuus.getuser_id() == "")
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "\t\t★---------------------------------------------★" << endl;
			//cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
			cout << "\t\t|\t          用户名错误!!!\t\t\t|" << endl;
			//cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t★---------------------------------------------★" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			_getch();
			//system("cls");
		}
		else
		{
			if (uuus.getuser_secret() != user_password)
			{
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "\t\t★---------------------------------------------★" << endl;
				//cout << "\t\t|\t\t\t\t\t\t|" << endl;
				//cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
				cout << "\t\t|\t          密码错误!!!\t\t\t|" << endl;
				//cout << "\t\t|\t\t\t\t\t\t|" << endl;
				cout << "\t\t★---------------------------------------------★" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				_getch();
			//	system("cls");
			
			}
		}
		
		if (uuus.getuser_id() != ""&&uuus.getuser_secret() == user_password)
		{
			system("cls");
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "\t\t★---------------------------------------------★" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
			cout << "\t\t|\t\t登录成功!!! \t\t\t|" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t\t   尊敬的用户：" << uuus.getuser_name() <<" \t\t"<< endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t|\t\"伊赛尔\"  酒店管理系统欢迎你！\t\t|" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t★---------------------------------------------★" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			_getch();
			system("cls");
			
			kk = 2;
			string ch = uuus.getuser_id();
			int gg = ch.size();
			for (int i = 0; i < gg; i++)
				BB.setuser_id(ch[i]);
			break;
		}
			
		else
		{
			--n;
			system("cls");
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "\t\t★---------------------------------------------★" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
			cout << "\t\t|\t请重新登录，您还有" << n << "次机会"<< endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t★---------------------------------------------★" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			_getch();
			system("cls");
		}

		if (n == 0)
		{
			system("cls");
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "\t\t★---------------------------------------------★" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
			cout << "\t\t|\t\t非注册用户无法登录\t\t|" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t|   请使用游客身份或预设用户帐号密码登录！谢谢! |" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t★---------------------------------------------★" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			_getch();
			system("cls");
			//kk = 0;
			break;
		}
			
	}

	return kk;
}

//不同身份，运行不同功能：

void  youke()
{
	system("cls");

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t欢迎使用游客功能!\t\t" << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << "\t\t\t\t\t\t\t\t" << endl;
	//cout << "\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t您可以进来逛一逛！\t\t " << endl;
	cout << "\t\t  （只能使用查询服务，不能使用预定服务）\t\t" << endl;
	cout << "\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t祝您逛得开心！！！\t\t" << endl;
	cout << "\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	_getch();
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t  >>> 亲爱的游客，欢迎您！！<<< \t" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	// cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  1.查询酒店\t\t|" << endl;   // 里面再分预定、退出
	// cout << "\t\t\t|\t  2.查看订单\t\t|" << endl;   //里面再分退订、退出   退订时评价酒店    
	// cout << "\t\t\t|\t  3.查看个人信息\t\t|" << endl; //里面再分更改个人信息
	//		 cout << "\t\t\t|\t  4.阅读用户说明书\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  2.返回上一级\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  3.直接退出系统\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;
	switch (_getch())
	{
	case '1':{
				 system("cls");
				 user_find_hotel_offline();
				 system("cls");
				 usermain();
				 // break;
	}
	case '2':{
				 system("cls");
				 usermain();
				 // break;
	}
	case '3':{
				 system("cls");
				 exit_all();
				 // break;
	}

	default:{
				system("cls");
				flase_input();
				system("cls");
				youke();
				//break; }
	}


	}
}
		
void  zhengshi()
{

	user useridentiti;
	int m = user_login(useridentiti);

	if (m == 0)
	{
		system("cls");
		youke();
	}
	else if (m == 2)
	{
		system("cls");
		user_func(useridentiti);
	}
}
	
void user_func(user f)
{
loop1:
	int heihei;
	user ff = f;
	//int b = A.get_managers_num();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t      >>> 正式用户！<<< \t" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  1.预定 \t\t|" << endl;   // 里面再分预定、退出
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  2.查看订单\t\t|" << endl;   //里面再分退订、退出   退订时评价酒店  
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  3.查看个人信息\t|" << endl; //里面再分更改个人信息
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  4.阅读用户说明书\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  5.退出登录 \t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  6.直接退出系统\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;

	switch (_getch())
	{
	case '1':{
				 system("cls");
				 heihei = user_find_hotel_online(ff);
				 system("cls");
				 if (heihei == 0)
				 {
					 cout << endl;
					 cout << endl;
					 cout << endl;
					 cout << "\t\t★--------------------------------------------------★" << endl;
					 cout << "\t\t\t很抱歉 先生\\女士，该房间 该时间段已经被预定！!!!\t\t\t" << endl;
					 cout << "\t\t★--------------------------------------------------★" << endl;
					 cout << endl;

				 }
				 else if (heihei==1)
				 {
					 cout << endl;
					 cout << endl;
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t          预订成功!!!\t\t\t" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << endl;
				 }
				 _getch();
				 system("cls");
				 goto loop1;
				 //break;
	}
	case '2':{
				 system("cls");
				 function *d = new function;
				 vector<user> alluser3;     //新建所有用户
				 int num_of_alluser3 = d->get_users_num();
				 for (int j = 0; j < num_of_alluser3; j++)
					 alluser3.push_back(d->getuser(j));
				 delete d;
				 int flag55 = 0;
				 vector <user> ::iterator point;
				
				 for (point = alluser3.begin(); point != alluser3.end(); point++)
				 {
					 if (point->getuser_id() == ff.getuser_id())
					 {
						
						 if (point->get_users_order_num() != 0)
						 {
							 flag55 = 1;
							//不用现在打印，在下面打印（1064开始）
							 //point->print_myorders_to_screen();
						 }
						 
					 }
						 
				 }
				 if (flag55 == 0)
				 {
					 cout << endl;
					 cout << endl;
					 cout << "\t\t★--------------------------------------------------------★" << endl;
					 cout << "\t\t\t 尊敬的用户，目前您没有任何订单!!!\t\t\t" << endl;
					 cout << "\t\t★--------------------------------------------------------★" << endl;
					 _getch();
					 system("cls");
					 goto loop1;
				 }
				 else if (flag55 == 1)
				 {
					
					 cout << "用户名\t\t订单号\t酒店编号\t酒店名称|\t\t房间号 \t房间类型|\t\t入住时间-退房时间\t费用（RMB） " << endl;
					 for (point = alluser3.begin(); point != alluser3.end(); point++)
					 {
						 if (point->getuser_id() == ff.getuser_id())
						 {

							 if (point->get_users_order_num() != 0)
							 {
								 point->print_myorders_to_screen();
							 }

						 }

					 }
					 cout << endl;
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t          是否取消订单!!!\t\t\t" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << endl;
			     	 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t    取消订单  请按  \" 9 \"  " << endl << endl;
					 cout << "\t\t\t    不操作    请按任意键继续：" << endl << endl;
					 cout << "\t\t★---------------------------------------------★" << endl<<endl;
					 

					 switch (_getch())
					 {
					 case '9':{
							  loop88:
								  cout << "输入您要删除的订单号：";
								  string c;
								  cin >> c;
								  int aha;
								  vector <user> ::iterator point2;
								  for (point2 = alluser3.begin(); point2 != alluser3.end(); point2++)
								  {
									  if (point2->getuser_id() == ff.getuser_id())
									  {
									
										  aha = point2->delete_order(c);
									  }

								  }
								  if (aha == 0)
								  {
									  
									  cout << endl << "该订单删除失败！" << endl << "请重新";
									  goto loop88;
								  }
								  else if (aha == 1)
								  {
									  cout << endl << "该订单成功被删除！" << endl;
									  system("cls");
									  cout << endl;
									  cout << endl;
									  cout << "\t\t★---------------------------------------------★" << endl;
									  cout << "\t\t\t  成功取消订单号为 \" " << c << " \" 的订单" << endl; 
									  cout << "\t\t★---------------------------------------------★" << endl;
									  cout << endl;
									  cout << endl;
									 
									ofstream fp;
									  fp.open("order.txt", ios::out);
									  if (fp)
									  fp.close();
									 
									  vector <user> ::iterator point3;
									  for (point3 = alluser3.begin(); point3 != alluser3.end(); point3++)
									  {
										  point3->print_myorders_to_file();
									  }


								  }
								  _getch();
								  system("cls");
								  goto loop1;
					 }
					 default:{
								 system("cls");
								 goto loop1;
								 //break; 		
					 }
					 }
				 }
				
				 
	}

	case '3':{
				 system("cls");
				 function *d = new function;
				 vector<user> alluser3;     //新建所有用户
				 int num_of_alluser3 = d->get_users_num();
				 for (int j = 0; j < num_of_alluser3; j++)
					 alluser3.push_back(d->getuser(j));
				 delete d;
				 vector <user> ::iterator point;
				 cout <<endl<<endl<< "帐号\t姓名\t性别\t联系方式\t密码"<<endl;
				 for (point = alluser3.begin(); point != alluser3.end(); point++)
				 {
					 if (point->getuser_id() == ff.getuser_id())
						 point->print_user_information_toscreen();
				 }
				 _getch();
				 system("cls");
				 goto loop1;
					
	}
	case '4':{
				 system("cls");
				 cout << "\t\t\t\t\t用户说明书:" << endl;
				 cout << endl << "\n\n\n\t\t\t\t需要其他咨询，请联系艾山江！";
				 _getch();
				 system("cls");
				 goto loop1;
				 //阅读用户说明书
				 // break;
	}
	case '5':{
				 system("cls");
				 cout << endl;
				 cout << endl;
				 cout << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				 cout << "\t\t|\t\t\t\t\t\t|" << endl;
				 cout << "\t\t|\t\t成功退出登录！ \t\t\t|" << endl;
				 cout << "\t\t|\t\t\t\t\t\t|" << endl;
				 cout << "\t\t|\t\t感谢使用！ \t\t\t|" << endl;
				 cout << "\t\t|\t\t\t\t\t\t|" << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				 _getch();
				 system("cls");
				 usermain();
				 // break;
	}
	case '6':{
				 system("cls");
				 exit_all();
				 // break;
	}
	default:{
				system("cls");
				flase_input();
				system("cls");
				goto loop1;
				//break; 

	}
	}
}