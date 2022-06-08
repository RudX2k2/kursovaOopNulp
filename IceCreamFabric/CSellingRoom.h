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
	//конструктори
	CSellingRoom();
	CSellingRoom(char * name, vector<CWorker*> workers, double money, vector<CIce*> menu);
	CSellingRoom(const CSellingRoom & obj);
	virtual ~CSellingRoom();

	//гетери і сетери
	void Set_Money(double money);
	double Get_Money();
	void Set_Menu(vector<CIce*> menu);
	vector<CIce*> Get_Menu();

	//віртуальні функції
	virtual void HireWorker(CWorker & c);
	virtual double SendBills(double value);
	virtual void ShowInfo();

	//власні функції
	double SellIce(double kg, int iceIndx);
	void ShowMenu();

	//перевантаження операторів
	CSellingRoom& operator=(const CSellingRoom& obj);
	/*friend ostream& operator<< (ostream &out, CSellingRoom &obj);
	friend istream& operator>> (istream &in, CSellingRoom &obj);*/
};
#endif