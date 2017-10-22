// BomberManCpp.cpp: define el punto de entrada de la aplicación de consola.
#include "stdafx.h"
#include "iostream"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>



#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

using namespace std;


int cc = 1, cf = 1;
char tecla;
/* Obtener caracter en posicion (x,y) */
char get_char_at_xy(int x, int y) {



	CHAR_INFO ci;
	COORD xy = { 0, 0 };
	SMALL_RECT rect = { x, y, x, y };
	COORD coordBufSize = { 1,1 };
	return ReadConsoleOutput(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&ci,
		coordBufSize,
		xy,
		&rect)
		? ci.Char.AsciiChar
		: '\0';
}
/* Posicionar cursor en posicion(x,y) */
void gotoxy(int x, int y) {//Posicionar Cursor [#include<windows.h>]
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

int main()
{

	srand(time(NULL));
	int num;

	const int tam_x = 13;
	const int tam_y = 16;



	int mapa[tam_x][tam_y] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,1,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,1,1,0,1,0,1 },
		{ 1,0,1,0,0,0,0,0,0,0,0,1,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
	};


	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			//Generamos un random para crear aleatoriamente bloques de premios (x), o fantasmas (f)
			num = 1 + rand() % (101 - 1);

			if (mapa[i][j] == 1)
			{
				printf("#");
			}

			if (mapa[i][j] == 0)
			{
				if (num >= 0 && num <= 90)
					printf(" ");
				if (num > 90 && num <= 95)
					printf("x");
				if (num > 95 && num < 100)
					printf("f");

			}
		}
		printf("\n");
	}

	gotoxy(cc, cf);
	cout << 'B';
	//------------------
	int q = 0;
	int w = 0;
	while (q == 0) {
		Sleep(200);
		gotoxy(w++, 10);
		//cout << '_';
		
		int q = 0;
		HWND hwnd = ::GetConsoleWindow();
	hola:
		while(1){ 
			if ((/*(::GetForegroundWindow() == hwnd) && */
				((::GetKeyState(VK_SPACE) & 0x8000) != 0))) {
				Sleep(100);
				cout << "Space";
			}
			Sleep(100);
			
			cout << "S";
			goto hola;			
		}
		
	}
	//------------------

		while (tecla != 'x') {
			tecla = _getch();//tecla = getch();

			Sleep(300);

			switch (tecla) {
			case DERECHA:
				if (get_char_at_xy(cc + 1, cf) != '#')
				{
					gotoxy(cc, cf);
					if (get_char_at_xy(cc + 1, cf) == 'f')
					{
						cout << ' ';
						cc++;
						gotoxy(cc, cf);
						cout << ' ';
						cc = 1;
						cf = 1;
						gotoxy(cc, cf);
						cout << 'B';
					}
					if (get_char_at_xy(cc + 1, cf) == 'x')
					{
						gotoxy(cc, cf);
					}
					else
					{
						cout << ' ';
						cc++;
						gotoxy(cc, cf);
						cout << 'B';
					}
				}
				else {
					gotoxy(cc, cf);
				}
				break;
			case IZQUIERDA:
				if (get_char_at_xy(cc - 1, cf) != '#')
				{
					gotoxy(cc, cf);
					if (get_char_at_xy(cc - 1, cf) == 'f')
					{
						cout << ' ';
						cc--;
						gotoxy(cc, cf);
						cout << ' ';
						cc = 1;
						cf = 1;
						gotoxy(cc, cf);
						cout << 'B';
					}
					if (get_char_at_xy(cc - 1, cf) == 'x')
					{
						gotoxy(cc, cf);
					}
					else
					{
						cout << ' ';
						cc--;
						gotoxy(cc, cf);
						cout << 'B';
					}
				}
				else {
					gotoxy(cc, cf);
				}
				break;
			case ABAJO:
				if (get_char_at_xy(cc, cf + 1) != '#')
				{
					gotoxy(cc, cf);
					if (get_char_at_xy(cc, cf + 1) == 'f')
					{
						cout << ' ';
						cf++;
						gotoxy(cc, cf);
						cout << ' ';
						cc = 1;
						cf = 1;
						gotoxy(cc, cf);
						cout << 'B';
					}
					if (get_char_at_xy(cc, cf + 1) == 'x')
					{
						gotoxy(cc, cf);
					}
					else
					{
						cout << ' ';
						cf++;
						gotoxy(cc, cf);
						cout << 'B';
					}
				}
				else {
					gotoxy(cc, cf);
				}
				break;
			case ARRIBA:
				if (get_char_at_xy(cc, cf - 1) != '#')
				{
					gotoxy(cc, cf);
					if (get_char_at_xy(cc, cf - 1) == 'f')
					{
						cout << ' ';
						cf--;
						gotoxy(cc, cf);
						cout << ' ';
						cc = 1;
						cf = 1;
						gotoxy(cc, cf);
						cout << 'B';
					}
					if (get_char_at_xy(cc, cf - 1) == 'x')
					{
						gotoxy(cc, cf);
					}
					else
					{
						cout << ' ';
						cf--;
						gotoxy(cc, cf);
						cout << 'B';
					}
				}
				else {
					gotoxy(cc, cf);
				}
				break;
			}
		}
		return 0;
	}
