//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
//#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
//typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

/* 
    支持modify的线段树，融合的merge
    默认功能是区间和，可以自定义扩展
*/

struct Seg
{
    struct Node
    {
        i64 sum;
        i64 xorlazy;
        bool has_modify = 0;
    };
    Node merge(const Node &L, const Node &R)
    {
        Node res;
        res.sum = L.sum + R.sum;
        return res;
    }
    i64 n;
    vector<Node> seg;
    Seg(i64 n)
    {
        this->n = n;
        seg.resize(4 * n + 4);
    }
    void build(i64 idx, i64 l, i64 r, vint a)
    {
        if (l == r) {
            seg[idx].sum = a[l];
            return;
        }
        i64 mid = (l + r) >> 1;
        build(idx << 1, l, mid, a);
        build(idx << 1 | 1, mid + 1, r, a);
        seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
    }
    void apply(i64 idx, i64 l, i64 r, i64 val)
    {
        seg[idx].sum = (r - l + 1) * val;
        seg[idx].xorlazy = val;
        seg[idx].has_modify = 1;
    }
    void push(i64 idx, i64 l, i64 r)
    {
        if (!seg[idx].has_modify) return;
        i64 mid = (l + r) >> 1;
        i64 down = seg[idx].xorlazy;
        apply(idx << 1, l, mid, down);
        apply(idx << 1 | 1, mid + 1, r, down);
        seg[idx].has_modify = 0;
    }
    void modify(i64 idx, i64 l, i64 r, i64 ql, i64 qr, i64 val)
    {
        if (ql <= l && r <= qr) {
            apply(idx, l, r, val);
            return;
        }
        push(idx, l, r);
        i64 mid = (l + r) >> 1;
        if (ql <= mid) modify(idx << 1, l, mid, ql, qr, val);
        if (qr > mid) modify(idx << 1 | 1, mid + 1, r, ql, qr, val);
        seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
    }
    Node query(i64 idx, i64 l, i64 r, i64 ql, i64 qr)
    {
        if (ql <= l && r <= qr) {
            return seg[idx];
        }
        push(idx, l, r);
        i64 mid = (l + r) >> 1;
        if (ql <= mid)
            return query(idx << 1, l, mid, ql, qr);
        else if (qr > mid)
            return query(idx << 1 | 1, mid + 1, r, ql, qr);
        else
            return merge(query(idx << 1, l, mid, ql, qr), query(idx << 1 | 1, mid + 1, r, ql, qr));
    }
};

void solve() { 
    
}
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