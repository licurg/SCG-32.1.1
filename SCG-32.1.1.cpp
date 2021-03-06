// SCG-32.1.1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

unsigned int matrix[32] = {
	3193055860,
	971011855,
	1942023710,
	3884047420,
	2319948703,
	1372263641,
	2744527282,
	40398979,
	80797958,
	161595916,
	323191832,
	646383664,
	1292767328,
	2585534656,
	1903977063,
	3807954126,
	2159389307,
	1143961361,
	2287922722,
	1442447267,
	2884894534,
	312728939,
	625457878,
	1250915756,
	2501831512,
	1870263639,
	3740527278,
	4171495099,
	3020148369,
	759414469,
	1518828938,
	3037657876
}; //Матриця Галуа
   //unsigned long f = 138878607;//Поліном
   //unsigned int oe = 3193055860;//Утворюючий елемент
char cki_symbol; //Символ, що зчитуємо
char gamma; //Байт гами
unsigned int vector = 1843441187; //Вектор ініціалізації
unsigned int g; //4 байти на виході генератора
int n; // Для циклів
void main()
{
	while (true)
	{
		cki_symbol = _getch(); //Тут зчитуємо введений символ
		if (cki_symbol == 0) {
			continue;
		} //_getch() додає '0' до зчитаного символу -> виходить два, тому прибираємо '0'
		gamma = 0;
		n = 0;
		g = 0;
		while (n < 32) {
			g ^= matrix[n] & (matrix[n] * (vector & 0x1));
			vector >>= 1;
			n++;
		} //Перемножаємо вектор на матрицю
		vector = g;
		n = 0;
		while (n < 4) {
			gamma ^= g ^ ((g >> 8) << 8);
			g >>= 8;
			n++;
		} //Складаємо 4 байти у гаму
		cout << (char)(cki_symbol ^ gamma) << ends;
	}
	getchar();
}

