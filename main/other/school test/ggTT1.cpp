#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int n,m;
int x0,y0,xe,ye;
vector<vector<int>> dp(n,vector<int>(m));
vector<vector<int>> dpt(n,vector<int>(m));



int main()
{
    cin >> n >> m;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            if (a == '#')
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    cin >> x0 >> y0 >> xe >> ye;
    
    
    
    
    


    return 0;
}