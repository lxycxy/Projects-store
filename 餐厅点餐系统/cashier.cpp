#include"mainop.h"


void settle()
{
	tabley tab1[50];
	fstream tab;

	char nonum;//桌编号
	int sum;//sum为总金额
	tablel num[20];
	fstream ifs;
	ifs.open("costbill.txt", ios::in);
	int ti = 0;//记录桌位数
	/*读桌文件*/
	tab.open("table.txt");
	int feetab;
	tab >> feetab;
	while (!tab.eof())
	{
		tab >> tab1[ti].no >> tab1[ti].num >> tab1[ti].state;
		ti++;
	}
	tab.close();
	cout << "               请输入待结算顾客小票的桌号：";

	/*输入错误清况*/
	while (true)
	{
		int j, f1 = 0;
		cin >> nonum;//输入待修改的桌号
		for (j = 0; j < ti - 1; j++)
		{
			if (tab1[j].no == nonum - '0' && tab1[j].state == 0)
			{
				f1 = 1;
				break;
			}
			else if (tab1[j].no == nonum - '0' && tab1[j].state == 1)
			{
				f1 = 0;
				tab1[j].state = 0;
				break;
			}
		}
		if (!f1 && j != ti - 1)
		{
			break;
		}
		else
		{
			cout << "输入错误！该桌为空桌！请重新输入：";
		}

	}
	int i = 0;
	int flag = 0;
	fstream ofs;//结算后把已完成的订单移到另一个文件
	ofs.open("settlebill.txt", ios::app);
	while (!ifs.eof())//对顾客数据录入
	{
		ifs >> num[i].tableno >> num[i].dishnum >> num[i].peonum;//存入桌号以及菜品数量
		sum = 0;
		for (int j = 0; j < num[i].dishnum; j++)//读顾客手中小票
		{
			ifs >> num[i].bill[j].dishno
				>> num[i].bill[j].dish
				>> num[i].bill[j].price
				>> num[i].bill[j].state;
			if (num[i].bill[j].state)//只有做完了才加上金额
				sum += num[i].bill[j].price;
		}
		if (sum < 500 && sum>0)
		{
			sum += num[i].peonum * feetab;//总消费额小于500，结算时加上餐位费
		}
		if (num[i].tableno == nonum - '0')//匹配到结算桌号,再进行操作
		{
			flag = i;//给上标记以便后面录入数据
			ofs << num[i].tableno << " " << num[i].dishnum << " " << num[i].peonum << " " << sum << endl;
			for (int j = 0; j < num[i].dishnum; j++)
			{
				ofs << num[i].bill[j].dishno << " "
					<< num[i].bill[j].dish << " "
					<< num[i].bill[j].price << " "
					<< num[i].bill[j].state << endl;
			}
			cout << "  桌号: " << num[i].tableno << "    菜的数量 :" << num[i].dishnum << "        用餐人数:" << num[i].peonum << "" << endl;

			cout << " 菜品编号    菜名         价格     完成状态" << endl;
			for (int j = 0; j < num[i].dishnum; j++)
			{
				cout << setw(5) << num[i].bill[j].dishno << setw(16) << num[i].bill[j].dish << setw(8)
					<< num[i].bill[j].price << "      ";
				if (num[i].bill[j].state)
					cout << setw(6) << "已完成" << endl;
				else
					cout << setw(6) << "未完成" << endl;
			}
			cout << "           总消费金额为：" << sum << "元" << endl;
		}
		i++;
	}
	ifs.close();//先关闭
	ofs.close();
	ifs.open("costbill.txt", ios::out | ios::trunc);//清空再写入
	/*重新写入数据到顾客*/
	for (int j = 0; j < i - 1; j++)
	{
		if (j != flag)
		{
			ifs << num[j].tableno << " " << num[j].dishnum << "  " << num[j].peonum << endl;

			for (int m = 0; m < num[j].dishnum; m++)
			{

				ifs << num[j].bill[m].dishno << "  " << num[j].bill[m].dish << " " << num[j].bill[m].price << " "
					<< num[j].bill[m].state << " " << endl;
			}
		}

	}
	ifs.close();
	tab.open("table.txt");
	/*重新写入数据到桌文件*/
	tab << feetab << endl;
	for (int j = 0; j < ti - 1; j++)
	{
		tab << tab1[j].no << " " << tab1[j].num << " " << tab1[j].state << endl;
	}
	system("pause");
	system("cls");
}
void sumsettle()//统计订单数与营业额
{
	tablel tab[100];
	fstream ifs;
	ifs.open("settlebill.txt");
	int i = 0;
	int sum = 0;
	int t = 0;
	while (!ifs.eof())
	{
		t = 0;
		ifs >> tab[i].tableno >> tab[i].dishnum >> tab[i].peonum >> t;
		sum += t;
		for (int j = 0; j < tab[i].dishnum; j++)
		{
			ifs >> tab[i].bill[j].dishno >> tab[i].bill[j].dish >> tab[i].bill[j].price >> tab[i].bill[j].state;
		}
		i++;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                          今日完成订单数为：" << i - 1 << " 单" << endl;
	cout << "                           今日总营业额为： " << sum << " 元" << endl;
	system("pause");
	system("cls");
}
void cashshow()
{
	cout << "                 ___________________________________" << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;


	cout << "                 |*|        1、顾客结算           |*|" << endl;

	cout << "                 |*|        2、统计结算           |*|" << endl;

	cout << "                 |*|        3、菜品统计           |*|" << endl;

	cout << "                 |*|        0、返回身份选项       |*|" << endl;

	cout << "                 ___________________________________" << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;
	cout << "                          请选择你要的操作：";
}
void dishsum()
{
	dishy dishes[200];
	int fsum = 0, ssum = 0;
	fstream ifs;
	ifs.open("chef.txt");
	int i = 0;
	while (!ifs.eof())
	{
		ifs >> dishes[i].tablen >> dishes[i].dishno >> dishes[i].dish >> dishes[i].state;
		if (dishes[i].state == 1)fsum++;
		else if (dishes[i].state == 0) ssum++;
		i++;
	}
	ifs.close();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                今日已完成菜品数量：" << fsum << "份   " << endl;
	cout << endl;
	cout << "                今日待完成菜品数量：" << ssum << "份   " << endl;
	cout << endl;
	system("pause");
	system("cls");
}
void cashier()
{
	char choice;
	while (true)//选择界面
	{
		cashshow();
		cin >> choice;
		system("cls");
		if (choice == '1')
		{
			settle();
		}
		else if (choice == '2')
		{
			sumsettle();
		}
		else if (choice == '3')
		{
			dishsum();
		}
		else if (choice == '0')
		{
			break;
		}
		else
		{
			cout << "输入错误！" << endl;
		}
	}




}

