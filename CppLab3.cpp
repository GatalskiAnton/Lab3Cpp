#include <iostream>   
#include <vector>     
#include <ctime>
#include <math.h>
using namespace std;

#define MAX_NUMBER_OF_MATRIX  10
int getValue(int i, int j, vector <vector <int>> &a) {
    return  a[i][j];
}
int SortMatrix(int n, int m, vector <vector <int>> &a) {
    int characteristiс, characteristic_next;
    for (int j = 0; j < m - 1; j++)
    {
        characteristic_next = 0;
        characteristiс = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] < 0 && (a[i][j] % 2))
            {
                characteristiс += abs(a[i][j]);
            }
            if (a[i][j + 1] < 0 && (a[i][j + 1] % 2))
            {
                characteristic_next += abs(a[i][j + 1]);
            }
        }
        if (characteristic_next < characteristiс)
        {
            for (int p = 0; p < n; p++)
            {
                swap(a[p][j], a[p][j + 1]);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << getValue(i, j, a) << " ";
        cout << endl;

    }
    return 0;
}
int matrixSum(int n, int m, vector <vector <int>> &a) {
    int sum;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            if (a[i][j] < 0)
            {
                for (int k = 0; k < n; k++)
                {
                    sum += a[k][j];
                }
                cout << "Column " << j + 1 << " " << sum << " " << endl;
                break;
            }
        }
    }
    return 0;
}
int main()
{
    int value_of_last_element = 0;
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
    vector < vector <int> > a(n, vector <int>(m));
    cout << "Enter the values of  the elements at positions i + j = odd\n";
    cin >> value_of_last_element;
    cout << "How do you want to filing the matrix, by keyboard input or random number generator(type keyboard, generator accordingly\n";
    string method_of_filing;
    cin >> method_of_filing;
    if (method_of_filing == "keyboard")
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!((i + j) % 2) || (i == 0 && j == 0)) {
                    cin >> a[i][j];
                }
                else {
                    a[i][j] = value_of_last_element;
                }
            }
    }
    else {
        int right_border, left_border;
        cout << "Enter the left border of the range\n";
        cin >> left_border;
        cout << "Enter the right border of the range\n";
        cin >> right_border;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!((i + j) % 2) || (i == 0 && j == 0)) {
                    a[i][j] = value_of_last_element;
                }
                else {
                    a[i][j] = rand() % right_border + left_border;
                }
            }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << getValue(i, j, a) << " ";
        cout << endl;

    }
    cout << endl;
    matrixSum(n, m, a);
    cout << endl;
    SortMatrix(n, m, a);
    return 0;



}
