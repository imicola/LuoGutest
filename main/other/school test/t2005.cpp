#include <bits/stdc++.h>
using namespace std;

int main()
{
    //string s;
    int m,n,r,c;
    while (cin >> n >> m >> r >>c)
    {
        // m = s[0] - '0';
        // n = s[2] - '0';
        // r = s[4] - '0';
        // c = s[6] - '0';
        // vector<vector<int>> vis(n,vector<int> (m,0));
        // for (size_t i = 0; i < r; i++)
        // {
        //     for (size_t j = 0; j < n; j++)
        //     {
        //         vis[i][j]++;
        //     }
        // }
        // for (size_t i = 0; i < c; i++)
        // {
        //     for (size_t j = 0; j < m; j++)
        //     {
        //         vis[j][i]++;
        //     }
        // }
        // int p = 0;
        // for (size_t i = 0; i < m; i++)
        // {
        //     for (size_t j = 0; j < n; j++)
        //     {
        //         if (vis[i][j] == 0)
        //         {
        //             p++;
        //         }   
        //     }
        // }
        long long p = n*m;
        p -= (n*c + m*r - r*c);
        if (p < 0)
        {
            cout << 0;
        }
        else
        {
            cout << p <<endl;
        }
    }
    return 0;
}