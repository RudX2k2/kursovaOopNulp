//CWorker.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "CWorker.h"
#include <iostream>
using namespace std;

CWorker::CWorker() : name(new char[30]), department(new char[30])
{
	strcpy(name, "No name");
	age = 0;
	salaryPerH = 0;
	strcpy(department, "No department");
}
CWorker::CWorker(char* name, int age, double salaryPerH, char* department)
{
	Set_Name(name);
	Set_Age(age);
	Set_SalaryPerH(salaryPerH);
	Set_Department(department);
}
CWorker::CWorker(const CWorker& obj)
{
		delete[] name;
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		age = obj.age;
		salaryPerH = obj.salaryPerH;
		delete[] department;
		department = new char[strlen(obj.department) + 1];
		strcpy(department, obj.department);
}
CWorker::~CWorker()
{
	delete[] name;
	delete[] department;
}

void CWorker::Set_Name(char * name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
char * CWorker::Get_Name()
{
	return this->name;
}

void CWorker::Set_Age(int age)
{
	this->age = age;
}
int CWorker::Get_Age()
{
	return age;
}

void CWorker::Set_Department(char* department)
{
	this->department = new char[strlen(department) + 1];
	strcpy(this->department, department);
}
char* CWorker::Get_Department()
{
	return this->department;
}

void CWorker::Set_SalaryPerH(double salaryPerH)
{
	this->salaryPerH = salaryPerH;
}
double CWorker::Get_SalaryPerH()
{
	return salaryPerH;
}

bool CWorker::operator!=(CWorker &obj)
{
	return (this->salaryPerH != obj.salaryPerH) ? true : false;
}
CWorker& CWorker::operator=(const CWorker& obj)
{
	if (this != &obj)
	{
		delete[] name;
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		delete[] department;
		department = new char[strlen(obj.department) + 1];
		strcpy(department, obj.department);
	}
	return *this;
}
ostream& operator<< (ostream &out, CWorker &obj)
{
	out << "Data about worker:\n";
	out << "Name: " << obj.name << endl;
	out << "\nAge: " << obj.age << endl;
	out << "\nSalary per hour of work:" << obj.salaryPerH << endl;
	out << "\nDepartment: " << obj.department << endl;

	return out;
}
istream& operator>> (istream &in, CWorker &obj)
{
	/*delete[] obj.name;
	int age;
	double salaryPerH;
	char* department;
	cout << "Enter name: \n";
	string strtmp;
	cin >> strtmp;
	const char* tmp = strtmp.c_str();*/
	return in;
}