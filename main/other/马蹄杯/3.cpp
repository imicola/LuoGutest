#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define endl '\n'
using namespace std;
typedef vector<int> vint;
const int MOD = 1e9 + 7;

vector<vector<int>> mp;
int n;

void dfs(int i, int j, int k)
{
    if (i > 2 || i < 1) return;
    if (j > n || j < 1) return;
    if (mp[i][j] != k) return;
    mp[i][j] = -1;
    dfs(i + 1, j, k); // 下
    dfs(i, j + 1, k); // 右
    dfs(i, j - 1, k); // 左
    dfs(i - 1, j, k); // 上
}

void solve()
{
    cin >> n;
    mp = vector<vector<int>>(3, vint(n + 1));
    // 1base
    for (size_t i = 1; i <= 2; i++) {
        for (size_t j = 1; j <= n; j++) {
            char c;
            cin >> c;
            mp[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (size_t i = 1; i <= 2; i++) {
        for (size_t j = 1; j <= n; j++) {
            if (mp[i][j] == -1) continue;
            ans++;
            dfs(i, j, mp[i][j]);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int TT = 1;
    // cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}