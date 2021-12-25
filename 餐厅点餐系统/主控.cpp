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


	cout << "                 |*|        1、消费者            |*|" << endl;
	cout << endl;

	cout << "                 |*|        2、收银员            |*|" << endl;
	cout << endl;

	cout << "                 |*|        3、厨师              |*|" << endl;
	cout << endl;

	cout << "                 |*|        4、服务员            |*|" << endl;
	cout << endl;

	cout << "                 |*|        5、老板              |*|" << endl;
	cout << endl;

	cout << "                 |*|        6、系统管理员        |*|" << endl;
	cout << endl;

	cout << "                 |*|        0、退出系统          |*|" << endl;
	cout << endl;

	cout << "                 ___________________________________" << endl;
	cout << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;

	cout << "                   欢迎你的光临，请选择你要的操作：";


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
			cout << "                   错误输出！" << endl;
		}
		mainshow();
		cin >> choice;
		system("cls");

	}

	cout << "欢迎下次使用" << endl;

}