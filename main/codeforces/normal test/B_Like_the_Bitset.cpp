//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vint res(n);
    iota(all(res), 1);
    queue<i64> qu;
    i64 cnt = 1;
    for (i64 i = 0; i < n; i++) {
        if (qu.front() <= i - k) qu.pop();
        if (s[i] == '0') qu.emplace(i);
        if (s[i] == '1' && i >= k - 1) {
            if (qu.empty()) {
                cout << "NO" << endl;
            }
            i64 idx = qu.back();
            swap(res[idx], res[i]);
        }
    }
    cout << "YES" << endl;
    for (auto &&i : res) {
        cout << i << " ";
    }
    cout << endl;
}

void solve2()
{
    i64 n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    i64 ok = 0;
    i64 cnt = 0;
    for (i64 i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (k == 1) {
                cout << "NO" << endl;
                return;
            }
        }
        if (s[i] == '1' && s[i + 1] == '1') {
            if (cnt == 0) cnt++;
            cnt++;
        }
        if (s[i] == '0') cnt = 0;
        if (cnt == k) {
            cout << "NO" << endl;
            return;
        }
    }
    i64 now = 1;
    vint res(n);
    for (i64 i = 0; i < n; i++) {
        if (s[i] == '1') res[i] = now, now++;
    }
    now = n;
    for (i64 i = 0; i < n; i++) {
        if (s[i] == '0') res[i] = now, now--;
    }
    cout << "YES" << endl;
    for (auto &&i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve2();
    }
    return 0;
}