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
        unordered_map<char, vector<int>> mp;
        int ans = 1e6;
        for (size_t i = 0; i < n; i++) {
            char temp;
            cin >> temp;
            if (mp[temp].size() == 0) mp[temp].push_back(n + i);
            mp[temp].push_back(i);
        }
        for (auto &&[ch, i] : mp) {
            // cout << ch << " ";
            // cout << i[0] << " " << i[1] << " ";
            if (i.size() < 3) {
                // cout << endl;
                continue;
            }
            else {
                for (size_t j = 2; j < i.size(); j++) {
                    // cout << i[j] << " ";
                    ans = min(ans,min(i[j] - i[j - 1] - 1, i[0] - i[j] - 1));
                }
            }
            // cout << endl;
        }
        if (ans == 1e6)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
