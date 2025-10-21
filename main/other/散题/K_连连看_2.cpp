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

/* 
    先考虑特殊情况，两个相邻的时候肯定无解
    考虑两个位于对角，有两个边已经被封死了，只需要再封死两个边就可以，输出2
    考虑处于边的情况,只要两个的一边距离小于等于1，就可以两个
    考虑
    0x
    x0
    这种情况也是两个
    当某一边的距离小于等于1时候，可以用三个围堵一个
*/

void solve()
{
    i64 n, m;
    cin >> n >> m;
    i64 stx, sty, edx, edy;
    cin >> stx >> sty >> edx >> edy;
    i64 ok = 0;
    pii ed = {edx, edy};
    for (auto &&i : {1, -1}) {
        pii k1 = {stx + i, sty};
        pii k2 = {stx, sty + i};
        if (k1 == ed || k2 == ed) {
            cout << -1 << endl;
            return;
        }
    }
    if (ok) {
        cout << -1 << endl;
        return;
    }
    i64 ans = 3;
    if (m <= 2 || n <= 2) {
        cout << min(m, n) << endl;
        return;
    }
    // 边角
    vpii edge = {{1, 1}, {n, 1}, {1, m}, {n, m}};
    for (auto &&i : edge) {
        pii x1 = {stx, sty};
        pii x2 = {edx, edy};
        if (x1 == i || x2 == i) {
            cout << 2 << endl;
            return;
        }
    }
    if (abs(stx - edx) <= 1 && abs(sty - edy) <= 1) {
        cout << 2 << endl;
        return;
    }
    // 贴边
    vint px = {1, n};
    vint py = {1, m};
    for (auto &&i : px) {
        if (stx == i || edx == i) {
            // if (stx == i) {
            if (abs(stx - edx) <= 1) {
                cout << 2 << endl;
                return;
            }
        }
    }
    for (auto &&i : py) {
        if (sty == i || edy == i) {
            // if (sty == i) {
            if (abs(sty - edy) <= 1) {
                cout << 2 << endl;
                return;
            }
        }
    }
    // 考虑三个的情况
    if (stx == 1 || sty == 1 || stx == n || sty == m) {
        cout << 3 << endl;
        return;
    }
    if (abs(stx - edx) <= 1 || abs(sty - edy) <= 1) {
        cout << 3 << endl;
        return;
    }
    // 考虑坐标差为2
    /* 
        a0x
        0x0
        x0b
    */
    if (abs(stx - edx) == 2 && abs(sty - edy) == 2) {
        cout << 3 << endl;
        return;
    }
    //否则需要全部围堵
    cout << 4 << endl;
    return;
}

int solve2()
{
    i64 n, m;
    cin >> n >> m;
    i64 stx, sty, edx, edy;
    cin >> stx >> sty >> edx >> edy;
    if (abs(stx - edx) + abs(sty - edy) == 1) return -1;
    if (n == 1 || m == 1) return 1;
    if ((stx == 1 || stx == n) && (sty == 1 || sty == m)) return 2;
    if (abs(stx - edx) == 1 && abs(sty - edy) == 1) return 2;
    if (stx == 1 && edx <= 2) return 2;
    if (stx == n && edx >= n - 1) return 2;
    if (sty == 1 && edy <= 2) return 2;
    if (sty == m && edy >= m - 1) return 2;
    if (stx == 1 || stx == n || sty == 1 || sty == m) return 3;
    if (abs(stx - edx) <= 1 || abs(sty - edy) <= 1) return 3;
    if (abs(stx - edx) == 2 && abs(sty - edy) == 2) return 3;
    return 4;
}

// ================= 对拍辅助：纯函数版本 =================
static int solve1_eval(i64 n, i64 m, i64 stx, i64 sty, i64 edx, i64 edy)
{
    // 邻接判负一
    pii ed = {edx, edy};
    for (auto &&i : {1, -1}) {
        pii k1 = {stx + i, sty};
        pii k2 = {stx, sty + i};
        if (k1 == ed || k2 == ed) {
            return -1;
        }
    }

    if (m <= 2 || n <= 2) {
        return (int)min(m, n);
    }
    // 边角
    vpii edge = {{1, 1}, {n, 1}, {1, m}, {n, m}};
    for (auto &&i : edge) {
        pii x1 = {stx, sty};
        pii x2 = {edx, edy};
        if (x1 == i || x2 == i) {
            return 2;
        }
    }
    if (abs(stx - edx) <= 1 && abs(sty - edy) <= 1) {
        return 2;
    }
    // 贴边
    // 贴边：同时考虑行/列
    bool on_edge_x = (stx == 1 || stx == n || edx == 1 || edx == n);
    bool on_edge_y = (sty == 1 || sty == m || edy == 1 || edy == m);
    if (on_edge_x && abs(stx - edx) <= 1) {
        return 2;
    }
    if (on_edge_y && abs(sty - edy) <= 1) {
        return 2;
    }
    if (on_edge_x || on_edge_y) {
        return 3;
    }
    // 考虑三个的情况
    if (stx == 1 || sty == 1 || stx == n || sty == m) {
        // cout << 3 << endl;
        return 3;
    }
    if (abs(stx - edx) <= 1 || abs(sty - edy) <= 1) {
        return 3;
    }
    // 坐标差为2
    if (abs(stx - edx) == 2 && abs(sty - edy) == 2) {
        return 3;
    }
    // 否则需要全部围堵
    return 4;
}

static int solve2_eval(i64 n, i64 m, i64 stx, i64 sty, i64 edx, i64 edy)
{
    if (abs(stx - edx) + abs(sty - edy) == 1) return -1;
    if (n == 1 || m == 1) return 1;
    if ((stx == 1 || stx == n) && (sty == 1 || sty == m)) return 2;
    if (abs(stx - edx) == 1 && abs(sty - edy) == 1) return 2;
    if (stx == 1 && edx <= 2) return 2;
    if (stx == n && edx >= n - 1) return 2;
    if (sty == 1 && edy <= 2) return 2;
    if (sty == m && edy >= m - 1) return 2;
    if (stx == 1 || stx == n || sty == 1 || sty == m) return 3;
    if (abs(stx - edx) <= 1 || abs(sty - edy) <= 1) return 3;
    if (abs(stx - edx) == 2 && abs(sty - edy) == 2) return 3;
    return 4;
}

// 对拍：一次生成多组随机数据并比较两种解法
static void stress_test(int rounds = 10000, int nMax = 10, int mMax = 10, unsigned long long seed = 0)
{
    if (seed == 0) seed = chrono::steady_clock::now().time_since_epoch().count();
    mt19937_64 rng(seed);
    auto rnd = [&](i64 l, i64 r) { return uniform_int_distribution<i64>(l, r)(rng); };

    for (int t = 1; t <= rounds; ++t) {
        i64 n = rnd(1, nMax);
        i64 m = rnd(1, mMax);
        i64 stx = rnd(1, n);
        i64 sty = rnd(1, m);
        i64 edx = rnd(1, n);
        i64 edy = rnd(1, m);
        // 可选：避免完全相同起终点，若想允许则删除此段
        if (stx == edx && sty == edy) {
            if (edx < n)
                ++edx;
            else if (edx > 1)
                --edx; // 轻微扰动
        }

        int a = solve1_eval(n, m, stx, sty, edx, edy);
        int b = min(solve2_eval(n, m, stx, sty, edx, edy), solve1_eval(n, m, edx, edy, stx, sty));
        if (a != b) {
            cout << "Mismatch found at test #" << t << "\n";
            cout << "Input: n=" << n << ", m=" << m << ", st=(" << stx << "," << sty << "), ed=(" << edx << "," << edy
                 << ")\n";
            cout << "solve1_eval -> " << a << ", solve2_eval -> " << b << "\n";
            return;
        }
    }
    cout << "All " << rounds << " tests passed. Seed=" << seed << "\n";
}
#define STRESS_TEST
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);

    // 若要直接运行对拍，将下行宏改为 1 或在编译时添加 -DSTRESS_TEST
#ifdef STRESS_TEST
    stress_test(10000, 15, 15);
    return 0;
#else
    i64 T = 1;
    cin >> T;
    while (T--) {
        cout << solve2() << endl;
        // solve();
    }
    return 0;
#endif
}