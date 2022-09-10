#include <iostream>
#include <Windows.h>
using namespace std;

int kolejka[5], wolne_miejsce = 0, ile = 0;
HANDLE h0ut = GetStdHandle(STD_OUTPUT_HANDLE);

//-------------------------------------------------------------------------------------------------------

void pokaz_kolejke()
{
		system("cls");
	SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "                   Kolejka                        " << endl;
		cout << "--------------------------------------------------" << endl;

		for (int i = 0; i <= ile - 1; i++)
		{
			cout << kolejka[i] << " ";
		}

		if (ile == 0)
			cout << "Pusta";

		cout << endl;
		cout << "--------------------------------------------------" << endl;
		
}

//-------------------------------------------------------------------------------------------------------

void push()
{
	if (ile == 5)
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
		cout << "Kolejka Pelna!" << endl;
		Sleep(1000);
	}
	else 
	{
		cout << "Wpisz liczbe ktora chcesz dodac do kolejki: "; cin >> kolejka[ile];
		ile++;
		SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
		cout << "Dodawanie do kolejki...";
		Sleep(1000);
	}
	system("cls");
}

//-------------------------------------------------------------------------------------------------------

void pop()
{
	if (ile == 0)	
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
		cout << "Nie ma czego usuwac! Kolejka jest pusta" << endl;
		Sleep(1000);
	}

	else
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
		cout << "Usuwanie z kolejki liczby " << kolejka[0] << "..." << endl;
		ile--;
		Sleep(1000);

		for (int i = 0; i < 4; i++)
		{
			kolejka[i] = kolejka[i + 1];
		}
	}
	system("cls");
}

//-------------------------------------------------------------------------------------------------------

void empty()
{
	if (ile == 0)
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
		cout << "Kolejka jest pusta!" << endl;
		Sleep(1000);
	}
	else
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
		cout << "Kolejka nie jest pusta!" << endl;
		Sleep(1000);
	}
	system("cls");
}

//-------------------------------------------------------------------------------------------------------

void size()
{
	if (ile > 1)
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
		cout << "W Kolejce sa " << ile << " liczby" << endl;
		Sleep(1000);
	}
	else if (ile == 1)
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
		cout << "W Kolejce jest 1 liczba" << endl;
		Sleep(1000);
	}
	else
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
		cout << "Kolejka jest pusta!" << endl;
		Sleep(1000);
	}
	system("cls");
}

//-------------------------------------------------------------------------------------------------------

int main()
{
	int Wybor = {};

	while (Wybor != 5)
	{
		pokaz_kolejke();

		// kolor standardowy
		SetConsoleTextAttribute(h0ut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
		cout << "             Menu Glowne Kolejki" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "1. Funkcja PUSH() //Dodawanie do kolejki//" << endl;
		cout << "2. Funkcja POP() //Usuwanie z kolejki//" << endl;
		cout << "3. Funkcja EMPTY() //Czy kolejka jest pusta?" << endl;
		cout << "4. Funkcja SIZE() //Sprawdzanie rozmiaru kolejki" << endl;
		cout << "5. Wyjdź z programu" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "Wybierz opcje: ";  cin >> Wybor;

		switch (Wybor)
		{
		case 1: push();			break;
		case 2: pop();			break;
		case 3: empty();		break;
		case 4: size();			break;
		case 5: exit(0);		break;
		default:	SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
					cout << "Nie ma takiej opcji!" << endl;
								break;
		}

	}
}