#pragma once
#include<string>
#include<iomanip>
#include<iostream>
#include<vector>
#include<Windows.h>
#include<fstream>
using namespace std;
enum RESARCHWAY { NamePatterm, TellPattern };
//定义个人信息中的出生日期
class Birth
{
	int year;//出生年
	int month;//出生月
	int day;//出生日
public:

	Birth(int , int , int );//初始化出生年、月、日
	string getBirth();//使int转到string型，再返回

	//修改或设置年、月、日
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	void reSet(int, int, int);

	//返回int型的年、月、日
	int getBirthYear();
	int getBirthMonth();
	int getBirthDay();
	
};
//定义通讯录中的信息以及信息处理方法
class Info
{
	Birth birth;//日期
	string Name;//姓名
	string Tellnum;//电话号码
	string Workplace;//工作单位
	string Adsmail;//邮箱

public:
	//初始化数据
	Info(string, int , int , int , string, string, string);

	//修改或设置数据
	void reSetName(string);
	void reSetBirthYear(int);
	void reSetBirthMonth(int);
	void reSetBirthDay(int);
	void reSetTellnum(string);
	void reSetWorkplace(string);
	void reSetAdsmail(string);
	void reSetBirth(int y, int m, int d);

	//返回对应类型的数据
	string getName();
	string getTellnum();
	string getWorkplace();
	string getAdsmail();
	int getBirthYear();
	int getBirthMonth();
	int getBirthDay();

	//打印信息
	void PrintInfo();
};
//定义通讯录以及管理方法
class adsBook
{
	vector<Info>book;//vector存取信息

public:
	//初始化数据，从数据文本文件中读取
	adsBook();

	//修改容器中信息
	void addInfo(const Info& in);
	void addInfo(string, int, int, int, string, string, string);
	bool deleInfo(int);
	void findInfo(string,int);
	bool modifyInfo(int , Info&);
	void clearInfo();

	//打印所有信息
	bool printInfo();

	//数据写入文件
	void inFile();
};
void mainFace();//主界面函数
void AddadsMan(adsBook&);//添加联系人
void DeleadsMan(adsBook&);//删除联系人
void FindadsMan(adsBook&);//查找联系人
void ClearadsMan(adsBook&);//清空联系人
void ModifyadsMan(adsBook&);//修改联系人信息
void Exitprogram();//退出程序
