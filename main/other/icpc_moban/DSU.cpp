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

const int N = 1e7;
class DSU
{
private:
    vector<int> parent = vector<int>(N);
    vector<int> ranks = vector<int>(N);

public:
    void init()
    {
        for (size_t i = 0; i < N; i++) {
            parent[i] = i;
            ranks[i] = 1;
        }
    }
    int dsufind(int x)
    {
        if (parent[x] != x) parent[x] = dsufind(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y)
    {
        int rootx = x;
        int rooty = y;
        if (rootx != rooty) {
            if (ranks[rootx] > ranks[rooty]) {
                parent[rooty] = rootx;
            }
            else if (ranks[rootx] < ranks[rooty]) {
                parent[rootx] = rooty;
            }
            else {
                parent[rootx] = rooty;
                ranks[rootx]++;
            }
        }
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