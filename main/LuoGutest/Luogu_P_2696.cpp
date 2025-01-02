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

int yuesefu(int n, int k)
{
    int fina = 0;
    for (size_t i = 2; i <= n; i++) {
        fina = ((fina + k) % i);
    }
    return fina + 1;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    int ans = 0;
    while (true) {
        int k1 = yuesefu(T, 2);
        if (T - k1 == 0) {
            ans += 2 * k1;
            break;
        }
        ans += (T - k1);
        T = k1;
    }
    cout << ans;
    return 0;
}