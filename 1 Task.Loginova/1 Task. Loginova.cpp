#include <iostream>
using namespace std;

const int M = 20;

void EnterMatrix(int[][M], int, int);
void DisplayMatrix(int[][M], int, int);
void Swap(int &a, int &b);
int SearchForTheMinElement(int a[][M], int n, int m);
int SearchForTheMaxElement(int a[][M], int n, int m);
void Work(int[][M], int k, int l, int n, int m);

int main()
{
	while (true)
	{
		int n, m;
		int matrix[M][M] = { { 0 } };
		while (true)
		{

			cout << "Enter n m <= " << M << endl;
			cin >> n >> m;
			if (n > 0 && n <= M && m <= M && m > 0)
			{
				break;
			}
			cout << "Error! " << endl;
			system("pause");
			system("cls");

		}
		EnterMatrix(matrix, n, m);
		cout << endl;
		system("cls");
		cout << "Sourse matrix: ";
		cout << endl;
		DisplayMatrix(matrix, n, m);
		cout << endl;

		int k = SearchForTheMinElement(matrix, n, m);
		int l = SearchForTheMaxElement(matrix, n, m);
		Work(matrix, k, l, n, m);

		cout << "Changed matrix: " << endl;
		DisplayMatrix(matrix, n, m);

		system("pause");
		system("cls");

		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
		system("cls");
	}
	return 0;
}

void EnterMatrix(int a[][M], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "a[" << (i + 1) << "][" << (j + 1) << "]=";
			cin >> a[i][j];

		}
	}
}

void DisplayMatrix(int a[][M], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(5);
			cout << a[i][j];
		}
		cout << endl;
	}
}


void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int SearchForTheMinElement(int a[][M], int n, int m)
{
	int min = a[0][0], minNum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				minNum = i;
			}
		}
	}
	return minNum;
}

int SearchForTheMaxElement(int a[][M], int n, int m)
{
	int max = a[0][0], maxNum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				maxNum = i;
			}
		}
	}
	return maxNum;
}

void Work(int a[][M], int k, int l, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Swap(a[k][j], a[l][j]);
		}
	}
}