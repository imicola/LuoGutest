//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (size_t i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (temp <= 6 || temp >= 70) ans++;
    }
    cout << ans;
    return 0;
}