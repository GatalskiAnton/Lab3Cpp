#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define MAX_NUMBER_OF_MATRIX  10
int PrintMatrix(int n, int m, vector <int>& matrix, int last_element);
int GetValue(int n, int m, vector <int>& matrix, int last_element, int i, int j);
int SortMatrix(int n, int m, vector <int>& matrix, int last_element) {
	int characteristic(0), characteristic_next(0);
	for (int m = 0; m < m*n*10; m++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (GetValue(n, m, matrix, last_element, i, j) < 0 && (GetValue(n, m, matrix, last_element, i, j) % 2) % 2) {
					characteristic += abs(GetValue(n, m, matrix, last_element, i, j));
				}
				if (GetValue(n, m, matrix, last_element, i, j + 1) < 0 && (GetValue(n, m, matrix, last_element, i, j + 1) % 2) % 2) {
					characteristic_next += abs(GetValue(n, m, matrix, last_element, i, j + 1));
				}
			}
			if (characteristic > characteristic_next)
			{
				for (int p = 0; p < n; p++)
				{
					int first_column = GetValue(n, m, matrix, last_element, p, j);
					int second_column = GetValue(n, m, matrix, last_element, p, j + 1);
					swap(first_column,second_column);
				}
			}
		}
	}
	PrintMatrix(n, m, matrix, last_element);
	return 0;
}
int PrintMatrix(int n , int m,vector <int>&matrix, int last_element) {
	int pointer(0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i + j) % 2 == 0) {
				cout << last_element << " ";
			}
			else {
				cout << matrix[pointer] << " ";
				pointer++;
			}
		}
		cout << endl;
	}
	return 0;
}
int ColumnSum(int n, int m, vector <int>& matrix, int last_element) {
	int sum;
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
		{
			sum = 0;
			if (GetValue(n, m, matrix, last_element, i, j) < 0 )
			{
				for (int k = 0; k < n; k++)
				{
					sum += GetValue(n, m, matrix, last_element, k, j);
				}
				cout << "Column " << j + 1 << " " << sum << " " << endl;
				break;
			}
		}
	}
	return 0;
}
int GetValue(int n, int m, vector <int>&matrix, int last_element, int i, int j) {
	int pos;
	if (j == (m - 1) && (i == 0 && j == 1))
	{
		pos = floor(((i + 1) * m - (m - (j + 1))) / 2) - 1;
	}
	else {
		pos = floor(((i + 1) * m - (m - (j + 1))) / 2) - 1;
	}
	if (!(j % 2))
	{
		pos = floor(((i + 1) * m - (m - (j + 1))) / 2) ;
	}
	if ((i + j) % 2 == 0) {
		return  last_element;
	}
	return matrix[pos];
	
}
int main() {
	srand(time(NULL));
	int n(0), m(0);
	int k = 0;
	do
	{
		if (k > 0)
		{
			cout << "Incorrect value\n";
		};
		cout << "Enter Matrix size(n,m)\n";
		k++;
		cin >> m >> n;
	} while ((n > MAX_NUMBER_OF_MATRIX) || (m > MAX_NUMBER_OF_MATRIX) || ((n <= 0) || (m <= 0)));
	int last_element(0);
	vector <int> matrix(ceil((n * m) / 2));
	int method;
	cout << "How do you want to filing the matrix, by keyboard input or random number generator(type 1, 2 accordingly\n";
	cin >> method;
	if (method == 1)
	{
		for (int i = 0; i < ceil((n * m) / 2); i++)
		{
			cin >> matrix[i];
		}
	}
	else {
		int right_border, left_border;
		cout << "Enter the left border of the range\n";
		cin >> left_border;
		cout << "Enter the right border of the range\n";
		cin >> right_border;
		for (int i = 0; i < ceil((n * m) / 2); i++)
		{
			matrix[i] = rand() % right_border + left_border;
		}
	}
	PrintMatrix(n,m,matrix,0);
	cout << endl;
	ColumnSum(n, m, matrix, last_element);
	cout << endl;
	SortMatrix(n, m, matrix, last_element);
}
