#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    set<pair<string, char>> mp;
    map<char, int> mp2;
    for (size_t i = 0; i < n; i++) {
        char s2;
        string s1, s3;
        cin >> s1 >> s2 >> s3;
        if (s3 == "accepted") {
            auto k = make_pair(s1, s2);
            if (mp.contains(k)) continue;
            mp.insert(k);
            mp2[s2]++;
        }
    }
    int maxans = INT_MIN;
    char ans;
    for (auto &&[i, j] : mp2) {
        if (j > maxans) {
            ans = i;
            maxans = j;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}