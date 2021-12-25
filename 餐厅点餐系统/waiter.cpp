#include"mainop.h"

void Menu(int a, int b, dishy dishs[], dishy beverage[])
{
	cout << "______________________________________________________________" << endl;
	cout << endl;
	cout << "**************************************************************" << endl;
	cout << "|*|         ����              |*|            ��ˮ          |*|" << endl;
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
	fm.open("menu.txt");//��ӡ�˵�����¼������
	int fnum = 0, a = 0, b = 0;
	while (!fm.eof())
	{
		fm >> foodbill[fnum].dishno >> foodbill[fnum].dish >> foodbill[fnum].price;
		foodbill[fnum].state = 0;//����״̬�Ա����ʹ��
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
	while (!ifs.eof())//�Թ˿�����¼��
	{
		ifs >> num[i].tableno >> num[i].dishnum >> num[i].peonum;//���������Լ���Ʒ����

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
	cfs.open("chef.txt", ios::app);//�ӳ�ʦ�ļ�ĩβд��
	int flag = 0;//���ж�
	char record;//��¼���
	cout << "             " << "������Ҫ�Ӳ˵����ţ�����nȡ���Ӳˣ�:";
	while (true)
	{
		cin >> record;//����
		if (record == 'n')break;
		for (int i1 = 0; i1 < i - 1; i1++)
		{
			if (num[i1].tableno == record - '0')//�ҵ�����������
			{
				cout << endl;
				flag = 1;
				int plus[50] = { 0 }, pnum = 0;//��¼�²˵Ķ������,�Լ�������
				cout << "             " << "����������Ӳ˵ı��(��-1��������)��";
				while (true)//��¼�����еĲ˱��
				{
					cin >> plus[pnum];
					if (plus[pnum] == -1)break;//����-1���˳�
					pnum++;
				}
				for (int j = 0; j < pnum; j++)//�ҵ���ͬ��Ų� ����˿Ͳ˵�
				{
					for (int k = 0; k < fnum - 1; k++)
					{
						if (plus[j] == foodbill[k].dishno)//��Ʒ 
						{
							num[i1].bill[num[i1].dishnum + j].dishno = foodbill[k].dishno;
							num[i1].bill[num[i1].dishnum + j].dish = foodbill[k].dish;
							num[i1].bill[num[i1].dishnum + j].price = foodbill[k].price;
							num[i1].bill[num[i1].dishnum + j].state = foodbill[k].state;
							if (plus[j] < 2000 && plus[j]>1000)//�Ǿ�ˮ¼���ʦ�ļ�
							{
								cfs << num[i1].tableno << " " << foodbill[k].dishno << " " << foodbill[k].dish << " " << foodbill[k].state << endl;

							}

						}
					}
				}
				num[i1].dishnum += pnum;
				break;//������˳�
			}
		}
		if (flag && record != 'n')
		{
			cout << "              �޸ĳɹ���" << endl;
			break;
		}
		else
		{
			cout << "              ����Ϊ����������������(����nȡ���Ӳ�)��";
		}

	}
	if (record == 'n')
	{
		cout << "                    ȡ���ɹ���" << endl;
	}
	cfs.close();
	ifs.close();
	ifs.open("costbill.txt");
	cout << i << endl;
	for (int j = 0; j < i - 1; j++)//�޸ĺ�¼��˿��ļ�����
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
void printreceipt()//�鿴�˿�СƱ
{
	tablel num[20];
	char n;//����
	fstream ifs;
	ifs.open("costbill.txt", ios::in);
	cout << "               ��������鿴�˿�СƱ�����ţ�";
	cin >> n;
	int i = 0, k = 0;
	while (!ifs.eof())//�Թ˿�����¼��
	{
		ifs >> num[i].tableno >> num[i].dishnum >> num[i].peonum;//���������Լ���Ʒ����
		for (int j = 0; j < num[i].dishnum; j++)
		{
			ifs >> num[i].bill[j].dishno
				>> num[i].bill[j].dish
				>> num[i].bill[j].price
				>> num[i].bill[j].state;
		}
		i++;
	}
	k = i;//��������
	i = 0;
	int flag1 = 1;//�жϼ����鿴�Ƿ��������
	while (true)
	{
		char flag = 'y';
		if (num[i].tableno == n - '0')
		{

			if (flag1)
			{
				cout << " ��Ʒ���    ����         �۸�     ���״̬" << endl;
				for (int j = 0; j < num[i].dishnum; j++)
				{
					cout << setw(5) << num[i].bill[j].dishno << setw(16) << num[i].bill[j].dish << setw(8)
						<< num[i].bill[j].price << "      ";
					if (num[i].bill[j].state)
						cout << setw(6) << "�����" << endl;
					else
						cout << setw(6) << "δ���" << endl;
				}
				cout << "          �������Ƿ�����鿴(y/n)��";
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
				cout << "               ��������鿴�˿�СƱ�����ţ�";
				cin >> n;
			}
			else
			{
				cout << "            ��������!,���������룺";

				flag1 = 0;
			}

		}
		if (flag == 'y')
			i++;

		if (i == k)//����һ��δ�ҵ��������������ٴα���
		{
			cout << "       ����Ϊ���������ٴ�������鿴�˿�СƱ�����ţ�";
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
	/*�ļ���Ϊ0����δ���Ĳˣ�Ϊ2�������ϵĲˣ�1Ϊ���õ�û���ϵĲ�*/
	fstream ifs, ofs, record;
	ifs.open("chef.txt");
	dishy food[200];
	int i = 0;
	while (!ifs.eof())//�Գ�ʦ�ļ���¼����
	{
		ifs >> food[i].tablen >> food[i].dishno >> food[i].dish >> food[i].state;// ����   �˱��   ����   �˵�״̬
		if (food[i].state == 1)dishnum++;//�Դ��ϲ˽��м�¼
		i++;
	}

	ifs.close();//�ر��ļ��Ա���һ��д������
	ofs.open("chef.txt");//д���ݲ���
	record.open("costbill.txt");
	int k = 0;//k��¼�ж���������

	tablel num[12];
	while (!record.eof())
	{
		record >> num[k].tableno >> num[k].dishnum >> num[k].peonum;//���붩�����Լ������Լ���Ʒ����
		for (int j = 0; j < num[k].dishnum; j++)
		{
			record >> num[k].bill[j].dishno
				>> num[k].bill[j].dish
				>> num[k].bill[j].price
				>> num[k].bill[j].state;
		}
		k++;
	}
	record.close();//�����ݲ�����������ʼд����
	record.open("costbill.txt");
	char flag = 'y';//�ж�����������
	int flag1 = 1;
	int name;
	int tnum = 0;//��ֵΪ����Ϊ���ж�����
	while (true)
	{
		if (flag1)
		{
			if (dishnum)
			{
				cout << "             ʣ����ϲ�����Ϊ��" << dishnum << endl;
				for (int j = 0; j < i - 1; j++)//��ӡ���ϲ�
				{
					if (food[j].state == 1)
					{
						cout << setw(3) << food[j].tablen << "����" << setw(6) << food[j].dishno << setw(12) << food[j].dish;
						cout << setw(12) << "���ϲ�" << endl;
					}
				}
				cout << "�Ƿ��޸Ĳ˵�״̬��y/n����";
			}
			else
			{
				cout << "���޴��ϲˣ�" << endl;
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
			cout << "��������޸Ĳ˵������Լ��˵ı�ţ�";
			cin >> tnum >> name;
			system("cls");
		}
		else
		{
			cout << "����������������룺";
			flag1 = 0;
		}
		if (tnum)
		{
			for (int j = 0; j < i - 1; j++)
			{
				if (tnum == food[j].tablen && food[j].dishno == name)
				{
					food[j].state = 2;
					dishnum--;//����˺���ϲ�������һ
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
			for (int j = 0; j < k - 1; j++)//�޸ĺ�¼��˿��ļ�����
			{
				record << num[j].tableno << " " << num[j].dishnum << num[j].peonum << endl;

				for (int m = 0; m < num[j].dishnum; m++)
				{
					if (num[j].bill[m].dishno == name && num[j].bill[m].state != 1 && num[j].tableno == tnum)//�ҵ���������
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


	cout << "                 |*|        1���˿ͼӲ�            |*|" << endl;

	cout << "                 |*|        2���鿴�˿�СƱ        |*|" << endl;

	cout << "                 |*|        3���鿴���ϲ�Ʒ        |*|" << endl;

	cout << "                 |*|        0���������ѡ��        |*|" << endl;

	cout << "                 ___________________________________" << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;
	cout << "                          ��ѡ����Ҫ�Ĳ�����";
}
void waiter()//����Ա����
{
	char choice;

	while (true)
	{
		waitershow();
		cin >> choice;
		system("cls");
		if (choice == '1')//�˿ͼӲ�
		{
			pulsfood();
		}
		else if (choice == '2')//�鿴�˿�СƱ
		{
			printreceipt();
		}
		else if (choice == '3')//�鿴���ϲ�Ʒ
		{
			findserve();
		}
		else if (choice == '0')//�˳�ϵͳ
		{
			break;
		}
		else
		{
			cout << "�������!" << endl;//�����������ʾ��Ϣ�������
		}
	}
}

