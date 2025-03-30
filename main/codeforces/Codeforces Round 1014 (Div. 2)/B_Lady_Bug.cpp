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

void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int cnts1 = 0, cnts2 = 0;
    int ji0 = 0, ou0 = 0, ji1 = 0, ou1 = 0;
    for (size_t i = 0; i < n; i++) {
        if (s1[i] == '1') {
            cnts1++;
            ((i + 1) % 2 ? ou1++ : ji1++);
        }
        if (s2[i] == '0') {
            cnts2++;
            ((i + 1) % 2 ? ou0++ : ji0++);
        }
    }
    if (cnts2 < cnts1) {
        cout << "NO" << endl;
        return;
    }
    if(ji0 >= ou1 && ou0 >= ji1){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}
// 010001
// 010111
//
// 10000
// 01010
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