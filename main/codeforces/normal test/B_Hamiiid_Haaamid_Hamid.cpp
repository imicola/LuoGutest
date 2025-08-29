//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    int n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    // 如果就在边界，则直接逃离
    if (x == 1 || x == n) {
        cout << 1 << endl;
        return;
    }
    // 否则向#少的地方冲刺
    int cnt1 = 0, cnt2 = 0;
    for (size_t i = 0; i < n; i++) {
        if (s[i] == '#' && i < x) cnt1++;
        if (s[i] == '#' && i > x) cnt2++;
    }
    if(abs(cnt1 - cnt2) > 1){
        
    }
    
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}