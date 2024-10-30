#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<bool> vis(n + 10,1);
        for (int i = 2; i <= n; i++) {
            for (int k = 1; i * k <= n; k++) {
                vis[i * k] = !vis[i * k];
            }
        }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) cout << i << " ";
    }

    return 0;
}