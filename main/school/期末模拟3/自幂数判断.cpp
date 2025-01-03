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

long long fastpower(long long a, long long b)
{
    long long ans = 1;
    while (b > 0) {
        if (b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

void solve()
{
    string a;
    cin >> a;
    int i_a = stoll(a);
    int res = 0;
    for (size_t i = 0; i < a.size(); i++) {
        res += fastpower(a[i] ^ 48, a.size());
    }
    cout << (res == i_a ? "T" : "F") << endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}