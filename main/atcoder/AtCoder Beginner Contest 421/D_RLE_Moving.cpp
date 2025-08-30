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

// 将字符移动转换为 (dx, dy) 向量
pii move_to_vec(char c)
{
    if (c == 'U') return {-1, 0};
    if (c == 'D') return {1, 0};
    if (c == 'L') return {0, -1};
    if (c == 'R') return {0, 1};
    return {0, 0};
}

void solve()
{
    int rt, ct, ra, ca;
    cin >> rt >> ct >> ra >> ca;
    int n, m, l;
    cin >> n >> m >> l;
    vector<pair<char, int>> s(m);
    for (size_t i = 0; i < m; i++) {
        cin >> s[i].first >> s[i].second;
    }
    vector<pair<char, int>> t(l);
    for (size_t i = 0; i < l; i++) {
        cin >> t[i].first >> t[i].second;
    }

    int dx = rt - ra;
    int dy = ct - ca;

    int s_ptr = 0, t_ptr = 0;
    int ans = 0;

    while (s_ptr < m && t_ptr < l) {
        auto [s_char, s_len] = s[s_ptr];
        auto [t_char, t_len] = t[t_ptr];

        int steps_to_process = min(s_len, t_len);

        pii s_move = move_to_vec(s_char);
        pii t_move = move_to_vec(t_char);

        // 相对移动速度
        int vx = s_move.first - t_move.first;
        int vy = s_move.second - t_move.second;

        if (vx == 0 && vy == 0) {
            if (dx == 0 && dy == 0) {
                ans += steps_to_process;
            }
        }
        else {
            // 求解 k: dx + k*vx = 0, dy + k*vy = 0
            // k = -dx/vx, k = -dy/vy
            LL k1 = -1, k2 = -1;
            if (vx != 0) {
                if (dx % vx == 0) {
                    k1 = -dx / vx;
                }
            }
            else if (dx == 0) {
                k1 = -2; // 表示 dx=0, vx=0，对 k 没有限制
            }

            if (vy != 0) {
                if (dy % vy == 0) {
                    k2 = -dy / vy;
                }
            }
            else if (dy == 0) {
                k2 = -2; // 表示 dy=0, vy=0，对 k 没有限制
            }

            LL k = -1;
            if (k1 == -2 && k2 != -1 && k2 > 0)
                k = k2;
            else if (k2 == -2 && k1 != -1 && k1 > 0)
                k = k1;
            else if (k1 != -1 && k1 == k2 && k1 > 0)
                k = k1;

            if (k != -1 && k <= steps_to_process) {
                ans++;
            }
        }
        // 更新相对坐标
        dx += steps_to_process * vx;
        dy += steps_to_process * vy;

        // 更新剩余步数
        s[s_ptr].second -= steps_to_process;
        t[t_ptr].second -= steps_to_process;

        if (s[s_ptr].second == 0) {
            s_ptr++;
        }
        if (t[t_ptr].second == 0) {
            t_ptr++;
        }
    }

    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // cout << setiosflags(ios::fixed) << setprecision(2); // 这道题不需要浮点数精度
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}