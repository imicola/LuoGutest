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

void solve()
{
    i64 n, m;
    cin >> n >> m;
    vint a1, b1, a2, b2;
    set<i64> st1, st2;
    a1.reserve(n), a2.reserve(n);
    b1.reserve(m), b2.reserve(m);
    for (i64 i = 0; i < n; i++) {
        i64 x;
        cin >> x;
        (x > 0 ? a1.emplace_back(x) : a2.emplace_back(-x));
        (x > 0 ? st1.insert(x) : st2.insert(-x));
    }
    for (i64 i = 0; i < m; i++) {
        i64 x;
        cin >> x;
        (x > 0 ? b1.emplace_back(x) : b2.emplace_back(-x));
    }
    /* 
        我们可以当作两个问题来算，纯正数的 + 纯负数的
        什么思路呢？对于每一个bi，我们都可以知道它前面有多少个ai
        这就代表如果到这个点，他之前的尾巴块能有多长
        那么这个点最多的情况就是 前面块长度中覆盖多少个bi + 这个点后有多少个本身就在点位置上的
        前面的情况可以用二分
        后面的情况就可以先做一个后缀预处理
    */
    reverse(all(b2));
    // ensure vectors are sorted for upper_bound / binary searches
    sort(all(a1));
    sort(all(a2));
    sort(all(b1));
    sort(all(b2));
    auto f = [&](set<i64> st, vint a, vint b) -> i64 {
        i64 res = 0;
        i64 lena = a.size(), lenb = b.size();
        if (lena == 0 || lenb == 0) return 0;
        vint suf(lenb);
        suf[lenb - 1] = (st.count(b[lenb - 1]) ? 1 : 0);
        for (int i = lenb - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + (st.count(b[i]) ? 1 : 0);
        }
        for (i64 i = 0; i < lenb; i++) {
            i64 have = 1;
            // 找到第一个大于b的元素
            auto it = upper_bound(all(a), b[i]);
            i64 idx = it - a.begin();
            if (idx == 0) continue;
            i64 len = idx;
            if (it == a.end()) len = lena;
            auto it2 = upper_bound(all(b), b[i] - len);
            i64 idx2 = it2 - b.begin();
            if (idx2 == 0)
                have = i + 1;
            else
                have = i + 1 - idx2;
            if (st.count(b[i])) have--;
            res = max(have + suf[i], res);
        }
        return res;
    };
    cout << f(st1, a1, b1) + f(st2, a2, b2) << endl;
}
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