//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

/* 
    先考虑特殊情况，两个相邻的时候肯定无解
    考虑两个位于对角，有两个边已经被封死了，只需要再封死两个边就可以，输出2
    考虑处于边的情况,只要两个的一边距离小于等于1，就可以两个
    考虑
    0x
    x0
    这种情况也是两个
    当某一边的距离小于等于1时候，可以用三个围堵一个
*/

void solve()
{
    i64 n, m;
    cin >> n >> m;
    i64 stx, sty, edx, edy;
    cin >> stx >> sty >> edx >> edy;
    i64 ok = 0;
    pii ed = {edx, edy};
    for (auto &&i : {1, -1}) {
        pii k1 = {stx + i, sty};
        pii k2 = {stx, sty + i};
        if (k1 == ed || k2 == ed) {
            cout << -1 << endl;
            return;
        }
    }
    if (ok) {
        cout << -1 << endl;
        return;
    }
    i64 ans = 3;
    if (m <= 2 || n <= 2) {
        cout << min(m, n) << endl;
        return;
    }
    // 边角
    vpii edge = {{1, 1}, {n, 1}, {1, m}, {n, m}};
    for (auto &&i : edge) {
        pii x1 = {stx, sty};
        pii x2 = {edx, edy};
        if (x1 == i || x2 == i) {
            cout << 2 << endl;
            return;
        }
    }
    if (abs(stx - edx) <= 1 && abs(sty - edy) <= 1) {
        cout << 2 << endl;
        return;
    }
    // 贴边
    vint px = {1, n};
    vint py = {1, m};
    for (auto &&i : px) {
        if (stx == i || edx == i) {
            if (abs(stx - edx) <= 1) {
                cout << 2 << endl;
                return;
            }
        }
    }
    for (auto &&i : py) {
        if (sty == i || edy == i) {
            if (abs(sty - edy) <= 1) {
                cout << 2 << endl;
                return;
            }
        }
    }
    // 考虑三个的情况
    if (stx == 1 || sty == 1 || stx == n || sty == m) {
        cout << 3 << endl;
        return;
    }
    if (abs(stx - edx) <= 1 || abs(sty - edy) <= 1) {
        cout << 3 << endl;
        return;
    }
    // 考虑坐标差为2
    /* 
        a0x
        0x0
        x0b
    */
    if (abs(stx - edx) == 2 && abs(sty - edy) == 2) {
        cout << 3 << endl;
        return;
    }
    //否则需要全部围堵
    cout << 4 << endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}