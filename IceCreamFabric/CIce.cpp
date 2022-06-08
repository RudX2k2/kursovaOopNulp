//CIce.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "CIce.h"
#include <iostream>
using namespace std;

CIce::CIce()
{
	strcpy(name, "No name");
	price = 0;
	strcpy(reciept, "No department");
}
CIce::CIce(char* name, double price, char* reciept)
{
	Set_Name(name);
	Set_Price(price);
	Set_Reciept(reciept);
}
CIce::CIce(const CIce& obj)
{
	Set_Name(obj.name);
	Set_Price(obj.price);
	Set_Reciept(obj.reciept);
}
CIce::~CIce()
{
	delete[] name;
	delete[] reciept;
}

void CIce::Set_Name(char * name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
char * CIce::Get_Name()
{
	return this->name;
}

void CIce::Set_Price(double price)
{
	this->price = price;
}
double CIce::Get_Price()
{
	return price;
}

void CIce::Set_Reciept(char* reciept)
{
	this->reciept = new char[strlen(reciept) + 1];
	strcpy(this->reciept, reciept);
}
char * CIce::Get_Reciept()
{
	return this->reciept;
}

void CIce::ShowInfo()
{
	cout << "Назва: " << this->name << endl;
	cout << "Ціна: " << this->reciept << endl;
	cout << "Склад:\n" << this->reciept << endl;
}

void CIce::Rustle()
{
	cout << "*" << name << " is rustling*: shr-shr\n";
}

CIce& CIce::operator=(const CIce& obj)
{
	if (this != &obj)
	{
		delete[] name;
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
	}
	return *this;
}