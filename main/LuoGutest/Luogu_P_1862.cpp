//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    LL n;
    cin >> n;
    unordered_map<int, pair<int, int>> mp;
    LL maxa = -1e7, mina = 1e7;
    //first -> max
    //second -> min
    for (size_t i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (mp[a].first != 0 && b > mp[a].first) mp[a].first = b;
        if (mp[a].second != 0 && b < mp[a].second) mp[a].second = b;
        if (mp[a].first == 0 || mp[a].second == 0) mp[a].first = mp[a].second = b;
        if (b > maxa) maxa = b;
        if (b < mina) mina = b;
    }
    LL ans = 1e8;
    for (int i = mina; i <= maxa; i++) {
        LL tempans = 0;
        for (auto &&k : mp) {
            if (i < k.second.second) tempans += abs(k.second.first - i);
            if (i >= k.second.second && i <= k.second.first) tempans += abs(k.second.first - k.second.second);
            if (i > k.second.first) tempans += abs(i - k.second.second);
        }
        if (tempans < ans) ans = tempans;
    }
    cout << ans;
    return 0;
}