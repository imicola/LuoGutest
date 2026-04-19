//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(),v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64,i64> pii;
typedef vector<pii> vpii;

struct Fenwick
{
    i64 n;
    vint bit;
    Fenwick(i64 n): n(n),bit(n + 1,0){}
    void add(i64 i,i64 v = 1){for(;i <= n; i += i&-i)bit[i] += v;}
    i64 sum(i64 i){i64 r = 0; for(;i > 0;i -= i&-i)r += bit[i];return r;}
    i64 sum(i64 l,i64 r){ if(r<l) return 0; return sum(r) - sum(l - 1);}
};



void solve() {
    
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}