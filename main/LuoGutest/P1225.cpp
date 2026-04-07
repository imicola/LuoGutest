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
    状态压缩，按顺序编码棋盘，如果该位置是1则该位为1
    生成状态图
    bfs 求解最短路径
*/

void solve()
{
    i64 st = 0;
    i64 target = 0;
    // 初始图
    for (i64 i = 0; i < 16; i++) {
        char c;
        cin >> c;
        st += (c == '0' ? 0 : (1LL << i));
    }
    // 目标图
    for (i64 i = 0; i < 16; i++) {
        char c;
        cin >> c;
        target += (c == '0' ? 0 : (1LL << i));
    }
    // 生成状态图
    vint pre(1 << 16, -1);
    vstr step(1 << 16);
    bitset<(1 << 16)> bs;
    queue<i64> q;
    q.push(st);
    pre[st] = st;
    step[st] = "";
    while (!q.empty()) {
        // cout << 1 << endl;
        // 我们现在有当前状态，我们讲下一个可能的状态加入队列
        // 棋盘相邻的是可交换的，4 x 4 的棋盘有效相邻位置有 24 个
        i64 u = q.front();
        q.pop();
        // 如果当前状态被访问过了，我们就不继续往下走了
        if (u == target) {
            // 从当前路径回溯到初始状态
            vector<string> ans;
            while (u != st) {
                ans.push_back(step[u]);
                u = pre[u];
            }
            reverse(all(ans));
            cout << ans.size() << endl;
            for (auto &&s : ans) {
                cout << s << endl;
            }
            return;
        }
        // 枚举24个状态
        // 下标to位
        auto idx2mask = [&](i64 x, i64 y) -> i64 { return 4 * x + y; };
        auto getcloro = [&](i64 x, i64 y) -> i64 { return (u >> idx2mask(x, y)) & 1; };
        // 横向
        for (i64 i = 0; i < 4; i++) {
            for (i64 j = 0; j < 3; j++) {
                // 同色
                if (getcloro(i, j) == getcloro(i, j + 1)) continue;
                // 交换
                // 如何快速生成交换后的状态
                i64 v = u ^ (1LL << idx2mask(i, j)) ^ (1LL << idx2mask(i, j + 1));
                if(bs[v]) continue;
                bs[v] = 1;
                q.push(v);
                if (pre[v] == -1) {
                    pre[v] = u;
                    step[v] = to_string(i + 1) + to_string(j + 1) + to_string(i + 1) + to_string(j + 2);
                }
            }
        }
        // 竖向
        for (i64 i = 0; i < 3; i++) {
            for (i64 j = 0; j < 4; j++) {
                // 同色
                if (getcloro(i, j) == getcloro(i + 1, j)) continue;
                // 交换
                i64 v = u ^ (1LL << idx2mask(i, j)) ^ (1LL << idx2mask(i + 1, j));
                if (bs[v]) continue;
                bs[v] = 1;
                q.push(v);
                if (pre[v] == -1) {
                    pre[v] = u;
                    step[v] = to_string(i + 1) + to_string(j + 1) + to_string(i + 2) + to_string(j + 1);
                }
            }
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