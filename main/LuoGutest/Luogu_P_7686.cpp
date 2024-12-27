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
    int n, m;
    cin >> n >> m;
    vint result(m);
    vint ans;
    map<int, int> mp;
    for (auto &&i : result) {
        cin >> i;
    }
    for (int i = result.size() - 1; i >= 0; i--) {
        if (mp[result[i]] != 0) continue;
        mp[result[i]] = 1;
        ans.emplace_back(result[i]);
    }
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}