#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

ll a[15][15];
ll out[15][15];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int p = max(n, m);
    for (size_t i = 0; i < n; i++) {
        for (size_t k = 0; k < m; k++) {
            cin >> a[i][k];
        }
    }
    for (size_t i = 0; i < m; i++) {
        for (size_t k = 0; k < n; k++) {
            cout << a[k][i] << " ";
        }
        cout << endl;
    }

    return 0;
}