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
    vint v(n);
    map<int, int> num;
    for (auto &&i : v) {
        cin >> i;
        num[i]++;
    }
    if (n == 1) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    if (num.size() == 1) {
        cout << 0 << endl;
        return;
    }
    int maxx = 0;
    pii ansindex = {-1, -1};
    for (size_t i = 0; i < n; i++) {
        int k = i;
        if (num[v[i]] == 1) {
            while (k < n && num[v[k]] == 1) {
                k++;
            }
            int p = k - i;
            if (p > maxx) {
                ansindex.first = i;
                ansindex.second = k - 1;
                maxx = p;
            }
            i = k;
        }
    }
    if (ansindex.first == -1 && ansindex.second == -1) {
        cout << 0 << endl;
        return;
    }
    cout << ansindex.first + 1 << " " << ansindex.second + 1 << endl;
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