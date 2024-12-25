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
    // vvint mpp(n+10, vint(m+10));
    int max_k = -1;
    int index_i = 0, index_j = 0;
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            int k;
            cin >> k;
            if (k > max_k) {
                max_k = k;
                index_i = i;
                index_j = j;
            }
        }
    }
    cout << index_i << " " << index_j;

    return 0;
}