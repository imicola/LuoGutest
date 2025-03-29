//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

void solve() {
    int n;
    cin >> n;
    vint v(n);
    for (auto &&i : v)
    {
        cin >> i;
    }
    map<int, int> mp;
    int cnt = 0;
    for (auto &&i : v)
    {
        mp[i]++;
        cnt++;
        if(mp[2] >= 2 && mp[3] >= 1 && mp[0] >= 3 && mp[5] >= 1 && mp[1] >=1 ){
            cout << cnt <<endl;
            return;
        }
    }
    cout << 0 << endl;
}
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}