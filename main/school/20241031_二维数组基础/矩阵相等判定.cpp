#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> a2(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> a[i][k];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> a2[i][k];
        }
    }
    if (a == a2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}