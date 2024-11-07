//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    string s;
    for (size_t i = 0; i < n; i++) {
        s = "";
        cin >> s;
        int ans = 0;
        for (auto &&i : s) {
            ans += (i - 'A' + 1);
        }
        cout << ans << endl;
    }

    return 0;
}