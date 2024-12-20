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
    int t = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int l = 1, r = n;
        for (size_t i = 1; i <= n; i++) {
            if (i % k == 0) {
                cout << l << " ";
                l++;
            }
            else {
                cout << r << " ";
                r--;
            }
        }
        cout << endl;
    }

    return 0;
}
//