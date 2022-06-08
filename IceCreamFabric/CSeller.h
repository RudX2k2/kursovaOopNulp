#pragma once
#include <iostream>
#include "CWorker.h"
using namespace std;

#ifndef Seller
#define Seller
class CSeller : virtual public CWorker {
protected:
	double coefSelling;
public:
	//конструктори
	CSeller();
	CSeller(char * name, int age, double pricePerOperation, char* department, double pricePerKg);
	CSeller(const CSeller & obj);
	virtual ~CSeller();

	//гетери і сетери
	void Set_CoefSelling(double coefSelling);
	double Get_CoefSelling();

	//віртуальні функції
	virtual void SendBills(int hours);
	virtual void ShowInfo();
	virtual double GetUnique();
	virtual void SetUnique(double value);
	virtual double work(double value, double add);
	//virtual bool comp(CWorker & w1, CWorker & w2);

	//власні функції
	double SellIce(double kg);

	//перевантаження операторів
	CSeller& operator=(const CSeller& obj);
	friend CSeller operator> (const CSeller &obj1, const CSeller &obj2);
	friend CSeller operator< (const CSeller &obj1, const CSeller &obj2);
	friend ostream& operator<< (ostream &out, CSeller &obj);
	friend istream& operator>> (istream &in, CSeller &obj);
};
#endif