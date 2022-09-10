#include <iostream>
#include <windows.h>

using namespace std;

HANDLE h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
int stos[6], rozmiar = 0;

void show(); // wyswietlanie zawartosci stosu
void push(); //wpisywanie na stos
void pop(); //usuwanie liczby ze stosu
void size(); //sprawdzanie ilosci liczb
void empty(); //? sprawdzanie czy pusty

int main()
{
	int Wybor = 0;

	while (Wybor != 5)
	{
		show();

		SetConsoleTextAttribute(h0ut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

		cout << "-------------------------------" << endl;
		cout << "1.PUSH() // Dodawanie na stos //" << endl;
		cout << "2.POP() // Usuwanie ze stosu //" << endl;
		cout << "3.SIZE() // Sprawdzanie wielkosci stosu //" << endl;
		cout << "4.EMPTY() // Spradzanie czy stos jest pusty //" << endl;
		cout << "5.ZAKONCZ DZIALANIE" << endl;
		cout << "-------------------------------" << endl;
		
		cout << "Wybierz opcje: "; 
		cin >> Wybor;

		switch (Wybor)
		{
			case 1: push(); break;
			case 2: pop(); break;
			case 3: size(); break;
			case 4: empty(); break;
			case 5: exit(0); break;
			default:
			{
				SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
				cout << "Nie ma takiej opcji!" << endl;
				Sleep(500);
				break;
			}
		}
		
	}


	
}

void show()
{
	SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN | FOREGROUND_RED);
	
	system("cls");

	cout << "-------------------------------" << endl;
	cout << "        ZAWARTOSC STOSU        " << endl;
	cout << "-------------------------------" << endl;

	if (rozmiar == 0)
		cout << "Pusty" << endl;

	for (int i = rozmiar; i >= 1; i--)
	{
		cout << stos[i] << endl;
	}

	cout << "-------------------------------" << endl;
}

void push()
{
	if (rozmiar != 5)
	{
		cout << "Wpisz liczbe ktora chcesz dodac na stos: "; cin >> stos[rozmiar + 1];
		SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
		cout << "Dodawanie na stos..."; 
		Sleep(2000);
		rozmiar += 1;
	}
	else
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
		cout << "Nie ma miejsca na stosie!";
		Sleep(2000);
	}
	system("cls");
}

void pop()
{
	if (rozmiar == 0)
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
		cout << "Stos jest pusty, nie ma czego usuwac!";
		Sleep(2000);
	}
	else
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
		cout << "Usuwanie ze stosu liczby " << stos[rozmiar] << "...";
		stos[rozmiar] = 0;
		rozmiar = rozmiar - 1;
		Sleep(2000);
		
	}
	system("cls");
}

void size()
{
	SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
	cout << "Liczb na stosie: " << rozmiar << endl;
	Sleep(2000);
	system("cls");
}

void empty()
{
	cout << "Sprawdzanie czy stos jest pusty..." << endl;
	Sleep(1000);

	if (rozmiar == 0)
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_GREEN);
		cout << "STOS JEST PUSTY!" << endl;
	}
	else
	{
		SetConsoleTextAttribute(h0ut, FOREGROUND_RED);
		cout << "STOS NIE JEST PUSTY" << endl;
	}
	Sleep(2000);

	system("cls");
}