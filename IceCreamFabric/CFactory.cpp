//CFactory.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CFactory.h"
#include "CWorker.h"
#include <vector>
#include <iostream>
using namespace std;

CFactory::CFactory() : CDepartment()
{
	TotalIPH = 0;
}
CFactory::CFactory(char * name, vector<CWorker*> workers) : CDepartment(name, workers)
{
	Set_TotalIPH(workers);
}
CFactory::CFactory(const CFactory& obj) : CDepartment(obj)
{
	TotalIPH = obj.TotalIPH;
}
CFactory::~CFactory()
{

}

void CFactory::Set_TotalIPH(vector<CWorker*> workers)
{
	for (int i = 0; i < workers.size(); i++)
	{
		TotalIPH += workers.at(i)->GetUnique();
	}
}
double CFactory::Get_TotalIPH()
{
	return TotalIPH;
}

double CFactory::SendBills(double value)
{
	double bill = 0;
	for (int i = 0; i < workers.size(); i++)
		bill += workers.at(i)->Get_SalaryPerH()*(int)value;
	return bill;
}

void CFactory::HireWorker(CWorker & c)
{

}

double CFactory::ProduceIce(int hours)
{
	return hours * TotalIPH;
}

void CFactory::ShowInfo()
{
	cout << "Назва: " << this->name << endl;
	cout << "Загальна кількість виробництва кілограм морозива в годину: " << this->TotalIPH << endl;
}

CFactory& CFactory::operator=(const CFactory& obj)
{
	if (this != &obj)
	{
		delete[] name;
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		
	}
	return *this;
}