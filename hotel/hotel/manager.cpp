//#include"user.h"
#include"manager.h"
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



int manager_login(manager &BB);
void  zhengshi2();
void  managerfuctions(manager ma);


//������
void managermain()
{

	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t >>> ��ӭ��������Ա¼ҳ�棡<<< \t" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   1.��¼\t\t" << endl;
	//cout << "\t\t\t\t\t\t\t" << endl;
	//cout << "\t\t\t\t   2.�ο͵�¼\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   2.����\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   3.������һ��\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   4.�˳�ϵͳ\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;
	switch (_getch())
	{
	case '1':{
				 zhengshi2();
				 // break; 
	}
	case'2':{
				system("cls");
				cout << "\t\t\t\t\t����Ա˵����:" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "��½:ָƾ����Ա�˺š������¼���������������������μ��Զ��˳���¼��" << endl;
				cout <<  endl << endl;
				cout << "��½�ɹ����ɽ��С��鿴�������鿴������Ϣ�ȹ��ܣ�" << endl;
				cout << "���ο�ֻ��ʹ�ò�ѯ���ܣ�Ҳ���������  ^o^  " << endl;
				cout << endl;
				_getch();
				system("cls");
				usermain();
				//break;
	}
	case '3':{
				 system("cls");
				 enter();
				 // break;
	}
	case '4':{
				 system("cls");
				 exit_all();
				 // break;
	}

	default:{
				system("cls");
				flase_input();
				system("cls");
				managermain();
				//		break; 
	}

	}



}

//��½����
int manager_login(manager &BB)
{

	int n = 3;
	string manager_id_number;
	string manager_password;
	int kk = 0;
	//_getch();
	system("cls");
	for (;;)
	{
		cout << endl;
		cout << "Ԥ�����Ա�ʺ�: 999" << endl;
		cout << "����: 999";
		cout << endl;
		cout << endl;
		cout << endl;
		printf("���������Ա�ʺţ�");
		//scanf_s("%10s", number);
		cin >> manager_id_number;
		printf("���������룺");
		//scanf_s("%6s", passward);
		cin >> manager_password;


		function *SS = new function;

		vector<manager> allmanager2;   //��������û����û���¼ʱ��
		int num_of_allmanager = SS->get_managers_num();
		for (int j = 0; j < num_of_allmanager; j++)
			allmanager2.push_back(SS->getmanagers(j));

		delete SS;
		manager uuus;
		vector<manager> ::iterator it;
		for (it = allmanager2.begin(); it != allmanager2.end(); it++)
		{
			if (it->getmanager_id() ==manager_id_number )
			{
				uuus = *it;
				break;
			}
		}
		if (uuus.getmanager_id() == "")
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "\t\t��---------------------------------------------��" << endl;
			//cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    ллʹ�ã�\t\t\t|" << endl;
			cout << "\t\t|\t          ����Ա������!!!\t\t\t|" << endl;
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
			if (uuus.getmanager_secret() != manager_password)
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

		if (uuus.getmanager_id() !=""&&uuus.getmanager_secret() == manager_password)
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
			cout << "\t\t\t   �𾴵Ĺ���Ա��" << uuus.getmanager_name()<< " \t" << endl;
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
			string ch = uuus.getmanager_id();
			int gg = ch.size();
			for (int i = 0; i < gg; i++)
				BB.setmanager_id(ch[i]);
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
			cout << "\t\t|\t�����µ�¼��������" << n << "�λ���" << endl;
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
			cout << "\t\t|\t\t��ע�����Ա�޷���¼\t\t|" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t|   ��ʹ���ο���ݻ�Ԥ�����Ա�ʺ������¼��лл! |" << endl;
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

//ȷ�ϵ�½
void  zhengshi2()
{

	manager useridentiti;
	int m =manager_login(useridentiti);

	 if (m == 2)
	{
		system("cls");
		managerfuctions(useridentiti);
	}
}
//��ع����ܺ���
void  managerfuctions(manager ma)
{
	
	loop1:
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t      >>> ����Ա ��<<< \t" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  1.����Ƶ���Ϣ   \t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  2.���ӾƵ�\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  3.ɾ���Ƶ�\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  4.�޸ľƵ�\t\t|" << endl;
	//cout << "\t\t\t|\t\t\t\t|" << endl;
	//cout << "\t\t\t|\t  6.�鿴ĳ���û�����\t|" << endl;
	//cout << "\t\t\t|\t\t\t\t|" << endl;
	//cout << "\t\t\t|\t  6.�鿴���ж���\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  5.�鿴������Ϣ\t|" << endl;   //�浽��ĵط�/����ļ�,�ٷ־Ƶ���Ϣ�Ͷ�����Ϣ
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  6.�Ķ�����Ա˵����\t|" << endl;
 	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  7.�˳���¼ \t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  8.ֱ���˳�ϵͳ\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t��-----------------------------��" << endl;

	switch (_getch())
	{
	case '1':{
				 system("cls");
				 string a;
				 int n;
				 function *p = new function;
				 cout << endl << endl;
				 
				 cout << "\t\t��---------------------------------------------��" << endl;
				 cout << "\t\t\t    ���ļ��е���Ƶ���Ϣ�� " << endl << endl;
				 cout << "\t\t\t������Ŀ���ļ�����(Ԥ���ļ�Ϊ \" ������Ϣ.txt \" " << endl << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				
				
				 cin >> a;
				 n=p->download_hotel_info(a);
				 delete p;
				 if (n == 0)
				 {
					 cout << endl << endl;
					//cout << "�����ļ���������һ����ʧ��!  ����ʧ�ܣ�" << endl;
					 cout << "�ļ���ʧ��!  ����ʧ�ܣ�" << endl;
					 _getch();
					 system("cls");
					 goto loop1;
				 }
				 else if (n == 1)
				 {
					 cout << endl << endl;
					 
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t                  ����ɹ���  " << endl << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 
					 _getch();
					 system("cls");
					 goto loop1;
				 }

	}
	case '2':{
				 system("cls");
				 cout << "���ӾƵ�";
				 string aa,bb;
				 function *pp = new function;
				 cout << endl << endl;
			
				// cout << "���,�Ǽ�,����,����,����ص�|����,�۸�,����|����,�۸�,����|����,�۸�,����|" << endl;
				// cout << "0000,3,��ҾƵ�,�Ͼ�,��վ��|101,200,�󴲷�|201,230,��׼��|301,400,������|302,400,������|" <<endl;
				// cout << "���ϸ���������ʽ(ֻ֧��Ӣ�İ�Ƿ���,���޿ո�)������Ƶ���Ϣ���þƵ�ӵ�еķ�����Ϣ��" << endl;
				 cout << endl;
				 cout << "\t\t��---------------------------------------------��" << endl<<endl;
				 cout << "\t\t\t               ��ӾƵ�ʵ���� " << endl << endl;
				 cout << "\t\t\t     ���   �Ǽ�   ����      ����   ����ص�" << endl;
				 cout << "\t\t\t     0000    3   ��ҾƵ�    �Ͼ�   ��վ��" << endl << endl;
				 cout << "\t\t��---------------------------------------------��" << endl<<endl;
			
				 cout << "������Ƶ��ţ�";
				 cin >> bb;
				 aa+=bb;
				 aa.push_back(',');
				 cout << "������Ƶ�ȼ���1-7������";
				 string nn;
				 cin >> nn;
				 while (nn > "7" || nn < "1")
				 {
					 cout << "�Ƶ�ȼ�ֻ����1-7 �����������룺";
					 cin >> nn;
				 }
				 aa += nn;
				 aa.push_back(',');
				 cout << "������Ƶ����ƣ�";
				 cin >> bb;
				 aa += bb;
				 aa.push_back(',');
				 cout << "������Ƶ����ڳ��У�";
				 cin >> bb;
				 aa += bb;
				 aa.push_back(',');
				 cout << "������Ƶ�����ַ��";
				 cin >> bb;
				 aa += bb;
				 aa.push_back('|');

				 cout << endl;
				 cout << "\t\t��---------------------------------------------��" << endl << endl;
				 cout << "\t\t\t            Ϊ�þƵ���ӷ��䣺 " << endl << endl;
				 cout << "\t���磺" << endl;
				 cout << "\t\t     �����   ����۸�   ��������" << endl;
				 cout << "\t\t      201        230       ��׼�� " << endl << endl;
				 cout << "\t\t��---------------------------------------------��" << endl << endl;
				 
				 cout << "���У�����������:" << endl << "   ���˼䣬˫�˼䣬���˼䣬�󴲷�����׼��, ������" << endl;
				 cout<<"   ����䣬��ͳ�׷�, ���·�, �߼�������ͥʽ����Ӥ����), �Զ��巿������"<<endl<<endl<<endl;
	 loop2:
				cout << "�����뷿��ţ�";
				cin >> bb;
				aa += bb;
				aa.push_back(',');

				cout << "�����뷿��۸�";
				cin >> bb;
				aa += bb;
				aa.push_back(',');

				cout << "�����뷿�����ͣ�";
				cin >> bb;
				aa += bb;
				aa.push_back('|');
				cout << endl;
				cout << "\t\t��---------------------------------------------��" << endl;
				cout << "\t\t\t    ������ӷ���  �밴  \" 9 \"  " << endl << endl;
				cout << "\t\t\t    ������    �밴�����������" << endl << endl;
				cout << "\t\t��---------------------------------------------��" << endl<<endl;
			
				switch (_getch())
				{
				case '9':{
							 goto loop2;
				}
				default:
				{
						   break;
				}
				}

				aa.push_back('\n');
				//�������



				//�жϸþƵ��Ƿ��Ѿ�����
				 string ww;
				 for (int i = 0; aa[i] != ','; i++)
				 {
					 ww.push_back(aa[i]);
				 }
				 vector<hotel> allhotels3;   
				 int num_of_allhotels3 = pp->get_hotel_num();
				 for (int j = 0; j <num_of_allhotels3; j++)
					 allhotels3.push_back(pp->gethotel(j));
				 delete pp;
				 vector <hotel> ::iterator point;
				 for (point = allhotels3.begin(); point != allhotels3.end(); point++)
				 {
					 if (point->gethotel_number() == ww)
					 {
						 cout << endl << endl << "�þƵ��Ѵ��ڣ� �޷���ӣ�" <<endl<<endl;
						 _getch();
						 system("cls");
						 goto loop1;
					 }
				 }
				 
				 //���ӾƵ�
		

				 //��ŸþƵ�
			
				 ofstream fp;
				 fp.open("hotel.txt", ios::app);
				 if (!fp)
				 {
					 cout << "�޷��� \" hotel.txt \"  ! " << endl;
				 }
				 fp << aa;
				 
				 fp.close();
				 cout << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				 cout << "\t\t\t    ���ı�������ˣ�  " << endl << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				 cout << "���,�Ǽ�,����,����,����ص�|����,�۸�,����|����,�۸�,����|����,�۸�,����|����" << endl;
				 cout << aa << endl << endl;
				 _getch();
				 system("cls");
				 cout << endl;
				 cout << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				 cout << "\t\t\t  �ɹ���ӾƵ���Ϊ \" " << ww << " \" �ľƵ�" << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				 _getch();
				 system("cls");
				 goto loop1;

				 break; 
	}

	case '3':{
				 system("cls");
				 cout << "ɾ���Ƶ�" << endl<<endl<<endl;
				 cout << "Ŀǰϵͳ�������¾Ƶ꣺" << endl << endl;
				  string ww;
				 function *pp = new function;
				 vector<hotel> allhotels4;
				 int num_of_allhotels4 = pp->get_hotel_num();
				 for (int j = 0; j < num_of_allhotels4; j++)
					 allhotels4.push_back(pp->gethotel(j));
				 vector <hotel> ::iterator point2;
				 for (point2 = allhotels4.begin(); point2 != allhotels4.end(); point2++)
				 {
					 point2->print_onehotel_toscreen();
				 }

				
				 cout << endl;
				 cout << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				 cout << "\t\t\t    ɾ���Ƶ�  �밴  \" 9 \"  " << endl<<endl;
				 cout << "\t\t\t    ������    �밴�����������" << endl << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				 // cout << "  ɾ���Ƶ�  �밴  \" 9 \"  " << endl;
				 //cout << endl;
				 //cout << "  ������    �밴�����������" << endl << endl;

				 switch (_getch())
				 {
				 case '9':{
							  break;
				 }
				 default:{
							 system("cls");
							 goto loop1;
							 //break; 		
				 }
				 }
				 cout << endl << endl;
				 int ttt = 0;
			 loop88:
				 if (ttt>4)
				 {
					 system("cls");
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t  ���Դ���̫����������" << endl<<endl<<endl;
					 cout << "\t\t\t  ɾ������ֹͣ��" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					
					 //_getch();
					 goto loop55;//�������
				 }
				 cout << "������Ҫɾ���ľƵ��ţ�";
				 ttt++;
				 cin >> ww;
				 //�������
				 int aha;
				aha = pp->delete_hotel(ww);				
				 if (aha == 0)
				 {
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t  �þƵ겻���ڣ���   �Ƶ�ɾ��ʧ�ܣ�" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout <<endl << "������";
					 goto loop88;
				 }
				 else if (aha == 2)
				 {
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t  �þƵ��ж�������   �Ƶ�ɾ��ʧ�ܣ�" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << endl << "������";
					 //cout << endl << "�þƵ��ж�������   �Ƶ�ɾ��ʧ�ܣ�" << endl << "������";
					 goto loop88;
				 }
				 else if (aha == 1)
				 {
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t            �þƵ�ɹ���ɾ����" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					// cout << endl << "�þƵ�ɹ���ɾ����" << endl;
					 system("cls");
					 cout << endl;
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t  �ɹ�ɾ���Ƶ���Ϊ \" " << ww << " \" �ľƵ�" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << endl;
					 cout << endl;

					 //������оƵ�
					 /*vector<hotel> allhotels4;
					 int num_of_allhotels4 = pp->get_hotel_num();
					 for (int j = 0; j < num_of_allhotels4; j++)
						 allhotels4.push_back(pp->gethotel(j));
					*/

					 ofstream fp;
					 fp.open("hotel.txt", ios::out);
					 if (!fp)
					 {
						 cout << "�޷��� \" hotel.txt \"  ! " << endl;
					 }
					 fp.close();
					 /*vector <hotel> ::iterator point2;
					 string hh = "hotel.txt";
					 for (point2 = allhotels4.begin(); point2 != allhotels4.end(); point2++)
					 {
						 point2->print_onehotel_tofile(hh);
					 }*/

					 //�ҵ��˸����ӷ���ķ�����
					 pp->print_allhotels_tofile();
					 delete pp;
				 }
	 loop55:
				 _getch();
				 system("cls");
				 goto loop1;

				// break;
	}
	case '4':{

				 system("cls");
				 cout << "�޸ľƵ�" << endl << endl << endl;
				 cout << "Ŀǰϵͳ�������¾Ƶ꣺" << endl << endl;
				 string ww;
				 function *pp = new function;
				 vector<hotel> allhotels4;
				 int num_of_allhotels4 = pp->get_hotel_num();
				 for (int j = 0; j < num_of_allhotels4; j++)
					 allhotels4.push_back(pp->gethotel(j));
				 vector <hotel> ::iterator point2;
				 cout << "���\t�Ǽ�\t����\t����\t����ص�" << endl;
				 for (point2 = allhotels4.begin(); point2 != allhotels4.end(); point2++)
				 {
					 point2->print_onehotel_toscreen();
				 }


				 cout << endl;
				 cout << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				 cout << "\t\t\t    �޸ľƵ�  �밴  \" 9 \"  " << endl << endl;
				 cout << "\t\t\t    ������    �밴�����������" << endl << endl;
				 cout << "\t\t��---------------------------------------------��" << endl;
				 

				 switch (_getch())
				 {

				 case '9':{
							  break;
				 }
				 default:{
							 system("cls");
							 goto loop1;
							 //break; 		
				 }
				 }
				 cout << endl << endl;
			 loop99:
				 cout << "������Ҫ�޸ĵľƵ��ţ�";
				 cin >> ww;
				 //�������
				 int aha;
				 aha = pp->change_hotel(ww);
				 if (aha == 0)
				 {
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t  �þƵ겻���ڣ���   �Ƶ��޸�ʧ�ܣ�" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << endl << "������";
					 goto loop99;
				 }
				 else if (aha == 2)
				 {
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t  �þƵ��ж�������   �Ƶ��޸�ʧ�ܣ�" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << endl << "������";
				
					 goto loop99;
				 }
				 else if (aha == 1)
				 {
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t            �þƵ�ɹ����޸ģ�" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					
					 system("cls");
					 cout << endl;
					 cout << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << "\t\t\t  �ɹ��޸ľƵ���Ϊ \" " << ww << " \" �ľƵ�" << endl;
					 cout << "\t\t��---------------------------------------------��" << endl;
					 cout << endl;
					 cout << endl;

					 //������оƵ�
					 /*vector<hotel> allhotels4;
					 int num_of_allhotels4 = pp->get_hotel_num();
					 for (int j = 0; j < num_of_allhotels4; j++)
					 allhotels4.push_back(pp->gethotel(j));
					 */

					 ofstream fp;
					 fp.open("hotel.txt", ios::out);
					 if (!fp)
					 {
						 cout << "�޷��� \" hotel.txt \"  ! " << endl;
					 }
					 fp.close();
					 /*vector <hotel> ::iterator point2;
					 string hh = "hotel.txt";
					 for (point2 = allhotels4.begin(); point2 != allhotels4.end(); point2++)
					 {
					 point2->print_onehotel_tofile(hh);
					 }*/

					 //�ҵ��˸���������ķ�����
					 pp->print_allhotels_tofile();
					 delete pp;
				 }
				 _getch();
				 system("cls");
				 goto loop1;

				 // break;
	}
	case '5':{
				 system("cls");
				 function *d = new function;
				 vector<manager> allmanager3;     //�½������û�
				 int num_of_allmanager3 = d->get_managers_num();
				 for (int j = 0; j < num_of_allmanager3; j++)
					 allmanager3.push_back(d->getmanagers(j));
				 delete d;
				 vector <manager> ::iterator point;
				 cout << endl << endl << "�ʺ�\t����\t�Ա�\t��ϵ��ʽ\t����" << endl;
				 for (point = allmanager3.begin(); point != allmanager3.end(); point++)
				 {
					 if (point->getmanager_id() == ma.getmanager_id())
						 point->print_manager_information_toscreen();
				 }
				 _getch();
				 system("cls");
				 goto loop1;
				
				 //break; 
	}
	case '6':{
				 system("cls");
				 cout << "\t\t\t\t\t����Ա˵����:" << endl;
				 cout <<endl<< "\n\n\n\t\t\t\t��Ҫ������ѯ������ϵ��ɽ����";
				 _getch();
				 system("cls");
				 goto loop1;
				 //break;
	}
	case '7':{
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
				 managermain();
				 //break; 
	}
	case '8':{
				 system("cls");
				 exit_all();
				 //break; 
	}

	default:{
				system("cls");
				flase_input();
				system("cls");
				goto loop1;
				// break;
	}

	}
}

