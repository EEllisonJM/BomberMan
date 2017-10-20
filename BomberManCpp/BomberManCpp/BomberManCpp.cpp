// BomberManCpp.cpp: define el punto de entrada de la aplicaci�n de consola.
#include "stdafx.h"
#include "iostream"
#include<stdio.h>
#include<conio.h>
#include<windows.h>

#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77

using namespace std;

int cc = 1, cf = 1;
char tecla;

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
	const int tam_x = 13;
	const int tam_y = 16;

	int mapa[tam_x][tam_y] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//15
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,1,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,1,1,0,1,0,1 },
		{ 1,0,1,0,0,0,0,0,0,0,0,1,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,0,0,0,0 },
		{ 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,0,1,0,1,0,1,0,1,0,1,0,1 },
		{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };//13

	for (int i = 0; i<13; i++)
	{
		for (int j = 0; j<15; j++)
		{
			if (mapa[i][j] == 1)
			{
				printf("#");

			}

			if (mapa[i][j] == 0)
			{

				printf(" ");
			}
		}
		printf("\n");
	}
	
	gotoxy(cc,cf);
	cout << 'B';
	while (tecla != 'x'){
		tecla = _getch();//tecla = getch();
		switch (tecla){
		case DERECHA:
			//gotoxy(20, 20);
			//cout << mapa[cc + 1][cf];
			//cout << get_char_at_xy(cc + 1, cf) << "s";

			if (get_char_at_xy(cc + 1, cf) != '#'){

				gotoxy(cc, cf);
				cout << ' ';
				cc++;
				gotoxy(cc, cf);
				cout << 'B';
			}
			else {
				gotoxy(cc, cf);
			}
			break;
		case IZQUIERDA:
			//gotoxy(cc, cf);
			gotoxy(20, 20);
			//cout << mapa[cc - 1][cf];
			cout << get_char_at_xy(cc - 1, cf);
			if (get_char_at_xy(cc - 1, cf) != '#')
				//if (mapa[cc - 1][cf] != '#')//1=> Obstaculo

			{
				gotoxy(cc, cf);
				cout << ' ';
				cc--;
				gotoxy(cc, cf);
				cout << 'B';
			}
			else {
				gotoxy(cc, cf);
			}
			break;
		case ABAJO:
			//gotoxy(cc, cf);
			gotoxy(20, 20);
			//cout << mapa[cc][cf + 1];
			cout << get_char_at_xy(cc, cf + 1);

			if (get_char_at_xy(cc, cf + 1) != '#')
				//if (mapa[cc][cf + 1] != '#')
			{
				gotoxy(cc, cf);
				cout << ' ';

				cf++;
				gotoxy(cc, cf);
				cout << 'B';
			}
			else {
				gotoxy(cc, cf);
			}
			break;
		case ARRIBA:
			//gotoxy(cc, cf);
			gotoxy(20, 20);
			//cout << mapa[cc][cf - 1];
			cout << get_char_at_xy(cc, cf - 1);
			if (get_char_at_xy(cc, cf - 1) != '#')
				//if (mapa[cc][cf - 1] != '#')
			{
				gotoxy(cc, cf);
				cout << ' ';
				cf--;
				gotoxy(cc, cf);
				cout << 'B';
			}
			else {
				gotoxy(cc, cf);
			}
			break;
		}
	}
	return 0;
}