#include"adsbook.h"
//通讯录信息类定义以及方法定义
Info::Info(string name, int y,int m,int d, string tell, string wkplace, string email):birth(y,m,d)
{
	this->Name = name;
	this->Tellnum = tell;
	this->Workplace = wkplace;
	this->Adsmail = email;
}
string Info::getName()
{
	return this->Name;
}
string Info::getTellnum()
{
	return this->Tellnum;
}
string Info::getWorkplace()
{
	return this->Workplace;
}
string Info::getAdsmail()
{
	return this->Adsmail;
}
int Info::getBirthYear()
{
	return birth.getBirthYear();
}
int Info::getBirthMonth()
{
	return birth.getBirthMonth();
}
int Info::getBirthDay()
{
	return birth.getBirthDay();
}
//设置或者更新数据
void Info::reSetName(string name)
{
	this->Name = name;
}
void Info::reSetTellnum(string t)
{
	this->Tellnum = t;
}
void Info::reSetAdsmail(string t)
{
	this->Adsmail = t;
}
void Info::reSetBirthYear(int y)
{
	birth.setYear(y);
}
void Info::reSetBirthMonth(int m)
{
	birth.setMonth(m);
}
void Info::reSetBirthDay(int d)
{
	birth.setDay(d);
}
void Info::reSetBirth(int y, int m, int d)
{
	birth.reSet(y, m, d);
}
void Info::reSetWorkplace(string m)
{
	this->Workplace = m;
}
//打印信息
void Info::PrintInfo()
{
	cout << "\t姓名：" << Name << "\t出生日期：" << birth.getBirth() << "\t电话号码：" << Tellnum
		<< "\t工作单位：" << Workplace << "\t电子邮箱：" << Adsmail << endl;
}