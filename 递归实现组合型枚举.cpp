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

vint path;
vvint ressult;

void bfs(int a, int k, int n)
{
    if (path.size() == k) {
        for (auto &&i : path) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (size_t i = a; i <= n; i++) {
        path.emplace_back(i);
        bfs(i + 1, k, n);
        path.pop_back();
        // bfs(i + 1, k, n);
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    bfs(1, m, n);
    return 0;
}