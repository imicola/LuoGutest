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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t = 1;
    cin >> t;
    vint n(t);
    for (size_t i = 0; i < t; i++) {
        cin >> n[i];
    }
    stack<int> sta;
    vint result(t, 0);
    for (size_t i = t - 1; i >= 0; i--) {
        while (!sta.empty() && n[sta.top()] <= n[i]) {
            sta.pop();
        }
        result[i] = sta.empty() ? 0 : sta.top() + 1;
        sta.push(i);
    }
    for (auto &&i : result) {
        cout << i << " ";
    }
    return 0;
}