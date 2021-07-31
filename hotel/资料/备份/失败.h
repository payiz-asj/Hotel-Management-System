#include<iostream>
#include<fstream>
#include<stdio.h>
#include<cstring>
using namespace std;
#define MAX_HOTEL_NUM 20

struct RoomType
{
	int room_num;
	int room_price;
	char room_styl[20];
};

class File
{
	char inFileName[20] = { '\0' };
	char outFileName[20] = { '\0' };
	room_list A;
public:
	File()
	{
		strcpy(inFileName, "hotel_soure.txt");
		strcpy(outFileName, "save_list.txt");
	}
	void reate_hotel_and_room(File f, room_list A);

};
class room_list
{
	RoomType *rooms[20];
	int room_count;
	File f;
public:
	

};


struct hotel_node
{
	int hotel_number;
	char hotel_name[50];
	char region[20];
	char location[50];
	hotel_node *next;

};
class hotel_list
{
	hotel_node *hotels;
	int hotel_count;
public:
	hotel_list()
	{

	}
	void read_hotel_sourse();
};
class manager
{
	hotel_list *h;
};



void File:: reate_hotel_and_room(File f,room_list A)
{
	int i = 0;
	FILE *fp = fopen(f.inFileName, "r");
	if (fp == NULL){
		cout << "failed to open \"price_list.txt\"!";
		exit(-1);
	}
	
	while (!feof(fp))
	{
		char ch;
		char c[100];
		do
		{
			fscanf(fp, "%9s", c);
			for (int i = 0; i < n; i++)
			{
				if (strcmp(str[i].name, c) == 0)
				{
					route *p = new route;
					p->data = &str[i];
					p->next = NULL;
					if (route1 == NULL) {
						route1 = p;
						tail = p;
					}
					else
					{
						tail->next = p;
						tail = p;
					}
				}
			}
		} while (ch = fgetc(fp) != '\n');

	}
	return i;
}