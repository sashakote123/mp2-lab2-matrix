// ����, ���, ���� "������ ����������������-2", �++, ���
//
// sample_matrix.cpp - Copyright (c) ������� �.�. 07.05.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (20.04.2015)
//
// ������������ ����������������� �������

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");

	int n1 = 0, n2 = 0;
	cout << "������� ������ ������� � � ��������:\n";
	cout << "������ ������� �:\n";
	cin >> n1;
	cout << "������ ������� B:\n";
	cin >> n2;
	TMatrix<int> A(n1), B(n2);

	cout << "������� �:\n";
	cin >> A;
	cout << "������� B:\n";
	cin >> B;
	cout << "������� �:\n" << A;
	cout << "������� B:\n" << B;
	char operatorr;
	cout << "�������� ��������:\n";
	cin >> operatorr;
	switch (operatorr) {
	case '+':
		cout << A + B;
		break;
	case '-':
		cout << A - B;
		break;
	default:
		cout << "�������� ��������...\n";
		break;
	}

}
//---------------------------------------------------------------------------
