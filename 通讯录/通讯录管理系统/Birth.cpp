#include"adsbook.h"
//Birth�෽������
Birth::Birth(int y, int m, int d)
{
	this->year = y;
	this->month = m;
	this->day = d;
}
void Birth::setYear(int y)
{
	this->year = y;
}
void Birth::setMonth(int m)
{
	this->month = m;
}
void Birth::setDay(int d)
{
	this->day = d;
}
void Birth::reSet(int y, int m, int d)
{
	this->year = y;
	this->month = m;
	this->day = d;
}
//����int���ͳ�����������
int Birth::getBirthYear()
{
	return year;
}
int Birth::getBirthMonth()
{
	return month;
}
int Birth::getBirthDay()
{
	return day;
}
//����string���ͣ��������
string Birth::getBirth()
{
	string res;//�������ս��
	int t;//��������
	t = day;//һ��һ�������ֱ�Ϊchar�ͣ��ӵ������
	for (int i = 0; i < 2; i++)
	{
		res += t % 10+'0';
		t /= 10;
	}
	res += "-";
	t = month;
	for (int i = 0; i < 2; i++)
	{
		res += t % 10 + '0';
		t /= 10;
	}
	res += "-";
	t = year;
	for (int i = 0; i < 4; i++)
	{
		res += t % 10+'0';
		t /= 10;
	}
	reverse(res.begin(), res.end());//�������ת
	return res;
}
