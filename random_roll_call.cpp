#include <iostream>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct student {
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
void read_save1();
void read_save2();
void read_save3();
void read_save4();
void read_save5();
void final_result();
void address_E();
void resorting();
void pastp_add(int x, int y);


int main()
{
	read_save1();
	address_E();
	read_save2();
	address_E();
	read_save3();
	address_E();
	read_save4();
	address_E();
	read_save5();
	address_E();
	final_result();
}

void pastp_add(int x, int y)
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
	}
}
void address_E()
{
	sort(stu, stu + 90, cmp);
	//�������
	for (int i = 0; i < 20; i++)//����ÿһ�ſε�20�ο�
	{
		for (int j = 0; j < 5; j++)//7��
		{
			if (stu[j].here[i] == 0)//û��
			{
				numerator++;
				stu[j].pastp += 0.5;
			}
		}
		int temp = rand() % 4;//0-3����
		if (temp == 2)//����2����
		{
			int num = (rand() % (7 - 5) + 6);//�ڳ���ǰ�������������ǰ����һ��
			pastp_add(num, i);
			denominator += 1;
		}
		else if (temp == 3)//����3����
		{
		
			int num1 = (rand() % (9 - 5) + 6);//�ڳ���ǰ�������������ǰ4������
			int num2 = (rand() % (9 - 5) + 6);
			while (num2 == num1)
			{
				num2 = (rand() % (9 - 5) + 6);
				if (num2 != num1) break;
			}
			pastp_add(num1, i);
			pastp_add(num2, i);
			denominator += 2;
		}
	}
	//�����ĸ
	denominator += 100;//ǰ5-8��ȡ��5��
}

void read_save1() //�����һ�ſε���������
{
	ifstream infile;
	infile.open("output1.txt");      //ע���ļ���·��  
	for (int i = 0; i < 90; i++)
	{
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
