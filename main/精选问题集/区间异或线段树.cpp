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

struct Seg
{
    struct Node
    {
        i64 sum;
        array<i64, 61> cnt; // 每一位的1的个数（支持到60位）
        i64 xorlazy;
        Node()
        {
            sum = 0;
            xorlazy = 0;
            cnt.fill(0);
        }
    };
    Node merge(const Node &L, const Node &R)
    {
        Node res;
        res.sum = L.sum + R.sum;
        for (int b = 0; b < 61; ++b) res.cnt[b] = L.cnt[b] + R.cnt[b];
        return res;
    }
    i64 n;
    vector<Node> seg;
    Seg(i64 n)
    {
        this->n = n;
        seg.resize(4 * n + 4);
    }
    void build(i64 idx, i64 l, i64 r, const vint &a)
    {
        if (l == r) {
            seg[idx].sum = a[l];
            seg[idx].xorlazy = 0;
            for (int b = 0; b < 61; b++) seg[idx].cnt[b] = ((a[l] >> b) & 1);
            return;
        }
        i64 mid = (l + r) >> 1;
        build(idx << 1, l, mid, a);
        build(idx << 1 | 1, mid + 1, r, a);
        seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
    }
    void apply(i64 idx, i64 l, i64 r, i64 val)
    {
        if (val == 0) return;
        i64 len = r - l + 1;
        for (int b = 0; b < 61; ++b) {
            if ((val >> b) & 1) {
                // 该位翻转：1 的个数变为 len - cnt
                seg[idx].cnt[b] = len - seg[idx].cnt[b];
            }
        }
        // 根据每位的计数重算 sum
        i64 s = 0;
        for (int b = 0; b < 61; b++)
            if (seg[idx].cnt[b]) s += (seg[idx].cnt[b] << b);
        seg[idx].sum = s;
        seg[idx].xorlazy ^= val;
    }
    void push(i64 idx, i64 l, i64 r)
    {
        if (!seg[idx].xorlazy) return;
        i64 mid = (l + r) >> 1;
        i64 _val = seg[idx].xorlazy;
        apply(idx << 1, l, mid, _val);
        apply(idx << 1 | 1, mid + 1, r, _val);
        seg[idx].xorlazy = 0;
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
        if (qr <= mid)
            return query(idx << 1, l, mid, ql, qr);
        else if (ql > mid)
            return query(idx << 1 | 1, mid + 1, r, ql, qr);
        else
            return merge(query(idx << 1, l, mid, ql, qr), query(idx << 1 | 1, mid + 1, r, ql, qr));
    }
};

void solve()
{
    i64 n, q;
    cin >> n >> q;
    vint v(n + 1, 0);
    Seg sg(n);
    sg.build(1, 1, n, v);
    while (q--) {
        i64 op;
        cin >> op;
        i64 l, r;
        cin >> l >> r;
        if (op == 0) {
            sg.modify(1, 1, n, l, r, 1);
        }
        else {
            cout << sg.query(1, 1, n, l, r).sum << endl;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}