#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<iostream>
#include<fstream>
using namespace std;
#define LEN sizeof(teacher)//�궨��ṹ���ֽ���
#define LIST_INIT_SIZE 100// ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10// ���Ա�洢�ռ�ķ������� 
 class teacher //����ṹ��
{   public:
	int teacher_number;//��ʦ��
	int age;//���� 
	int salay;//���� 
	int telephone;//�绰 
	char name[30];//����
	char sex[10];//�Ա�
	char education_background[50];//ѧ��
	char address[50];//��ַ 
	char job_title[20];//ְ�� 
	teacher *next;//ָ����һ����� 
	int createteacher();
	void deleteteacher();
	int readteacher();
	void sortteacher1();
	void sortteacher2();
	void searchteacher1();
	void searchteacher2();

};
 teacher temp;//������ʱ����
 
class office 
{   public:
	teacher *tea=(teacher*)malloc(LIST_INIT_SIZE * sizeof(teacher));
	int length=0;
	int listsize=100;
};
office L;

void key()//���� 
{
	int circulation, key;
	for (circulation = 0; circulation < 3; circulation++)
	{
		printf("������������������%d�Σ���\n", 3 - circulation);
		std::cin >> key;
		if (key ==123)//������ȷ
		{
		std::cout << "��ӭ���������Ϣ����ϵͳ\n";break;//���� 
		}
		else
		{
			std::cout << "�������\n";
			if (circulation == 2)//�������������
			{
				std::cout << "������������������ޣ������Զ��˳���\n";
				Sleep(1*2000);
				exit(0);
			}
		}
	}
}
	
void teacher::deleteteacher() {
	int i;
	cout << "��������Ҫɾ���Ľ�ʦ�Ľ�ʦ�ţ�";
	cin >> i;
	ofstream outFile("��ʦ��Ϣ��.txt", ios::out | ios::binary);
	if (!outFile)
	{
		cout << "���ļ�ʧ��";
		
	}
	else
	{
		teacher *s = new teacher;
		cout << "�����ʦ��ʦ��:";
		cin >> s->teacher_number;
		cout << "����:";
		cin >> s->age;
		cout << "�绰��";
		cin >> s->telephone;
		cout << "нˮ��";
		cin >> s->salay;
		cout << "��ַ��";
		cin >> s->address;
		cout << "�Ա�";
		cin >> s->sex;
		cout << "ְ�ƣ�";
		cin >> s->job_title;
		cout << "ѧ��";
		cin >> s->education_background;
		cout << "������";
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
	cout << "��ʦ�ţ�" << L.tea[n].teacher_number;
	cout << "���䣺" << L.tea[n].age;
	cout << "�绰��" << L.tea[n].telephone;
	cout << "�Ա�" << L.tea[n].sex;
	cout << "ְ�ƣ�" << L.tea[n].job_title;
	cout << "��ַ��" << L.tea[n].address;
	cout << "ѧ��" << L.tea[n].education_background;
	cout << "����" << L.tea[n].name;
	cout << "����" << L.tea[n].salay;
}

void teacher:: sortteacher2() {



}

			
			void chooseteacher1()//ѡ������ʽ�ĺ���
			{
				int i;
					cout << "����ʽ";
				cout<<"1.������ʦ�����򡿣�2.������н����\n";
				cout<<"��ѡ��";
				cin>> i;
				while ((i < 1) || (i > 2))
				{
					printf("ѡ����Ч��������������ȷ��ѡ���");
					cin>>i;
				}
				switch (i)
				{
				case 1:temp.sortteacher1(); break;
				case 2:temp.sortteacher2(); break;
				}
			}
			void teacher:: searchteacher1() 
				//����ʦ�Ų��ҵĺ���
			{
				
				int i, k, n;
				if (L.length = 0)
				{
					std::cout << "\n��δ¼�����ʦ��Ϣ\n" << "�����˳�ϵͳ";//����Ϊ��ʱ���
					exit(0);
				}
				else {


					std::cout << "������Ҫ�����Ϣ�Ľ�ʦ�Ľ�ʦ�ţ�";
					cin >> i;
					for (n = 0; n <= L.length; n++)
						if (L.tea[n].teacher_number = i)
						{
							k = 1;
							std::cout << "��ʦ�ţ�" << L.tea[n].teacher_number;
							std::cout << "���䣺" << L.tea[n].age;
							std::cout << "�绰��" << L.tea[n].telephone;
							std::cout << "�Ա�" << L.tea[n].sex;
							std::cout << "ְ�ƣ�" << L.tea[n].job_title;
							std::cout << "��ַ��" << L.tea[n].address;
							std::cout << "ѧ��" << L.tea[n].education_background;
							std::cout << "����" << L.tea[n].name;
							std::cout << "����" << L.tea[n].salay;
							std::cout << "��Ϣ�����ϣ������˳�ϵͳ";
							Sleep(10 * 2000);
							exit(0);

						}
						else k = 0;
					if (k = 0)
						std::cout << "\n��¼��Ľ�ʦ��Ϣ��û�н�ʦ��Ϊ" << i << "��\n" << "�����˳�ϵͳ";
					Sleep(2 * 2000);
					
					exit(0);
				}
			}
			void teacher::searchteacher2()
				//��ְ�Ʋ��ҵĺ���
			{
			
				
				int i, k, n;
				cout << "������Ҫ������Ϣ�Ľ�ʦְ�ƣ�";
				cin >> i;
				for (n = 0; n <= L.length; n++)
				{
					if (L.tea[n].teacher_number = i)
					{
						k = 1;
						cout << "��ʦ�ţ�" << L.tea[n].teacher_number;
						cout << "���䣺" << L.tea[n].age;
						cout << "�绰��" << L.tea[n].telephone;
						cout << "�Ա�" << L.tea[n].sex;
						cout << "ְ�ƣ�" << L.tea[n].job_title;
						cout << "��ַ��" << L.tea[n].address;
						cout << "ѧ��" << L.tea[n].education_background;
						cout << "����" << L.tea[n].name;
						cout << "����" << L.tea[n].salay;


					}
					else
						k = 0;
				}
				if (k = 0)
					cout << "\n��¼��Ľ�ʦ��Ϣ��û�н�ʦ��Ϊ" << i << "��\n";
			}


void chooseteacher2()//ѡ����ҷ�ʽ�ĺ���
{
	int i;
	cout<<"��ѯ��ʽ\n";
	cout<<"1.������ʦ�Ų�ѯ����2.����ְ�Ʋ�ѯ��";
	cout<<"��ѡ��:";
	cin>>i;
	while ((i < 1) || (i > 2))
	{
		cout<<"ѡ����Ч��������������ȷѡ�";
		cin>>i;
	}
	switch (i)
	{
	case 1:temp.searchteacher1(); break;
	case 2:temp.searchteacher2(); break;
	}
}
int teacher:: createteacher() {
	ofstream outFile("��ʦ��Ϣ��.txt", ios::out | ios::binary);
	if(!outFile)
	{
		cout << "���ļ�ʧ��";
		return 0;
	   }
	else
	{
		teacher *s = new teacher;
		cout << "�����ʦ��ʦ��:";
		cin >> s->teacher_number;
		cout << "����:";
		cin >> s->age;
		cout << "�绰��";
		cin >> s->telephone;
		cout << "нˮ��";
		cin >> s->salay;
		cout << "��ַ��";
		cin >> s->address;
		cout << "�Ա�";
		cin >> s->sex;
		cout << "ְ�ƣ�";
		cin >> s->job_title;
		cout << "ѧ��";
		cin >> s->education_background;
		cout << "������";
		cin >> s->name;
		outFile.write((char*)s, sizeof(teacher));
	
	}
	outFile.close();
	return 1;

}
int teacher::readteacher() 
{
	int c;
	ifstream inFile("��ʦ��Ϣ��.txt", ios::in | ios::binary);
	if (!inFile) {
		cout << "���ļ�ʧ��";
		return 0;
	}
	else
		for (c = 0; c <= L.length; c++)
		{
			teacher *p = new teacher;
			inFile.read((char*)p, sizeof(teacher));
			cout << "��ʦ��:" << p->teacher_number;
			cout << "нˮ:" << p->salay;
			cout << "�绰��" << p->telephone;
			cout << "����:" << p->age;
			cout << "��ַ:" << p->address;
			cout << "ְ��:" << p->job_title;
			cout << "ѧ����" << p->education_background;
			cout << "�Ա�" << p->sex;
			cout << "���֣�" << p->name;
		}
	inFile.close();
}

void menu() 
{
	//�˵�
	int a;
	cout << "�˵�\n" ;
	cout <<"1.����ʦ��Ϣ¼�롿��2.�������ʦ��Ϣ����3.����ʦ��Ϣɾ������4.����ѯ������Ϣ����5.����ѯ������Ϣ����6.���˳���Ϣϵͳ��\n";
	cout << "��ѡ��";
	cin  >> a;
      if ((a < 1) || (a > 6))
	{
		cout<<"ѡ����Ч��������������ȷѡ�";
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
int main() //������
{
	
	key();
	menu();

	return 0;
}
	




















































































