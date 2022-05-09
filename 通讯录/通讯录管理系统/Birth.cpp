#include"adsbook.h"
//Birth类方法定义
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
//返回int类型出生日期数据
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
//返回string类型，方便操作
string Birth::getBirth()
{
	string res;//定义最终结果
	int t;//单个数字
	t = day;//一步一步把数字变为char型，加到结果上
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
	reverse(res.begin(), res.end());//做完后逆转
	return res;
}
