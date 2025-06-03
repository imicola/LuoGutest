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

vint box(20);
void f()
{
    box[1] = 1;
    box[2] = 2;
    for (size_t i = 2; i <= 12; i++) {
        box[i] = box[i - 1] + box[i - 2];
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    // vvint bbox(m + 1, vint(3, 0));
    // 0 - w / 1 - l / 2 - h
    for (size_t i = 0; i < m; i++) {
        // cin >> bbox[i][0] >> bbox[i][1] >> bbox[i][2];
        vint s(3), x = {box[n + 1], box[n + 1], box[n] + box[n + 1]};
        for (auto &&i : s) {
            cin >> i;
        }
        ranges::sort(s);
        bool jump = 0;
        for (size_t i = 0; i < 3; i++) {
            // cout << x[i] << endl;
            if (s[i] < x[i]) {
                cout << 0;
                jump = 1;
                break;
            }
        }
        if (jump) continue;
        cout << 1;
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    f();
    while (T--) {
        solve();
    }
    return 0;
}