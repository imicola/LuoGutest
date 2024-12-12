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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, x;
    cin >> n >> x;
    vint t(n);
    for (auto &&i : t) {
        cin >> i;
    }
    pii ans, temp;
    int sum = t[0];
    auto [l, r] = temp;
    auto [al, ar] = ans;
    l = 0, r = 0, al = 1e3, ar = 1e5;
    for (; r < n;) {
        if (sum < x) {
            r++;
            sum += t[r];
        }
        if (sum >= x) {
            if (r - l < ar - al) {
                ar = r;
                al = l;
            }
            sum -= t[l];
            l++;
        }
    }
    cout << al + 1 << " " << ar + 1;
    return 0;
}