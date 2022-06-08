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
	//������������
	CWorkMan();
	CWorkMan(char * name, int age, double salaryPerH, char* department, double IPH);
	CWorkMan(const CWorkMan & obj);
	virtual ~CWorkMan();

	//������ � ������
	void Set_IPH(double IPH);
	double Get_IPH();

	//�������� �������
	virtual void SendBills(int hours);
	virtual void ShowInfo();
	virtual double GetUnique();
	virtual void SetUnique(double value);
	virtual double work(double value, double add);
	//virtual bool comp(CWorker & w1, CWorker & w2);

	//����� �������
	double ProduceIce(int hours);

	//�������������� ���������
	CWorkMan& operator=(const CWorkMan& obj);
	friend CWorkMan operator> (const CWorkMan &obj1, const CWorkMan &obj2);
	friend CWorkMan operator< (const CWorkMan &obj1, const CWorkMan &obj2);
	friend ostream& operator<< (ostream &out, CWorkMan &obj);
	friend istream& operator>> (istream &in, CWorkMan &obj);
};
#endif