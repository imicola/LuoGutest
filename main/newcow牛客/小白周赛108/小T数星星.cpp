//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (auto &&i : v) cin >> i;
        unordered_map<int, int> freq;
        for (auto &x : v) freq[x]++;
        long long ans = 0;
        for (auto &[key, val] : freq) {
            if (val % 2 == 0)
                ans += 2;
            else
                ans += 1;
        }
        cout << ans << endl;
    }

    return 0;
}