//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int LL
#define endl '\n'
#define size_t int
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long LL;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int ans;
void f(int a, int n, int last_num)
{
    if (n == 0 && a == 0) {
        ans++;
        return;
    }
    for (size_t i = last_num; i <= a; i++) {
        f(a - i, n - 1, i);
    }
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a, n;
    cin >> a >> n;
    f(a, n, 1);
    cout << ans;
    return 0;
}