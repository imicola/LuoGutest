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
    int n, a;
    cin >> n >> a;
    vint v(n);
    int cnt1 = 0;
    for (auto &&i : v) {
        char c;
        cin >> c;
        i = (c - '0');
        if (i == 1) cnt1++;
    }
    if(a == 1 && n > 1){
        cout << n << endl;
        return;
    }
    // if  0 + a个1 或 a个1 + 0 => a+1 个 1 => cnt1++
    // if a + 1 个 0 ==> cnt1 += a+1
    for (size_t i = 0; i < n; i++)
    {
        int p = 0;
        while(v[i] == 0){
            i++;
            p++;
            if(p == a + 1){
                cnt1 += a + 1;
                break;
            }
        }
        
    }
    
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}