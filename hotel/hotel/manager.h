#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h> 
using namespace std;
 

#ifndef MMMM
#define MMMM


class manager
{
	string manager_id;
	string manager_name;
	string manager_sex;
	string manager_phonenumber;
	string secret;
public:
	manager(){}
	void setmanager_id(char c){ manager_id.push_back(c); }
	void setmanager_name(char c){ manager_name.push_back(c); }
	void setmanager_sex(char c){ manager_sex.push_back(c); }
	void setmanager_phonenumber(char c){ manager_phonenumber.push_back(c); }
	void setsecret(char c){ secret.push_back(c); }
	string getmanager_id(){ return manager_id; }
	string getmanager_secret(){ return secret; }
	string getmanager_name(){ return manager_name; }

	void print_manager_information_toscreen()
	{
		cout << manager_id << "   " << manager_name << "   " << manager_sex << "   " << manager_phonenumber << "  |  " << secret << "  |  " << endl;
	}


};
#endif 

void managermain();