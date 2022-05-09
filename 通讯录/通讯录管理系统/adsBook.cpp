#include"adsbook.h"
//���캯�����ڶ�ȡ�ļ�������

adsBook::adsBook()
{
	
	fstream In;
	In.open("adsmans.txt", ios::in);
	string n; int y; int m; int d; string tell; string work; string email;
	while (!In.eof())
	{
		In >> n >> y >> m >> d >> tell >> work >> email;
		book.push_back(Info(n, y, m, d, tell, work, email));
	}
	book.erase(book.end()-1);//���һ��Ϊ�գ�Ҳ�ᱻ����
}
//������������д���ļ�
void adsBook::inFile()
{
	fstream out;
	out.open("adsmans.txt",ios::trunc|ios::out);
	for (int i = 0; i < book.size(); i++)
	{
		out << book[i].getName() << " " << book[i].getBirthYear() << " " << book[i].getBirthMonth() << " "
			<< book[i].getBirthDay() << " " << book[i].getTellnum() << " " << book[i].getWorkplace() << " "
			<< book[i].getAdsmail() << endl;
	}
}
//���һ����Ϣ
void adsBook::addInfo(const Info & in)
{
	book.push_back(in);
	inFile();
}
void adsBook::addInfo(string n, int y , int m, int d, string tell, string work, string email)
{
	Info in(n, y, m, d, tell, work, email);
	book.push_back(in);
	inFile();
}
void adsBook::clearInfo()
{
	book.clear();
	inFile();
}
//���������������ͽ���ɾ��
bool adsBook::deleInfo(int index)
{
	//�ж�ѡ���Ƿ���ȷ
	if (index > book.size() || index < 0)return false;

	for (int i = 0; i < book.size(); i++)
	{
		if (i == index)
		{
			book.erase(book.begin() + i);//ɾ��
			inFile();//д���ļ�
			return true;
		}
	}
	
}
//�������������е�Ԫ�أ��ҵ�������ͬ���ߵ绰��ͬ���
void adsBook::findInfo(string n, int wayofdele)
{

	int reind[2000] ; int renum = 0;//��¼������ϵ��
	if (wayofdele == RESARCHWAY::NamePatterm)
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].getName() == n)reind[renum++] = i;
			
		}
	}
	else if (wayofdele == RESARCHWAY::TellPattern)
	{
		for (int i = 0; i < book.size(); i++)
		{
			if (book[i].getTellnum() == n)reind[renum++] = i;
		}
	}
	if (renum == 0)//δ�ҵ�ʱֱ�ӷ���
	{
		cout << "δ���ҵ����Ӧ��ϵ��!" << endl;
		return ;
	}
	cout << "���ҵ� " << renum << " ����ϵ�˼�¼" << endl;
	for (int i = 0; i < renum; i++)
	{
		book[reind[i]].PrintInfo();
	}
	return ;
}
//��ӡ���е���ϵ��
bool adsBook::printInfo()
{
	if (book.size() == 0)
	{
		cout << "��ǰ��ϵ��Ϊ��!" << endl;
		return false;
	}
	for (int i = 0; i < book.size(); i++)
	{
		cout << "��ţ� " << i + 1;

		book[i].PrintInfo();//����Info�����������
	}
	return true;
}
bool adsBook::modifyInfo(int index, Info& in)
{
	if (index > book.size() || index < 0)//�����ı�ų�����Χ
	{
		return false;
	}
	else
	{
		book[index] = in;
		inFile();
		return true;
	}
}
