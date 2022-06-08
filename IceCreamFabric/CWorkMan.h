#pragma once
#include <iostream>
#include "CWorker.h"
using namespace std;

#ifndef WorkMan
#define WorkMan
class CWorkMan: virtual public CWorker {
protected:
	double IPH;
public:
	//конструктори
	CWorkMan();
	CWorkMan(char * name, int age, double salaryPerH, char* department, double IPH);
	CWorkMan(const CWorkMan & obj);
	virtual ~CWorkMan();

	//гетери і сетери
	void Set_IPH(double IPH);
	double Get_IPH();

	//віртуальні функції
	virtual void SendBills(int hours);
	virtual void ShowInfo();
	virtual double GetUnique();
	virtual void SetUnique(double value);
	virtual double work(double value, double add);
	//virtual bool comp(CWorker & w1, CWorker & w2);

	//власні функції
	double ProduceIce(int hours);

	//перевантаження операторів
	CWorkMan& operator=(const CWorkMan& obj);
	friend CWorkMan operator> (const CWorkMan &obj1, const CWorkMan &obj2);
	friend CWorkMan operator< (const CWorkMan &obj1, const CWorkMan &obj2);
	friend ostream& operator<< (ostream &out, CWorkMan &obj);
	friend istream& operator>> (istream &in, CWorkMan &obj);
};
#endif