#include<iostream>
#include"tab.h"
#include"Trigonometric.h"
#include"arctan.h"
#include"menu.h"
using namespace std;
int main()
{
	cout.precision(16);
	int select = 10;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
		{
			double beta;
			int n;
			cout << "������Ƕ�beta=" << endl;
			cin >> beta;
			cout << "�������������n=" << endl;
			cin >> n;
			struct Result r = Trigonometric(beta, n);
			cout << "sin(beta)=" << r.sine << endl;
			cout << "cosin(beta)=" << r.cosine << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			double numy;
			cout << "����������ֵ��" << endl;
			cin >> numy;
			double angle = arctan(numy);
			cout << "��Ӧ�Ƕ�Ϊ��" << angle << endl;
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			system("pause");
			return 0;
		}
		}
	}
}