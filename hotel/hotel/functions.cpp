#include"functions.h"
#include<iostream>
#include<algorithm>
#include<map>
#include<fstream>
#include<stdio.h>
#include<cstdlib>
#include<string>
#include<conio.h>
#include<ctime>
using namespace std;




//默认构造函数：用来初始化function   即allhotels
function::function()
{

	///////////////////////////////////////////////////////////////////////打开hotel.txt
	FILE *ho;
	fopen_s(&ho,"hotel.txt", "r");
	//set_file_error(1);
	if (ho == NULL)
	{
		//cout << "打开  \"hotel.txt\"  失败!" << endl;
		//cout << "导入失败!!!" << endl;
		//exit(-1);
		//goto loop5;
	}
	//cout <<endl<< "正在读取\"hotel.txt\"的信息……" << endl<<endl;
	char c1 = fgetc(ho);
	//set_file_error(2);
	if (c1 == EOF)
	{
		//cout << "文件\"hotel.txt\"  为空文件 !" << endl;
		//cout << "导入失败!!!" << endl;
		//exit(-1);
		//goto loop2;
		//goto loop0;
	}
	//set_file_error(2);

	fseek(ho, 0, SEEK_SET);
	string hotel_information;
	while (!feof(ho))
	{
		char c;
		c = fgetc(ho);
		hotel_information.push_back(c);
	}
	addhotels(hotel_information);


	///////////////////////////////////////////////////////////////////////打开user.txt
	FILE *us;
	fopen_s(&us,"user.txt", "r");
	//set_file_error(1);
	if (us == NULL)
	{
		//cout << "打开  \"user.txt\"  失败!" << endl;
		//cout << "导入失败!!!" << endl;
		//exit(-1);
		//goto loop3;
	}
	//cout << endl << "正在读取\"user.txt\"的信息……" << endl << endl;
	char c3 = fgetc(us);
	//set_file_error(8);
	if (c3 == EOF)
	{
		//cout << "文件\"user.txt\"  为空文件 !" << endl;
		//cout << "导入失败!!!" << endl;
		//exit(-1);
	//	goto loop2;
	}

	//set_file_error(6);
	fseek(us, 0, SEEK_SET);
	string user_information;
	while (!feof(us))
	{
		char c;
		c = fgetc(us);
		user_information.push_back(c);
	}
	addusers(user_information);

	////////////////////////////////////////////////////////////////////打开order.txt
	FILE *or;
	fopen_s(&or, "order.txt", "r");
	//set_file_error(3);
	if (or == NULL)
	{
		//cout << "打开  \"order.txt\"  失败!" << endl;
		//cout << "如果不是第一次使用，请检查该文件是否被删除！";
		//exit(-1);
		//	goto loop2;
	}
	char c4 = fgetc(or);
	//set_file_error(4);
	if (c4 == EOF)
	{
		//cout << "文件\"order.txt\"  为空文件 !" << endl;
		//cout << "当前无任何订单!!!" << endl;
		//exit(0);
		//goto loop1;
	}

	//set_file_error(5);
	///cout << endl << endl << "order.txt文件都有内容！" << endl;
	fseek(or, 0, SEEK_SET);
	string order_information;
	while (!feof(or))
	{
		char c;
		c = fgetc(or);
		order_information.push_back(c);
	}
	addorders(order_information);

	fclose(or);


	///////////////////////////////////////////////////////////////////////打开manager.txt
	FILE *ma;
	fopen_s(&ma,"manager.txt", "r");
	//set_file_error(6);
	if (ma == NULL)
	{
		//cout << "打开  \"user.txt\"  失败!" << endl;
		//cout << "导入失败!!!" << endl;
		//exit(-1);
		//FILE *mng = fopen("manager.txt", "w");
		//fclose(mng);
	}

	//cout << endl << "正在读取\"manager.txt\"的信息……" << endl << endl;
	char c2 = fgetc(ma);
	//set_file_error(7);
	if (c2 == EOF)
	{
		//cout << "文件\"manager.txt\"  为空文件 !" << endl;
		//cout << "导入失败!!!" << endl;
		//exit(-1);
		//goto loop2;
		//goto loop00;
	}
	//set_file_error(6);

	fseek(ma, 0, SEEK_SET);
	string manager_information;
	while (!feof(ma))
	{
		char c;
		c = fgetc(ma);
		manager_information.push_back(c);
	}
	addmanager(manager_information);






	fclose(ho);
	fclose(us);
	fclose(ma);

	 sort(allhotels.begin(), allhotels.end(), compare_hotel);
	 sort(allusers.begin(), allusers.end(), compare_user);
	 sort(allmanagers.begin(), allmanagers.end(), compar_manager);



}

//导入酒店信息
int function::download_hotel_info(string c)
{
	int k = 0;
	ifstream fp;
	fp.open(c, ios::in);
	ofstream hp;
	hp.open("hotel.txt",ios::app);
	if (!fp||!hp)
	{
		k = 0;
	}
	else
	{
		k = 1;
		string cc;
		while (!fp.eof())
		{
			fp >> cc;
			hp << cc<<endl;
		}
		//hp << endl;
		fp.close();
		hp.close();
	}
	return k;
}

//输入所有酒店信息
void function::addhotels(string c)
{
	int i = 0;
	int m = c.size();
	while (i < m - 1)
	{
		hotel tel;
		for (; c[i] != ','; i++)
		{
			tel.sethotel_number(c[i]);
		}
		i++;
		for (; c[i] != ','; i++)
		{
			tel.sethotel_level(c[i] - '0');
		}
		i++;
		for (int j = 0; c[i] != ','; i++)
		{
			tel.sethotel_name(c[i]);
		}
		i++;
		for (int j = 0; c[i] != ','; i++)
		{
			tel.sethotel_city(c[i]);
		}
		i++;
		for (int j = 0; c[i] != '|'; i++)
		{
			tel.sethotel_location(c[i]);
		}
		i++;
		string cc;
		while (c[i] != '\n')
		{
			cc.push_back(c[i]);
			i++;
		}
		i++;
		tel.addrooms(cc);
		tel.select_room_sty();
		allhotels.push_back(tel);
	}
	//
}

//输入所有用户信息
void function::addusers(string ch)
{
	int  m = ch.size();
	int i = 0;
	while (i < m - 1)
	{
		user ser;
		for (; ch[i] != ','; i++)
		{
			ser.setuser_id(ch[i]);
		}
		i++;
		for (; ch[i] != ','; i++)
		{
			ser.setuer_name(ch[i]);
		}
		i++;
		for (; ch[i] != ','; i++)
		{
			ser.setuser_sex(ch[i]);
		}
		i++; for (; ch[i] != '|'; i++)
		{
			ser.setuser_phonenumber(ch[i]);
		}
		i++;
		for (; ch[i] != '|'; i++)
		{
			ser.setsecret(ch[i]);
		}
		i++;
		allusers.push_back(ser);
		i++;

	}

}


//输入所有管理员信息
void function::addmanager(string ch)
{
	int  m = ch.size();
	int i = 0;
	while (i < m - 1)
	{
		manager ger;
		for (; ch[i] != ','; i++)
		{
			ger.setmanager_id(ch[i]);
		}
		i++;
		for (; ch[i] != ','; i++)
		{
			ger.setmanager_name(ch[i]);
		}
		i++;
		for (; ch[i] != ','; i++)
		{
			ger.setmanager_sex(ch[i]);
		}
		i++; for (; ch[i] != '|'; i++)
		{
			ger.setmanager_phonenumber(ch[i]);
		}
		i++;
		for (; ch[i] != '|'; i++)
		{
			ger.setsecret(ch[i]);
		}
		i++;
		i++;
		//line++;
		allmanagers.push_back(ger);
	}
				
}



//添加一个用户的所有订单
void function::addorders(string ch)
{
	int  m = ch.size();
	int i = 0;
	while (i<m-1)
	{
		//while (ch[i] != '\n')
		//{
			order der;
			for (; ch[i] != '|'; i++)
			{
				der.setor_user(ch[i]);
			}
			i++;
			for (; ch[i] != '|'; i++)
			{
				der.setorder_num(ch[i]);
			}
			i++;
			hotel hhh;
			for (; ch[i] != ','; i++)
			{
				hhh.sethotel_number(ch[i]);
			}
			i++;
			for (; ch[i] != ','; i++)
			{
				hhh.sethotel_level(ch[i] - '0');
			}
			i++;
			for (; ch[i] != ','; i++)
			{
				hhh.sethotel_name(ch[i]);
			}
			i++;
			for (; ch[i] != ','; i++)
			{
				hhh.sethotel_city(ch[i]);
			}
			i++;
			for (; ch[i] != '|'; i++)
			{
				hhh.sethotel_location(ch[i]);
			}
			i++;
			der.setordered_hotel(hhh);
			date ddd;
			ddd.year = ch[i] - '0';
			i++;
			for (; ch[i] != '/'; i++)
			{
				ddd.year = ddd.year * 10 + (ch[i] - '0');
			}
			i++;
			ddd.month = ch[i] - '0';
			i++;
			for (; ch[i] != '/'; i++)
			{
				ddd.month = ddd.month * 10 + (ch[i] - '0');
			}
			i++;
			ddd.day = ch[i] - '0';
			i++;
			for (; ch[i] != '-'; i++)
			{
				ddd.day = ddd.day * 10 + (ch[i] - '0');
			}
			i++;
			der.setindate(ddd);
			date dddd;
			dddd.year = ch[i] - '0';
			i++;
			for (; ch[i] != '/'; i++)
			{
				dddd.year = dddd.year * 10 + (ch[i] - '0');
			}
			i++;
			dddd.month = ch[i] - '0';
			i++;
			for (; ch[i] != '/'; i++)
			{
				dddd.month = dddd.month * 10 + (ch[i] - '0');
			}
			i++;
			dddd.day = ch[i] - '0';
			i++;
			for (; ch[i] != '|'; i++)
			{
				dddd.day = dddd.day * 10 + (ch[i] - '0');
			}
			i++;
			der.setoutdate(dddd);
			Room mmm;
			string tt2;
			for (; ch[i] != '-'; i++)
			{
				tt2.push_back(ch[i]);
			}
			mmm.set_style(tt2);
			i++;
			for (; ch[i] != '|'; i++)
			{
				mmm.set_room_num(ch[i]);
			}
			i++;
			//mmm.set_room_price(0) 
			//这里，因为订单没有房间一晚上的价钱，
			//所以暂时使用mmm的初始化函数将其初始化

			der.setordered_room(mmm);
			for (; ch[i] != '|'; i++)
			{
				der.setmoney(ch[i]);
			}                                                         //调试点
			i++;
			i++;
			vector<user>::iterator it;
			for (it = allusers.begin(); it != allusers.end(); it++)
			{
				if (der.getor_user() == it->getuser_id())
					it->setmy_orders(der);
			}

		//}
	}

}

//查找hotel，建立城市map
int  function::find_hotel(string cit)
{
	vector<hotel>::iterator it;
	for (it = allhotels.begin(); it != allhotels.end(); it++)
	{
		if (it->gethotel_city() == cit)
		{
			finded_hotel.push_back(*it);
		}
		//pair < string, vector<hotel>> p =(cit, finded_hotel);
	}
	if (finded_hotel.empty())
	{
		//cout << "没有找到该城市！";
		return 1;
	}
	else
	{
		cities.insert(make_pair(cit, finded_hotel));
		return 2;
	}
}

int function ::delete_hotel(string cc)
{
	int flag = 0;
	vector <hotel>::iterator it;

	for (it = allhotels.begin(); it != allhotels.end(); it++)
	{

		if (it->gethotel_number() == cc)
		{
			//该酒店存在
			vector<order> allorders3;
			vector<user>::iterator point2;
			for (point2 = allusers.begin(); point2 != allusers.end();point2++)
			{
				for (int i = point2->get_users_order_num(), j = 0; j < i; j++)
				{
					allorders3.push_back(point2->getorder(j));
				}
				
			}
			vector<order> ::iterator point3;
			for (point3 = allorders3.begin(); point3 != allorders3.end(); point3++)
			{
				if (point3->getordered_hotel_num() == cc)
				{
					//该酒店有订单，不能被删除
					flag = 2;
					return flag;
				}
			}
			flag = 1;
			allhotels.erase(it);
			return flag;
		}

	}
	return flag;
}

int function::change_hotel(string cc)
{
	int flag = 0;
	vector <hotel>::iterator it;

	for (it = allhotels.begin(); it != allhotels.end(); it++)
	{

		if (it->gethotel_number() == cc)
		{
			//该酒店存在
			vector<order> allorders3;
			vector<user>::iterator point2;
			for (point2 = allusers.begin(); point2 != allusers.end(); point2++)
			{
				for (int i = point2->get_users_order_num(), j = 0; j < i; j++)
				{
					allorders3.push_back(point2->getorder(j));
				}

			}
			vector<order> ::iterator point3;
			for (point3 = allorders3.begin(); point3 != allorders3.end(); point3++)
			{
				if (point3->getordered_hotel_num() == cc)
				{
					//该酒店有订单，不能被修改
					flag = 2;
					return flag;
				}
			}
		loop66:
			flag = 1;
			system("cls");
			cout << endl << endl << "\t\t 您正在使用 \" 修改酒店信息 \" 功能" << endl << endl;
			cout << "\t\t 请按照下列选项操作：" << endl << endl;

			cout << "\t★---------------------------------------------★" << endl << endl;
			cout << "\t\t               酒店属性： " << endl << endl;
			cout << "\t       编号   星级   名称    城市   具体地点   房间信息  保存退出" << endl;
			cout << "\t选项:   1      2      3       4         5         6         7    " << endl << endl;
			cout << "\t\t★---------------------------------------------★" << endl << endl;

			cout << "该酒店的信息："<<endl;
			it->print_onehotel_toscreen();
			cout << endl << endl;
		loop33:
			cout << endl << "请选择:" << endl;
			switch (_getch())
			{
			case'1':{
						string aaa;
						cout << "请输入酒店编号：";
						cin >> aaa;
						it->change_hotel_number(aaa);
						goto loop33;

			}
			case'2':{

						cout << "请输入酒店星级：";
						int nn;
						cin >> nn;
						while (nn > 7 || nn < 1)
						{
							cout << "酒店等级只能是1-7 ，请重新输入：";
							cin >> nn;
						}
						it->change_hotel_level(nn);
						goto loop33;
			}
			case'3':
			{
					   string aaa;
					   cout << "请输入酒店名称：";
					   cin >> aaa;
					   it->change_hotel_name(aaa);
					   goto loop33;
			}
			case'4':
			{
					   string aaa;
					   cout << "请输入酒店城市：";
					   cin >> aaa;
					   it->change_hotel_city(aaa);
					   goto loop33;
			}
			case'5':
			{
					   string aaa;
					   cout << "请输入酒店具体地点：";
					   cin >> aaa;
					   it->change_hotel_location(aaa);
					   goto loop33;
			}
			case'6':
			{
					   it->change_room();
					   goto loop22;
			}
			case'7':
			{
					   loop22:
					   cout <<endl<<endl<< "该酒店以更改为：" << endl;
					   cout << "编号\t星级\t名称\t\t城市\t具体地点" << endl;
					   it->print_onehotel_toscreen();
					   //打印房间
					   //it->find_room(*it);
					 

					   cout << endl << endl << "继续修改 请按9  |  确认更改  请按任意键继续" << endl;
					   switch (_getch())
					   {
					   case '9':{
									goto loop66;
					   }
					   default:
					   {
								  return flag;
					   }
					   }

			}
			}

		}
		
	}
	return flag;
}