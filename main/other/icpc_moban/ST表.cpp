//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

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
    n = read();
    m = read();
    vector<i64> a(n);
    for (auto &&i : a) {
        cin >> i;
    }
    ST p(n);
    p.pre(a);
    while (m--) {
        int l, r;
        l = read();
        r = read();
        cout << p.get(l - 1, r - 1) << endl;
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}