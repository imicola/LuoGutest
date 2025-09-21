//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    string s;
    cin >> n >> s;

    bool ok = 1;
    for (i64 i = 0; i < n && ok;) {
        i64 j = i;
        while (j + 1 < n && s[j + 1] != s[j]) j++;
        if (s[i] == '1' && s[j] == '1') {
            i64 cnt0 = 0;
            for (i64 k = i; k <= j; k++)
                if (s[k] == '0') cnt0++;
            if (cnt0 & 1) ok = 0;
        }
        i = j + 1;
    }

    cout << (ok ? "YES" : "NO") << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}