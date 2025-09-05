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

constexpr i64 MAXN = 1e5 + 5;
constexpr i64 MAXM = 20;

struct RMQ
{
    i64 N, A[MAXN];
    i64 blockSize;
    i64 S[MAXN][MAXM], Pow[MAXM], Log[MAXN];
    i64 Belong[MAXN], Pos[MAXN];
    i64 Pre[MAXN], Sub[MAXN];
    i64 F[MAXN];

    void buildST()
    {
        i64 cur = 0, id = 1;
        Pos[0] = -1;
        for (i64 i = 1; i <= N; ++i) {
            S[id][0] = std::max(S[id][0], A[i]);
            Belong[i] = id;
            if (Belong[i - 1] != Belong[i])
                Pos[i] = 0;
            else
                Pos[i] = Pos[i - 1] + 1;
            if (++cur == blockSize) {
                cur = 0;
                ++id;
            }
        }
        if (N % blockSize == 0) --id;
        Pow[0] = 1;
        for (i64 i = 1; i < MAXM; ++i) Pow[i] = Pow[i - 1] * 2;
        for (i64 i = 2; i <= id; ++i) Log[i] = Log[i / 2] + 1;
        for (i64 i = 1; i <= Log[id]; ++i) {
            for (i64 j = 1; j + Pow[i] - 1 <= id; ++j) {
                S[j][i] = std::max(S[j][i - 1], S[j + Pow[i - 1]][i - 1]);
            }
        }
    }

    void buildSubPre()
    {
        for (i64 i = 1; i <= N; ++i) {
            if (Belong[i] != Belong[i - 1])
                Pre[i] = A[i];
            else
                Pre[i] = std::max(Pre[i - 1], A[i]);
        }
        for (i64 i = N; i >= 1; --i) {
            if (Belong[i] != Belong[i + 1])
                Sub[i] = A[i];
            else
                Sub[i] = std::max(Sub[i + 1], A[i]);
        }
    }

    void buildBlock()
    {
        static i64 S[MAXN], top;
        for (i64 i = 1; i <= N; ++i) {
            if (Belong[i] != Belong[i - 1])
                top = 0;
            else
                F[i] = F[i - 1];
            while (top > 0 && A[S[top]] <= A[i]) F[i] &= ~(1 << Pos[S[top--]]);
            S[++top] = i;
            F[i] |= (1 << Pos[i]);
        }
    }

    void init()
    {
        for (i64 i = 1; i <= N; ++i) cin >> A[i];
        blockSize = log2(N) * 1.5;
        buildST();
        buildSubPre();
        buildBlock();
    }

    i64 queryMax(i64 l, i64 r)
    {
        i64 bl = Belong[l], br = Belong[r];
        if (bl != br) {
            i64 ans1 = 0;
            if (br - bl > 1) {
                i64 p = Log[br - bl - 1];
                ans1 = std::max(S[bl + 1][p], S[br - Pow[p]][p]);
            }
            i64 ans2 = std::max(Sub[l], Pre[r]);
            return std::max(ans1, ans2);
        }
        else {
            return A[l + __builtin_ctz(F[r] >> Pos[l])];
        }
    }
} R;

void solve()
{
    i64 m;
    cin >> R.N >> m;
    R.init();
    while (m--) {
        i64 l, r;
        cin >> l >> r;
        cout << R.queryMax(l, r) << endl;
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