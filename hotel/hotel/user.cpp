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

//**************  ����������   *************

//�������ڵ�һЩ��������
date input_date_information(int year, int mon, int day);
bool isleapyear(int y);
int sum(int y, int m, int d);
int Count(int y1, int m1, int d1, int y2, int m2, int d2);

//���ڲ�ѯ��һЩ��������
void user_find_hotel_offline();
int  user_find_hotel_online(user A);
void user_find_room_offline(function asj_user2);
// int  countday(int beginyear, int beginmonth, int beginday, int endyear, int  endmonth, int  endday);   //�������̭��


//��½��������
int user_login(user &BB);
//��ͬ��ݣ����в�ͬ���ܣ�
void  youke();
void  zhengshi();
void user_func(user f);


//**************  ����ʵ����   *************

//=========�û�������=================

void usermain()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t >>> ��ӭ�����û���¼ҳ�棡<<< \t" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   1.��ʽ��¼\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   2.�ο͵�¼\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   3.����\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   4.������һ��\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   5.�˳�ϵͳ\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;
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
				cout << "\t\t\t\t\t����Ա˵����:" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "��ʽ��½:ָƾ�û��˺š������¼���������������������μ��Զ������ο�ģʽ��" << endl;
				cout << "�ɼ��ο�ģʽָ���ǲ���Ҫ�ʺš�����ֱ�ӵ�¼" << endl << endl;
				cout << "Ȼ������ʽ��¼Ϊ���Ϸ����ο͵�¼Ϊ���·��񡣶�����ʹ�ñ�ϵͳ��Ȩ�޲�ͬ��" << endl << endl;
				cout << "������ʽ��½�ɹ����ɽ���Ԥ�����鿴�������鿴������Ϣ�ȹ��ܣ�" << endl;
				cout << "���ο�ֻ��ʹ�ò�ѯ���ܣ�Ҳ���������  ^o^  " << endl;
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




//�������ڵ�һЩ����
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
	cout << "��֣�";
	cin >> year;
	cout << endl;
	while (year<2017 || year>2027)
	{
		cout << endl;
		cout << "\t\t��---------------------------------------------��" << endl;
		cout << "\t\t\t����ݲ��ڷ�������������2017-2027��֮�����ݣ�" << endl << endl;
		cout << "\t\t��---------------------------------------------��" << endl << endl;
		cout << "��֣�";
		cin >> year;
		cout << endl;
	}
	cout << "�·ݣ�";
	cin >> mon;
	cout << endl;
	while (mon<1 || mon>12)
	{
		cout << endl;
		cout << "\t\t��---------------------------------------------��" << endl;
		cout << "\t\t\t���·ݲ��ڷ�������������1��-12��֮����·ݣ�" << endl << endl;
		cout << "\t\t��---------------------------------------------��" << endl << endl;
		cout << "�·֣�";
		cin >> mon;
		cout << endl;
	}
	cout << "��������ڣ�";
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
					cout << "\t\t��---------------------------------------------��" << endl;
					cout << "\t\t\t       ���·����ֻ��1�յ�29�գ�" << endl << endl;
					cout << "\t\t��---------------------------------------------��" << endl << endl;
					cout << "�������룺";
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
					cout << "\t\t��---------------------------------------------��" << endl;
					cout << "\t\t\t       ���·����ֻ��1�յ�31�գ�" << endl << endl;
					cout << "\t\t��---------------------------------------------��" << endl << endl;
					
					cout << "�������룺";
				}
				else { flag = 1; break; }
			}
			else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
			{
				if (day > 31 || day < 1)
				{
					cout << endl;
					cout << "\t\t��---------------------------------------------��" << endl;
					cout << "\t\t\t       ���·����ֻ��1�յ�30�գ�" << endl << endl;
					cout << "\t\t��---------------------------------------------��" << endl << endl;
					
					cout << "�������룺";
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
					cout << "\t\t��---------------------------------------------��" << endl;
					cout << "\t\t\t       ���·����ֻ��1�յ�28�գ�" << endl << endl;
					cout << "\t\t��---------------------------------------------��" << endl << endl;
					cout << "�������룺";
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
					cout << "\t\t��---------------------------------------------��" << endl;
					cout << "\t\t\t       ���·����ֻ��1�յ�31�գ�" << endl << endl;
					cout << "\t\t��---------------------------------------------��" << endl << endl;
					cout << "�������룺";
				}
				else { flag = 1; break; }
			}
			else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
			{
				if (day > 31 || day < 1)
				{
					cout << endl;
					cout << "\t\t��---------------------------------------------��" << endl;
					cout << "\t\t\t       ���·����ֻ��1�յ�30�գ�" << endl << endl;
					cout << "\t\t��---------------------------------------------��" << endl << endl;
					cout << "�������룺";
				}
				else {
					flag = 1; break;
				}
			}
		}
		
		cout << "����������������ڣ�";
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
 
//����̭�ķ�����

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
//	//����ĳ����ǰ�·ݵ�����
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
//	//�·�������������µ�����
//	sum = sum + endday;
//	sum = 365 * (endyear - beginyear) + y + sum;
//
//
//	if (endyear % 400 == 0 || (endyear % 4 == 0 && endyear % 100 != 0)) //�ж��Ƿ�����
//		leap = 1;
//	else
//		leap = 0;
//
//	if (leap == 1 && endmonth>2)sum = sum + 1;
//	return sum;
//}        //    
  



//���ڲ�ѯ��һЩ����

void user_find_hotel_offline()
{
	function  asj_user;


loop1:
	cout << endl << endl << endl;
	int flag = 0;
	string input_cityname;
	cout << "������Ҫ���ҵĳ��У�";


	cin >> input_cityname;
	flag = asj_user.find_hotel(input_cityname);
	if (flag == 1)
	{
		cout << endl;
		cout << "\t\t��---------------------------------------------��" << endl;
		cout << "\t\t\t    û���ҵ��ó���! " << endl << endl;
		cout << "\t\t\t    ���������밴 \"9\"    |     �˳��밴 \"0\" " << endl << endl;
		cout << "\t\t��---------------------------------------------��" << endl << endl;
		
	loop2:
		char c = _getch();
		switch (c)
		{
		case '9':{goto loop1; }

		case '0':{goto loop3; break; }
		default:{cout << "\t\t������� �������룡" << endl; goto loop2; break; }
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
	cout << "  ѡ�������ѯ�ľƵ꣺";
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
		cout << "\t\t��---------------------------------------------��" << endl;
		cout << "\t\t\t    û���ҵ��þƵ�! " << endl << endl;
		cout << "\t\t\t    ���������밴 \"9\"    |     �˳��밴 \"0\" " << endl << endl;
		cout << "\t\t��---------------------------------------------��" << endl << endl;
	
	loop2:
		char c = _getch();
		switch (c)
		{
		case '9':{goto loop1; break; }

		case '0':{goto loop3; break; }
		default:{cout << "\t\t������� �������룡" << endl; goto loop2; break; }
		}
	}
	else
	{
		cout << "�����\t����۸�\t��������" << endl;
		ho.find_room(ho);
	}

loop3:

	cout << endl << endl;
	cout << "\t\t��---------------------------------------------��" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	//cout << "\t\t|\t\t    ллʹ�ã�\t\t\t|" << endl;
	cout << "\t\t|\t ���·��񵽴˽�����ллʹ��!!! \t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t��---------------------------------------------��" << endl;

	_getch();



}


int  user_find_hotel_online(user A)
{

	function  asj_user_book;
loop1:
	int flag = 0;
	string input_cityname;
	cout << endl << endl;
	cout << "      ������Ҫ���ҵĳ������ƣ�";

	cin >> input_cityname;
	flag = asj_user_book.find_hotel(input_cityname);
	if (flag == 1)
	{
		cout << endl;
		cout << "\t\t��---------------------------------------------��" << endl;
		cout << "\t\t\t    û���ҵ��ó���! " << endl << endl;
		cout << "\t\t\t    ��������  �밴  \" 9 \"  " << endl << endl;
		cout << "\t\t��---------------------------------------------��" << endl << endl;
		

loop2:
		char c = _getch();
		switch (c)
		{
		case '9':{goto loop1;  }
		default:{cout << "\t\t������� �������룡" << endl; goto loop2;  }
		}
		
	}
	else
	{
	
		asj_user_book.print_cities();  //��ӡ�Ƶ���Ϣ
	}

loop4 :
	cout << "ѡ�������ѯ�ľƵ��ţ�";
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
		  cout << "\t\t��---------------------------------------------��" << endl;
		  cout << "\t\t\t    û���ҵ��þƵ�! " << endl << endl;
		  cout << "\t\t\t    ��������  �밴  \" 9 \"  " << endl << endl;
		  cout << "\t\t��---------------------------------------------��" << endl << endl;
loop5:
		  char c = _getch();
		  switch (c)
		  {
		  case '9':{goto loop4;  }
		  default:{cout << "\t\t������� �������룡" << endl; goto loop5; }
		  }
	  }
	  else
	  {
		  cout << "�����\t����۸�\t��������" << endl;
		  ho.find_room(ho);//��ӡ������Ϣ
	  }

  loop11:
	  cout << "ѡ������Ԥ���ķ���ķ���ţ�";
	  string input_room_num;


	  cin >> input_room_num;


	  string cost_of_eachroom;
	  vector<Room> source_rooms;      //�þƵ�����з��䣬��������ʱ��
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
		  cout << "\t\t��---------------------------------------------��" << endl;
		  cout << "\t\t\t    û���ҵ��÷���! " << endl << endl;
		  cout << "\t\t\t    ��������  �밴  \" 9 \"  " << endl << endl;
		  cout << "\t\t��---------------------------------------------��" << endl << endl;
		 
	  loop22:
		  char c = _getch();
		  switch (c)
		  {
		  case '9':{goto loop11; break; }

		  default:{cout << "\t\t������� �������룡" << endl; goto loop22; break; }
		  }
	  }
	  else{
		  order booked;     //һ��order���������������ζ���



		  date   comdate, godate;
		  int year1 = 0, year2 = 0, mon1 = 0, mon2 = 0, day1 = 0, day2 = 0;

 loop44:
		  cout << "���붩��ʱ��" << endl;
		  comdate = input_date_information(year1, mon1, day1);
		  godate = input_date_information(year2, mon2, day2);
		  //int sum = countday(comdate.year, comdate.month,comdate.day,godate.year, godate.month, godate.day);
		  int sum = Count(comdate.year, comdate.month, comdate.day, godate.year, godate.month, godate.day);
		  if (sum < 0)
		  {
			  cout << endl;
			  cout << "\t\t��---------------------------------------------��" << endl;
			  cout << "\t\t\t    �˷�����Ӧ����ס����֮�� " << endl << endl;
			  cout << "\t\t��---------------------------------------------��" << endl << endl;
			 
			  goto loop44;
		  }

		  vector<user> alluser2;     //�½������û�
		  int num_of_alluser = asj_user_book.get_users_num();
		  for (int j = 0; j < num_of_alluser; j++)
			  alluser2.push_back(asj_user_book.getuser(j));


		  /////////////////////////////////////////////////////////////////////Ԥ�����ж������жϿɷ�Ԥ��
		  vector<order> allorder2;     //�½����ж���
		  vector <user> ::iterator point;
		  for (point = alluser2.begin(); point != alluser2.end(); point++)
		  {
			  int num_of_oneusers_order = point->get_users_order_num();
			  for (int j = 0; j < num_of_oneusers_order; j++)
				  allorder2.push_back(point->getorder(j));
		  }
		  vector <order> target_hotel_orders;  //  ��С�ȽϷ�Χ
		  vector <order> ::iterator point2;
		  for (point2 = allorder2.begin(); point2 != allorder2.end(); point2++)
		  {
			  if (point2->getordered_hotel_num() == input_hotelnum)
			  {
				  target_hotel_orders.push_back(*point2);
			  }
		  }
		  vector<order>target_room_orders;  // ���� ��С�ȽϷ�Χ
		  for (point2 = target_hotel_orders.begin(); point2 != target_hotel_orders.end(); point2++)
		  {
			  if (point2->getordered_room_num() == input_room_num)
			  {
				  target_room_orders.push_back(*point2);
			  }
		  }
		  //�жϲ����뷿�䣬��ؼ��ĵط�������
		  int flag2 = 0;
		  if (target_room_orders.size() == 0)
		  {
			  //����Ԥ��
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
					  //����Ԥ��
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
					  //����Ԥ��
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
					  //����Ԥ�����÷��䣬��ʱ����Ѿ���Ԥ������!
					  break;
				  }
			  }
		  }
		  int haha = 0;
		  if (flag2 == 0)
		  {
			  //cout << "�ܱ�Ǹ ����\\Ůʿ���÷��� ��ʱ����Ѿ���Ԥ����" << endl<<endl;
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

//��½����
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
		cout << "Ԥ���û��ʺ�: 666" << endl;
		cout << "����: 666";
		cout << endl;
		cout << endl;
		cout << endl;
		printf("�������û��ʺţ�");
		//scanf_s("%10s", number);
		cin >> user_id_number;
		printf("���������룺");
		//scanf_s("%6s", passward);
		cin >>user_password;


		function *SS = new function;
	
		vector<user> alluser2;   //��������û����û���¼ʱ��
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
			cout << "\t\t��---------------------------------------------��" << endl;
			//cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    ллʹ�ã�\t\t\t|" << endl;
			cout << "\t\t|\t          �û�������!!!\t\t\t|" << endl;
			//cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t��---------------------------------------------��" << endl;
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
				cout << "\t\t��---------------------------------------------��" << endl;
				//cout << "\t\t|\t\t\t\t\t\t|" << endl;
				//cout << "\t\t|\t\t    ллʹ�ã�\t\t\t|" << endl;
				cout << "\t\t|\t          �������!!!\t\t\t|" << endl;
				//cout << "\t\t|\t\t\t\t\t\t|" << endl;
				cout << "\t\t��---------------------------------------------��" << endl;
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
			cout << "\t\t��---------------------------------------------��" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    ллʹ�ã�\t\t\t|" << endl;
			cout << "\t\t|\t\t��¼�ɹ�!!! \t\t\t|" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t\t   �𾴵��û���" << uuus.getuser_name() <<" \t\t"<< endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t|\t\"������\"  �Ƶ����ϵͳ��ӭ�㣡\t\t|" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t��---------------------------------------------��" << endl;
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
			cout << "\t\t��---------------------------------------------��" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    ллʹ�ã�\t\t\t|" << endl;
			cout << "\t\t|\t�����µ�¼��������" << n << "�λ���"<< endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t��---------------------------------------------��" << endl;
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
			cout << "\t\t��---------------------------------------------��" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    ллʹ�ã�\t\t\t|" << endl;
			cout << "\t\t|\t\t��ע���û��޷���¼\t\t|" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t|   ��ʹ���ο���ݻ�Ԥ���û��ʺ������¼��лл! |" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t��---------------------------------------------��" << endl;
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

//��ͬ��ݣ����в�ͬ���ܣ�

void  youke()
{
	system("cls");

	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t\t��ӭʹ���ο͹���!\t\t" << endl;
	cout << "\t\t��---------------------------------------------��" << endl;
	cout << "\t\t\t\t\t\t\t\t" << endl;
	//cout << "\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t�����Խ�����һ�䣡\t\t " << endl;
	cout << "\t\t  ��ֻ��ʹ�ò�ѯ���񣬲���ʹ��Ԥ������\t\t" << endl;
	cout << "\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\tף����ÿ��ģ�����\t\t" << endl;
	cout << "\t\t\t\t\t\t\t\t" << endl;
	cout << "\t\t��---------------------------------------------��" << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	_getch();
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t  >>> �װ����οͣ���ӭ������<<< \t" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	// cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  1.��ѯ�Ƶ�\t\t|" << endl;   // �����ٷ�Ԥ�����˳�
	// cout << "\t\t\t|\t  2.�鿴����\t\t|" << endl;   //�����ٷ��˶����˳�   �˶�ʱ���۾Ƶ�    
	// cout << "\t\t\t|\t  3.�鿴������Ϣ\t\t|" << endl; //�����ٷָ��ĸ�����Ϣ
	//		 cout << "\t\t\t|\t  4.�Ķ��û�˵����\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  2.������һ��\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  3.ֱ���˳�ϵͳ\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;
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
	cout << "\t\t\t      >>> ��ʽ�û���<<< \t" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  1.Ԥ�� \t\t|" << endl;   // �����ٷ�Ԥ�����˳�
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  2.�鿴����\t\t|" << endl;   //�����ٷ��˶����˳�   �˶�ʱ���۾Ƶ�  
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  3.�鿴������Ϣ\t|" << endl; //�����ٷָ��ĸ�����Ϣ
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  4.�Ķ��û�˵����\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  5.�˳���¼ \t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  6.ֱ���˳�ϵͳ\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;

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
					 cout << "\t\t��--------------------------------------------------��" << endl;
					 cout << "\t\t\t�ܱ�Ǹ ����\\Ůʿ���÷��� ��ʱ����Ѿ���Ԥ����!!!\t\t\t" << endl;
					 cout << "\t\t��--------------------------------------------------��" << endl;
					 cout << endl;

				 }
				 else if (heihei==1)
				 {
					 cout << endl;
					 cout << endl;
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t          Ԥ���ɹ�!!!\t\t\t" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
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
				 vector<user> alluser3;     //�½������û�
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
							//�������ڴ�ӡ���������ӡ��1064��ʼ��
							 //point->print_myorders_to_screen();
						 }
						 
					 }
						 
				 }
				 if (flag55 == 0)
				 {
					 cout << endl;
					 cout << endl;
					 cout << "\t\t��--------------------------------------------------------��" << endl;
					 cout << "\t\t\t �𾴵��û���Ŀǰ��û���κζ���!!!\t\t\t" << endl;
					 cout << "\t\t��--------------------------------------------------------��" << endl;
					 _getch();
					 system("cls");
					 goto loop1;
				 }
				 else if (flag55 == 1)
				 {
					
					 cout << "�û���\t\t������\t�Ƶ���\t�Ƶ�����|\t\t����� \t��������|\t\t��סʱ��-�˷�ʱ��\t���ã�RMB�� " << endl;
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
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t          �Ƿ�ȡ������!!!\t\t\t" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << endl;
			     	 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t    ȡ������  �밴  \" 9 \"  " << endl << endl;
					 cout << "\t\t\t    ������    �밴�����������" << endl << endl;
					 cout << "\t\t��---------------------------------------------��" << endl<<endl;
					 

					 switch (_getch())
					 {
					 case '9':{
							  loop88:
								  cout << "������Ҫɾ���Ķ����ţ�";
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
									  
									  cout << endl << "�ö���ɾ��ʧ�ܣ�" << endl << "������";
									  goto loop88;
								  }
								  else if (aha == 1)
								  {
									  cout << endl << "�ö����ɹ���ɾ����" << endl;
									  system("cls");
									  cout << endl;
									  cout << endl;
									  cout << "\t\t��---------------------------------------------��" << endl;
									  cout << "\t\t\t  �ɹ�ȡ��������Ϊ \" " << c << " \" �Ķ���" << endl; 
									  cout << "\t\t��---------------------------------------------��" << endl;
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
				 vector<user> alluser3;     //�½������û�
				 int num_of_alluser3 = d->get_users_num();
				 for (int j = 0; j < num_of_alluser3; j++)
					 alluser3.push_back(d->getuser(j));
				 delete d;
				 vector <user> ::iterator point;
				 cout <<endl<<endl<< "�ʺ�\t����\t�Ա�\t��ϵ��ʽ\t����"<<endl;
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
				 cout << "\t\t\t\t\t�û�˵����:" << endl;
				 cout << endl << "\n\n\n\t\t\t\t��Ҫ������ѯ������ϵ��ɽ����";
				 _getch();
				 system("cls");
				 goto loop1;
				 //�Ķ��û�˵����
				 // break;
	}
	case '5':{
				 system("cls");
				 cout << endl;
				 cout << endl;
				 cout << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				 cout << "\t\t|\t\t\t\t\t\t|" << endl;
				 cout << "\t\t|\t\t�ɹ��˳���¼�� \t\t\t|" << endl;
				 cout << "\t\t|\t\t\t\t\t\t|" << endl;
				 cout << "\t\t|\t\t��лʹ�ã� \t\t\t|" << endl;
				 cout << "\t\t|\t\t\t\t\t\t|" << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
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