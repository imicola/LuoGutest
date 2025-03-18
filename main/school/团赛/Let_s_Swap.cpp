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

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int a, b;
    cin >> a >> b;
    auto choose = abs(a - b) % 2;
    if (s1 == s2)
    {
        cout << "yes";
        return;
    }
    /*
    thisisast
    012345678
    */
    int n = s1.size();
    for (int i = 1; i < n - 1; i += 1 + choose) // 枚举长度
    {
        auto ss1 = s1.substr(0, i), ss2 = s1.substr(i);
        if (s2 == ss2 + ss1)
        {
            cout << "yes";
            return;
        }
    }
    cout << "no";
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
        cout << endl;
    }
    return 0;
}