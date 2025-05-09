//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
#define endl '\n'
// #define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

void solve()
{
    int n;
    cin >> n;
    vint a(n);
    for (auto &&i : a) {
        cin >> i;
    }
    vint vs = a;
    ranges::sort(vs, greater<int>{});
    //抽象优化技巧之把v[i]和其对应的下标存入map中
    map<int, vector<int>> v_index;
    for (int j = 0; j < n; ++j) {
        v_index[a[j]].emplace_back(j);
    }
    //为每个权重记录了下一次我们应该从 v_index[i] 向量的哪个位置开始查找
    map<int, size_t> next_idx_ptr;
    map<int, int> st;
    vint path(n, 0);
    int ans = 0;
    for (auto &&i : vs) {
        if (st[i] > 0) {
            st[i]--;
            continue;
        }
        //这个idx表示我们55行后面操作的下标
        int idx = -1;
        if (v_index.count(i)) {
            // 取当前数的所有下标集合
            vint &vi_idx = v_index[i];
            // 取这个数下标集合中进行到多少个下标
            size_t &now_idx = next_idx_ptr[i];
            while (now_idx < vi_idx.size()) {
                // f_inx 代表我们要找的第下标的实际值
                // 该下标应该满足path[idx] != 0
                int f_idx = vi_idx[now_idx];
                // 当我们找到符合的下标的时候退出
                if (path[f_idx] == 0) {
                    idx = f_idx;
                    now_idx++;
                    break;
                }
                now_idx++;
            }
        }
        // 为什么要做上面这一步？
        // 我们需要排除出现找10时候出现[... 10 10 ...] 这样的情况
        if (idx != -1) {
            ans++;
            path[idx] = 1;
            for (int k = idx; k + 1 < n; ++k) {
                if (a[k] >= a[k + 1] && path[k + 1] == 0) {
                    path[k + 1] = 1;
                    st[a[k + 1]]++;
                    continue;
                }
                break;
            }
            for (int k = idx; k - 1 >= 0; --k) {
                if (a[k] >= a[k - 1] && path[k - 1] == 0) {
                    path[k - 1] = 1;
                    st[a[k - 1]]++;
                    continue;
                }
                break;
            }
        }
    }
    cout << ans << endl;
    
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}