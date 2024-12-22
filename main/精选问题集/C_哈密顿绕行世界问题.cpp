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

vvint a;
vint resulta;
int x = 1;
vint path(25, 0);
void bfs(int n, int r)
{
    if (path[n] != 0) return;
    for (size_t i = 1; i <= 3; i++) {
        if (a[n][i] == r && resulta.size() == 19) {
            cout << x << ":  ";
            cout << r << " ";
            for (auto &&i : resulta) {
                cout << i << " ";
            }
            cout << r << endl;
            x++;
        }
    }
    if (path[n] == 0) {
        path[n] = 1;
        for (size_t i = 1; i <= 3; i++) {
            resulta.push_back(a[n][i]);
            bfs(a[n][i], r);
            resulta.pop_back();
        }
        path[n] = 0;
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    a = vvint(21, vint(4, 0));
    for (size_t i = 1; i <= 20; i++) {
        cin >> a[i][1] >> a[i][2] >> a[i][3];
    }
    vint result;
    while (true) {
        int t;
        cin >> t;
        if (t == 0) break;
        result.emplace_back(t);
    }
    // cout << a[7][3];
    for (auto &&i : result) {
        bfs(i, i);
    }
    return 0;
}