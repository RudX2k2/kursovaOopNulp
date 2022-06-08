#pragma once
#include <iostream>
#include <vector>
#include "CWorker.h"
using namespace std;

#ifndef Department
#define Department
class CDepartment {
protected:
	char* name;
	vector<CWorker*> workers;
public:
	//�����������
	CDepartment();
	CDepartment(char * name, vector<CWorker*> workers);
	CDepartment(const CDepartment & obj);
	virtual ~CDepartment();

	//������ � ������
	void Set_Name(char * name);
	char * Get_Name();

	void Set_Workers(vector<CWorker*> workers);
	vector<CWorker*> Get_Workers();

	//����� �������� �������
	virtual void ShowInfo() = 0;
	void ShowWorkers();
	virtual double SendBills(double value) = 0;
	virtual void HireWorker(CWorker & c) = 0;

	//�������������� ���������
	CDepartment& operator=(const CDepartment& obj);
	bool operator!=(CDepartment &obj);
	friend ostream& operator<< (ostream &out, CDepartment &obj);
	friend istream& operator>> (istream &in, CDepartment &obj);
};
#endif