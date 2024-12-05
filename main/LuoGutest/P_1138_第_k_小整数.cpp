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

signed main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a, k;
    cin >> a >> k;
    set<int> n;
    for (size_t i = 0; i < a; i++) {
        int t;
        cin >> t;
        n.insert(t);
    }
    auto it = n.begin();
    if (k > n.size() || k <= 0) {
        cout << "NO RESULT";
        return 0;
    }
    advance(it, k - 1);
    cout << *it;

    return 0;
}