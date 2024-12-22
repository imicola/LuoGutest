//#pragma GCC optimize(3)
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
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (size_t i = l; i <= r; i++) {
        string s = to_string(i);
        int countt = 0;
        if (s.size() == 1) {
            ans++;
            continue;
        }
        for (size_t k = 1; k < s.size(); k++) {
            if ((s[k] ^ 48) > (s[k - 1] ^ 48)) {
                countt++;
            }
        }
        if (countt == s.size() - 1) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}