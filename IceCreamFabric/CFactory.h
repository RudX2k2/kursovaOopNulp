#pragma once
#include <iostream>
#include "CDepartment.h"
#include <vector>
#include "CWorkMan.h"
using namespace std;

#ifndef Factory
#define Factory
class CFactory : virtual public CDepartment {
protected:
	double TotalIPH;
public:
	//конструктори
	CFactory();
	CFactory(char * name, vector<CWorker*> workers);
	CFactory(const CFactory & obj);
	virtual ~CFactory();

	//гетери і сетери
	void Set_TotalIPH(vector<CWorker*> workers);
	double Get_TotalIPH();

	//віртуальні функції
	virtual void HireWorker(CWorker & c);
	virtual void ShowInfo();

	//власні функції
	double ProduceIce(int hours);
	virtual double SendBills(double value);

	//перевантаження операторів
	CFactory& operator=(const CFactory& obj);
	/*friend ostream& operator<< (ostream &out, CFactory &obj);
	friend istream& operator>> (istream &in, CFactory &obj);*/
};
#endif