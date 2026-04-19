//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
using i128 = __int128;
using vint = vector<i64>;
using vvint = vector<vint>;
using vstr = vector<string>;
using pii = pair<i64, i64>;
using vpii = vector<pii>;
template <typename T>
using vec = vector<T>;
const constexpr i64 MOD = 998244353;

void solve()
{
    i64 r, g, b;
    cin >> r >> g >> b;
    /* 
        如果有一个很大 R > G + B + 1
        则我们为了隔开R，最多只能有l = (G + B + 1)*2 + 1的长度
        : RGRGRBRBR
        否则我们就可以将这些用完，即l = R + G + B
    */
    i64 l = min(r + g + b, 2 * (r + g + b - max({r, g, b})) + 1);
    // 找到最大的
    // [r,g,b] => [0,1,2]
    struct data
    {
        i64 k;
        char p;
    };

    vec<data> vp = {{r, 'R'}, {g, 'G'}, {b, 'B'}};
    sort(all(vp), [](auto a, auto b) { return a.k > b.k; });

    if (vp[0].k > vp[1].k + vp[2].k + 1) {
        // 截断绝对用不上的
        vp[0].k = vp[1].k + vp[2].k + 1;
    }
    string s = "";
    for (i64 i = 0; i < l; i++) {
        i64 best = -1;
        for (i64 j = 0; j < 3; j++) {
            auto &&[jk, jp] = vp[j];
            if (jk <= 0) continue;
            if (i >= 1 && jp == s[i - 1]) continue;
            if (i >= 3 && jp == s[i - 3]) continue;
            if (best == -1) {
                best = j;
            }
            else {
                auto &&[bk, bp] = vp[best];
                bool ok1 = (i >= 2 && jp == s[i - 2]);
                bool ok2 = (i >= 2 && bp == s[i - 2]);
                // 先消耗多的
                if (jk > bk) {
                    best = j;
                }
                else if (jk == bk) {
                    // 如果一样多，优先消耗一样的
                    if (ok1 && !ok2) {
                        best = j;
                    }
                }
            }
        }
        s += vp[best].p;
        vp[best].k--;
    }
    cout << s << endl;
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