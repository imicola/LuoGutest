//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

vector<i64> fac(i64 x)
{
    vector<i64> res;
    if (x <= 1) return res;
    if (x % 2 == 0) {
        res.push_back(2);
        while (x % 2 == 0) x /= 2;
    }
    for (i64 p = 3; p * p <= x; p += 2) {
        if (x % p == 0) {
            res.push_back(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) res.push_back(x);
    return res;
}

void solve()
{
    i64 n;
    cin >> n;
    vint a(n), b(n);
    i64 odd = 0, env = 0;
    map<i64, i64> mp;
    i64 Max = -1;
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        Max = max(Max, a[i]);
        if (a[i] % 2 == 0)
            odd++;
        else {
            env++;
        }
    }
    for (i64 i = 0; i < n; i++) {
        cin >> b[i];
    }
    // bi = 1 (easy version)
    if (odd >= 2) {
        cout << 0 << endl;
        return;
    }
    unordered_map<i64, i64> cnt;
    cnt.reserve(n * 2);
    for (i64 i = 0; i < n; i++) {
        auto primes = fac(a[i]);
        for (i64 p : primes) cnt[p] += 1;
    }
    for (auto &kv : cnt) {
        if (kv.second >= 2) {
            cout << 0 << endl;
            return;
        }
    }
    bool ok = 0;
    for (i64 i = 0; i < n; i++) {
        auto primes = fac(a[i] + 1);
        for (i64 p : primes) {
            if (cnt.find(p) != cnt.end() && cnt[p] > 0) {
                ok = 1;
                break;
            }
        }
        if (ok) break;
    }
    if (odd == 1) {
        cout << 1 << endl;
        return;
    }
    cout << (ok ? 1 : 2) << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
