//CWorkMan.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "CWorkMan.h"
#include <iostream>
using namespace std;

CWorkMan::CWorkMan() : CWorker()
{
	IPH = 0;
}
CWorkMan::CWorkMan(char* name, int age, double salaryPerH, char* department, double IPH) : CWorker(name, age, salaryPerH, department)
{
	Set_IPH(IPH);
}
CWorkMan::CWorkMan(const CWorkMan& obj) : CWorker(obj)
{
	Set_IPH(obj.IPH);
}
CWorkMan::~CWorkMan()
{

}

void CWorkMan::Set_IPH(double IPH)
{
	this->IPH = IPH;
}
double CWorkMan::Get_IPH()
{
	return IPH;
}

double CWorkMan::ProduceIce(int hours)
{
	return IPH * hours;
}

void CWorkMan::SendBills(int hours)
{
	this->salaryPerH*hours;
}
void CWorkMan::ShowInfo()
{
	cout << "\n___Інформація про робітника___" << endl;
	cout << "Ім'я: " << this->name << endl;
	cout << "Вік: " << this->age << endl;
	cout << "Зарплатня за годину роботи: " << this->salaryPerH << endl;
	cout << "Відділ роботи: " << this->department << endl;
	cout << "Кількість морозива виготовленого працівником за 1 годину: " << this->IPH << endl;
	cout << "Зарплатня за годину роботи: " << this->salaryPerH << endl;

}
double CWorkMan::GetUnique()
{
	return IPH;
}
void CWorkMan::SetUnique(double value)
{
	IPH = value;
}

double CWorkMan::work(double value, double add)//hours
{
	return IPH * value;
}

CWorkMan operator> (const CWorkMan &obj1, const CWorkMan &obj2)
{
	if (obj1.IPH > obj2.IPH)
		return obj1;
	return obj2;
}
CWorkMan operator< (const CWorkMan &obj1, const CWorkMan &obj2)
{
	if (obj1.IPH < obj2.IPH)
		return obj2;
	return obj1;
}
CWorkMan& CWorkMan::operator=(const CWorkMan& obj)
{
	if (this != &obj)
	{
		delete[] name;
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		delete[] department;
		department = new char[strlen(obj.department) + 1];
		strcpy(department, obj.department);
		IPH = obj.IPH;
	}
	return *this;
}
ostream& operator<< (ostream &out, CWorkMan &obj)
{
	out << "Data about worker:\n";
	out << "Name: " << obj.name << endl;
	out << "\nAge: " << obj.age << endl;
	out << "\nSalary per hour of work:" << obj.salaryPerH << endl;
	out << "\nDepartment: " << obj.department << endl;

	return out;
}
istream& operator>> (istream &in, CWorkMan &obj)
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