//CSellingRoom.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CSellingRoom.h"
#include "CWorker.h"
#include "CSeller.h"
#include <algorithm>
#include <vector>
using namespace std;

CSellingRoom::CSellingRoom() : CDepartment()
{
	money = 0;
}
CSellingRoom::CSellingRoom(char * name, vector<CWorker*> workers, double money, vector<CIce*> menu) : CDepartment(name, workers)
{
	Set_Money(money);
	Set_Menu(menu);
}
CSellingRoom::CSellingRoom(const CSellingRoom& obj) : CDepartment(obj)
{
	money = obj.money;
}
CSellingRoom::~CSellingRoom()
{

}

void CSellingRoom::Set_Money(double money)
{
	this->money = money;
}
double CSellingRoom::Get_Money()
{
	return money;
}
void CSellingRoom::Set_Menu(vector<CIce*> menu)
{
	for (int i = 0; i < menu.size(); i++)
		this->menu.push_back(menu.at(i));
}
vector<CIce*> CSellingRoom::Get_Menu()
{
	return menu;
}

void CSellingRoom::HireWorker(CWorker & c)
{
	cout << "Hire\n";
}

double CSellingRoom::SendBills(double value)
{
	return workers.at(workers.size() - 1)->Get_SalaryPerH() + (value / 10);
}

double CSellingRoom::SellIce(double kg, int iceIndx)
{
	vector<double> prices;
	srand(time(NULL));
	double num;
	for (int i = 0; i < workers.size(); i++)
	{
		num = 1 + ((double)rand() / RAND_MAX) * (2 - 1);
		workers.at(i)->SetUnique(num);
		prices.push_back(num);
	}

	int maxElementIndex = max_element(prices.begin(), prices.end()) - prices.begin();
	int moneyFromDeal = workers.at(maxElementIndex)->work(kg, menu.at(iceIndx)->Get_Price());

	cout << "|||�������������� ��������� " << name << " �� " << workers.at(maxElementIndex)->Get_Name() << endl;
	cout << "������� " << kg << " ������� �������� " << menu.at(iceIndx)->Get_Name() <<
		" �� ����� " << moneyFromDeal << " �������" << endl;
	cout << "������� �� ������� ��������: " << menu.at(iceIndx)->Get_Price() << " �������" << endl;
	cout << "ֳ�� �� ���� ������� ������� ��������: " << menu.at(iceIndx)->Get_Price()* workers.at(maxElementIndex)->GetUnique() << " �������" << endl;
	cout << "���� ������� ����������� " << workers.at(maxElementIndex)->Get_Name() << " �� ������������ " <<
		workers.at(maxElementIndex)->GetUnique() << " �� �������" << endl;
	money += moneyFromDeal;

	cout << "||������ �������� ���������� " << name << " " << workers.at(maxElementIndex)->Get_Name() <<
		" � ������� " << SendBills(moneyFromDeal) << " �������." << endl;
	return moneyFromDeal;
}

void CSellingRoom::ShowInfo()
{
	cout << "�����: " << this->name << endl;
	cout << "ʳ������ ������� � ����������: " << this->money << endl;
}


void CSellingRoom::ShowMenu()
{
	cout << "������ �������� ���������� ��� ����������� �� �������:\n";
	for (int i = 0; i < menu.size(); i++)
	{
		cout << "�" << i+1 << "__________________________\n";
		menu.at(i)->ShowInfo();
		cout << "__________________________\n";
	}
}

CSellingRoom& CSellingRoom::operator=(const CSellingRoom& obj)
{
	if (this != &obj)
	{
		delete[] name;
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);

	}
	return *this;
}
