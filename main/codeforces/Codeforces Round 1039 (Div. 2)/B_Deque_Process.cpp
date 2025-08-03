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

void solve()
{
    int n;
    cin >> n;
    vint p(n);
    for (auto &&i : p) cin >> i;
    int l = 1, r = n - 1;
    int tail = p[0];
    cout << "L";
    while (l < r) {
        bool check = (p[l] < p[r]);
        if (tail >= min(p[l], p[r])) check = !check;
        if (check) {
            cout << "RL";
            tail = p[l];
        }
        else {
            cout << "LR";
            tail = p[r];
        }
        l++, r--;
    }
    if (n % 2 == 0) cout << "L";
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}