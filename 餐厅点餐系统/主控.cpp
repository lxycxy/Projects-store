#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include"mainop.h"


void mainshow()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                 ___________________________________" << endl;
	cout << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;


	cout << "                 |*|        1��������            |*|" << endl;
	cout << endl;

	cout << "                 |*|        2������Ա            |*|" << endl;
	cout << endl;

	cout << "                 |*|        3����ʦ              |*|" << endl;
	cout << endl;

	cout << "                 |*|        4������Ա            |*|" << endl;
	cout << endl;

	cout << "                 |*|        5���ϰ�              |*|" << endl;
	cout << endl;

	cout << "                 |*|        6��ϵͳ����Ա        |*|" << endl;
	cout << endl;

	cout << "                 |*|        0���˳�ϵͳ          |*|" << endl;
	cout << endl;

	cout << "                 ___________________________________" << endl;
	cout << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;

	cout << "                   ��ӭ��Ĺ��٣���ѡ����Ҫ�Ĳ�����";


}
int main()
{
	char choice;
	mainshow();
	cin >> choice;
	system("cls");


	while (true)
	{

		if (choice == '4')
		{
			waiter();
		}
		else if (choice == '2')
		{
			cashier();
		}
		else if (choice == '0')
		{
			break;
		}
		else
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "                   ���������" << endl;
		}
		mainshow();
		cin >> choice;
		system("cls");

	}

	cout << "��ӭ�´�ʹ��" << endl;

}