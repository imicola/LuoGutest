#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            cin >> arr[i][k];
        }
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (k < i && arr[i][k] != 0) {
                flag = 1;
                break;
            }
        }
    }
    if (flag) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}