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
    int n, k;
    cin >> n >> k;
    vint v(n);
    int maxx = -1e5;
    int minn = 1e5;
    for (auto &&i : v) {
        cin >> i;
        maxx = max(maxx, i);
        minn = min(minn, i);
    }
    for (auto &&i : v) {
        if (i < k)
            cout << minn << " ";
        else if (i == k) {
            cout << k << " ";
        }
        else if (i > k) {
            cout << maxx<< " ";
        }
    }
    return 0;
}