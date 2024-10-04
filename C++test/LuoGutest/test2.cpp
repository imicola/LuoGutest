#include <bits/stdc++.h>
using namespace std;

int n;
char end0[11][11];
char temp1[11][11];
char temp0[11][11];

void get_n()
{
    cin >> n;
}

void get_block()
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> temp0[i][j];
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> end0[i][j];
        }
    }
}

void fanzhuan()
{
    char temp;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < ceil(n/2.0); j++)
        {
            swap(temp1[i][j],temp1[i][n-j-1]);
        }
    }
}

void fanshe()
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            temp1[i][j] = temp0[i][j];
        }
    }
    fanzhuan();
}

int main()
{
    get_n();
    get_block();
    fanshe();
    for (size_t j = 0; j < n; j++)
    {
        for (size_t k = 0; k < n; k++)
        {
            cout << temp1[j][k];   
        }
        cout <<endl;
    }
}