#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (auto &&i : arr) {
        for (auto &&k : i) {
            cin >> k;
        }
    }
    int r;
    cin >> r;
    int ans = 0;
    for (size_t i = 0; i < m; i++) {
        ans += arr[r - 1][i];
    }
    cout << ans;
    return 0;
}