#include"adsbook.h"
//��ӡ������
void mainFace()
{
	cout << " ����������������������������������" << endl;
	cout << "|*****     ͨѶ¼����ϵͳ     *****|" << endl;
	cout << "|*         1���鿴��ϵ��          *|" << endl;
	cout << "|*         2�������ϵ��          *|" << endl;
	cout << "|*         3��ɾ����ϵ��          *|" << endl;
	cout << "|*         4��������ϵ��          *|" << endl;
	cout << "|*         5���޸���ϵ��          *|" << endl;
	cout << "|*         6�������ϵ��          *|" << endl;
	cout << "|*         0���˳�ͨѶ¼          *|" << endl;
	cout << " ����������������������������������" << endl;
}

//�������е��õ������ϵ�˺���
void AddadsMan(adsBook &adsbook)
{
	//���´������ϵ����Ϣ
	string name,tell,work,mail;
	int y, m, d;

	//����������ϵ�˵���Ϣ
	cout << "������������"; cin >> name; cout << endl;
	cout << "������������ڣ�ʹ�ÿո�ָ�����"; cin >> y >> m >> d; cout << endl;
	cout << "������绰���룺"; cin >> tell; cout << endl;
	cout << "�����빤����λ��"; cin >> work; cout << endl;
	cout << "������������䣺"; cin >> mail; cout << endl;

	Info temp(name, y, m, d, tell, work, mail);//������ʱ��Ϣ��

	//�������з������
	adsbook.addInfo(temp);
}

////�������е��õ�ɾ����ϵ�˺���
//ͨ������������绰���������ͽ���ɾ��
void DeleadsMan(adsBook& adsbook)
{
	int index;

	//��ӡ������Ϣ����ʾ�û������Ž���ɾ����ok�����ϵ���Ƿ�Ϊ��
	bool ok = adsbook.printInfo();
	if (ok)
	{
		cout << "�������ɾ����ϵ�˱�ţ�";
		cin >> index;
	}
	else return;

	//ok��ȡ�Ƿ�ɹ�
	ok = adsbook.deleInfo(index - 1);
	if (ok)cout << "ɾ���ɹ�" << endl;
	else cout << "ɾ��ʧ��" << endl;
}

//�������е��õĲ�����ϵ�˺���
void FindadsMan(adsBook& adsbook)
{
	string n;
	int coe;
	//������Ϣ����ɾ��
	cout << "��ѡ���Ժ��ַ�ʽ������ϵ�ˣ�0������ 1���绰��"; cin >> coe; cout << endl;
	cout << "�������������ϵ����Ϣ��"; cin >> n; cout << endl;

	//�������з�������
	adsbook.findInfo(n, coe);
}

//�������е��õ������ϵ�˺���
void ClearadsMan(adsBook& adsbook)
{
	int flag;
	cout << "ȷ���Ƿ����(1���� 2����)"; cin >> flag; cout << endl;
	
	if (flag)
	{
		adsbook.clearInfo();
		cout << "����ɹ�!" << endl;
	}

	else cout << "��ȡ�����!" << endl;
}

//�������е��õ��˳�������
void Exitprogram()
{
	int flag;//��¼�ж�
	cout << "�Ƿ�ȷ��(1���� 2����)��"; cin >> flag;
	if (flag == 1)//ȷ�Ϻ�����������˳�����
	{
		cout << "������˳�����" << endl;
		Sleep(3000);//ϵͳ�������룬����˳�
		exit(0);//�˳�����
	}
}

//�������е��õ��޸���ϵ����Ϣ����
void ModifyadsMan(adsBook& adsbook)
{
	string name, tell, work, mail;
	int y, m, d;
	int index;
	
	//�ȴ�ӡ��������ϵ��
	bool ok = adsbook.printInfo();
	if (!ok)return;
	
	cout << "��������޸���ϵ�˱��"; cin >> index; cout << endl;

	//����������ϵ�˵���Ϣ
	cout << "������������"; cin >> name; cout << endl;
	cout << "������������ڣ�ʹ�ÿո�ָ�����"; cin >> y >> m >> d; cout << endl;
	cout << "������绰���룺"; cin >> tell; cout << endl;
	cout << "�����빤����λ��"; cin >> work; cout << endl;
	cout << "������������䣺"; cin >> mail; cout << endl;
	Info temp(name, y, m, d, tell, work, mail);

	//��ȡ�Ƿ��޸ĳɹ�
ok=adsbook.modifyInfo(index-1, temp);

	if (ok)cout << "�޸ĳɹ�" << endl;
	else cout << "�޸�ʧ��" << endl;
}