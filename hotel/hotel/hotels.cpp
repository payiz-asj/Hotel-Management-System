#include"hotels.h"
#include"functions.h"
#include<map>
#include<fstream>
#include<stdio.h>
#include<cstdlib>
#include<string>
#include<conio.h>
#include<ctime>
#include<iostream>
using namespace std;

//添加某个酒店所有房间
void hotel::addrooms(string ch)
{
	int  m = ch.size();
	int i = 0;
	while (i<m-1)
	{

		Room oom;
		for (; ch[i] != ','; i++)
		{
			oom.set_room_num(ch[i]);
		}
		i++;
		for (; ch[i] != ','; i++)
		{
			oom.set_room_price(ch[i]);
		}
		i++;
		string tt;
		for (; ch[i] != '|'; i++)
		{
			tt.push_back(ch[i]);
		}
		oom.set_style(tt);
		i++;
		allrooms.push_back(oom);
	}
}


//设置房间类型
void Room::set_style(string cc)
{
	//一共有这么多类型的房间{ 自定义房间类型，单人间，
	//双人间，三人间，大床房，标准间，豪华房，商务房，
	//总统套房 ,雅致房，高级房，家庭式（带婴儿床）}

	string::size_type p;
	string a = "单人";
	string b = "双人";
	string c = "三人";
	string d = "大床";
	string e = "标准";
	string f = "豪华";
	string g = "商务";
	string h = "总统";
	string i = "雅致";
	string j = "高级";
	string k = "家庭";
	if ((p = cc.find(a)) != cc.npos || (p = cc.find("单")) != cc.npos)style = "单人间";
	else{
		if ((p = cc.find(b)) != cc.npos || (p = cc.find("双")) != cc.npos)style = "双人间";
		else{
			if ((p = cc.find(c)) != cc.npos || (p = cc.find("三")) != cc.npos)style = "三人间";
			else{
				if ((p = cc.find(d)) != cc.npos || (p = cc.find("大")) != cc.npos)style = "大床房";
				else{
					if ((p = cc.find(e)) != cc.npos || (p = cc.find("标")) != cc.npos)style = "标准间";
					else{
						if ((p = cc.find(f)) != cc.npos || (p = cc.find("豪")) != cc.npos)style = "豪华房";
						else{
							if ((p = cc.find(g)) != cc.npos || (p = cc.find("商")) != cc.npos)style = "商务房";
							else{
								if ((p = cc.find(h)) != cc.npos || (p = cc.find("总")) != cc.npos)style = "总统套房";
								else{
									if ((p = cc.find(i)) != cc.npos || (p = cc.find("雅")) != cc.npos)style = "雅致房";
									else{
										if ((p = cc.find(j)) != cc.npos || (p = cc.find("高级")) != cc.npos)style = "高级房";
										else{
											if ((p = cc.find(k)) != cc.npos || (p = cc.find("家")) != cc.npos)style = "家庭式(带婴儿床)";
											else{
												//cout << "未找到对应的房间，所以帮您指定为自定义房间类型：";
												style = "自定义房间类型:";
												style.insert(15, cc);
											}
										}
									}

								}

							}
						}
					}
				}
			}
		}
	}
}


//将同种类型的房间收录在vector里，方知道酒店中该来型的房间有几个
void hotel::select_room_sty()
{
	vector<Room> ::iterator it;
	for (it = allrooms.begin(); it != allrooms.end(); it++)
	{

		if (it->get_style() == "单人间")sty1.push_back(*it);
		else if (it->get_style() == "双人间")sty2.push_back(*it);
		else if (it->get_style() == "三人间")sty3.push_back(*it);
		else if (it->get_style() == "大床房")sty4.push_back(*it);
		else if (it->get_style() == "标准间")sty5.push_back(*it);
		else if (it->get_style() == "豪华房")sty6.push_back(*it);
		else if (it->get_style() == "商务间")sty7.push_back(*it);
		else if (it->get_style() == "总统套房")sty8.push_back(*it);
		else if (it->get_style() == "雅致房")sty9.push_back(*it);
		else if (it->get_style() == "高级房")sty10.push_back(*it);
		else if (it->get_style() == "家庭式(带婴儿床)")sty11.push_back(*it);
		else sty0.push_back(*it);
	}
}


void hotel::print_onehotel_tofile(string c)
{
	ofstream fp;
	if (c == "hotel.txt")
	{
		fp.open(c, ios::app);
		if (!fp)
		{
			cout << "文件 " << c << "打开失败！  无法写入";
			//exit(-1);
		}
		else
		{
			fp << hotel_number << ',' << hotel_level << ',' << hotel_name << ',' << hotel_city << ',' << hotel_location << '|';
			int n = allrooms.size();
			for (int i = 0; i < n; i++)
			{
				string n, p, s;
				n = allrooms[i].get_room_num();
				p = allrooms[i].get_room_price();
				s = allrooms[i].get_style();
				fp << n << ',' << p << ',' <<s<< '|';

			}
			fp << endl;
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
			fp << hotel_number << ',' << hotel_level << ',' << hotel_name << ',' << hotel_city << ',' << hotel_location << '|';
			int n = allrooms.size();
			for (int i = 0; i < n; i++)
			{
				string n, p, s;
				n = allrooms[i].get_room_num();
				p = allrooms[i].get_room_price();
				s = allrooms[i].get_style();
				fp << n << ',' << p << ',' << s << '|';
			}
			fp << endl;
			fp.close();
		}

	}


}


void hotel::find_room(hotel h)
{
	


	if (!h.sty0.empty())
	{
		vector<Room>::iterator it;
		for (it = sty0.begin(); it != sty0.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty1.empty())
	{
		vector<Room>::iterator it;
		for (it = sty1.begin(); it != sty1.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty2.empty())
	{
		vector<Room>::iterator it;
		for (it = sty2.begin(); it != sty2.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty3.empty())
	{
		vector<Room>::iterator it;
		for (it = sty3.begin(); it != sty3.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty4.empty())
	{
		vector<Room>::iterator it;
		for (it = sty4.begin(); it != sty4.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty5.empty())
	{
		vector<Room>::iterator it;
		for (it = sty5.begin(); it != sty5.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty6.empty())
	{
		vector<Room>::iterator it;
		for (it = sty6.begin(); it != sty6.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty7.empty())
	{
		vector<Room>::iterator it;
		for (it = sty7.begin(); it != sty7.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty8.empty())
	{
		vector<Room>::iterator it;
		for (it = sty8.begin(); it != sty8.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty9.empty())
	{
		vector<Room>::iterator it;
		for (it = sty9.begin(); it != sty9.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty10.empty())
	{
		vector<Room>::iterator it;
		for (it = sty10.begin(); it != sty10.end(); it++)
			it->print_oneroom_toscreen();
	}
	 if (!h.sty11.empty())
	{
		vector<Room>::iterator it;
		for (it = sty11.begin(); it != sty11.end(); it++)
			it->print_oneroom_toscreen();
	}


}


int hotel::change_room()
{
	
loop11:
	system("cls");
	vector <Room> ::iterator  p;
	cout << "该酒店目前有以下房间:" << endl << endl;
	for (p = allrooms.begin(); p != allrooms.end(); p++)
	{
		p->print_oneroom_toscreen();
		cout << endl;
	}
	cout << "修改请按9，退出请按0：";
loop77:
	switch (_getch())
	{
	case'9':
	{
			   break;
	}
	case'0':
	{
			   return 0;
	}
	default:{
				cout << "\t\t输入错误！ 重新输入！";
				goto loop77;
	}

	}
	
	cout << endl << endl << "请选择您要修改的房间（输入房间号）：";
	string cc;
	cin >> cc;
	cout << endl;
	for (p = allrooms.begin(); p != allrooms.end(); p++)
	{

		if (p->get_room_num ()== cc)
		{
		loop444:
			system("cls");
			cout << endl << endl << "\t\t 您正在使用 \" 修改房间信息 \" 功能" << endl << endl;
			cout << "\t\t 请按照下列选项操作：" << endl << endl;

			cout << "\t\t★---------------------------------------------★" << endl << endl;
			cout << "\t\t               房间属性： " << endl << endl;
			cout << "\t       房间号   价格   类型   保存退出" << endl;
			cout << "\t 选项:    1       2      3        4       " << endl << endl;
			cout << "\t\t★---------------------------------------------★" << endl << endl;

			cout << "该房间的信息："<<endl;
			p->print_oneroom_toscreen();
			cout << endl << endl;
		loop333:
			cout << endl << "请选择:" << endl;
			switch (_getch())
			{
			case'1':{
						string aaa;
						cout << "请输入房间号：";
						cin >> aaa;
						p->change_room_num(aaa);
						goto loop333;

			}
			case'2':
			{
					   string aaa;
					   cout << "请输入房间价格：";
					   cin >> aaa;
					   p->change_room_price(aaa);
					   goto loop333;
			}
			case'3':{
						string aaa;
						cout << "请输入房间类型：";
						cin >> aaa;
						p->set_style(aaa);
						goto loop333;
			}
			case'4':{
						cout << "该房间以更改为：" << endl;
						p->print_oneroom_toscreen();

						cout <<endl<<endl<< "继续修改 请按9  |   确认更改  请按任意键继续" << endl;
						switch (_getch())
						{
						case '9':{
									 goto loop444;
						}
						default:
						{
								   goto loop11;
						}
						}
			}
			}
		}
	}
	cout << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << "\t\t\t  该酒店不存在！！   酒店修改失败！" << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << endl << "请重新";
	

}
			
			