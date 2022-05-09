#include"adsbook.h"
//构造函数用于读取文件中数据

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
	book.erase(book.end()-1);//最后一行为空，也会被读入
}
//析构函数用于写入文件
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
//添加一个信息
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
//根据输入数据类型进行删除
bool adsBook::deleInfo(int index)
{
	//判断选择是否正确
	if (index > book.size() || index < 0)return false;

	for (int i = 0; i < book.size(); i++)
	{
		if (i == index)
		{
			book.erase(book.begin() + i);//删除
			inFile();//写入文件
			return true;
		}
	}
	
}
//遍历容器中所有的元素，找到名字相同或者电话相同输出
void adsBook::findInfo(string n, int wayofdele)
{

	int reind[2000] ; int renum = 0;//记录多条联系人
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
	if (renum == 0)//未找到时直接返回
	{
		cout << "未能找到相对应联系人!" << endl;
		return ;
	}
	cout << "共找到 " << renum << " 条联系人记录" << endl;
	for (int i = 0; i < renum; i++)
	{
		book[reind[i]].PrintInfo();
	}
	return ;
}
//打印所有的联系人
bool adsBook::printInfo()
{
	if (book.size() == 0)
	{
		cout << "当前联系人为空!" << endl;
		return false;
	}
	for (int i = 0; i < book.size(); i++)
	{
		cout << "编号： " << i + 1;

		book[i].PrintInfo();//调用Info类中输出函数
	}
	return true;
}
bool adsBook::modifyInfo(int index, Info& in)
{
	if (index > book.size() || index < 0)//给出的编号超出范围
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
