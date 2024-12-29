#pragma GCC optimize(3)
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
    int n, q;
    cin >> n >> q;
    unordered_map<int, int> num;
    for (size_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        num[temp]++;
    }
    vpii res(num.begin(), num.end());
    sort(all(res), [](const pii &a,const pii &b) { return a.second < b.second; });
    int cnt = n;
    auto l = res.begin();
    while (q--) {
        int k;
        cin >> k;
        while ((*l).second <= k) {
            if (cnt == 0) {
                break;
            }
            cnt -= (*l).second;
            l++;
        }
        cout << cnt << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}