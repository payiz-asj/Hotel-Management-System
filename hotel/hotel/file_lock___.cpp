#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<stdlib.h>
using namespace std;


void dofile(char *in_fname, char *pwd, char *out_fname);/*���ļ����м��ܵľ��庯��*/

void do_it(int argc, char *argv[])/*����main()�����������в���*/
{
	char in_fname[30];/*�û������Ҫ���ܵ��ļ���*/
	char out_fname[30];
	char pwd[8];/*������������*/

	if (argc != 4)
	{/*�ݴ���*/
		cout<<endl<<"\n����������ļ�����";
		gets(in_fname);/*�õ�Ҫ���ܵ��ļ���*/

		cout<<endl<<"����:";
		gets(pwd);/*�õ�����*/

		cout<<endl<<"���� \\ ���ܺ���ļ���:";
		gets(out_fname);/*�õ����ܺ���Ҫ���ļ���*/


		dofile(in_fname, pwd, out_fname);
		cout << endl << "���� \\ ���ܳɹ���" << endl;
	}
	else
	{/*��������в�����ȷ,��ֱ�����г���*/
		strcpy(in_fname, argv[1]);
		strcpy(pwd, argv[2]);
		strcpy(out_fname, argv[3]);
		dofile(in_fname, pwd, out_fname);
		cout << endl << "���� \\ ���ܳɹ���" << endl;
	}

}


/*�����Ӻ�����ʼ*/
void dofile(char *in_fname, char *pwd, char *out_file)
{
	FILE *fp1, *fp2;
	register char ch;
	int j = 0;
	int j0 = 0;

	fp1 = fopen(in_fname, "rb");
	if (fp1 == NULL){
		printf("cannot open in-file./n");
		exit(1);/*������ܴ�Ҫ���ܵ��ļ�,���˳�����*/
	}
	fp2 = fopen(out_file, "wb");
	if (fp2 == NULL){
		printf("cannot open or create out-file./n");
		exit(1);/*������ܽ������ܺ���ļ�,���˳�*/
	}
	while (pwd[++j0]);
	ch = fgetc(fp1);

	/*�����㷨��ʼ*/
	while (!feof(fp1)){
		fputc(ch^pwd[j >= j0 ? j = 0 : j++], fp2);/*����д��fp2�ļ�*/
		ch = fgetc(fp1);
	}
	fclose(fp1);/*�ر�Դ�ļ�*/
	fclose(fp2);/*�ر�Ŀ���ļ�*/
}

/*�������*/
