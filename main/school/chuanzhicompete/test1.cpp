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

void solve()
{
    int a, b;
    cin >> a >> b;
    int k = 0;
    while (k * b <= a) {
        if (k * b + b < a) {
            k++;
            continue;
        }
        for (size_t i = 0; i < b; i++) {
            if (k * b + i == a) {
                printf("%d=%d*%d+%d\n", a, k, b, i);
                return;
            }
        }
        k++;
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}