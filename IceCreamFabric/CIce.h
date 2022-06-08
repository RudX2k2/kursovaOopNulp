#pragma once
#include <iostream>
#include "CWorker.h"
using namespace std;

#ifndef Ice
#define Ice
class CIce {
protected:
	char* name;
	double price;
	char* reciept;
public:
	//конструктори
	CIce();
	CIce(char* name, double price, char* reciept);
	CIce(const CIce & obj);
	virtual ~CIce();

	//гетери і сетери
	void Set_Name(char * name);
	char * Get_Name();

	void Set_Price(double price);
	double Get_Price();

	void Set_Reciept(char* reciept);
	char* Get_Reciept();

	void Rustle();
	void ShowInfo();

	//перевантаження операторів
	CIce& operator=(const CIce& obj);
	bool operator!=(CIce &obj);
	friend ostream& operator<< (ostream &out, CIce &obj);
	friend istream& operator>> (istream &in, CIce &obj);
};
#endif