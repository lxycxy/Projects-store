#include"adsbook.h"
//打印主界面
void mainFace()
{
	cout << " —————————————————" << endl;
	cout << "|*****     通讯录管理系统     *****|" << endl;
	cout << "|*         1、查看联系人          *|" << endl;
	cout << "|*         2、添加联系人          *|" << endl;
	cout << "|*         3、删除联系人          *|" << endl;
	cout << "|*         4、查找联系人          *|" << endl;
	cout << "|*         5、修改联系人          *|" << endl;
	cout << "|*         6、清空联系人          *|" << endl;
	cout << "|*         0、退出通讯录          *|" << endl;
	cout << " —————————————————" << endl;
}

//主函数中调用的添加联系人函数
void AddadsMan(adsBook &adsbook)
{
	//存下待添加联系人信息
	string name,tell,work,mail;
	int y, m, d;

	//输入待添加联系人的信息
	cout << "请输入姓名："; cin >> name; cout << endl;
	cout << "请输入出生日期（使用空格分隔）："; cin >> y >> m >> d; cout << endl;
	cout << "请输入电话号码："; cin >> tell; cout << endl;
	cout << "请输入工作单位："; cin >> work; cout << endl;
	cout << "请输入电子邮箱："; cin >> mail; cout << endl;

	Info temp(name, y, m, d, tell, work, mail);//创建临时信息类

	//调用类中方法添加
	adsbook.addInfo(temp);
}

////主函数中调用的删除联系人函数
//通过输入姓名或电话，给定类型进行删除
void DeleadsMan(adsBook& adsbook)
{
	int index;

	//打印所有信息再提示用户输入编号进行删除，ok标记联系人是否为空
	bool ok = adsbook.printInfo();
	if (ok)
	{
		cout << "请输入待删除联系人编号：";
		cin >> index;
	}
	else return;

	//ok读取是否成功
	ok = adsbook.deleInfo(index - 1);
	if (ok)cout << "删除成功" << endl;
	else cout << "删除失败" << endl;
}

//主函数中调用的查找联系人函数
void FindadsMan(adsBook& adsbook)
{
	string n;
	int coe;
	//输入信息进行删除
	cout << "请选择以何种方式查找联系人（0、姓名 1、电话）"; cin >> coe; cout << endl;
	cout << "请输入待查找联系人信息："; cin >> n; cout << endl;

	//调用类中方法查找
	adsbook.findInfo(n, coe);
}

//主函数中调用的清空联系人函数
void ClearadsMan(adsBook& adsbook)
{
	int flag;
	cout << "确认是否清空(1、是 2、否)"; cin >> flag; cout << endl;
	
	if (flag)
	{
		adsbook.clearInfo();
		cout << "清除成功!" << endl;
	}

	else cout << "已取消清空!" << endl;
}

//主函数中调用的退出程序函数
void Exitprogram()
{
	int flag;//记录判断
	cout << "是否确认(1、是 2、否)："; cin >> flag;
	if (flag == 1)//确认后休眠三秒后退出程序
	{
		cout << "三秒后将退出程序" << endl;
		Sleep(3000);//系统休眠三秒，随后退出
		exit(0);//退出程序
	}
}

//主函数中调用的修改联系人信息函数
void ModifyadsMan(adsBook& adsbook)
{
	string name, tell, work, mail;
	int y, m, d;
	int index;
	
	//先打印出所有联系人
	bool ok = adsbook.printInfo();
	if (!ok)return;
	
	cout << "请输入待修改联系人编号"; cin >> index; cout << endl;

	//输入待添加联系人的信息
	cout << "请输入姓名："; cin >> name; cout << endl;
	cout << "请输入出生日期（使用空格分隔）："; cin >> y >> m >> d; cout << endl;
	cout << "请输入电话号码："; cin >> tell; cout << endl;
	cout << "请输入工作单位："; cin >> work; cout << endl;
	cout << "请输入电子邮箱："; cin >> mail; cout << endl;
	Info temp(name, y, m, d, tell, work, mail);

	//读取是否修改成功
ok=adsbook.modifyInfo(index-1, temp);

	if (ok)cout << "修改成功" << endl;
	else cout << "修改失败" << endl;
}