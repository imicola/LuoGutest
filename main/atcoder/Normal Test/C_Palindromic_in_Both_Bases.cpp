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

bool ishui(const string &s)
{
    int len = s.size() - 1;
    for (int i = 0, j = len; i < j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

void solve()
{
    int a, n;
    cin >> a >> n;
    //转换进制成为字符串
    auto tr = [&](int p) -> string {
        string s;
        while (p > 0) {
            s += ((p % a) + '0');
            p /= a;
        }
        //因为要判断回文，所以无需反转字符串，直接返回
        return s;
    };
    //需要到达的最高位
    int len = to_string(n).size();
    int cnt = 0;
    //1 - 9 都是回文数
    for (size_t i = 0; i < 10; i++) {
        if (ishui(tr(i)) && i <= n) cnt += i;
    }
    if (n < 10) {
        cout << cnt << endl;
        return;
    }
    //生成回文数，只需要生成到最高位数的一半
    for (size_t i = 1; i <= pow(10, len / 2); i++) {
        string s = to_string(i);
        string p = s;
        string g = s;
        reverse(all(p));
        //生成偶数位回文数
        g += p;
        int re = stoll(g);
        if (re > n) break;
        if (ishui(tr(re))) cnt += re;
        //生成奇数位回文数
        for (char k = '0'; k <= '9'; k++) {
            g = s;
            g += k + p;
            re = stoll(g);
            if (re > n) break;
            if (ishui(tr(re))) cnt += re;
        }
    }
    cout << cnt << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}