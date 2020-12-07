#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { ��, ��, ��, ��, �� };

string specialtyStr[] = { "��", "��", "��", "��", "��" };

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
	cout << "������ N: "; cin >> N;

	Student* p = new Student[N];

	double MinAve = 0.0;
	int countPhysics = 0;
	int countMathematics = 0;
	int countInformatics = 0;

	int menuItem;
	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ���� ���������� ���������� ����" << endl;
		cout << " [4] - ���� ������� 4 � ������� ��������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			cout << "̳������� ������� ���: " << setprecision(2) << fixed << MinAve << endl;
			break;
		case 4:
			CountMarks(p, N, countPhysics, countMathematics, countInformatics);
			cout << "ʳ������ 4 � ������: " << countPhysics << endl;
			cout << "ʳ������ 4 � ����������: " << countMathematics << endl;
			cout << "ʳ������ 4 � �����������: " << countInformatics << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
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
		cout << "������� � " << i + 1 << ":" << endl;
		cin.sync();
		cout << " �������: "; cin >> p[i].prizv;
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������ (0 - ��, 1 - ��, 2 - ��, 3 - ��, 4 - ��): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " ������ � ������: "; cin >> p[i].physics;
		cout << " ������ � ����������: "; cin >> p[i].mathematics;
		cout << " ������ � �����������: "; cin >> p[i].informatics;
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "==========================================================================="
		<< endl;
	cout << "| � | ������� | ���� | ������������ | Գ���� | ���������� | ����������� |"
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