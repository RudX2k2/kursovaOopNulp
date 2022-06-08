#pragma once
#include <iostream>
#include "CDepartment.h"
#include "CWorkMan.h"
#include "CIce.h"
#include <ctime>
#include <vector>

using namespace std;

#ifndef SellingRoom
#define SellingRoom
class CSellingRoom : virtual public CDepartment {
protected:
	double money;
	vector<CIce*> menu;
public:
	//������������
	CSellingRoom();
	CSellingRoom(char * name, vector<CWorker*> workers, double money, vector<CIce*> menu);
	CSellingRoom(const CSellingRoom & obj);
	virtual ~CSellingRoom();

	//������ � ������
	void Set_Money(double money);
	double Get_Money();
	void Set_Menu(vector<CIce*> menu);
	vector<CIce*> Get_Menu();

	//�������� �������
	virtual void HireWorker(CWorker & c);
	virtual double SendBills(double value);
	virtual void ShowInfo();

	//����� �������
	double SellIce(double kg, int iceIndx);
	void ShowMenu();

	//�������������� ���������
	CSellingRoom& operator=(const CSellingRoom& obj);
	/*friend ostream& operator<< (ostream &out, CSellingRoom &obj);
	friend istream& operator>> (istream &in, CSellingRoom &obj);*/
};
#endif