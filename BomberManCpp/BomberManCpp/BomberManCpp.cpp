// BomberManCpp.cpp: define el punto de entrada de la aplicación de consola.
#include "stdafx.h"
#include "iostream"
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
//Haciendo cambios en esta compu


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
/*Establecer Vidas de BomberMan*/
void vida(int vid){
	int xV = 5;
	int yV = 15;
	int xP = 6;

	gotoxy(xV, yV);
	cout << "V";
	gotoxy(xP, yV);
	cout << ":";
	cout << vid;

	if (vid < 0)
	{
		cc = 0;
		cf = 0;
		gotoxy(cc, cf);

		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				cout << "X";
			}
			printf("\n");
		}
		gotoxy(xV, yV);
		cout << "V";
		gotoxy(xP, yV);
		cout << ":";
		cout << "GAME OVER";
	}
	/*cc = 0;
	cf = 1;
	gotoxy(cc, cf);*/
}
/*Cargar Escenario del Juego*/
void cargarEscenario(int tam_x, int tam_y) {
	int num;
	//const int x = tam_x;
	int mapa[13][16] =
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
}
/*Metodo inicioJuego*/
void inicioJuego() {
	cargarEscenario(13,16);
	
	cc = 1;
	cf = 1;
	gotoxy(cc, cf);
	cout << 'B';
}
/*Metodo de Tralacion*/
void traslacion(int p1, int p2, int t) {
	//pintar(p1 + t, p2 + t);
}

int main()
{
	int aux = 0;
	srand(time(NULL));
	inicioJuego();
	int vidas = 3;
	vida(vidas);
	//------------------
	HWND hwnd = ::GetConsoleWindow();
	while (1) {
	hola:
		if ((GetKeyState(VK_SPACE) & 0x8000) != 0) {
			Sleep(100);
			cout << "Space";
		}
		if ((GetKeyState(VK_LEFT) & 0x8000) != 0) {//Sleep(100);
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

					vidas--;
					vida(vidas);
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
		}
		if ((GetKeyState(VK_RIGHT) & 0x8000) != 0) {//Sleep(100);
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

					vidas--;
					vida(vidas);
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
		}
		if ((GetKeyState(VK_DOWN) & 0x8000) != 0) {
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

					vidas--;
					vida(vidas);
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
		}
		if ((GetKeyState(VK_UP) & 0x8000) != 0) {
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

					vidas--;
					vida(vidas);
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
		}
		Sleep(100);
		gotoxy(aux++, 20);
		cout << "S";
		goto hola;
	}
	//------------------
	
	return 0;
}
