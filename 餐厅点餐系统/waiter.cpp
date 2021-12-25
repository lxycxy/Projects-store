#include"mainop.h"

void Menu(int a, int b, dishy dishs[], dishy beverage[])
{
	cout << "______________________________________________________________" << endl;
	cout << endl;
	cout << "**************************************************************" << endl;
	cout << "|*|         菜肴              |*|            酒水          |*|" << endl;
	for (int i = 0; i < a; i++)
	{
		if (i < b)
		{
			cout << "|*|";
			cout << setw(4) << dishs[i].dishno << " ";
			cout << setw(14) << dishs[i].dish << " ";
			cout << setw(5) << dishs[i].price << "  |*|";
			cout << setw(4) << beverage[i].dishno << " ";
			cout << setw(14) << beverage[i].dish << " ";
			cout << setw(5) << beverage[i].price << " |*|" << endl;
		}
		else
		{
			cout << "|*|";
			cout << setw(4) << dishs[i].dishno << " ";
			cout << setw(14) << dishs[i].dish << " ";
			cout << setw(5) << dishs[i].price << "  |*|    ";
			cout << "                      |*|" << endl;
		}
	}
	cout << "**************************************************************" << endl;
	cout << "______________________________________________________________" << endl;
}
void pulsfood()
{
	int i = 0;
	tablel num[20];
	dishy foodbill[100];
	dishy beverage[40];
	dishy food[80];
	fstream fm;
	fm.open("menu.txt");//打印菜单，先录入数据
	int fnum = 0, a = 0, b = 0;
	while (!fm.eof())
	{
		fm >> foodbill[fnum].dishno >> foodbill[fnum].dish >> foodbill[fnum].price;
		foodbill[fnum].state = 0;//赋好状态以便后面使用
		if (foodbill[fnum].dishno < 2000 && foodbill[fnum].dishno>1000)
		{
			food[a].dishno = foodbill[fnum].dishno;
			food[a].dish = foodbill[fnum].dish;
			food[a].price = foodbill[fnum].price;
			a++;
		}
		else
		{
			beverage[b].dishno = foodbill[fnum].dishno;
			beverage[b].dish = foodbill[fnum].dish;
			beverage[b].price = foodbill[fnum].price;
			b++;
		}
		fnum++;


	}
	fm.close();
	Menu(a, b - 1, food, beverage);
	fstream ifs;
	ifs.open("costbill.txt");
	while (!ifs.eof())//对顾客数据录入
	{
		ifs >> num[i].tableno >> num[i].dishnum >> num[i].peonum;//存入桌号以及菜品数量

		for (int j = 0; j < num[i].dishnum; j++)
		{
			ifs >> num[i].bill[j].dishno
				>> num[i].bill[j].dish
				>> num[i].bill[j].price
				>> num[i].bill[j].state;
		}

		i++;
	}

	fstream cfs;
	cfs.open("chef.txt", ios::app);//从厨师文件末尾写入
	int flag = 0;//做判断
	char record;//记录编号
	cout << "             " << "请输入要加菜的桌号（输入n取消加菜）:";
	while (true)
	{
		cin >> record;//桌号
		if (record == 'n')break;
		for (int i1 = 0; i1 < i - 1; i1++)
		{
			if (num[i1].tableno == record - '0')//找到订单编号相等
			{
				cout << endl;
				flag = 1;
				int plus[50] = { 0 }, pnum = 0;//记录下菜的订单编号,以及菜数量
				cout << "             " << "依次输入待加菜的编号(以-1结束输入)：";
				while (true)//记录下所有的菜编号
				{
					cin >> plus[pnum];
					if (plus[pnum] == -1)break;//输入-1后退出
					pnum++;
				}
				for (int j = 0; j < pnum; j++)//找到相同编号菜 加入顾客菜单
				{
					for (int k = 0; k < fnum - 1; k++)
					{
						if (plus[j] == foodbill[k].dishno)//菜品 
						{
							num[i1].bill[num[i1].dishnum + j].dishno = foodbill[k].dishno;
							num[i1].bill[num[i1].dishnum + j].dish = foodbill[k].dish;
							num[i1].bill[num[i1].dishnum + j].price = foodbill[k].price;
							num[i1].bill[num[i1].dishnum + j].state = foodbill[k].state;
							if (plus[j] < 2000 && plus[j]>1000)//非酒水录入厨师文件
							{
								cfs << num[i1].tableno << " " << foodbill[k].dishno << " " << foodbill[k].dish << " " << foodbill[k].state << endl;

							}

						}
					}
				}
				num[i1].dishnum += pnum;
				break;//改完后退出
			}
		}
		if (flag && record != 'n')
		{
			cout << "              修改成功！" << endl;
			break;
		}
		else
		{
			cout << "              该桌为空桌！请重新输入(输入n取消加菜)：";
		}

	}
	if (record == 'n')
	{
		cout << "                    取消成功！" << endl;
	}
	cfs.close();
	ifs.close();
	ifs.open("costbill.txt");
	cout << i << endl;
	for (int j = 0; j < i - 1; j++)//修改后录入顾客文件数据
	{
		ifs << num[j].tableno << " " << num[j].dishnum << "  " << num[j].peonum << endl;

		for (int m = 0; m < num[j].dishnum; m++)
		{

			ifs << num[j].bill[m].dishno << "  " << num[j].bill[m].dish << " " << num[j].bill[m].price << " "
				<< num[j].bill[m].state << " " << endl;
		}

	}

	system("pause");
	system("cls");
}
void printreceipt()//查看顾客小票
{
	tablel num[20];
	char n;//桌号
	fstream ifs;
	ifs.open("costbill.txt", ios::in);
	cout << "               请输入待查看顾客小票的桌号：";
	cin >> n;
	int i = 0, k = 0;
	while (!ifs.eof())//对顾客数据录入
	{
		ifs >> num[i].tableno >> num[i].dishnum >> num[i].peonum;//存入桌号以及菜品数量
		for (int j = 0; j < num[i].dishnum; j++)
		{
			ifs >> num[i].bill[j].dishno
				>> num[i].bill[j].dish
				>> num[i].bill[j].price
				>> num[i].bill[j].state;
		}
		i++;
	}
	k = i;//保存桌数
	i = 0;
	int flag1 = 1;//判断继续查看是否输入错误
	while (true)
	{
		char flag = 'y';
		if (num[i].tableno == n - '0')
		{

			if (flag1)
			{
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
				cout << "          请输入是否继续查看(y/n)：";
			}
			cin >> flag;

			if (flag == 'n')
			{
				flag1 = 1;
				break;
			}
			else if (flag == 'y')
			{
				flag1 = 1;
				system("cls");
				cout << "               请输入待查看顾客小票的桌号：";
				cin >> n;
			}
			else
			{
				cout << "            错误输入!,请重新输入：";

				flag1 = 0;
			}

		}
		if (flag == 'y')
			i++;

		if (i == k)//遍历一遍未找到，则重新输入再次遍历
		{
			cout << "       该桌为空桌！请再次输入待查看顾客小票的桌号：";
			cin >> n;
			i = 0;
		}

	}

	system("pause");
	system("cls");
}
void findserve()
{
	int dishnum = 0;
	/*文件中为0的是未做的菜，为2的是已上的菜，1为做好但没有上的菜*/
	fstream ifs, ofs, record;
	ifs.open("chef.txt");
	dishy food[200];
	int i = 0;
	while (!ifs.eof())//对厨师文件记录数据
	{
		ifs >> food[i].tablen >> food[i].dishno >> food[i].dish >> food[i].state;// 桌号   菜编号   菜名   菜的状态
		if (food[i].state == 1)dishnum++;//对待上菜进行记录
		i++;
	}

	ifs.close();//关闭文件以便下一步写入数据
	ofs.open("chef.txt");//写数据操作
	record.open("costbill.txt");
	int k = 0;//k记录有多少桌客人

	tablel num[12];
	while (!record.eof())
	{
		record >> num[k].tableno >> num[k].dishnum >> num[k].peonum;//存入订单号以及桌号以及菜品数量
		for (int j = 0; j < num[k].dishnum; j++)
		{
			record >> num[k].bill[j].dishno
				>> num[k].bill[j].dish
				>> num[k].bill[j].price
				>> num[k].bill[j].state;
		}
		k++;
	}
	record.close();//读数据操作结束，开始写数据
	record.open("costbill.txt");
	char flag = 'y';//判断输入错误情况
	int flag1 = 1;
	int name;
	int tnum = 0;//赋值为零作为下判断条件
	while (true)
	{
		if (flag1)
		{
			if (dishnum)
			{
				cout << "             剩余待上菜数量为：" << dishnum << endl;
				for (int j = 0; j < i - 1; j++)//打印待上菜
				{
					if (food[j].state == 1)
					{
						cout << setw(3) << food[j].tablen << "号桌" << setw(6) << food[j].dishno << setw(12) << food[j].dish;
						cout << setw(12) << "待上菜" << endl;
					}
				}
				cout << "是否修改菜的状态（y/n）：";
			}
			else
			{
				cout << "暂无待上菜！" << endl;
				break;
			}

		}
		cin >> flag;

		if (flag == 'n')
		{
			break;
		}
		else if (flag == 'y' && i != 0)
		{
			flag1 = 1;
			cout << "请输入待修改菜的桌号以及菜的编号：";
			cin >> tnum >> name;
			system("cls");
		}
		else
		{
			cout << "输入错误！请重新输入：";
			flag1 = 0;
		}
		if (tnum)
		{
			for (int j = 0; j < i - 1; j++)
			{
				if (tnum == food[j].tablen && food[j].dishno == name)
				{
					food[j].state = 2;
					dishnum--;//上完菜后待上菜数量减一
				}
				ofs << food[j].tablen;
				ofs << " ";
				ofs << food[j].dishno;
				ofs << " ";
				ofs << food[j].dish;
				ofs << " ";
				ofs << food[j].state;
				ofs << endl;
			}
			for (int j = 0; j < k - 1; j++)//修改后录入顾客文件数据
			{
				record << num[j].tableno << " " << num[j].dishnum << num[j].peonum << endl;

				for (int m = 0; m < num[j].dishnum; m++)
				{
					if (num[j].bill[m].dishno == name && num[j].bill[m].state != 1 && num[j].tableno == tnum)//找到该桌菜名
					{
						num[j].bill[m].state = 1;
					}
					record << num[j].bill[m].dishno << "  " << num[j].bill[m].dish << " " << num[j].bill[m].price << " "
						<< num[j].bill[m].state << " " << endl;
				}

			}
		}
	}
	system("pause");
	system("cls");
}
void waitershow()
{
	cout << "                 ___________________________________" << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;


	cout << "                 |*|        1、顾客加菜            |*|" << endl;

	cout << "                 |*|        2、查看顾客小票        |*|" << endl;

	cout << "                 |*|        3、查看待上菜品        |*|" << endl;

	cout << "                 |*|        0、返回身份选项        |*|" << endl;

	cout << "                 ___________________________________" << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;
	cout << "                          请选择你要的操作：";
}
void waiter()//服务员操作
{
	char choice;

	while (true)
	{
		waitershow();
		cin >> choice;
		system("cls");
		if (choice == '1')//顾客加菜
		{
			pulsfood();
		}
		else if (choice == '2')//查看顾客小票
		{
			printreceipt();
		}
		else if (choice == '3')//查看待上菜品
		{
			findserve();
		}
		else if (choice == '0')//退出系统
		{
			break;
		}
		else
		{
			cout << "输入错误!" << endl;//不能输入出提示信息外的数字
		}
	}
}

