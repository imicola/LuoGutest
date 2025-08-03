//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int MOD = 998244353;

void solve()
{
    int n;
    cin >> n;
    
}
// 
// int f(vint n)
// {
//     stack<int> sk;
//     for(auto && i : n){
//         while (!sk.empty() && sk.top() > i)
//         {
//             sk.pop();
//         }
//         sk.push(i);
//     }
//     return sk.size();
// }

/*
1 2 3 return 3
1 3 2 return 2
2 1 3 return 2
3 1 2 return 2
2 3 1 return 1
3 2 1 return 1
*/

/*
1 2 3 4 > 4
1 2 4 3 > 3
1 3 2 4 > 3
1 3 4 2 > 3
1 
*/


signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}