#include"user.h"
#include"manager.h"
#include<iostream>
#include<conio.h>
#include<iostream>

using namespace std;

void welcome();
void enter();
void enter_choice();
void  exit_all();
void flase_input();





void play_frist_menu()
{
	system("cls");
	welcome();
	enter();


}
void welcome()
{

	cout << endl;
	//cout << endl;
	
	cout  << "\t\t★---------------------------------------------★"<<endl;
	cout  << "\t\t|\t\t\t\t\t\t|"<<endl;
	cout  << "\t\t|\t\t    \"伊赛尔\"   \t\t\t|"<< endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout  << "\t\t|\t     酒店预定管理系统欢迎您 !\t\t|" << endl;
	cout  << "\t\t|\t\t\t\t\t\t|" << endl;
	cout  << "\t\t★---------------------------------------------★" << endl;
	cout << endl;
	//cout << endl;
	//cout << endl;
	cout << endl;
	cout << "          ***********                                          **" << endl;
	cout << "          ***********                                          **" << endl;
	cout << "          **                                                   **" << endl;
	cout << "          **                            *********      **      **    " << endl;
	cout << "          ***********                   *                      ** " << endl;
	cout << "          ***********     =========     *              **      **" << endl;
	cout << "          **              =========     *********      **      **" << endl;
	cout << "          **                                    *      **      **" << endl;
	cout << "          ***********                           *      **      **********" << endl;
	cout << "          ***********                   *********      **      ********** " << endl;
	cout << endl;
	cout << "                                                              MADE BY <艾山江>";
	_getch();
	enter();
}


///////////////////////////之前的想法，因为时间原因，暂时不做了
//void enter()
//{
//	_getch();
//	cout << endl;
//	cout << endl;
//	cout << endl;
//
//	system("cls");
//	cout << endl;
//	cout << endl;
//	cout << endl;
//	cout << "\t\t\t      >>>选择你想要的功能<<< \t" << endl;
//	cout << "\t\t\t●-----------------------------●" << endl;
//	cout << "\t\t\t\t\t\t\t" << endl;
//	cout << "\t\t\t\t   1.登录 \t\t\t" << endl;
//	cout << "\t\t\t\t\t\t\t" << endl;
//	cout << "\t\t\t\t   2.注册\t\t\t" << endl;
//	cout << "\t\t\t\t\t\t\t" << endl;
//	cout << "\t\t\t\t   3.注销\t\t\t" << endl;
//	cout << "\t\t\t\t\t\t\t" << endl;
//	cout << "\t\t\t\t   4.帮助\t\t\t" << endl;
//	cout << "\t\t\t\t\t\t\t" << endl;
//	cout << "\t\t\t\t   5.反回上一级 \t\t" << endl;
//	cout << "\t\t\t\t\t\t\t" << endl;
//	cout << "\t\t\t\t   6.退出系统 \t\t" << endl;
//	cout << "\t\t\t\t\t\t\t" << endl;
//	cout << "\t\t\t●-----------------------------●" << endl;
//
//
//	switch (_getch())
//	{
//	case '1':{
//				 system("cls");
//				 enter_choice(); break;
//	}
//	case '2':{
//				 system("cls");
//				 // user_list(); break;
//	}
//	case'3':{
//				system("cls");
//				//help_list(); break;
//	}
//
//	case '4':{
//				 system("cls");
//				 exit_all(); break; }
//
//	default:{
//				system("cls");
//				flase_input();
//				system("cls");
//				 break; }
//
//	}
//}

void enter()
	{
		cout << endl;
		cout << endl;
		cout << endl;

		//_getch();
		system("cls");
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t      >>>选择你想要的角色<<< \t" << endl;
		cout << "\t\t\t●-----------------------------●" << endl;
		cout << "\t\t\t\t\t\t\t" << endl;
		cout << "\t\t\t\t   1.管理员\t\t" << endl;
		cout << "\t\t\t\t\t\t\t" << endl;
		cout << "\t\t\t\t   2.用户\t\t\t" << endl;
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
					 system("cls");
					 managermain();
					// manager_login();
					 // break; 
		}
		case '2':{
					 system("cls");
					 usermain();
					// break;
		}
		case'3':{
					system("cls");
					cout << "\t\t\t\t\t程序介绍:" << endl;
					cout << endl << "\n\n\n\t本程序为现代酒店信息管理系统。" << endl;
					cout<<"可为管理员提供管理酒店功能";
					_getch();
					system("cls");
					//help_list(); break;
		}

		case '4':{
					 system("cls");
					 welcome();
					 system("cls");
					 enter();
		}
		case '5':{
					 system("cls");
					 exit_all();
					 //break;
		}

		default:{
					system("cls");
					flase_input();
					system("cls");
					enter();
					//break;
		}

		}
	}
void  exit_all()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t|\t\t    谢谢使用！\t\t\t|" << endl;
	cout << "\t\t|\t          欢迎下次再来\t\t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t★---------------------------------------------★" << endl; 
	cout << endl;
	cout << endl;
	cout << endl;
	_getch();
	exit(-1);
}
void flase_input()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t|\t\t输入错误!\t请重试!\t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t★---------------------------------------------★" << endl;
	_getch();
}





