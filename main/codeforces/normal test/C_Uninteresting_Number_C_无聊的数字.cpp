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

int str_count(string &s, char c)
{
    int res = 0;
    int idx = s.find(c);
    while ((idx = s.find(c,idx)) != -1) {
        res++;
        idx += 1;
    }
    return res;
}

void solve()
{
    string s;
    cin >> s;
    int idx_sum = 0;
    for (auto &&i : s) {
        idx_sum += i ^ 48;
    }
    if (idx_sum % 9 == 0) {
        cout << "YES" << endl;
        return;
    }
    int n2 = str_count(s, '2');
    int n3 = str_count(s, '3');
    // cout << "n2: " << n2 << " n3: " << n3 << endl;
    for (size_t i = 0; i <= n3; i++) {
        for (size_t j = 0; j <= n2; j++) {
            if ((idx_sum + i * 6 + j * 2) % 9 == 0) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
    return;
}
// 5472778912773
// 
signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}