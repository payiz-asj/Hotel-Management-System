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

//���ĳ���Ƶ����з���
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


//���÷�������
void Room::set_style(string cc)
{
	//һ������ô�����͵ķ���{ �Զ��巿�����ͣ����˼䣬
	//˫�˼䣬���˼䣬�󴲷�����׼�䣬�����������񷿣�
	//��ͳ�׷� ,���·����߼�������ͥʽ����Ӥ������}

	string::size_type p;
	string a = "����";
	string b = "˫��";
	string c = "����";
	string d = "��";
	string e = "��׼";
	string f = "����";
	string g = "����";
	string h = "��ͳ";
	string i = "����";
	string j = "�߼�";
	string k = "��ͥ";
	if ((p = cc.find(a)) != cc.npos || (p = cc.find("��")) != cc.npos)style = "���˼�";
	else{
		if ((p = cc.find(b)) != cc.npos || (p = cc.find("˫")) != cc.npos)style = "˫�˼�";
		else{
			if ((p = cc.find(c)) != cc.npos || (p = cc.find("��")) != cc.npos)style = "���˼�";
			else{
				if ((p = cc.find(d)) != cc.npos || (p = cc.find("��")) != cc.npos)style = "�󴲷�";
				else{
					if ((p = cc.find(e)) != cc.npos || (p = cc.find("��")) != cc.npos)style = "��׼��";
					else{
						if ((p = cc.find(f)) != cc.npos || (p = cc.find("��")) != cc.npos)style = "������";
						else{
							if ((p = cc.find(g)) != cc.npos || (p = cc.find("��")) != cc.npos)style = "����";
							else{
								if ((p = cc.find(h)) != cc.npos || (p = cc.find("��")) != cc.npos)style = "��ͳ�׷�";
								else{
									if ((p = cc.find(i)) != cc.npos || (p = cc.find("��")) != cc.npos)style = "���·�";
									else{
										if ((p = cc.find(j)) != cc.npos || (p = cc.find("�߼�")) != cc.npos)style = "�߼���";
										else{
											if ((p = cc.find(k)) != cc.npos || (p = cc.find("��")) != cc.npos)style = "��ͥʽ(��Ӥ����)";
											else{
												//cout << "δ�ҵ���Ӧ�ķ��䣬���԰���ָ��Ϊ�Զ��巿�����ͣ�";
												style = "�Զ��巿������:";
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


//��ͬ�����͵ķ�����¼��vector���֪���Ƶ��и����͵ķ����м���
void hotel::select_room_sty()
{
	vector<Room> ::iterator it;
	for (it = allrooms.begin(); it != allrooms.end(); it++)
	{

		if (it->get_style() == "���˼�")sty1.push_back(*it);
		else if (it->get_style() == "˫�˼�")sty2.push_back(*it);
		else if (it->get_style() == "���˼�")sty3.push_back(*it);
		else if (it->get_style() == "�󴲷�")sty4.push_back(*it);
		else if (it->get_style() == "��׼��")sty5.push_back(*it);
		else if (it->get_style() == "������")sty6.push_back(*it);
		else if (it->get_style() == "�����")sty7.push_back(*it);
		else if (it->get_style() == "��ͳ�׷�")sty8.push_back(*it);
		else if (it->get_style() == "���·�")sty9.push_back(*it);
		else if (it->get_style() == "�߼���")sty10.push_back(*it);
		else if (it->get_style() == "��ͥʽ(��Ӥ����)")sty11.push_back(*it);
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
			cout << "�ļ� " << c << "��ʧ�ܣ�  �޷�д��";
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
			cout << "�ļ� " << c << "��ʧ�ܣ� �޷�д��";
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
	cout << "�þƵ�Ŀǰ�����·���:" << endl << endl;
	for (p = allrooms.begin(); p != allrooms.end(); p++)
	{
		p->print_oneroom_toscreen();
		cout << endl;
	}
	cout << "�޸��밴9���˳��밴0��";
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
				cout << "\t\t������� �������룡";
				goto loop77;
	}

	}
	
	cout << endl << endl << "��ѡ����Ҫ�޸ĵķ��䣨���뷿��ţ���";
	string cc;
	cin >> cc;
	cout << endl;
	for (p = allrooms.begin(); p != allrooms.end(); p++)
	{

		if (p->get_room_num ()== cc)
		{
		loop444:
			system("cls");
			cout << endl << endl << "\t\t ������ʹ�� \" �޸ķ�����Ϣ \" ����" << endl << endl;
			cout << "\t\t �밴������ѡ�������" << endl << endl;

			cout << "\t\t��---------------------------------------------��" << endl << endl;
			cout << "\t\t               �������ԣ� " << endl << endl;
			cout << "\t       �����   �۸�   ����   �����˳�" << endl;
			cout << "\t ѡ��:    1       2      3        4       " << endl << endl;
			cout << "\t\t��---------------------------------------------��" << endl << endl;

			cout << "�÷������Ϣ��"<<endl;
			p->print_oneroom_toscreen();
			cout << endl << endl;
		loop333:
			cout << endl << "��ѡ��:" << endl;
			switch (_getch())
			{
			case'1':{
						string aaa;
						cout << "�����뷿��ţ�";
						cin >> aaa;
						p->change_room_num(aaa);
						goto loop333;

			}
			case'2':
			{
					   string aaa;
					   cout << "�����뷿��۸�";
					   cin >> aaa;
					   p->change_room_price(aaa);
					   goto loop333;
			}
			case'3':{
						string aaa;
						cout << "�����뷿�����ͣ�";
						cin >> aaa;
						p->set_style(aaa);
						goto loop333;
			}
			case'4':{
						cout << "�÷����Ը���Ϊ��" << endl;
						p->print_oneroom_toscreen();

						cout <<endl<<endl<< "�����޸� �밴9  |   ȷ�ϸ���  �밴���������" << endl;
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
	cout << "\t\t��---------------------------------------------��" << endl;
	cout << "\t\t\t  �þƵ겻���ڣ���   �Ƶ��޸�ʧ�ܣ�" << endl;
	cout << "\t\t��---------------------------------------------��" << endl;
	cout << endl << "������";
	

}
			
			