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

void ser(vint k, int large_num, int small_num, int &ans)
{
    int diff = large_num - small_num;
    if (k.size() <= 1) {
        ans += k[0];
        return;
    }
    if (diff <= 0) {
        ans += k.back();
        k.front() -= large_num;
        k.pop_back();
        ser(k, k.back(), k.front(), ans);
    }
    else {
        k.erase(k.begin());
        ser(k, diff, k.front(), ans);
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    vint a(s1);
    vint b(s2);
    vint c(s3);
    vint d(s4);
    for (auto &&i : a) {
        cin >> i;
    }
    for (auto &&i : b) {
        cin >> i;
    }
    for (auto &&i : c) {
        cin >> i;
    }
    for (auto &&i : d) {
        cin >> i;
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    sort(all(d));
    int ans = 0;
    ser(a, a.back(), a.front(), ans);
    ser(b, b.back(), b.front(), ans);
    ser(c, c.back(), c.front(), ans);
    ser(d, d.back(), d.front(), ans);
    cout << ans;
    return 0;
}