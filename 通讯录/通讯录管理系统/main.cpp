#include"adsbook.h"

int main()
{
	
	int coe;//选择输入
	adsBook adsbook;//通讯录管理对象
	
	while (true)//界面保持
	{
		
		mainFace();//主功能界面

		cout << "请选择功能："; cin >> coe;//选择功能操作

		//对应功能调用相关函数
		switch (coe)
		{
		case 0:Exitprogram();//退出程序
			break;
		case 1:adsbook.printInfo();//查看联系人
			break;
		case 2:AddadsMan(adsbook);//添加联系人
			break;
		case 3:DeleadsMan(adsbook);//删除联系人
			break;
		case 4:FindadsMan(adsbook);//查找联系人
			break;
		case 5:ModifyadsMan(adsbook);//修改联系人
			break;
		case 6:ClearadsMan(adsbook);//清空联系人
			break;
			
		}
		system("pause");//防止闪退
		system("cls");//清除上一次，保持主界面
	}
	return 0;
}