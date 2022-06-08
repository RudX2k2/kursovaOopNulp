//CDepartment.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "CDepartment.h"
#include <iostream>
using namespace std;

CDepartment::CDepartment() : name(new char[30])
{
	strcpy(name, "No name");
}
CDepartment::CDepartment(char * name, vector<CWorker*> workers)
{
	Set_Name(name);
	Set_Workers(workers);
}
CDepartment::CDepartment(const CDepartment& obj)
{
	delete[] name;
	name = new char[strlen(obj.name) + 1];
	strcpy(name, obj.name);
	workers = obj.workers;
}
CDepartment::~CDepartment()
{
	delete[] name;
	workers.clear();
}

void CDepartment::Set_Name(char * name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
char * CDepartment::Get_Name()
{
	return this->name;
}

void CDepartment::Set_Workers(vector<CWorker*> workers)
{
	for (int i = 0; i < workers.size(); i++)
		this->workers.push_back(workers.at(i));
}
vector<CWorker*> CDepartment::Get_Workers()
{
	return workers;
}

void CDepartment::ShowWorkers()
{
	for (int i = 0; i < workers.size(); i++)
		workers.at(i)->ShowInfo();
}

CDepartment& CDepartment::operator=(const CDepartment& obj)
{
	if (this != &obj)
	{
		delete[] name;
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);
		workers = obj.workers;
	}
	return *this;
}

ostream& operator<< (ostream &out, CDepartment &obj)
{
	out << "Data about department:\n";
	out << "Name of department: " << obj.name << endl;
	out << "__Workers__";
	for (int i = 0; i < obj.workers.size(); i++)
		out << obj.name << endl;

	return out;
}
istream& operator>> (istream &in, CDepartment &obj)
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