#pragma once
#include <iostream>
#include "CWorker.h"
using namespace std;

#ifndef Worker
#define Worker
class CWorker{
protected:
	char* name;
	int age;
	double salaryPerH;
	char* department;
public:
	//конструктори
	CWorker();
	CWorker(char* name, int age, double salaryPerH, char* department);
	CWorker(const CWorker & obj);
	virtual ~CWorker();

	//гетери і сетери
	void Set_Name(char * name);
	char * Get_Name();

	void Set_Age(int age);
	int Get_Age();

	void Set_Department(char* department);
	char* Get_Department();

	void Set_SalaryPerH(double salaryPerH);
	double Get_SalaryPerH();

	//віртуальні функції
	virtual void SendBills(int hours) = 0;
	virtual void ShowInfo() = 0;
	virtual double GetUnique() = 0;
	virtual void SetUnique(double value) = 0;
	virtual double work(double value, double add) = 0;

	//перевантаження операторів
	CWorker& operator=(const CWorker& obj);
	bool operator!=(CWorker &obj);
	friend ostream& operator<< (ostream &out, CWorker &obj);
	friend istream& operator>> (istream &in, CWorker &obj);
};
#endif