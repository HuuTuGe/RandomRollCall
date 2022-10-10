#include <iostream>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct student {
	int number=0;//���� 
	double grade = 0;//����
	double pastp = 0;//ȱ��ϵ��
	double nownumber = 0;//����ȱ�ڴ���
	int here[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };  //��û��
}stu[90];
bool cmp(student x, student y)
{
	if (x.pastp == y.pastp) return x.grade < y.grade;
	else return x.pastp > y.pastp;
}

double E = 0, numerator = 0, denominator = 0;
string s1 = "�������", s2 = "���ݿ�ϵͳԭ��", s3 = "���������ϵͳ", s4 = "�����ͼ��ѧ", s5 = "��ѧӦ��д��";
void read_save1();
void read_save2();
void read_save3();
void read_save4();
void read_save5();
void final_result();
void address_E(string s);
int pastp_add(int x, int y);

int main()
{
	read_save1();
	address_E(s1);
	read_save2();
	address_E(s2);
	read_save3();
	address_E(s3);
	read_save4();
	address_E(s4);
	read_save5();
	address_E(s5);
	final_result();
}

int pastp_add(int x, int y)
{
	if (stu[x].here[y] == 0)//û�� 
	{
		stu[x].nownumber++;//����ȱ�ڴ�������1
		if (stu[x].nownumber == 1)
		{
			stu[x].pastp += 0.05; //ȱ��һ�� + 0.05 ,�ڶ��� + 0.5 ,������ + 0.5�����Ա�֤ż��һ��ȱ�β��ᱻһֱ���������γ�ȡ��������
		}
		else if (stu[x].nownumber > 1)
		{
			stu[x].pastp += 0.5;
		}
		numerator++;
			cout<<"ȱ��"<<" "; 
	     return 1;
	}
	else
	return 0;
}

void address_E(string s)
{
	int m,m1,m2;
	cout << s << "�ĳ�㷽������:" << endl; 
	//�������
	for (int i = 0; i < 20; i++)//����ÿһ�ſε�20�ο�
	{
		sort(stu, stu + 90, cmp);
		cout <<"��"<< i+1 << "�ογ���ͬѧ����Ϊ��" ;
		for (int j = 0; j < 6; j++)//6��
		{
			cout << stu[j].number<<" " ;
			if (stu[j].here[i] == 0)//û��
			{
				numerator++;
				cout<<"ȱ��"<<" "; 
				stu[j].pastp += 0.5;
			}
			else
			cout<<"����"<<" "; 
		}
		int temp = rand() % 4;//0-3����
	    if (temp == 3)//����3����
		{
			int num = (rand() % (7 - 5) + 6);//�ڳ���ǰ�������������ǰ����һ��
			cout << stu[num].number << " ";
			m=pastp_add(num, i);
			if(m==0)
			cout<<"����"<<" "; 
			denominator += 1;
		}
		cout << endl;
	}
	//�����ĸ
	denominator += 120;//ǰ5-8��ȡ��6��
    cout << endl; 
}

void read_save1() //�����һ�ſε���������
{
	ifstream infile;
	infile.open("output1.txt");      //ע���ļ���·��  
	for (int i = 0; i < 90; i++)
	{
		infile >> stu[i].number;
		infile >> stu[i].grade;
		infile >> stu[i].pastp;
		for (int j = 0; j < 20; j++)
		{
			infile >> stu[i].here[j];
		}
	}
	infile.close();
}

void read_save2() //����ڶ��ſε���������
{
	ifstream infile;
	infile.open("output2.txt");      //ע���ļ���·��  
	for (int i = 0; i < 90; i++)
	{
		infile >> stu[i].number;
		infile >> stu[i].grade;
		infile >> stu[i].pastp;
		for (int j = 0; j < 20; j++)
		{
			infile >> stu[i].here[j];
		}
	}
	infile.close();
}

void read_save3()//��������ſε���������
{
	ifstream infile;
	infile.open("output3.txt");      //ע���ļ���·��  
	for (int i = 0; i < 90; i++)
	{
		infile >> stu[i].number;
		infile >> stu[i].grade;
		infile >> stu[i].pastp;
		for (int j = 0; j < 20; j++)
		{
			infile >> stu[i].here[j];
		}
	}
	infile.close();
}
void read_save4()//��������ſε���������
{
	ifstream infile;
	infile.open("output4.txt");      //ע���ļ���·��  
	for (int i = 0; i < 90; i++)
	{
		infile >> stu[i].number;
		infile >> stu[i].grade;
		infile >> stu[i].pastp;
		for (int j = 0; j < 20; j++)
		{
			infile >> stu[i].here[j];
		}
	}
	infile.close();
}

void read_save5()//��������ſε���������
{
	ifstream infile;
	infile.open("output5.txt");      //ע���ļ���·��  
	for (int i = 0; i < 90; i++)
	{
		infile >> stu[i].number;
		infile >> stu[i].grade;
		infile >> stu[i].pastp;
		for (int j = 0; j < 20; j++)
		{
			infile >> stu[i].here[j];
		}
	}
	infile.close();
}

void final_result()
{
	E = numerator / denominator;
	cout << E << endl;
}
