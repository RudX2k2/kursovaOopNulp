//CSeller.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "CSeller.h"
#include <iostream>
using namespace std;

CSeller::CSeller() : CWorker()
{
	coefSelling = 1;
}
CSeller::CSeller(char* name, int age, double pricePerOperation, char* department, double coefSelling) : CWorker(name, age, salaryPerH, department)
{
	Set_CoefSelling(coefSelling);
}
CSeller::CSeller(const CSeller& obj) : CWorker(obj)
{
	Set_CoefSelling(obj.coefSelling);
}
CSeller::~CSeller()
{

}

void CSeller::Set_CoefSelling(double coefSelling)
{
	this->coefSelling = coefSelling;
}
double CSeller::Get_CoefSelling()
{
	return coefSelling;
}

double CSeller::SellIce(double kg)
{
	return kg * coefSelling;
}

void CSeller::SendBills(int hours)
{
	this->pricePerOperation*hours;
}
void CSeller::ShowInfo()
{
	cout << "\n___���������� ��� ��������___" << endl;
	cout << "��'�: " << this->name << endl;
	cout << "³�: " << this->age << endl;
	cout << "³��� ������: " << this->department << endl;
	cout << "���������� � ������ ��������� ����� 1 �� ��������: " << this->coefSelling << endl;
	cout << "��������� �� ������ ������: " << this->salaryPerH << endl;
}

double CSeller::GetUnique()
{
	return coefSelling;
}

void CSeller::SetUnique(double value)
{
	coefSelling = value;
}

double CSeller::work(double value, double add)//������� �������� �� ���� ��������
{
	return value * add * coefSelling;
}


CSeller operator> (const CSeller &obj1, const CSeller &obj2)
{
	if (obj1.coefSelling > obj2.coefSelling)
		return obj1;
	return obj2;
}
CSeller operator< (const CSeller &obj1, const CSeller &obj2)
{
	if (obj1.coefSelling < obj2.coefSelling)
		return obj2;
	return obj1;
}
CSeller& CSeller::operator=(const CSeller& obj)
{
	if (this != &obj)
	{
		delete[] name;
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		delete[] department;
		department = new char[strlen(obj.department) + 1];
		strcpy(department, obj.department);
		coefSelling = obj.coefSelling;
	}
	return *this;
}
ostream& operator<< (ostream &out, CSeller &obj)
{
	out << "___���������� ��� ��������___" << endl;
	out << "��'�: " << obj.name << endl;
	out << "³�: " << obj.age << endl;
	out << "�����������: " << obj.department << endl;
	out << "���������� � ������ ��������� ����� 1 �� ��������: " << obj.coefSelling << endl;
	out << "��������� �� ������ ������: " << obj.salaryPerH << endl;
	return out;
}
istream& operator>> (istream &in, CSeller &obj)
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