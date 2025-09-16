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

class DSU
{
private:
    i64 N = 6e3;
    vector<i64> parent = vector<i64>(N);
    vector<i64> ranks = vector<i64>(N);
    vector<i64> sz = vector<i64>(N); // 新增：记录每个集合的大小

public:
    // 初始化
    void init(i64 Nx)
    {
        this->N = Nx;
        for (i64 i = 0; i < N; ++i) {
            parent[i] = i;
            ranks[i] = 1;
            sz[i] = 1; // 每个元素初始时各自成集合，大小为1
        }
    }
    // 查找（带路径压缩）
    i64 dsufind(i64 x)
    {
        if (parent[x] != x) {
            parent[x] = dsufind(parent[x]);
        }
        return parent[x];
    }
    // 合并（按秩合并 + 更新集合大小）
    void union_set(i64 x, i64 y)
    {
        i64 rootx = dsufind(x);
        i64 rooty = dsufind(y);
        if (rootx != rooty) {
            if (ranks[rootx] > ranks[rooty]) {
                parent[rooty] = rootx;
                sz[rootx] += sz[rooty];
            }
            else if (ranks[rootx] < ranks[rooty]) {
                parent[rootx] = rooty;
                sz[rooty] += sz[rootx];
            }
            else {
                parent[rootx] = rooty;
                ranks[rooty]++;
                sz[rooty] += sz[rootx];
            }
        }
    }
    // 获取某元素所在集合的大小
    i64 getSize(i64 x)
    {
        int root = dsufind(x);
        return sz[root];
    }
};

void solve()
{
    i64 n;
    cin >> n;
    // 我们选择连续的线段长度但是不选择一个可以覆盖头尾的串
    // 如何统计?
    DSU ds;
    ds.init(2 * n);
    vint ans;
    for (i64 i = 0; i < n; i++) {
        i64 l, r;
        cin >> l >> r;
        if (ds.dsufind(l) == ds.dsufind(r)) continue;
        ds.union_set(l, r);
        ans.emplace_back(i + 1);
    }
    cout << ans.size() << endl;
    for (auto &&i : ans) {
        cout << i << " ";
    }
    cout << endl;
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