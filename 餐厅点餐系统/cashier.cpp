#include"mainop.h"


void settle()
{
	tabley tab1[50];
	fstream tab;

	char nonum;//�����
	int sum;//sumΪ�ܽ��
	tablel num[20];
	fstream ifs;
	ifs.open("costbill.txt", ios::in);
	int ti = 0;//��¼��λ��
	/*�����ļ�*/
	tab.open("table.txt");
	int feetab;
	tab >> feetab;
	while (!tab.eof())
	{
		tab >> tab1[ti].no >> tab1[ti].num >> tab1[ti].state;
		ti++;
	}
	tab.close();
	cout << "               �����������˿�СƱ�����ţ�";

	/*����������*/
	while (true)
	{
		int j, f1 = 0;
		cin >> nonum;//������޸ĵ�����
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
			cout << "������󣡸���Ϊ���������������룺";
		}

	}
	int i = 0;
	int flag = 0;
	fstream ofs;//����������ɵĶ����Ƶ���һ���ļ�
	ofs.open("settlebill.txt", ios::app);
	while (!ifs.eof())//�Թ˿�����¼��
	{
		ifs >> num[i].tableno >> num[i].dishnum >> num[i].peonum;//���������Լ���Ʒ����
		sum = 0;
		for (int j = 0; j < num[i].dishnum; j++)//���˿�����СƱ
		{
			ifs >> num[i].bill[j].dishno
				>> num[i].bill[j].dish
				>> num[i].bill[j].price
				>> num[i].bill[j].state;
			if (num[i].bill[j].state)//ֻ�������˲ż��Ͻ��
				sum += num[i].bill[j].price;
		}
		if (sum < 500 && sum>0)
		{
			sum += num[i].peonum * feetab;//�����Ѷ�С��500������ʱ���ϲ�λ��
		}
		if (num[i].tableno == nonum - '0')//ƥ�䵽��������,�ٽ��в���
		{
			flag = i;//���ϱ���Ա����¼������
			ofs << num[i].tableno << " " << num[i].dishnum << " " << num[i].peonum << " " << sum << endl;
			for (int j = 0; j < num[i].dishnum; j++)
			{
				ofs << num[i].bill[j].dishno << " "
					<< num[i].bill[j].dish << " "
					<< num[i].bill[j].price << " "
					<< num[i].bill[j].state << endl;
			}
			cout << "  ����: " << num[i].tableno << "    �˵����� :" << num[i].dishnum << "        �ò�����:" << num[i].peonum << "" << endl;

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
			cout << "           �����ѽ��Ϊ��" << sum << "Ԫ" << endl;
		}
		i++;
	}
	ifs.close();//�ȹر�
	ofs.close();
	ifs.open("costbill.txt", ios::out | ios::trunc);//�����д��
	/*����д�����ݵ��˿�*/
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
	/*����д�����ݵ����ļ�*/
	tab << feetab << endl;
	for (int j = 0; j < ti - 1; j++)
	{
		tab << tab1[j].no << " " << tab1[j].num << " " << tab1[j].state << endl;
	}
	system("pause");
	system("cls");
}
void sumsettle()//ͳ�ƶ�������Ӫҵ��
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
	cout << "                          ������ɶ�����Ϊ��" << i - 1 << " ��" << endl;
	cout << "                           ������Ӫҵ��Ϊ�� " << sum << " Ԫ" << endl;
	system("pause");
	system("cls");
}
void cashshow()
{
	cout << "                 ___________________________________" << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;


	cout << "                 |*|        1���˿ͽ���           |*|" << endl;

	cout << "                 |*|        2��ͳ�ƽ���           |*|" << endl;

	cout << "                 |*|        3����Ʒͳ��           |*|" << endl;

	cout << "                 |*|        0���������ѡ��       |*|" << endl;

	cout << "                 ___________________________________" << endl;
	cout << "                 * * * * * * * * * * * * * * * * * *" << endl;
	cout << "                          ��ѡ����Ҫ�Ĳ�����";
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
	cout << "                ��������ɲ�Ʒ������" << fsum << "��   " << endl;
	cout << endl;
	cout << "                ���մ���ɲ�Ʒ������" << ssum << "��   " << endl;
	cout << endl;
	system("pause");
	system("cls");
}
void cashier()
{
	char choice;
	while (true)//ѡ�����
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
			cout << "�������" << endl;
		}
	}




}

