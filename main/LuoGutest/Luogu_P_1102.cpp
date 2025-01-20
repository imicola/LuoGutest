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
    int N, C;
    cin >> N >> C;
    map<int, int> mp;
    for (size_t i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    int cnt = 0;
    for (auto &&[i, k] : mp) {
        if (mp.find(i + C) != mp.end()) {
            cnt += (*mp.find(i + C)).second*k;
        }
    }
    cout << cnt;
    return 0;
}