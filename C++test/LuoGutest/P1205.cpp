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

void fan90()
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            temp1[j][i] = temp0[i][j];
        }
    }
    fanzhuan();
}

void bianhuan()
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            temp0[i][j] = temp1[i][j];
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

void trans(int x)
{
    switch (x)
    {
    case 0:
        fan90();
        break;
    case 1:
        fan90();
        bianhuan();
        fan90();
        break;
    case 2:
        fan90();
        bianhuan();
        fan90();
        bianhuan();
        fan90();
        cout << "yy"<<endl;
        break;
    case 3:
        // for (size_t i = 0; i < n; i++)
        // {
        //     for (size_t j = 0; j < n; j++)
        //     {
        //         temp1[i][j] = temp0[i][j];
        //     }
        // }
        // fanzhuan();
        fanshe();
        break;
    case 4:
        fanshe();
        bianhuan();
        trans(0);
        break;
    case 5:
        fanshe();
        bianhuan();
        trans(1);
        break;
    case 6:
        fanshe();
        bianhuan();
        trans(2);
        break;
    case 7:
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                temp1[i][j] = temp0[i][j];
            }
        }
        break;
    case 8:
       for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                temp1[i][j] = end0[i][j];
            }
        }
        break; 
    }
    return ;
}

int main()
{
    get_n();
    get_block();
    int i = 0,p = 0;
    for(;i <= 9;i++)   
    {   
        cout << i <<endl;
        trans(i);
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                if (temp1[j][k] != end0[j][k])
                {
                    p++;
                }
            }
        }
        for (size_t j = 0; j < n; j++)
        {
            for (size_t k = 0; k < n; k++)
            {
                cout << temp1[j][k];   
            }
            cout <<endl;
        }
        // if (p == 0)
        // {
        //     break;
        // }
        p = 0;
    }
        // for (size_t j = 0; j < n; j++)
        // {
        //     for (size_t k = 0; k < n; k++)
        //     {
        //         cout << temp1[j][k];   
        //     }
        //     cout <<endl;
        // }
        cout << i;
        if (i <= 3)
        {
            cout << i+1;
            return 0;
        }
        else if (i == 4 || i == 5 || i == 6)
        {
            cout << 5;
            return 0;
        }
        else if (i == 7 || i == 8)
        {
            cout << i - 1;
            return 0;
        } 
}