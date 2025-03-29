//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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

int solve(int n)
{
    if (n == 0) return 0;
    int k = 1 << (31 - __builtin_clz(n));
    return (k << 1) - 1 - solve(n ^ k);
}
/*
01000   8
01001   9
01011   11
01010   10
01110   14
01111   15
01101   13
01100   12
00100   4
00101   5
00111   7
00110   6
00010   2
00011   3
00001   1
00000   0
*/
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    int p = 0;
    cin >> p;
    while (T--) {
        cout << solve(p);
    }

    return 0;
}