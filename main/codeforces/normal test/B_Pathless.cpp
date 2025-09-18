//#pragma GCC optimize(3)
#include <bits/stdc++.h>
// #define int LL
#define endl '\n'
#define all(v) v.begin(), v.end()
using namespace std;
using i64 = long long;
// typedef long long LL;
typedef vector<i64> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<i64, i64> pii;
typedef vector<pii> vpii;

void solve()
{
    i64 n, s;
    cin >> n >> s;
    vint v(n);
    i64 sum = 0;
    vint cnt(4);
    for (i64 i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
        cnt[v[i]]++;
    }
    if (sum > s) {
        for (i64 i = 0; i < n; i++) {
            cout << v[i] << ' ';
        }
        cout << endl;
        return;
    }
    if (sum == s) {
        cout << -1 << endl;
        return;
    }
    // s - sum 为需要多走的数
    // 如果构造,则不能出现01这样的结构
    // 则只能出现02
    // 我们将所有的0放到最前面,则开始一定是偶数进行的
    // 如果1的数量为偶数,则结果一定是偶数? 不是,但是构造不出sum + 1
    // 如果1的数量为奇数(不包括1),则为奇数
    // 如果1只有1个,则只会到sum 这个奇数,其余可以构造为偶数
    if (s == sum + 1) {
        for (i64 i = 0; i < cnt[0]; i++) {
            cout << 0 << " ";
        }
        for (i64 i = 0; i < cnt[2]; i++) {
            cout << 2 << " ";
        }
        for (i64 i = 0; i < cnt[1]; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    else {
        cout << -1 << endl;
        return;
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    i64 T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}