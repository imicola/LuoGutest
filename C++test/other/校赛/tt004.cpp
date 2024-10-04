#include <bits/stdc++.h>
using namespace std;

char c[5][5];

void gouzao()
{
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cin >> c[i][j];
        }
    }
}

int main()
{
    int y = 0,t = 0;
    cin >> y;
    vector<string> out(y);
    for (size_t i = 0; i < y;i++)
    {
        gouzao();
        for (size_t j = 1; j < 4; j++)
        {
            for (size_t k = 1; k < 4; k++)
            {
                if (c[j][k] == c[j-1][k-1] && c[j][k] == c[j][k-1] && c[j][k] == c[j-1][k])
                {
                    t++;
                }
            }
        }
        if (t == 0)
        {
            out[i] = "No";
        }
        else
        {
            out[i] = "Yes";
        }
        t = 0;
    }
    for(int x = 0; x < y ;x++)
    {
        cout << out[x] <<endl;
    }
    
    return 0;
}