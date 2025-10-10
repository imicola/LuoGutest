//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, rk, ck, rd, cd;
    cin >> n >> rk >> ck >> rd >> cd;
    i64 diff1 = abs(rk - rd);
    i64 diff2 = abs(ck - cd);
    if (diff1 == 0 && diff2 == 0) {
        cout << 0 << endl;
        return;
    }
    if (diff1 == 0) {
        cout << (ck < cd ? cd : n - cd) << endl;
        return;
    }
    if (diff2 == 0) {
        cout << (rk < rd ? rd : n - rd) << endl;
        return;
    }
    if (rk < rd && ck < cd) {
        cout << max(rd, cd) << endl;
        return;
    }
    if (rk > rd && ck < cd) {
        cout << max(n - rd, cd) << endl;
        return;
    }
    if (rk > rd && ck > cd) {
        cout << max(n - rd, n - cd) << endl;
        return;
    }
    if (rk < rd && ck > cd) {
        cout << max(rd, n - cd) << endl;
        return;
    }
}

/*
    主要看D，因为可以斜着走，所以我们可以把K相对的位置分成四个象限
    K为了避免被追上，一定会往 "远离原点方向" 跑，而最远距离就取决与D的位置
    这样划分一下，注意坐标系上的点就可以出来了
*/
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}