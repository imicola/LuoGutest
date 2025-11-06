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

/* 
    这个的主要问题是在限定条件下两个数组的最大取值可能性
    主要限制是z，确保了最大的选择值
    按从大到小排序
    如果z == a + b则就是合并后的前缀
    我们先看合并后缀z中包含多少a和多少b
    一定有一个是多的，记为over
    对于多的我们删去最小的 over个
    然后对于另外一个我们加上over个即可？
*/

void solve()
{
    i64 n, m, q;
    cin >> n >> m >> q;
    vint a(n), b(m);
    vpii ab(n + m);
    for (i64 i = 0; i < n; i++) {
        cin >> a[i];
        ab[i].first = a[i];
        ab[i].second = 1;
    }
    for (i64 i = 0; i < m; i++) {
        cin >> b[i];
        ab[n + i].first = b[i];
        ab[n + i].second = 2;
    }
    sort(all(ab), greater<pii>{});
    sort(all(a), greater<i64>{});
    sort(all(b), greater<i64>{});
    auto makepre = [&](const vint &v) -> vint {
        i64 len = v.size();
        vint res(len + 1, 0);
        for (i64 i = 1; i <= len; i++) {
            res[i] = res[i - 1] + v[i - 1];
        }
        return res;
    };
    vint prea = makepre(a);
    vint preb = makepre(b);
    vint preab(n + m + 1);
    vint typea(n + m + 1);
    vint typeb(n + m + 1);
    for (i64 i = 1; i <= n + m; i++) {
        preab[i] = preab[i - 1] + ab[i - 1].first;
        typea[i] = typea[i - 1] + (ab[i - 1].second == 1);
        typeb[i] = typeb[i - 1] + (ab[i - 1].second == 2);
    }
    while (q--) {
        i64 x, y, z;
        cin >> x >> y >> z;
        i64 ca = typea[z];
        i64 cb = typeb[z];
        if (x >= ca && y >= cb) {
            cout << preab[z] << endl;
            continue;
        }
        // 前面z个中的a数组数量大于需要的
        // 从a中拿走over个最小的
        // 即拿走x ~ z的
        if (x < ca) {
            i64 over = ca - x;
            i64 sum = preab[z];
            i64 drp = prea[ca] - prea[ca - over];
            i64 add = preb[cb + over] - preb[cb];
            cout << sum - drp + add << endl;
        }
        else if (y < cb) {
            i64 over = cb - y;
            i64 sum = preab[z];
            i64 drp = preb[cb] - preb[cb - over];
            i64 add = prea[ca + over] - prea[ca];
            cout << sum - drp + add << endl;
        }
    }
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