#pragma once
#include<string>
#include<iomanip>
#include<iostream>
#include<vector>
#include<Windows.h>
#include<fstream>
using namespace std;
enum RESARCHWAY { NamePatterm, TellPattern };
//���������Ϣ�еĳ�������
class Birth
{
	int year;//������
	int month;//������
	int day;//������
public:

	Birth(int , int , int );//��ʼ�������ꡢ�¡���
	string getBirth();//ʹintת��string�ͣ��ٷ���

	//�޸Ļ������ꡢ�¡���
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	void reSet(int, int, int);

	//����int�͵��ꡢ�¡���
	int getBirthYear();
	int getBirthMonth();
	int getBirthDay();
	
};
//����ͨѶ¼�е���Ϣ�Լ���Ϣ������
class Info
{
	Birth birth;//����
	string Name;//����
	string Tellnum;//�绰����
	string Workplace;//������λ
	string Adsmail;//����

public:
	//��ʼ������
	Info(string, int , int , int , string, string, string);

	//�޸Ļ���������
	void reSetName(string);
	void reSetBirthYear(int);
	void reSetBirthMonth(int);
	void reSetBirthDay(int);
	void reSetTellnum(string);
	void reSetWorkplace(string);
	void reSetAdsmail(string);
	void reSetBirth(int y, int m, int d);

	//���ض�Ӧ���͵�����
	string getName();
	string getTellnum();
	string getWorkplace();
	string getAdsmail();
	int getBirthYear();
	int getBirthMonth();
	int getBirthDay();

	//��ӡ��Ϣ
	void PrintInfo();
};
//����ͨѶ¼�Լ�������
class adsBook
{
	vector<Info>book;//vector��ȡ��Ϣ

public:
	//��ʼ�����ݣ��������ı��ļ��ж�ȡ
	adsBook();

	//�޸���������Ϣ
	void addInfo(const Info& in);
	void addInfo(string, int, int, int, string, string, string);
	bool deleInfo(int);
	void findInfo(string,int);
	bool modifyInfo(int , Info&);
	void clearInfo();

	//��ӡ������Ϣ
	bool printInfo();

	//����д���ļ�
	void inFile();
};
void mainFace();//�����溯��
void AddadsMan(adsBook&);//�����ϵ��
void DeleadsMan(adsBook&);//ɾ����ϵ��
void FindadsMan(adsBook&);//������ϵ��
void ClearadsMan(adsBook&);//�����ϵ��
void ModifyadsMan(adsBook&);//�޸���ϵ����Ϣ
void Exitprogram();//�˳�����
