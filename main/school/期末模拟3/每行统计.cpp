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
    int m, n;
    cin >> m >> n;
    for (size_t i = 0; i < m; i++) {
        int cnt = 0;
        for (size_t j = 0; j < n; j++) {
            int p;
            cin >> p;
            cnt += (p < 0);
        }
        cout << cnt << endl;
    }
    return 0;
}