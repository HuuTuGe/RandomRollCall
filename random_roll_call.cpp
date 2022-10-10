#include <iostream>
#include <time.h>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

struct student {
	int number=0;//号码 
	double grade = 0;//绩点
	double pastp = 0;//缺勤系数
	double nownumber = 0;//现在缺勤次数
	int here[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };  //到没到
}stu[90];
bool cmp(student x, student y)
{
	if (x.pastp == y.pastp) return x.grade < y.grade;
	else return x.pastp > y.pastp;
}

double E = 0, numerator = 0, denominator = 0;
string s1 = "软件工程", s2 = "数据库系统原理", s3 = "计算机操作系统", s4 = "计算机图形学", s5 = "大学应用写作";
void read_save1();
void read_save2();
void read_save3();
void read_save4();
void read_save5();
void final_result();
void address_E(string s);
void pastp_add(int x, int y);


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

void pastp_add(int x, int y)
{
	if (stu[x].here[y] == 0)//没到 
	{
		stu[x].nownumber++;//现在缺勤次数增加1
		if (stu[x].nownumber == 1)
		{
			stu[x].pastp += 0.05; //缺第一次 + 0.05 ,第二次 + 0.5 ,第三次 + 0.5，用以保证偶尔一次缺课不会被一直点名，三次抽取概率增加
		}
		else if (stu[x].nownumber > 1)
		{
			stu[x].pastp += 0.5;
		}
		numerator++;
	}
}
void address_E(string s)
{
	cout << s << "的抽点方案如下:" << endl;
	sort(stu, stu + 90, cmp);
	//处理分子
	for (int i = 0; i < 20; i++)//对于每一门课的20次课
	{
		cout <<"第"<< i+1 << "次课抽点的同学号码为：" ;
		for (int j = 0; j < 5; j++)//7个
		{
			cout << stu[j].number << " ";
			if (stu[j].here[i] == 0)//没到
			{
				numerator++;
				stu[j].pastp += 0.5;
			}
		}
		int temp = rand() % 4;//0-3个人
		if (temp == 2)//点了2个人
		{
			int num = (rand() % (7 - 5) + 6);//在除了前几个人里的排名前二抽一个
			cout << stu[num].number << " ";
			pastp_add(num, i);
			denominator += 1;
		}
		else if (temp == 3)//点了3个人
		{
			int num1 = (rand() % (9 - 5) + 6);//在除了前几个人里的排名前4抽两个
			int num2 = (rand() % (9 - 5) + 6);
			while (num2 == num1)
			{
				num2 = (rand() % (9 - 5) + 6);
				if (num2 != num1) break;
			}
			cout << stu[num1].number << " ";
			cout << stu[num2].number << " ";
			pastp_add(num1, i);
			pastp_add(num2, i);
			denominator += 2;
		}
		cout << endl;
	}
	//处理分母
	denominator += 100;//前5-8个取了5个
	cout << endl;
}

void read_save1() //输入第一门课的所有数据
{
	ifstream infile;
	infile.open("output1.txt");      //注意文件的路径  
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

void read_save2() //输入第二门课的所有数据
{
	ifstream infile;
	infile.open("output2.txt");      //注意文件的路径  
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

void read_save3()//输入第三门课的所有数据
{
	ifstream infile;
	infile.open("output3.txt");      //注意文件的路径  
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
void read_save4()//输入第四门课的所有数据
{
	ifstream infile;
	infile.open("output4.txt");      //注意文件的路径  
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

void read_save5()//输入第五门课的所有数据
{
	ifstream infile;
	infile.open("output5.txt");      //注意文件的路径  
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
	cout << "E的值是：" << E << endl;
}
