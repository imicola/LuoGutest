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

// 加法下的带lazy sign线段树
struct Seg
{
    struct Node
    {
        i64 sum = 0, add = 0, mul = 1;
    };
    i64 n;
    i64 mod;
    vector<Node> seg;
    Seg(i64 n, i64 mod)
    {
        this->n = n;
        this->mod = mod;
        seg.resize((n << 2) + 4);
    }
    // 合并逻辑
    Node merge(const Node &L, const Node &R)
    {
        Node res;
        res.sum = (L.sum + R.sum) % mod;
        res.add = 0;
        res.mul = 1;
        return res;
    }
    //懒标记应用
    void applyadd(i64 idx, i64 l, i64 r, i64 val)
    {
        seg[idx].add = (seg[idx].add + val) % mod;
        seg[idx].sum = (seg[idx].sum + val * (r - l + 1) % mod) % mod;
    }
    void applymul(i64 idx, i64 l, i64 r, i64 val)
    {
        seg[idx].mul = (seg[idx].mul * val) % mod;
        seg[idx].sum = seg[idx].sum * val % mod;
        seg[idx].add = seg[idx].add * val % mod;
    }
    // 懒标记向下应用
    void push(i64 idx, i64 l, i64 r)
    {
        i64 &_add = seg[idx].add;
        i64 &_mul = seg[idx].mul;
        if (_add == 0 && _mul == 1) return;
        i64 mid = (l + r) >> 1;
        applymul(idx << 1, l, mid, _mul);
        applymul(idx << 1 | 1, mid + 1, r, _mul);
        applyadd(idx << 1, l, mid, _add);
        applyadd(idx << 1 | 1, mid + 1, r, _add);
        _add = 0;
        _mul = 1;
    }
    void build(i64 idx, i64 l, i64 r, const vint &a)
    {
        if (l == r) {
            seg[idx].sum = a[l];
            seg[idx].add = 0;
            return;
        }
        i64 mid = (l + r) >> 1;
        build(idx << 1, l, mid, a);
        build(idx << 1 | 1, mid + 1, r, a);
        seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
    }
    // 1是加法，2是乘法
    void update(i64 idx, i64 l, i64 r, i64 ql, i64 qr, i64 val, i64 op)
    {
        if (op == 1) {
            if (ql <= l && r <= qr) {
                applyadd(idx, l, r, val);
                return;
            }
        }
        if (op == 2) {
            if (ql <= l && r <= qr) {
                applymul(idx, l, r, val);
                return;
            }
        }
        push(idx, l, r);
        i64 mid = (l + r) >> 1;
        if (ql <= mid) update(idx << 1, l, mid, ql, qr, val, op);
        if (qr > mid) update(idx << 1 | 1, mid + 1, r, ql, qr, val, op);
        seg[idx] = merge(seg[idx << 1], seg[idx << 1 | 1]);
    }
    Node query(i64 idx, i64 l, i64 r, i64 ql, i64 qr)
    {
        if (ql <= l && r <= qr) return seg[idx];
        push(idx, l, r);
        i64 mid = (l + r) >> 1;
        i64 res = 0;
        if (qr <= mid)
            return query(idx << 1, l, mid, ql, qr);
        else if (ql > mid)
            return query(idx << 1 | 1, mid + 1, r, ql, qr);
        else
            return merge(query(idx << 1, l, mid, ql, qr), query(idx << 1 | 1, mid + 1, r, ql, qr));
    }
    void build(const vint &a)
    {
        build(1, 1, n, a);
    }
    void update(i64 l, i64 r, i64 val, i64 op)
    {
        update(1, 1, n, l, r, val, op);
    }
    i64 query(i64 l, i64 r)
    {
        return query(1, 1, n, l, r).sum % mod;
    }
};

void solve()
{
    i64 n, m, mod;
    cin >> n >> m >> mod;
    vint a(n + 1);
    for (i64 i = 1; i <= n; i++) cin >> a[i];
    Seg sg(n, mod);
    sg.build(a);
    while (m--) {
        i64 op;
        cin >> op;
        if (op == 1) {
            i64 x, y, k;
            cin >> x >> y >> k;
            sg.update(x, y, k, 2);
        }
        if (op == 2) {
            i64 x, y, k;
            cin >> x >> y >> k;
            sg.update(x, y, k, 1);
        }
        if (op == 3) {
            i64 x, y;
            cin >> x >> y;
            cout << sg.query(x, y) % mod << endl;
        }
    }
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