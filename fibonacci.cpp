#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

HANDLE h0ut = GetStdHandle(STD_OUTPUT_HANDLE);

long long recursion_fib(int n) //rekurencja
{
	if (n == 1 || n == 2)
		return 1;
	else
		return recursion_fib(n - 1) + recursion_fib(n - 2);
}

long long iteration_fib(int n) //iteracja
{
	long long * fib;

	fib = new long long[n];

	fib[0] = 1;
	fib[1] = 1;

	long long wynik = 0;

	for (int i = 2; i < n; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
		wynik = fib[i];
	}

	if (n == 1 || n == 2)
		wynik = 1;

	delete[] fib;

	return wynik;
}

int main()
{
	int ile, Chose;
    SetConsoleTextAttribute(h0ut, FOREGROUND_BLUE);
	cout << "Porownanie czasu wyznaczania liczby ciagu Fibonacciego; "; cout << "REKURENCJA I ITERACJA" << endl;

	while (true)
	{
		while (true)
		{
		    SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
		    cout << "(Powyzej 50 liczby czas wyznaczania jest bardzo duzy dla rekurencji, nie polecam)" << endl;
		    SetConsoleTextAttribute(h0ut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << "Ktora liczbe ciagu Fibonacciego chcesz wyznaczyc? | ";
			cin >> ile;

			if (ile <= 0)
			{
				SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
				cout << "!!! Liczba musi byc wieksza od zera !!! " << endl;
				SetConsoleTextAttribute(h0ut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				continue;
			}
			else break;
		}
		cout << "-----------------------------" << endl;

		clock_t start = clock();

		cout << "REKURENCJA" << endl;
		cout << "Twoja liczba: " << recursion_fib(ile) << endl;

		clock_t end = clock();

		cout << "Czas wykonania procesu obliczania: " << ((double)end - start) / CLOCKS_PER_SEC << " s" << endl;
		cout << endl;

		clock_t start_i = clock();

		cout << "ITERACJA" << endl;
		cout << "Twoja liczba: " << iteration_fib(ile) << endl;

		clock_t end_i = clock();

		cout << "Czas wykonania procesu obliczania: " << ((double)end_i - start_i) / CLOCKS_PER_SEC << " s" << endl;
		cout << endl;

		cout << "1.Kontynuuj dzialanie programu" << endl;
		cout << "2.Zakoncz dzialanie programu" << endl;
		cout << "Twoj wybor: "; cin >> Chose;

		if (Chose == 1)
		{
			system("cls");
			continue;
		}
		else if (Chose == 2)
			exit(0);
		else
		{
			while (true)
			{
				cout << "Nie ma takiej opcji!" << endl;
				cout << "Twoj wybor: ";  cin >> Chose;
				if (Chose == 1)
				{
					system("cls");
					break;
				}
				else if (Chose == 2)
					exit(0);
				else continue;
			}
		}
	}
}
