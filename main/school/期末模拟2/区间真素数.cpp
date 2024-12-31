//#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int LL
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

bool isprime(int n)
{
    if (n < 2) return 0;
    for (size_t i = 2; i <= n / i; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m, n;
    cin >> m >> n;
    vint ans;
    for (int i = m; i <= n; i++) {
        string s = to_string(i);
        reverse(all(s));
        int x = stoll(s);
        if (isprime(i) && isprime(x)) ans.emplace_back(i);
    }
    if (ans.empty()) {
        cout << "No";
        return 0;
    }
    for (size_t i = 0; i < ans.size(); i++) {
        if (i != ans.size() - 1) {
            cout << ans[i] << ",";
        }
        else if (i == ans.size() - 1) {
            cout << ans[i];
        }
    }
    return 0;
}