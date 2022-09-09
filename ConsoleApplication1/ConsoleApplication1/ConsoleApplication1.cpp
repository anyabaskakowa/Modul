#include<iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int i = 0, j = 0, mini = 0;
	const int n = 10, m = 14;
	double a[n][m + 1];
	double result;
	int b[n];
	int  kmax, kmaxi;
	double c, eGmax, max[n], min[n], q, sa;
	double  eOmax, maxO[n];
	//---------------------------------------------------------

	cout << "Критерий Ходжа-Лемана" << endl;
	c = 0.5;
	q = 1 / 14.0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a[i][j] = rand() % 100 + 1;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for (i = 0; i < n; i++)
	{
		max[i] = a[i][0];
		min[i] = a[i][0];
		sa = 0;
		for (j = 0; j < m; j++)
		{
			if (a[i][j] > max[i]) max[i] = a[i][j];
			if (a[i][j] < min[i]) min[i] = a[i][j];
			sa = sa + q * a[i][j];
		}
		a[i][j] = c * sa + (1 - c) * min[i];
		cout << i + 1 << "  " << a[i][j] << endl;
	}
	eGmax = a[0][j];
	for (i = 0; i < n; i++)
		if (a[i][j] > eGmax)
		{
			eGmax = a[i][j];
			kmaxi = i;
		}
	cout << "Выигрыш = " << eGmax << endl;
	cout << "В строке = " << kmaxi + 1 << endl;
	cout << "*__________________________________________________*" << endl;

	//---------------------------------------------------------------------------

	cout << "Минимаксный  критерий " << endl;
	cout << "Исходная матрица решений" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;


	int maxi = 1000;
	cout << "Минимальное значение в каждой из строк" << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] < maxi)
			{
				maxi = a[i][j];
			}
		}
		b[i] = maxi;
		cout << "№" << i + 1 << " " << b[i] << endl;
		maxi = 1000;

	}
	cout << endl;


	for (i = 0; i < n; i++)
	{
		if (b[i] >= mini)
		{
			mini = b[i];
		}

	}

	for (i = 0; i < n; i++)
	{
		if (b[i] == mini)
		{
			cout << "Максимальное значение  " << mini << endl;
			cout << "В строке = " << i + 1 << endl;
			cout << "*__________________________________________________*" << endl;
			cout << endl;
		}
	}
}
