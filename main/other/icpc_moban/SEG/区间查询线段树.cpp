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

// 这里用求区间最大子段和来做示例

struct Seg
{
    struct Node
    {
        i64 sum, lmax, rmax, tmax;
    };
    i64 n;
    vector<Node> seg;
    Seg(i64 n): n(n), seg(4 * n + 4, Node()) { }
    //
    Node merge(const Node &L, const Node &R)
    {
        Node res;
        res.sum = L.sum + R.sum;
        res.lmax = max(L.lmax, L.sum + R.lmax);
        res.rmax = max(R.rmax, R.sum + L.rmax);
        res.tmax = max({L.tmax, R.tmax, L.rmax + R.lmax});
    }
    void build(i64 idx, i64 l, i64 r, const vint &v)
    {
        if (l == r) {
            i64 val = v[l];
            seg[idx] = {val, val, val, val};
            return;
        }
        i64 mid = (l + r) >> 1;
        build(idx << 1, l, mid, v);
        build(idx << 1 | 1, mid + 1, r, v);
        seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
    }
    Node query(i64 idx, i64 l, i64 r, i64 ql, i64 qr)
    {
        if (ql <= l && r <= qr) return seg[idx];
        i64 mid = (l + r) >> 1;
        if (qr <= mid) {
            return query(idx << 1, l, mid, ql, qr);
        }
        else if (ql > mid) {
            return query(idx << 1 | 1, mid + 1, r, ql, qr);
        }
        else {
            return merge(query(idx << 1, l, mid, ql, qr), query(idx << 1 | 1, mid + 1, r, ql, qr));
        }
    }
};

void solve() { }
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}