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
    int t = 1, ans = 0;
    cin >> t;
    stack<int> cowh;
    for (size_t i = 1; i <= t; i++) {
        int h;
        cin >> h;
        while (!cowh.empty() && cowh.top() <= h) {
            cowh.pop();
        }
        ans += cowh.size();
        cowh.push(h);
    }
    cout << ans;
    return 0;
}
