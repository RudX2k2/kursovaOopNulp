#include <iostream>
#include "CWorker.h"
#include "CWorkman.h"
#include "CSeller.h"
#include "CDepartment.h"
#include "CFactory.h"
#include "CIce.h"
#include "CSellingRoom.h"
#include <vector>
#include <Windows.h> 
using namespace std;

void simulateWork(int seconds);

int main()
{
	SetConsoleCP(1251); // встановлення кодування Windows-1251 в  потік введення
	SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
	//workers
	vector<CWorker*> workmans;
	vector<CWorker*> sellers;
	CWorker * wm1 = new CWorkMan((char*)"Жила Вадим", 18, 140, (char*)"Робітничий відділ", 40.2); //(name, age, salaryPerH, department, IPH)
	CWorker * wm2 = new CWorkMan((char*)"Хома Володимир", 19, 60, (char*)"Робітничий відділ", 15);
	CWorker * wm3 = new CWorkMan((char*)"Лебідь Максим", 18, 70.5, (char*)"Робітничий відділ", 21.5);
	CWorker * wm4 = new CWorkMan((char*)"Гуменюк Денис", 18, 84.9, (char*)"Робітничий відділ", 34.6);
	CWorker * wm5 = new CWorkMan((char*)"Дюк Рішильє", 54 , 68.9, (char*)"Робітничий відділ", 28.8);

	CWorker * s1 = new CSeller((char*)"Багула Ілля", 23, 400, (char*)"Відділ продажу", 1); //(name, age,salaryPerH, department, pricePerOperation)
	CWorker * s2 = new CSeller((char*)"Рудь Володимир", 18, 560, (char*)"Відділ продажу", 1);
	CWorker * s3 = new CSeller((char*)"Максимчук Катерина", 18, 690, (char*)"Відділ продажу", 1);
	CWorker * s4 = new CSeller((char*)"Гавриш Олексій", 34, 780, (char*)"Відділ продажу", 1);

	workmans.push_back(wm1);
	workmans.push_back(wm2);
	workmans.push_back(wm3);
	workmans.push_back(wm4);
	workmans.push_back(wm5);
	sellers.push_back(s1);
	sellers.push_back(s2);
	sellers.push_back(s3);
	sellers.push_back(s4);

	//ice
	CIce * ice1 = new CIce((char*)"Пломбір 100%", 15, (char*)"молоко знежирене, цукор білий кристалічний, кокосова олія, вода питна, вафельний стаканчик (вода питна, борошно пшеничне, олія соняшникова, бікарбонат натрію, сіль кухонна, емульгатор лецитин), сухе знежирене молоко, стабілізатор");
	CIce * ice2 = new CIce((char*)"Морозиво пломбір Ескімос", 20, (char*)"Вода питна, масло солодковершкове, молоко згущене незбиране з цукром, цукор білий кристалічний, сухе знежирене молоко, вафельний стаканчик (8,5%),сухий глюкозний сироп, стабілізатор, ароматизатор ваніль.");
	vector<CIce*> ices;
	ices.push_back(ice1);
	ices.push_back(ice2);

	//departments
	CFactory * factory = new CFactory((char*)"Робітничий відділ", workmans);
	CSellingRoom * sellroom = new CSellingRoom((char*)"Відділ продажу", sellers, 10000, ices);

	cout << "Вітаю на фабриці морозва! Ви - директор підприємтсва. Обиріть, що зробити згідно меню:";
	int choiceMain = 0, choiceIce = 0;
	int hours = 0;
	double ice = 0, moneyFromDeal = 0, moneyPrev = sellroom->Get_Money();
	bool iceFlag = false;
	do
	{
		cout << "\n_____Меню_____" << endl;
		cout << "1-Почати роботу відділів" << endl;
		cout << "2-Переглянути інформацію про підприємство" << endl;
		cout << "3-Переглянути інформацію про працівників" << endl;
		cout << "4-Найняти працівника" << endl;
		cout << "5-Звільнити працівника" << endl;
		cout << "6-Переглянути продукцію морозива" << endl;
		cout << "7-Добавити морозиво у меню" << endl;
		cout << "8-Видалити морозиво з меню" << endl;
		cout << "9-Записати поточну інформацію про підприємтсво у файл" << endl;
		cout << "10-Прочитати інформацію про підприємство записа" << endl;
		cout << "11-Закінчити програму" << endl;
		cout << "Вибір:";
		cin >> choiceMain;
		switch (choiceMain)
		{
		case 1:
			cout << "\n____Робітниче меню____" << endl;
			cout << "Наявні відділи:" << endl;
			cout << "1)" << factory->Get_Name() << "\t2)" << sellroom->Get_Name() << endl;
			cout << "Як будуть працювати відділи: вибирається морозиво з переліку\n" <<
				"і обирається скільки годин буде робитися це морозиво.\n" <<
				"Потім вироблена кількість морозива продається одним із працівників із відділу продажу,\n" <<
				"котрий має навищий коефіцієнт продажу, котрий генерується від 1 до 2. По закінченню роботи\n" <<
				"зароблені гроші потрабляють у скарбницю у " << sellroom->Get_Name() << ", з вирахуванням зарплати працівникам\n\n";
			do
			{
				cout << "Оберіть морозиво зі списку\n";
				sellroom->ShowMenu();
				cout << "Вибір: ";
				cin >> choiceIce;
				if (choiceIce <= sellroom->Get_Menu().size() && choiceIce > 0)
				{
					while (hours <= 0)
					{
						cout << "Оберіть скільки годин виробляти " << sellroom->Get_Menu().at(choiceIce - 1)->Get_Name() << endl;
						cin >> hours;
					}
					moneyPrev = sellroom->Get_Money();
					cout << "||||||Починаємо роботу виробничого цеху\n";
					simulateWork(5);
					ice = factory->ProduceIce(hours);
					cout << "|||||Виготовлено " << ice << " кг морозива " << sellroom->Get_Menu().at(choiceIce - 1)->Get_Name() << endl;
					sellroom->Set_Money(sellroom->Get_Money() - factory->SendBills(hours));
					cout << "|Видано запрплату працівникам " << factory->Get_Name() << " у кількості " << factory->SendBills(hours) <<
						" гривень" << endl;

					cout << "||||Даємо завдання продати виготовлене морозиво\n";
					simulateWork(3);
					moneyFromDeal = sellroom->SellIce(ice, choiceIce - 1);
					sellroom->Set_Money(sellroom->Get_Money() - sellroom->SendBills(moneyFromDeal));
					cout << "|Зароблено " << abs(moneyPrev - sellroom->Get_Money()) << " гривень з продажу виготовленого морозива" << endl;

					iceFlag = true;
					hours = 0;
				}
				else
					cout << "\nНеправильний вибір!" << endl;


			} while (iceFlag != true);

			break;
		case 2:
			cout << "\n____Інформацію про підприємство____" << endl;
			factory->ShowInfo();
			sellroom->ShowInfo();
			break;
		case 3:
			cout << "\n____Інформація про працівників____" << endl;
			factory->ShowWorkers();
			sellroom->ShowWorkers();
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			sellroom->ShowMenu();
			break;
		case 7:

			break;
		case 8: 

			break;
		case 9:

			break;
		case 10:

			break;
		case 11:
			cout << "Дозустрічі!\n";
			break;
		default:
			cout << "Неправильний вибір! Виберіть дію згідно меню!\n";
			break;
		}
	} while (choiceMain != 11);


}

void simulateWork(int seconds)
{
	for (int i = 0; i < seconds; i++)
	{
		cout << "*";
		Sleep(1000);
	}
	cout << endl;
}