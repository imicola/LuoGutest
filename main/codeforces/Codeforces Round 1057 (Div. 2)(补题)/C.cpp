//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n;
    cin >> n;
    vint v(n);
    map<i64, i64> mp;
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        mp[v[i]]++;
    }
    vint res;
    i64 base = 0;
    i64 cnt = 0;
    for (auto &&[a, b] : mp) {
        if (b % 2 == 0) {
            base += a * b;
            cnt += b / 2;
        }
        else {
            if (b > 2) cnt++;
            base += a * (b - 1);
            res.emplace_back(a);
        }
    }
    if (res.size() == 0) {
        cout << base << endl;
        return;
    }
    else {
        i64 k1, k2;
        res.insert(res.begin(), 0);
        i64 basec = base;
        for (int i = res.size() - 1; i > 0; i--) {
            k1 = res[i], k2 = res[i - 1];
            if (base > k1 - k2) {
                base += k1 + k2;
                break;
            }
        }
        if (basec != base) {
            cout << base << endl;
            return;
        }
        else {
            if (cnt == 1)
                cout << 0 << endl;
            else
                cout << base << endl;
        }

        return;
    }
    cout << base << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}