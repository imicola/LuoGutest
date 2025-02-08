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

vpii mpp;
int res = 0;

void dfs(int n, int path)
{
    if (n == 0) {
        res = max(res, path);
        return;
    }
    dfs(mpp[n].first, path + 1);
    dfs(mpp[n].second, path + 1);
    return;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int p;
    cin >> p;
    mpp = vpii(p + 1, make_pair(0, 0));
    for (size_t i = 0; i < p; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mpp[a] = make_pair(b, c);
    }
    dfs(1,0);
    cout << res;
    return 0;
}