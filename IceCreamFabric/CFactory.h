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
	//������������
	CFactory();
	CFactory(char * name, vector<CWorker*> workers);
	CFactory(const CFactory & obj);
	virtual ~CFactory();

	//������ � ������
	void Set_TotalIPH(vector<CWorker*> workers);
	double Get_TotalIPH();

	//�������� �������
	virtual void HireWorker(CWorker & c);
	virtual void ShowInfo();

	//����� �������
	double ProduceIce(int hours);
	virtual double SendBills(double value);

	//�������������� ���������
	CFactory& operator=(const CFactory& obj);
	/*friend ostream& operator<< (ostream &out, CFactory &obj);
	friend istream& operator>> (istream &in, CFactory &obj);*/
};
#endif