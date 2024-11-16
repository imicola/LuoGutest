//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> fl(n + 10, 0);
    while (m--) {
        string s;
        cin >> s;
        if (s == "water") {
            int l, r;
            cin >> l >> r;
            for (size_t i = l; i <= r; i++) {
                fl[i]++;
            }
        }
        if (s == "rise") {
            int l, r, k;
            cin >> l >> r >> k;
            int ans = 0;
            for (size_t i = l; i <= r; i++) {
                if (fl[i] >= k) {
                    ans++;
                    fl[i] = 0;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}