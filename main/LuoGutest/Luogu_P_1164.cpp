//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

//f(i,j)选择为i项菜，还剩 j 元所可以选择的选项

vector<vector<int>> f(2000, vector<int>(2000));
int ans = 0;
LL dfs(int a, int b, vector<int> arr)
{
    if (f[a][b]) return f[a][b];
    if (arr[a] > b) return 0;
    if (arr[a] == b) return 1;
    // f[a][b] = f[a][b-f[a]]
    for (size_t i = a + 1; i < arr.size(); i++) {
        f[a][b] += dfs(i, b - arr[a], arr);
    }
    return f[a][b];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> mun(n);
    for (auto &&i : mun) {
        cin >> i;
    }
    //从 i = 0 开始 搜索 i ~ n 的所有可能
    for (size_t i = 0; i < n; i++) {
        ans += dfs(i, m, mun);
    }
    cout << ans;
    return 0;
}