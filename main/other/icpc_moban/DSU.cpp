//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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

class DSU
{
private:
    const int N = 1e7;
    vector<int> parent = vector<int>(N);
    vector<int> ranks = vector<int>(N);
    vector<int> sz = vector<int>(N); // 新增：记录每个集合的大小

public:
    // 初始化
    void init()
    {
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
            ranks[i] = 1;
            sz[i] = 1; // 每个元素初始时各自成集合，大小为1
        }
    }
    // 查找（带路径压缩）
    int dsufind(int x)
    {
        if (parent[x] != x) {
            parent[x] = dsufind(parent[x]);
        }
        return parent[x];
    }
    // 合并（按秩合并 + 更新集合大小）
    void union_set(int x, int y)
    {
        int rootx = dsufind(x);
        int rooty = dsufind(y);
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
    int getSize(int x)
    {
        int root = dsufind(x);
        return sz[root];
    }
};

void solve()
{
    DSU ds;
    ds.init();
    ds.union_set(1, 2);
    ds.union_set(3, 1);
    cout << ds.dsufind(3);
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}