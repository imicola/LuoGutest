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
    if(x == 0)
    {
            fan90();
    }
    else if(x == 1)
    {
            fan90();
            bianhuan();
            fan90();
    }        
    else if(x == 2)
    {
            fan90();
            bianhuan();
            fan90();
            bianhuan();
            fan90();
    }
    else if(x == 3)
    {
        fanshe();
    }
    else if(x == 4) 
    {   
        fanshe();
        bianhuan();
        fan90();
    }        
    else if(x == 5) 
    {
        fanshe();
        bianhuan();
        fan90();
        bianhuan();
        fan90();
    }        
    else if(x == 6) 
    {
        fanshe();
        bianhuan();
        fan90();
        bianhuan();
        fan90();
        bianhuan();
        fan90();
    }        
    else if(x == 7) 
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                temp1[i][j] = temp0[i][j];
            }
        }
    }
    else if(x == 8) 
    {
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                temp1[i][j] = end0[i][j];
            }
        } 
    }
}

int main()
{
    get_n();
    get_block();
    int p = 0;
    int x = 0;
    for(; x < 9;x++)
    {   
        trans(x); 
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
        if (p == 0)
        {
            break;
        }
        p = 0;
    }
    
    if (x < 4)
        {
            cout << x+1;
            return 0;
        }
        else if (x == 4 || x == 5 || x == 6 )
        {
            cout << 5;
            return 0;
        }
        else if (x == 7 || x == 8)
        {
            cout << x - 1;
            return 0;
        }
}