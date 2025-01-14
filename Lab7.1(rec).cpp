﻿// Lab_7_1.cpp
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 17
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** y, const int rowCount, const int colCount, const int Low,
	const int High, int i = 0, int j = 0);
void Print(int** y, const int rowCount, const int colCount, int i = 0, int j = 0);
void Sort(int** y, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** y, const int row1, const int row2, const int colCount, int j = 0);
void Calc(int** y, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

int main()
{
	srand((unsigned)time(NULL));
	int Low = 11;
	int High = 64;
	int rowCount = 8;
	int colCount = 5;
	int** y = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		y[i] = new int[colCount];

	Create(y, rowCount, colCount, Low, High);
	Print(y, rowCount, colCount);
	Sort(y, rowCount, colCount);
	Print(y, rowCount, colCount);

	int S = 0;
	int k = 0;
	Calc(y, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(y, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] y[i];
	delete[] y;

	return 0;
}

void Create(int** y, const int rowCount, const int colCount, const int Low,
	const int High, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			y[i][j] = Low + rand() % (High - Low + 1);
			Create(y, rowCount, colCount, Low, High, i, j + 1);
		}
		else {
			Create(y, rowCount, colCount, Low, High, i + 1, 0);
		}
	}
}

void Print(int** y, const int rowCount, const int colCount, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			cout << setw(4) << y[i][j];
			Print(y, rowCount, colCount, i, j + 1);
		}
		else {
			cout << endl;
			Print(y, rowCount, colCount, i + 1, 0);
		}
	}
	else if (i == rowCount && j == 0) {
		cout << endl;
	}
}

void Sort(int** y, const int rowCount, const int colCount, int i0, int i1)
{
	if (i0 < rowCount - 1) {
		if (i1 < rowCount - i0 - 1) {
			if ((y[i1][0] > y[i1 + 1][0])
				|| (y[i1][0] == y[i1 + 1][0] && y[i1][1] > y[i1 + 1][1])
				|| (y[i1][0] == y[i1 + 1][0] && y[i1][1] == y[i1 + 1][1] && y[i1][3] > y[i1 + 1][3])) {
				Change(y, i1, i1 + 1, colCount);
			}
			Sort(y, rowCount, colCount, i0, i1 + 1);
		}
		else {
			Sort(y, rowCount, colCount, i0 + 1, 0);
		}
	}
}

void Change(int** y, const int row1, const int row2, const int colCount, int j)
{
	if (j < colCount) {
		int tmp = y[row1][j];
		y[row1][j] = y[row2][j];
		y[row2][j] = tmp;
		Change(y, row1, row2, colCount, j + 1);
	}
}

void Calc(int** y, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
	if (i < rowCount) {
		if (j < colCount) {
			if (y[i][j] % 2 != 0 || !(y[i][j] % 3 == 0)) {
				S += y[i][j];
				k++;
				y[i][j] = 0;
			}
			Calc(y, rowCount, colCount, S, k, i, j + 1);
		}
		else {
			Calc(y, rowCount, colCount, S, k, i + 1, 0);
		}
	}
}
