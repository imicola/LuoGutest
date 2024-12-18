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

string s;

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> s;
    int ans = 0;
    for (size_t i = 0; i < s.size() - 1; i++) {
        int count = 1;
        for (size_t k = i; s[k] != s[k + 1] && k < s.size() - 1; k++) {
            count++;
        }
        ans += (count * (count - 1)) / 2;
        i += count - 1;
    }
    cout << ans;
    return 0;
}
//10101 1101
//10