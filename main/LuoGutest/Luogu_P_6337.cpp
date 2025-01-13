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
    int T = 1;
    cin >> T;
    int a = 1, b = 1;
    int ans = 0;
    while (a + b < T + 2) {
        a++;
        if (a + b == T + 2) break;
        b++;
    }
    cout << a * b << endl;
    return 0;
}
// 1    2   4   6   9   12  16
// 0*1  1*2 2*2 3*2 3*3 4*3 4*4
// 0    1   2   3   4   5   6