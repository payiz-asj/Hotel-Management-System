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


//主函数
void managermain()
{

	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t >>> 欢迎来到管理员录页面！<<< \t" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   1.登录\t\t" << endl;
	//cout << "\t\t\t\t\t\t\t" << endl;
	//cout << "\t\t\t\t   2.游客登录\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   2.帮助\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   3.返回上一级\t\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t\t   4.退出系统\t\t" << endl;
	cout << "\t\t\t\t\t\t\t" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;
	switch (_getch())
	{
	case '1':{
				 zhengshi2();
				 // break; 
	}
	case'2':{
				system("cls");
				cout << "\t\t\t\t\t管理员说明书:" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
				cout << "登陆:指凭管理员账号、密码登录，输入错误次数超过有三次即自动退出登录。" << endl;
				cout <<  endl << endl;
				cout << "登陆成功方可进行、查看订单、查看个人信息等功能，" << endl;
				cout << "而游客只能使用查询功能，也就是随便逛逛  ^o^  " << endl;
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

//登陆函数
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
		cout << "预设管理员帐号: 999" << endl;
		cout << "密码: 999";
		cout << endl;
		cout << endl;
		cout << endl;
		printf("请输入管理员帐号：");
		//scanf_s("%10s", number);
		cin >> manager_id_number;
		printf("请输入密码：");
		//scanf_s("%6s", passward);
		cin >> manager_password;


		function *SS = new function;

		vector<manager> allmanager2;   //输出所有用户，用户登录时用
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
			cout << "\t\t★---------------------------------------------★" << endl;
			//cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
			cout << "\t\t|\t          管理员名错误!!!\t\t\t|" << endl;
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
			if (uuus.getmanager_secret() != manager_password)
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

		if (uuus.getmanager_id() !=""&&uuus.getmanager_secret() == manager_password)
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
			cout << "\t\t\t   尊敬的管理员：" << uuus.getmanager_name()<< " \t" << endl;
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
			cout << "\t\t★---------------------------------------------★" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			//cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
			cout << "\t\t|\t请重新登录，您还有" << n << "次机会" << endl;
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
			cout << "\t\t|\t\t非注册管理员无法登录\t\t|" << endl;
			cout << "\t\t|\t\t\t\t\t\t|" << endl;
			cout << "\t\t|   请使用游客身份或预设管理员帐号密码登录！谢谢! |" << endl;
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

//确认登陆
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
//相关功能总函数
void  managerfuctions(manager ma)
{
	
	loop1:
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t\t      >>> 管理员 ！<<< \t" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  1.导入酒店信息   \t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  2.增加酒店\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  3.删除酒店\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  4.修改酒店\t\t|" << endl;
	//cout << "\t\t\t|\t\t\t\t|" << endl;
	//cout << "\t\t\t|\t  6.查看某个用户订单\t|" << endl;
	//cout << "\t\t\t|\t\t\t\t|" << endl;
	//cout << "\t\t\t|\t  6.查看所有订单\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  5.查看个人信息\t|" << endl;   //存到别的地方/别的文件,再分酒店信息和订单信息
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  6.阅读管理员说明书\t|" << endl;
 	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  7.退出登录 \t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t  8.直接退出系统\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t|\t\t\t\t|" << endl;
	cout << "\t\t\t●-----------------------------●" << endl;

	switch (_getch())
	{
	case '1':{
				 system("cls");
				 string a;
				 int n;
				 function *p = new function;
				 cout << endl << endl;
				 
				 cout << "\t\t★---------------------------------------------★" << endl;
				 cout << "\t\t\t    从文件中导入酒店信息： " << endl << endl;
				 cout << "\t\t\t输入你目标文件名：(预设文件为 \" 导入信息.txt \" " << endl << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				
				
				 cin >> a;
				 n=p->download_hotel_info(a);
				 delete p;
				 if (n == 0)
				 {
					 cout << endl << endl;
					//cout << "两个文件中至少有一个打开失败!  导入失败！" << endl;
					 cout << "文件打开失败!  导入失败！" << endl;
					 _getch();
					 system("cls");
					 goto loop1;
				 }
				 else if (n == 1)
				 {
					 cout << endl << endl;
					 
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t                  导入成功！  " << endl << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 
					 _getch();
					 system("cls");
					 goto loop1;
				 }

	}
	case '2':{
				 system("cls");
				 cout << "增加酒店";
				 string aa,bb;
				 function *pp = new function;
				 cout << endl << endl;
			
				// cout << "编号,星级,名称,城市,具体地点|房号,价格,类型|房号,价格,类型|房号,价格,类型|" << endl;
				// cout << "0000,3,如家酒店,南京,火车站旁|101,200,大床房|201,230,标准间|301,400,豪华房|302,400,豪华房|" <<endl;
				// cout << "请严格按照上述格式(只支持英文半角符号,且无空格)，输入酒店信息及该酒店拥有的房间信息：" << endl;
				 cout << endl;
				 cout << "\t\t★---------------------------------------------★" << endl<<endl;
				 cout << "\t\t\t               添加酒店实例： " << endl << endl;
				 cout << "\t\t\t     编号   星级   名称      城市   具体地点" << endl;
				 cout << "\t\t\t     0000    3   如家酒店    南京   火车站旁" << endl << endl;
				 cout << "\t\t★---------------------------------------------★" << endl<<endl;
			
				 cout << "请输入酒店编号：";
				 cin >> bb;
				 aa+=bb;
				 aa.push_back(',');
				 cout << "请输入酒店等级（1-7级）：";
				 string nn;
				 cin >> nn;
				 while (nn > "7" || nn < "1")
				 {
					 cout << "酒店等级只能是1-7 ，请重新输入：";
					 cin >> nn;
				 }
				 aa += nn;
				 aa.push_back(',');
				 cout << "请输入酒店名称：";
				 cin >> bb;
				 aa += bb;
				 aa.push_back(',');
				 cout << "请输入酒店所在城市：";
				 cin >> bb;
				 aa += bb;
				 aa.push_back(',');
				 cout << "请输入酒店具体地址：";
				 cin >> bb;
				 aa += bb;
				 aa.push_back('|');

				 cout << endl;
				 cout << "\t\t★---------------------------------------------★" << endl << endl;
				 cout << "\t\t\t            为该酒店添加房间： " << endl << endl;
				 cout << "\t例如：" << endl;
				 cout << "\t\t     房间号   房间价格   房间类型" << endl;
				 cout << "\t\t      201        230       标准间 " << endl << endl;
				 cout << "\t\t★---------------------------------------------★" << endl << endl;
				 
				 cout << "其中，房间类型有:" << endl << "   单人间，双人间，三人间，大床房，标准间, 豪华房" << endl;
				 cout<<"   商务间，总统套房, 雅致房, 高级房，家庭式（带婴儿床), 自定义房间类型"<<endl<<endl<<endl;
	 loop2:
				cout << "请输入房间号：";
				cin >> bb;
				aa += bb;
				aa.push_back(',');

				cout << "请输入房间价格：";
				cin >> bb;
				aa += bb;
				aa.push_back(',');

				cout << "请输入房间类型：";
				cin >> bb;
				aa += bb;
				aa.push_back('|');
				cout << endl;
				cout << "\t\t★---------------------------------------------★" << endl;
				cout << "\t\t\t    继续添加房间  请按  \" 9 \"  " << endl << endl;
				cout << "\t\t\t    不操作    请按任意键继续：" << endl << endl;
				cout << "\t\t★---------------------------------------------★" << endl<<endl;
			
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
				//输入结束



				//判断该酒店是否已经存在
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
						 cout << endl << endl << "该酒店已存在！ 无法添加！" <<endl<<endl;
						 _getch();
						 system("cls");
						 goto loop1;
					 }
				 }
				 
				 //增加酒店
		

				 //存放该酒店
			
				 ofstream fp;
				 fp.open("hotel.txt", ios::app);
				 if (!fp)
				 {
					 cout << "无法打开 \" hotel.txt \"  ! " << endl;
				 }
				 fp << aa;
				 
				 fp.close();
				 cout << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				 cout << "\t\t\t    您的本次添加了：  " << endl << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				 cout << "编号,星级,名称,城市,具体地点|房号,价格,类型|房号,价格,类型|房号,价格,类型|……" << endl;
				 cout << aa << endl << endl;
				 _getch();
				 system("cls");
				 cout << endl;
				 cout << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				 cout << "\t\t\t  成功添加酒店编号为 \" " << ww << " \" 的酒店" << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				 _getch();
				 system("cls");
				 goto loop1;

				 break; 
	}

	case '3':{
				 system("cls");
				 cout << "删除酒店" << endl<<endl<<endl;
				 cout << "目前系统里有以下酒店：" << endl << endl;
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
				 cout << "\t\t★---------------------------------------------★" << endl;
				 cout << "\t\t\t    删除酒店  请按  \" 9 \"  " << endl<<endl;
				 cout << "\t\t\t    不操作    请按任意键继续：" << endl << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				 // cout << "  删除酒店  请按  \" 9 \"  " << endl;
				 //cout << endl;
				 //cout << "  不操作    请按任意键继续：" << endl << endl;

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
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t  尝试次数太多啦！！！" << endl<<endl<<endl;
					 cout << "\t\t\t  删除服务将停止！" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					
					 //_getch();
					 goto loop55;//在最后面
				 }
				 cout << "输入您要删除的酒店编号：";
				 ttt++;
				 cin >> ww;
				 //输入结束
				 int aha;
				aha = pp->delete_hotel(ww);				
				 if (aha == 0)
				 {
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t  该酒店不存在！！   酒店删除失败！" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout <<endl << "请重新";
					 goto loop88;
				 }
				 else if (aha == 2)
				 {
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t  该酒店有订单！！   酒店删除失败！" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << endl << "请重新";
					 //cout << endl << "该酒店有订单！！   酒店删除失败！" << endl << "请重新";
					 goto loop88;
				 }
				 else if (aha == 1)
				 {
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t            该酒店成功被删除！" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					// cout << endl << "该酒店成功被删除！" << endl;
					 system("cls");
					 cout << endl;
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t  成功删除酒店编号为 \" " << ww << " \" 的酒店" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << endl;
					 cout << endl;

					 //存放所有酒店
					 /*vector<hotel> allhotels4;
					 int num_of_allhotels4 = pp->get_hotel_num();
					 for (int j = 0; j < num_of_allhotels4; j++)
						 allhotels4.push_back(pp->gethotel(j));
					*/

					 ofstream fp;
					 fp.open("hotel.txt", ios::out);
					 if (!fp)
					 {
						 cout << "无法打开 \" hotel.txt \"  ! " << endl;
					 }
					 fp.close();
					 /*vector <hotel> ::iterator point2;
					 string hh = "hotel.txt";
					 for (point2 = allhotels4.begin(); point2 != allhotels4.end(); point2++)
					 {
						 point2->print_onehotel_tofile(hh);
					 }*/

					 //找到了个更加方便的方法：
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
				 cout << "修改酒店" << endl << endl << endl;
				 cout << "目前系统里有以下酒店：" << endl << endl;
				 string ww;
				 function *pp = new function;
				 vector<hotel> allhotels4;
				 int num_of_allhotels4 = pp->get_hotel_num();
				 for (int j = 0; j < num_of_allhotels4; j++)
					 allhotels4.push_back(pp->gethotel(j));
				 vector <hotel> ::iterator point2;
				 cout << "编号\t星级\t名称\t城市\t具体地点" << endl;
				 for (point2 = allhotels4.begin(); point2 != allhotels4.end(); point2++)
				 {
					 point2->print_onehotel_toscreen();
				 }


				 cout << endl;
				 cout << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				 cout << "\t\t\t    修改酒店  请按  \" 9 \"  " << endl << endl;
				 cout << "\t\t\t    不操作    请按任意键继续：" << endl << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
				 

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
				 cout << "输入您要修改的酒店编号：";
				 cin >> ww;
				 //输入结束
				 int aha;
				 aha = pp->change_hotel(ww);
				 if (aha == 0)
				 {
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t  该酒店不存在！！   酒店修改失败！" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << endl << "请重新";
					 goto loop99;
				 }
				 else if (aha == 2)
				 {
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t  该酒店有订单！！   酒店修改失败！" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << endl << "请重新";
				
					 goto loop99;
				 }
				 else if (aha == 1)
				 {
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t            该酒店成功被修改！" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					
					 system("cls");
					 cout << endl;
					 cout << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << "\t\t\t  成功修改酒店编号为 \" " << ww << " \" 的酒店" << endl;
					 cout << "\t\t★---------------------------------------------★" << endl;
					 cout << endl;
					 cout << endl;

					 //存放所有酒店
					 /*vector<hotel> allhotels4;
					 int num_of_allhotels4 = pp->get_hotel_num();
					 for (int j = 0; j < num_of_allhotels4; j++)
					 allhotels4.push_back(pp->gethotel(j));
					 */

					 ofstream fp;
					 fp.open("hotel.txt", ios::out);
					 if (!fp)
					 {
						 cout << "无法打开 \" hotel.txt \"  ! " << endl;
					 }
					 fp.close();
					 /*vector <hotel> ::iterator point2;
					 string hh = "hotel.txt";
					 for (point2 = allhotels4.begin(); point2 != allhotels4.end(); point2++)
					 {
					 point2->print_onehotel_tofile(hh);
					 }*/

					 //找到了个更见不变的方法：
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
				 vector<manager> allmanager3;     //新建所有用户
				 int num_of_allmanager3 = d->get_managers_num();
				 for (int j = 0; j < num_of_allmanager3; j++)
					 allmanager3.push_back(d->getmanagers(j));
				 delete d;
				 vector <manager> ::iterator point;
				 cout << endl << endl << "帐号\t姓名\t性别\t联系方式\t密码" << endl;
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
				 cout << "\t\t\t\t\t管理员说明书:" << endl;
				 cout <<endl<< "\n\n\n\t\t\t\t需要其他咨询，请联系艾山江！";
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
				 cout << "\t\t★---------------------------------------------★" << endl;
				 cout << "\t\t|\t\t\t\t\t\t|" << endl;
				 cout << "\t\t|\t\t成功退出登录！ \t\t\t|" << endl;
				 cout << "\t\t|\t\t\t\t\t\t|" << endl;
				 cout << "\t\t|\t\t感谢使用！ \t\t\t|" << endl;
				 cout << "\t\t|\t\t\t\t\t\t|" << endl;
				 cout << "\t\t★---------------------------------------------★" << endl;
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

