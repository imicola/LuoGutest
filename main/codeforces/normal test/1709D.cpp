// #pragma GCC optimize(3)
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

struct ST
{
    int maxn;
    vector<i64> logtab;
    vector<vector<i64>> st;
    ST(int maxk)
    {
        maxn = maxk;
    }
    void pre(const vector<i64> &a)
    {
        // 预处理log表
        logtab.resize(maxn + 1);
        int K = __lg(maxn) + 1;
        st = vector<vector<i64>>(maxn, vector<i64>(K));
        logtab[1] = 0;
        for (i64 i = 2; i <= maxn; i++) {
            logtab[i] = logtab[i / 2] + 1;
        }
        // 预处理st表
        // 初始化
        for (i64 i = 0; i < maxn; i++) {
            st[i][0] = a[i];
        }
        // pre
        for (i64 j = 1; (1 << j) <= maxn; j++) {
            for (i64 i = 0; i + (1 << j) <= maxn; i++) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    i64 get(int l, int r)
    {
        i64 k = logtab[r - l + 1];
        return max(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vint v(m);
    for (i64 i = 0; i < m; i++) {
        cin >> v[i];
    }
    i64 q;
    cin >> q;
    ST st(m);
    st.pre(v);
    /*
      我们用st表存[L,R]的最高的一个障碍，能不能越过这个障碍代表我们能不能越过从L到R之间的所有障碍
      我们在判断其距离是否为k的倍数
  */
    while (q--) {
        i64 stx, sty, edx, edy, k;
        cin >> stx >> sty >> edx >> edy >> k;
        if (stx == edx && sty == edy) {
            cout << "YES" << endl;
            continue;
        }
        if (sty > edy) {
            swap(stx, edx);
            swap(sty, edy);
        }
        if (abs(stx - edx) % k != 0 || abs(sty - edy) % k != 0) {
            cout << "NO" << endl;
            continue;
        }
        i64 Max = st.get(sty - 1, edy - 1);
        if (Max == n) {
            cout << "NO" << endl;
            continue;
        }
        // 可到达的最高层
        i64 top = stx + ((n - stx) / k) * k;
        if (top <= Max) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
