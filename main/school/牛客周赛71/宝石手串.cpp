#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        unordered_map<char, int> used;
        int ans = 1e6;
        for (size_t i = 0; i < n; i++) {
            if (used[s[i]] != 0) continue;
            for (size_t j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    ans = min(ans, min(j - i - 1, (n - j - 1) + i));
                }
            }
            used[s[i]] = 1;
        }
        if (ans == 1e6)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
