#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2,vector<int>(n));
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
        
    }
    long long ans = 0;
    for (size_t i = 0; i < n; i++)
    {
        ans += a[0][i]*a[1][i];
    }
    cout << ans;
    return 0;
}