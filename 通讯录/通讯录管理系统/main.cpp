#include"adsbook.h"

int main()
{
	
	int coe;//ѡ������
	adsBook adsbook;//ͨѶ¼�������
	
	while (true)//���汣��
	{
		
		mainFace();//�����ܽ���

		cout << "��ѡ���ܣ�"; cin >> coe;//ѡ���ܲ���

		//��Ӧ���ܵ�����غ���
		switch (coe)
		{
		case 0:Exitprogram();//�˳�����
			break;
		case 1:adsbook.printInfo();//�鿴��ϵ��
			break;
		case 2:AddadsMan(adsbook);//�����ϵ��
			break;
		case 3:DeleadsMan(adsbook);//ɾ����ϵ��
			break;
		case 4:FindadsMan(adsbook);//������ϵ��
			break;
		case 5:ModifyadsMan(adsbook);//�޸���ϵ��
			break;
		case 6:ClearadsMan(adsbook);//�����ϵ��
			break;
			
		}
		system("pause");//��ֹ����
		system("cls");//�����һ�Σ�����������
	}
	return 0;
}