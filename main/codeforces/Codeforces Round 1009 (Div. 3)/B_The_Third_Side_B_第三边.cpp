//#pragma GCC optimize(3)
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
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> p;
    for (size_t i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        p.push(temp);
    }
    while (p.size() != 1)
    {
        int x1 = p.top();
        p.pop();
        int x2 = p.top();
        p.pop();
        int x3 = x1 + x2 - 1;
        p.push(x3);
    }
    cout << p.top() <<endl;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}