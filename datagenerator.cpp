#include<iostream>
#include<time.h>
#include<fstream>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<windows.h>
using namespace std;
struct student{
	public:
	int number; 
	double grade=0;    //绩点 
	double pastp=0;    //缺勤率 
	int here[20]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};//到没到
}stu[90];
bool cmp(student x,student y)
{
	return x.grade < y.grade;
}
bool cmp2(student x,student y)
{
	return x.pastp > y.pastp;
}
void create_txt1();
void create_txt2();
void create_txt3();
void create_txt4();
void create_txt5();
void getnumber()    //学号生成 
{
	for(int i=0;i<=89;i++)
	{
		stu[i].number=i;
	}
}


int main()
{
	for (int k = 1; k < 6; k++)
	{
		int a = 0;
		int b = 0, c = 0;
		int count = 0, count2 = 0;
		int flag[90] = { 0 }, flag2[20] = { 0 };
		srand((int)time(0));
		getnumber();
		for (int i = 0; i <= 89; i++)
		{
			stu[i].grade = rand() % 3 + 1;
			stu[i].grade += (rand() % 100) * 0.01;    //产生随机数绩点，正态分布 
		}
		sort(stu, stu + 90, cmp);   //绩点从小到大排了 
		for (int j = 0; j <= 89; j++)
		{
			if (0 <= j && j <= 19)
			{
				stu[j].pastp = (rand() % 51) * 0.01;    //按照绩点排名分段抽 过去缺勤概率 
			}
			if (20 <= j && j <= 34)
			{
				stu[j].pastp = (rand() % 26) * 0.01;
			}
			if (35 <= j && j <= 54)
			{
				stu[j].pastp = (rand() % 11) * 0.01;
			} if (55 <= j && j <= 89)
			{
				stu[j].pastp = 0;
			}
		}
		sort(stu, stu + 90, cmp2);   //按过去概率从大到小排了 
		a = rand() % 4 + 5;           //a个人是那些毒瘤 
		for (int i = 0; i <= a - 1; i++)
		{
			count2 = 0;
			while (1)
			{
				if (count2 == 16)
					break;
				int w;
				w = rand() % 20;
				if (flag2[w] != 1)
				{
					count2++;
					flag2[w]++;
					stu[i].here[w] = 0;    //给他们随机挑那80% 到底是哪16天 
				}
			}
			for (int j = 0; j < 20; j++)
			{
				flag2[j] = 0;
			}
		}
		for (int i = 0; i <= 19; i++)   //加权生成各种原因缺勤三人 
		{
			count = 0;
			b = rand() % 4;
			while (1)
			{
				if (count == b)
					break;
				c = rand() % 100 + 1;
				if (1 <= c && c <= 39)    //利用两个rand产生不同范围不同概率选到这0-3人 
				{
					int t;
					t = rand() % ((89 - a) / 8) + a;
					if (flag[t] != 1)
					{
						flag[t]++;
						count++;
						stu[t].here[i] = 0;
					}
				}
				if (40 <= c && c <= 74)
				{
					int t;
					t = rand() % ((89 - a) / 2) + (a + (89 - a) / 8);
					if (flag[t] != 1)
					{
						flag[t]++;
						count++;
						stu[t].here[i] = 0;
					}

				}if (75 <= c && c <= 99)
				{
					int t;
					t = rand() % ((89 - a) / 8 * 3) + (a + (89 - a) / 8 * 5);
					if (flag[t] != 1)
					{
						flag[t]++;
						count++;
						stu[t].here[i] = 0;
					}

				}
				for (int j = 0; j < 20; j++)  //清空，下次再使用 
				{
					flag[j] = 0;
				}
			}
		}
		for(int times=0;times<=89;times++)   //随机打乱 
		{
			student temp;
			int t1=rand()%90;
			int t2=rand()%90;
			if(t1!=t2)
			{
				temp=stu[t1];
				stu[t1]=stu[t2];
				stu[t2]=temp;
				
				
			}
			
		}
		if (k == 1) create_txt1();
		else if (k == 2) create_txt2();
		else if (k == 3) create_txt3();
		else if (k == 4) create_txt4();
		else create_txt5();
		Sleep(1000);     //使得每次生成都不一样 
	}
}


void create_txt1() {
	ofstream outfile("output1.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	for (int i = 0; i <= 89; i++)
	{
	    	outfile << stu[i].number<<" "<< stu[i].grade << " " << stu[i].pastp << " ";
		for (int j = 0; j <= 19; j++)
		{
			outfile << stu[i].here[j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}

void create_txt2() {
	ofstream outfile("output2.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	for (int i = 0; i <= 89; i++)
	{
	   	outfile << stu[i].number<<" "<< stu[i].grade << " " << stu[i].pastp << " ";
		for (int j = 0; j <= 19; j++)
		{
			outfile << stu[i].here[j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}

void create_txt3() {
	ofstream outfile("output3.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	for (int i = 0; i <= 89; i++)
	{
		outfile << stu[i].number<<" "<< stu[i].grade << " " << stu[i].pastp << " ";
		for (int j = 0; j <= 19; j++)
		{
			outfile << stu[i].here[j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}

void create_txt4() {
	ofstream outfile("output4.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	
	for (int i = 0; i <= 89; i++)
	{
	     	outfile << stu[i].number<<" "<< stu[i].grade << " " << stu[i].pastp << " ";
		for (int j = 0; j <= 19; j++)
		{
			outfile << stu[i].here[j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}


void create_txt5() {
	ofstream outfile("output5.txt", ios::out);
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	for (int i = 0; i <= 89; i++)
	{
		outfile << stu[i].number<<" "<< stu[i].grade << " " << stu[i].pastp << " ";
		for (int j = 0; j <= 19; j++)
		{
			outfile << stu[i].here[j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}
