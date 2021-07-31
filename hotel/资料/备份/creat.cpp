#include<iostream>
#include<fstream>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
using namespace std;
#define MAX_HOTEL_NUM 20

struct RoomType
{
	char room_num[10];
	char room_price[10];
	char room_style[20];
};
struct hotel_node
{
	char hotel_number[10];
	char hotel_name[50];
	char region[20];
	char location[50];
	RoomType allrooms_of_eachhotel[100];
	hotel_node *next;
};
hotel_node *hotels = NULL; 
int  reate_hotel_and_room(const char *f)
{
	int i = 0;
	int out=0;
	FILE *fp = fopen(f, "r");
	if (fp == NULL){}
	else{
		out = 1;
		hotel_node *tail = NULL;

		while (!feof(fp))
		{

			char c[250];
			int line = 1;
			int i = 0;


			fgets(c, 999, fp);
			{
				hotel_node *p = new hotel_node;
				int m = strlen(c);
				int n = 0;
				for (int j = 0; c[i] != ','; i++)
				{
					p->hotel_number[j] = c[i];
					j++;
					n = j;
				}
				p->hotel_number[n] = '\0';
				i++;
				for (int j = 0; c[i] != ','; i++)
				{
					p->hotel_name[j] = c[i];
					j++;
					n = j;
				}
				p->hotel_name[n] = '\0';
				i++;
				for (int j = 0; c[i] != ','; i++)
				{
					p->region[j] = c[i];
					j++;
					n = j;
				}
				p->region[n] = '\0';
				i++;
				for (int j = 0; c[i] != '|'; i++)
				{
					p->location[j] = c[i];
					j++;
					n = j;
				}
				p->location[n] = '\0';
				i++;
				int k = 0;


				while (i< m - 1)
				{
					for (int j = 0; c[i] != ','; i++)
					{
						p->allrooms_of_eachhotel[k].room_num[j] = c[i];
						j++;
						n = j;
					}
					p->allrooms_of_eachhotel[k].room_num[n] = '\0';
					i++;
					for (int j = 0; c[i] != ','&&c[i] != '|'; i++)
					{
						p->allrooms_of_eachhotel[k].room_price[j] = c[i];
						j++;
						n = j;
					}
					p->allrooms_of_eachhotel[k].room_price[n] = '\0';
					i++;
					for (int j = 0; c[i] != ','&&c[i] != '|'; i++)
					{
						p->allrooms_of_eachhotel[k].room_style[j] = c[i];
						j++;
						n = j;
					}
					p->allrooms_of_eachhotel[k].room_style[n] = '\0';
					i++;
					k++;
				}


				line++;
				p->next = NULL;
				if (hotels == NULL)
				{
					hotels = tail = p;
				}
				else
				{
					tail->next = p;
					tail = p;
				}

			}


		}
	}
	
	return out;
}

void output()
{
	for (hotel_node *p = hotels; p->next != NULL; p = p->next)
		cout << p->hotel_name << "|" << p->hotel_number << "|" << p->location << \
		"|" << p->region << "|" << p->allrooms_of_eachhotel->room_num << "|" << p->allrooms_of_eachhotel->room_price << "|" << p->allrooms_of_eachhotel->room_style << "!!!!!!" << endl;
}
void part1()
{
	char inFileName[20];
	//char outFileName[20];
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "\t\t●---------------------------------------------●" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t|\t\t    初始化酒店信息：\t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t|\t\t    请输入文件名：\t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t\t\t ";
	scanf("%19s", inFileName);
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	int i=reate_hotel_and_room(inFileName);
	cout << "\t\t|\t\t\t\t\t\t|" << endl;
	cout << "\t\t|\t\t\t\t\t\t|" << endl;

	if (i == 1){
		cout << "\t\t|\t          导入成功！\t\t\t|" << endl;
		cout << "\t\t|\t\t\t\t\t\t|" << endl;
		cout << "\t\t●---------------------------------------------●" << endl;
	}
	else{
		cout << "\t\t\t ";
		cout << "failed to open \"" << inFileName << "\"!" << endl;
		cout << "\t\t|\t\t\t\t\t\t|" << endl;
		cout << "\t\t|\t\t\t\t\t\t|" << endl;
		cout << "\t\t●---------------------------------------------●" << endl;
	}

	//output();
	//how_many_rooms_in_hotel(A);
	
}




















