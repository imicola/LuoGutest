//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vint a(t);
    for (auto &&i : a) {
        cin >> i;
    }
    int ans = 0;
    vvint dp(t + 1, vint(t, 0));
    //dp[i][j] = 
    for (size_t i = 0; i < t; i++)
    {
        for (size_t j = 0; j < t; j++)
        {
            
        }
        
    }
    

    return 0;
}