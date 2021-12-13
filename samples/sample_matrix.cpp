// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");

	int n1 = 0, n2 = 0;
	cout << "Введите размер матрицы и её значения:\n";
	cout << "Размер матрицы А:\n";
	cin >> n1;
	cout << "Размер матрицы B:\n";
	cin >> n2;
	TMatrix<int> A(n1), B(n2);

	cout << "Матрица А:\n";
	cin >> A;
	cout << "Матрица B:\n";
	cin >> B;
	cout << "Матрица А:\n" << A;
	cout << "Матрица B:\n" << B;
	char operatorr;
	cout << "Выберите действие:\n";
	cin >> operatorr;
	switch (operatorr) {
	case '+':
		cout << A + B;
		break;
	case '-':
		cout << A - B;
		break;
	default:
		cout << "Неверное действие...\n";
		break;
	}

}
//---------------------------------------------------------------------------
