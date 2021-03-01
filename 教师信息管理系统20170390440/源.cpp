#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<iostream>
#include<fstream>
using namespace std;
#define LEN sizeof(teacher)//宏定义结构体字节数
#define LIST_INIT_SIZE 100// 线性表存储空间的初始分配量
#define LISTINCREMENT 10// 线性表存储空间的分配增量 
 class teacher //定义结构体
{   public:
	int teacher_number;//教师号
	int age;//年龄 
	int salay;//工资 
	int telephone;//电话 
	char name[30];//姓名
	char sex[10];//性别
	char education_background[50];//学历
	char address[50];//地址 
	char job_title[20];//职称 
	teacher *next;//指向下一个结点 
	int createteacher();
	void deleteteacher();
	int readteacher();
	void sortteacher1();
	void sortteacher2();
	void searchteacher1();
	void searchteacher2();

};
 teacher temp;//公用临时变量
 
class office 
{   public:
	teacher *tea=(teacher*)malloc(LIST_INIT_SIZE * sizeof(teacher));
	int length=0;
	int listsize=100;
};
office L;

void key()//口令 
{
	int circulation, key;
	for (circulation = 0; circulation < 3; circulation++)
	{
		printf("请输入口令（还可以输入%d次）：\n", 3 - circulation);
		std::cin >> key;
		if (key ==123)//口令正确
		{
		std::cout << "欢迎进入教室信息管理系统\n";break;//跳出 
		}
		else
		{
			std::cout << "口令错误\n";
			if (circulation == 2)//检查口令输入次数
			{
				std::cout << "口令输入次数超过上限，即将自动退出！\n";
				Sleep(1*2000);
				exit(0);
			}
		}
	}
}
	
void teacher::deleteteacher() {
	int i;
	cout << "请输入你要删除的教师的教师号：";
	cin >> i;
	ofstream outFile("教师信息库.txt", ios::out | ios::binary);
	if (!outFile)
	{
		cout << "打开文件失败";
		
	}
	else
	{
		teacher *s = new teacher;
		cout << "输入教师教师号:";
		cin >> s->teacher_number;
		cout << "年龄:";
		cin >> s->age;
		cout << "电话：";
		cin >> s->telephone;
		cout << "薪水：";
		cin >> s->salay;
		cout << "地址：";
		cin >> s->address;
		cout << "性别：";
		cin >> s->sex;
		cout << "职称：";
		cin >> s->job_title;
		cout << "学历";
		cin >> s->education_background;
		cout << "姓名：";
		cin >> s->name;
		outFile.write((char*)s, sizeof(teacher));

	}
	outFile.close();
	

}
	







void teacher:: sortteacher1() {
	int n,i, j,temp;
	for (i = 0; i<= L.length; i++)
	{
		for (j = 0; j <= L.length - i; j++)
		{
			if (L.tea[j].teacher_number > L.tea[j + 1].teacher_number)
			{
				temp = L.tea[j].teacher_number;
				L.tea[j].teacher_number = L.tea[j + 1].teacher_number;
				L.tea[j + 1].teacher_number = temp;
			}
		}
	}
	for (n = 0; n <= L.length; n++)
	cout << "教师号：" << L.tea[n].teacher_number;
	cout << "年龄：" << L.tea[n].age;
	cout << "电话：" << L.tea[n].telephone;
	cout << "性别：" << L.tea[n].sex;
	cout << "职称：" << L.tea[n].job_title;
	cout << "地址：" << L.tea[n].address;
	cout << "学历" << L.tea[n].education_background;
	cout << "名字" << L.tea[n].name;
	cout << "工资" << L.tea[n].salay;
}

void teacher:: sortteacher2() {



}

			
			void chooseteacher1()//选择排序方式的函数
			{
				int i;
					cout << "排序方式";
				cout<<"1.【按教师号排序】，2.【按月薪排序】\n";
				cout<<"请选择：";
				cin>> i;
				while ((i < 1) || (i > 2))
				{
					printf("选择无效，请重新输入正确的选择项：");
					cin>>i;
				}
				switch (i)
				{
				case 1:temp.sortteacher1(); break;
				case 2:temp.sortteacher2(); break;
				}
			}
			void teacher:: searchteacher1() 
				//按教师号查找的函数
			{
				
				int i, k, n;
				if (L.length = 0)
				{
					std::cout << "\n还未录入过教师信息\n" << "即将退出系统";//链表为空时输出
					exit(0);
				}
				else {


					std::cout << "输入你要浏览信息的教师的教师号：";
					cin >> i;
					for (n = 0; n <= L.length; n++)
						if (L.tea[n].teacher_number = i)
						{
							k = 1;
							std::cout << "教师号：" << L.tea[n].teacher_number;
							std::cout << "年龄：" << L.tea[n].age;
							std::cout << "电话：" << L.tea[n].telephone;
							std::cout << "性别：" << L.tea[n].sex;
							std::cout << "职称：" << L.tea[n].job_title;
							std::cout << "地址：" << L.tea[n].address;
							std::cout << "学历" << L.tea[n].education_background;
							std::cout << "名字" << L.tea[n].name;
							std::cout << "工资" << L.tea[n].salay;
							std::cout << "信息输出完毕，即将退出系统";
							Sleep(10 * 2000);
							exit(0);

						}
						else k = 0;
					if (k = 0)
						std::cout << "\n已录入的教师信息中没有教师号为" << i << "的\n" << "即将退出系统";
					Sleep(2 * 2000);
					
					exit(0);
				}
			}
			void teacher::searchteacher2()
				//按职称查找的函数
			{
			
				
				int i, k, n;
				cout << "输入你要查找信息的教师职称：";
				cin >> i;
				for (n = 0; n <= L.length; n++)
				{
					if (L.tea[n].teacher_number = i)
					{
						k = 1;
						cout << "教师号：" << L.tea[n].teacher_number;
						cout << "年龄：" << L.tea[n].age;
						cout << "电话：" << L.tea[n].telephone;
						cout << "性别：" << L.tea[n].sex;
						cout << "职称：" << L.tea[n].job_title;
						cout << "地址：" << L.tea[n].address;
						cout << "学历" << L.tea[n].education_background;
						cout << "名字" << L.tea[n].name;
						cout << "工资" << L.tea[n].salay;


					}
					else
						k = 0;
				}
				if (k = 0)
					cout << "\n已录入的教师信息中没有教师号为" << i << "的\n";
			}


void chooseteacher2()//选择查找方式的函数
{
	int i;
	cout<<"查询方式\n";
	cout<<"1.【按教师号查询】，2.【按职称查询】";
	cout<<"请选择:";
	cin>>i;
	while ((i < 1) || (i > 2))
	{
		cout<<"选择无效，请重新输入正确选项：";
		cin>>i;
	}
	switch (i)
	{
	case 1:temp.searchteacher1(); break;
	case 2:temp.searchteacher2(); break;
	}
}
int teacher:: createteacher() {
	ofstream outFile("教师信息库.txt", ios::out | ios::binary);
	if(!outFile)
	{
		cout << "打开文件失败";
		return 0;
	   }
	else
	{
		teacher *s = new teacher;
		cout << "输入教师教师号:";
		cin >> s->teacher_number;
		cout << "年龄:";
		cin >> s->age;
		cout << "电话：";
		cin >> s->telephone;
		cout << "薪水：";
		cin >> s->salay;
		cout << "地址：";
		cin >> s->address;
		cout << "性别：";
		cin >> s->sex;
		cout << "职称：";
		cin >> s->job_title;
		cout << "学历";
		cin >> s->education_background;
		cout << "姓名：";
		cin >> s->name;
		outFile.write((char*)s, sizeof(teacher));
	
	}
	outFile.close();
	return 1;

}
int teacher::readteacher() 
{
	int c;
	ifstream inFile("教师信息库.txt", ios::in | ios::binary);
	if (!inFile) {
		cout << "打开文件失败";
		return 0;
	}
	else
		for (c = 0; c <= L.length; c++)
		{
			teacher *p = new teacher;
			inFile.read((char*)p, sizeof(teacher));
			cout << "教师号:" << p->teacher_number;
			cout << "薪水:" << p->salay;
			cout << "电话：" << p->telephone;
			cout << "年龄:" << p->age;
			cout << "地址:" << p->address;
			cout << "职称:" << p->job_title;
			cout << "学历：" << p->education_background;
			cout << "性别：" << p->sex;
			cout << "名字：" << p->name;
		}
	inFile.close();
}

void menu() 
{
	//菜单
	int a;
	cout << "菜单\n" ;
	cout <<"1.【教师信息录入】，2.【浏览教师信息】，3.【教师信息删除】，4.【查询个人信息】，5.【查询排序信息】，6.【退出信息系统】\n";
	cout << "请选择：";
	cin  >> a;
      if ((a < 1) || (a > 6))
	{
		cout<<"选择无效，请重新输入正确选项：";
		cin>>a;
	}
	switch (a)
	{
	case 1:temp.createteacher(); break;
	case 2:temp.readteacher();break;
	case 3:temp.deleteteacher(); break;
	case 4:chooseteacher1(); break;
	case 5:chooseteacher2(); break;
	case 6:exit(0);
	}
	
}
int main() //主函数
{
	
	key();
	menu();

	return 0;
}
	




















































































