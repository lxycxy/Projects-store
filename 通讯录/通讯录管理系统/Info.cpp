#include"adsbook.h"
//ͨѶ¼��Ϣ�ඨ���Լ���������
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
//���û��߸�������
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
//��ӡ��Ϣ
void Info::PrintInfo()
{
	cout << "\t������" << Name << "\t�������ڣ�" << birth.getBirth() << "\t�绰���룺" << Tellnum
		<< "\t������λ��" << Workplace << "\t�������䣺" << Adsmail << endl;
}