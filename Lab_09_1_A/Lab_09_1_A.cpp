#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { КН, ІТ, ПЗ, ВП, СА };

string specialtyStr[] = { "КН", "ІТ", "ПЗ", "ВП", "СА" };

struct Student
{
	string prizv;
	short unsigned kurs;
	Specialty specialty;
	short unsigned physics;
	short unsigned mathematics;
	short unsigned informatics;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void MinAverage(Student* p, const int N, double& MinAve);
void CountMarks(Student* p, const int N, int& countPhysics, int& countMathematics, int& countInformatics);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* p = new Student[N];

	double MinAve = 0.0;
	int countPhysics = 0;
	int countMathematics = 0;
	int countInformatics = 0;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - вивід найменшого середьного балу" << endl;
		cout << " [4] - вивід кількості 4 з кожного предмету" << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;

		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			MinAverage(p, N, MinAve);
			cout << "Мінімальне середній бал: " << setprecision(2) << fixed << MinAve << endl;
			break;
		case 4:
			CountMarks(p, N, countPhysics, countMathematics, countInformatics);
			cout << "Кількість 4 з фізики: " << countPhysics << endl;
			cout << "Кількість 4 з математики: " << countMathematics << endl;
			cout << "Кількість 4 з інформатики: " << countInformatics << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	system("pause");
	return 0;
}

void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.sync();
		cout << " Прізвище: "; cin >> p[i].prizv;
		cout << " Курс: "; cin >> p[i].kurs;
		cout << " Спеціальність (0 - КН, 1 - ІТ, 2 - ПЗ, 3 - ВП, 4 - СА): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " Оцінка з фізики: "; cin >> p[i].physics;
		cout << " Оцінка з математики: "; cin >> p[i].mathematics;
		cout << " Оцінка з інформатики: "; cin >> p[i].informatics;
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "==========================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Інформатика |"
		<< endl;
	cout << "---------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			 << "| " << setw(4) << left << p[i].kurs << " "
			 << "| " << setw(14) << left << specialtyStr[p[i].specialty]
			 << "| " << setw(6) << left << p[i].physics << " "
			 << "| " << setw(10) << left << p[i].mathematics << " "
			 << "| " << setw(11) << left << p[i].informatics << " " << "|" << endl;
		cout << "---------------------------------------------------------------------------"
			 << endl;
	}
}

void MinAverage(Student* p, const int N, double& MinAve)
{
	int i = 0;
	double average = (p[i].physics + p[i].mathematics + p[i].informatics) / 3.;
	MinAve = average;
	for (int i = 1; i < N; i++)
	{
		average = (p[i].physics + p[i].mathematics + p[i].informatics) / 3.;
		if (MinAve > average)
			MinAve = average;
	}
}

void CountMarks(Student* p, const int N, int& countPhysics, int& countMathematics, int& countInformatics)
{
	countPhysics = 0;
	countMathematics = 0;
	countInformatics = 0;

	for (int i = 0; i < N; i++)
	{
		if (p[i].physics == 4)
			countPhysics++;
		if (p[i].mathematics == 4)
			countMathematics++;
		if (p[i].informatics == 4)
			countInformatics++;
	}
}