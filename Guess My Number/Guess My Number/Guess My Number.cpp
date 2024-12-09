#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <ctime>
using namespace std;

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_CTYPE, "ukr");
	srand(static_cast<unsigned int> (time(0)));		// зерно

	cout << "Гра запущена!" << endl << "Ціль гри: відгадати загадане число якомога меншою кількістю спроб" << endl;
	int number, answer;
	int tryCount = 0;

	cout << endl << "Виберіть складність гри серед: H - Hard; N - Normal; E - Easy" << endl << "Вiдповiдь: ";
	char dif;
	cin >> dif;

	if (dif == 'H' || dif == 'h')
	{
		number = rand() % 500 + 1; // від 500 до 0
	}
	else if (dif == 'N' || dif == 'n')
	{
		number = rand() % 100 + 1;
	}
	else if (dif == 'E' || dif == 'e')
	{
		number = rand() % 25 + 1;
	}
	else
	{
		cout << "Була обрана не коректна форма важкості!" << endl;
		exit(0);		// закриття програми
	}

	do
	{
		cout << "Ваше число: ";
		cin >> answer;
		tryCount++;

		if (answer == number)
		{
			cout << "Вітаю, ви виграли!" << endl << "Кількість використаних кроків: " << tryCount << endl;
		}
		else if (answer > number)
		{
			cout << "Ваше число занадто велике" << endl;
		}
		else
		{
			cout << "Ваше число занадто мале" << endl;
		}

	} while (answer != number);

	system("pause");
}
